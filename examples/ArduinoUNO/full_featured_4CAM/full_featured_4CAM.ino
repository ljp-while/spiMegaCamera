// Copyright 2021 Arducam Technology co., Ltd. All Rights Reserved.
// License: MIT License (https://en.wikipedia.org/wiki/MIT_License)
// Web: http://www.ArduCAM.com
// This program is a demo of how to use most of the functions
// of the library with ArduCAM Spi camera, and can run on Arduino platform.
// This demo was made for ArduCAM Spi Camera.
// It needs to be used in combination with PC software.
// It can test ArduCAM Spi Camerafunctions
#include "Arducam.hpp"
#include "Platform.h"
#include "ArducamLink.h"
#include "Arduino.h"

// Set pin 4,5,6,7 as the slave select for SPI:
const int CS1 = CS1_PIN;
const int CS2 = CS2_PIN;
const int CS3 = CS3_PIN;
const int CS4 = CS4_PIN;

Arducam myCAM1( CS1 );
Arducam myCAM2( CS2 );
Arducam myCAM3( CS3 );
Arducam myCAM4( CS4 );

ArducamLink myUart;
uint8_t temp = 0xff;
uint8_t sendFlag = TRUE;
uint8_t commandBuff[20] = {0};
uint8_t commandLength = 0;
uint32_t readImageLength = 0;
uint8_t jpegHeadFlag = 0;





void setup() {
  myUart.arducamUartBegin(921600);
  myCAM1.begin();
  myCAM2.begin();
  myCAM3.begin();
  myCAM4.begin();
}

 void loop() {
  if (myUart.arducamUartAvailable())
  {
    temp = myUart.arducamUartRead();
    arducamDelayMs(5);
    if (temp == 0x55)
    {
      while (myUart.arducamUartAvailable())
      {
        commandBuff[commandLength] = myUart.arducamUartRead();
        if (commandBuff[commandLength] == 0xAA)
        { 
          break;
        }
        commandLength++;
      }    
      myUart.arducamFlush();
      if (commandBuff[0] == SET_VIDEO_RESOLUTION)   //video mode
      {
        
        commandLength = 0;
        while(1)
        {
          if(myUart.arducamUartAvailable())
          {
            temp = myUart.arducamUartRead();
            arducamDelayMs(1);
            if (temp == 0x55)
            {
              while (myUart.arducamUartAvailable())
              {
                commandBuff[commandLength] = myUart.arducamUartRead();
                if (commandBuff[commandLength] == 0xAA)
                {
                  break;
                }
                commandLength++;
              }
              if(commandBuff[0]==0x21)
              {
                myUart.arducamUartWrite(0x55);
                myUart.arducamUartWrite(0xBB);
                break;
              }
              commandLength=0;
            }
          }
          myUart.uartCommandProcessing(&myCAM1,commandBuff); 
          myUart.uartCommandProcessing(&myCAM2,commandBuff); 
          myUart.uartCommandProcessing(&myCAM3,commandBuff);  
          myUart.uartCommandProcessing(&myCAM4,commandBuff);            
        }
      }
      else
      {
        myUart.uartCommandProcessing(&myCAM1,commandBuff); 
        myUart.uartCommandProcessing(&myCAM2,commandBuff); 
        myUart.uartCommandProcessing(&myCAM3,commandBuff);  
        myUart.uartCommandProcessing(&myCAM4,commandBuff);  
        commandLength = 0;
      }

   }    
  }
}