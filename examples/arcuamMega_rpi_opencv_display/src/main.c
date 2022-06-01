/*
 * This file is part of the Arducam SPI Camera project.
 *
 * Copyright 2021 Arducam Technology co., Ltd. All Rights Reserved.
 *
 * This work is licensed under the MIT license, see the file LICENSE for details.
 *
 */
#include "Arducam.h"
#include "Platform.h"
#include <stdio.h>
#include <termio.h>
#include <opencv2/opencv.hpp>
#include "time.h"
#include <unistd.h>

using namespace cv;
using namespace std;

#define JPEG_BUF_SIZE   2*1024*1024 //2M
#define posW            320
#define posH            240


typedef struct  
{
    unsigned long  dataLength;
    uint8_t        pu8ImageData[JPEG_BUF_SIZE];
    uint8_t cameraID;
    unsigned int errCount = 0;
}imageData;


imageData* ArducamImageData = new imageData;




cv::Mat JPGToMat(uint8_t* bytes,int length){
	cv::Mat image = Mat(1,length,CV_8UC1,bytes);
	if(length <= 0){
		image.data = NULL;
	    return image;
	}
	image = imdecode(image,IMREAD_ANYCOLOR);
	return image;
}
cv::Mat ConvertImage(imageData* frameData){
	cv::Mat rawImage ;
       if(frameData->dataLength<=0){
        printf("The %d camera is error.\r\n",frameData->cameraID);  
        return rawImage;
    }
	rawImage = JPGToMat(frameData->pu8ImageData,frameData->dataLength);
	return rawImage;
}


int key = 0;
int csPin = 22;
ArducamCamera myCAM;
int count = 0;
char name[10] = {0};
unsigned char imageBuff[300] = {0};
unsigned int imageLength = 0;


// int scanKeyboard()
// {
//     int in;
//     struct termios new_settings;
//     struct termios stored_settings;
//     tcgetattr(0,&stored_settings);
//     new_settings = stored_settings;
//     new_settings.c_lflag &= (~ICANON);
//     new_settings.c_cc[VTIME] = 0;
//     tcgetattr(0,&stored_settings);
//     new_settings.c_cc[VMIN] = 1;
//     tcsetattr(0,TCSANOW,&new_settings);
    
//     in = getchar();
    
//     tcsetattr(0,TCSANOW,&stored_settings);
//     return in;
// }

// void saveImage(ArducamCamera myCAM)
// {
//     unsigned long value = 0;
//     unsigned char data = 0;
//     FILE* fl = NULL;
//     sprintf(name,"%d.jpg",count);
//     fl = fopen(name,"w+");
//     if (fl == NULL)
//     {
//         printf("Create file failed\r\n");
//         return;
//     }
//     // for ( value = 0; value < myCAM.totalLength; value++)
//     // {
//     //     data = readByte(&myCAM);
//     //     fputc(data,fl);
//     // }
//     while (myCAM.receivedLength)
//     {
//         imageLength = readBuff(&myCAM,imageBuff,200);
//         fwrite(imageBuff,1,imageLength,fl);
//     }
    
//     fclose(fl);
//     count++;
    
// }
#define READ_IMAGE_LENGTH 255

 imageData* getOneframe(imageData* dataBuf)
 {
    unsigned long i  = 0, count = 0;
    unsigned long value = 0;
    uint8_t rt_length = 0;
    bool is_header=0;
    bool is_end = 0;
    bool errorFlag = 0;
    uint8_t temp_last = 0;
    uint8_t temp = 0;
    uint8_t buff[READ_IMAGE_LENGTH] = {0};
    uint8_t data[1024*20]= {0};
    dataBuf->dataLength = 0;
   takePicture(&myCAM,CAM_IMAGE_MODE_QVGA,CAM_IMAGE_PIX_FMT_JPG);
   while (myCAM.receivedLength) 
   {
      rt_length=readBuff(&myCAM,buff,READ_IMAGE_LENGTH);
      for (uint8_t ljp = 0; ljp < rt_length; ljp++)
      {
        data[count++]=buff[ljp];
      }
   }
   value = 0;
   while (count!=value) 
   {
      temp_last = temp;
      temp = data[value];
      value+=1;
     //Read JPEG data from FIFO
      if ( (temp == 0xD9) && (temp_last == 0xFF) ) //If find the end ,break while,
      {
        is_end = 1;
        dataBuf->pu8ImageData[i++] = temp;  //save the last  0XD9   
        dataBuf->dataLength = i-1;
       // is_header = false;
        break;
      } 
      if (is_header == true)
      { 
        dataBuf->pu8ImageData[i++] = temp;       
      }
      
      else if ((temp == 0xD8) && (temp_last == 0xFF))
      {
        is_header = true;
        dataBuf->pu8ImageData[i++] = temp_last;
        dataBuf->pu8ImageData[i++] = temp; 
      } 
   	}
   if(is_header == 0){
     printf("The %d camera can't find the header\r\n",dataBuf->cameraID);
       errorFlag = 1;
   }else{
      is_header = 0;
   }
   if(is_end == 0){
     printf("The %d camera can't find the end\r\n",dataBuf->cameraID);
     errorFlag = 1;
   }else {
      is_end = 0;
   }   
   if(errorFlag){
     dataBuf->errCount ++;
     printf("The %d frame is error\r\n",dataBuf->errCount);
   }

	count = 0;

    return dataBuf;
}

int main(void)
{
  // spiBegin();
  // spiCsOutputMode(csPin);
  // while(1)
  // {
  //   spiCsLow(csPin);
  //   spiReadWriteByte(0x01);
  //   spiCsHigh(csPin);
  // }
    cv::Mat rawImage ;
    unsigned char sendBuff[10] = {0};
    unsigned char readBuff[10] = {0};
    
    myCAM = createArducamCamera(csPin);
    begin(&myCAM);
    printf("Camera Init Succeed\r\n");
    cv::namedWindow("Arducam SPI1 Camera", cv::WINDOW_AUTOSIZE);
    cv::moveWindow("Arducam SPI1 Camera", posW*1,posH*1);
    while (1)
    {

    getOneframe(ArducamImageData); 
    rawImage = ConvertImage(ArducamImageData);
    if(rawImage.empty()){
        printf("Image load failed\r\n");
    }else
    cv::imshow("Arducam SPI1 Camera", rawImage);
     if(waitKey(20) >=0);       // 等待按键，跳出
    }
	// spiRelease();
	return 0;
}





