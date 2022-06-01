/* Copyright 2021 Arducam Technology co., Ltd. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/


#ifndef __SMARTSPICAM_H
#define __SMARTSPICAM_H
#include "Arducam.h"

/**
* @file Arducam.h
* @author Arducam
* @date 2021/12/6
* @version V1.0
* @copyright Arducam
*/

class Arducam
{
private:

    /**
    * @ref ArducamCamera
    * @brief Camera drive interface and information
    */
    ArducamCamera  cameraInfo;


public:


    Arducam(int cs);
    //**********************************************
    //!
    //! @brief Initialize the configuration of the camera module
    //! @return Return operation status 
    //**********************************************

    CamStatus begin(void);
    
    //**********************************************
    //!
    //! @brief Start a snapshot with specified resolution and pixel format
    //!
    //! @param mode Resolution of the camera module
    //! @param pixel_format Output image pixel format,which supports JPEG, RGB, YUV 
    //!
    //! @return Return operation status 
    //!			
    //! @note The mode parameter must be the resolution which the current camera supported
    //**********************************************
    CamStatus takePicture(CAM_IMAGE_MODE mode, CAM_IMAGE_PIX_FMT pixel_format) ;

    //**********************************************
    //!
    //! @brief Start multi capture with specified number of image. 
    //!
    //! @param mode Resolution of the camera module
    //! @param pixel_format Output image pixel format,which supports JPEG, RGB, YUV 
    //! @param number Number of pictures taken
    //!
    //! @return Return operation status 
    //!			
    //!
    //! @note The mode parameter must be the resolution which the current camera supported
    //**********************************************
    CamStatus takeMultiPictures(CAM_IMAGE_MODE mode, CAM_IMAGE_PIX_FMT pixel_format, uint8_t number);

    //**********************************************
    //!
    //! @brief Start preview with specified resolution mode.
    //!
    //! @param mode Resolution of the camera module
    //!
    //! @return Return operation status 
    //!			
    //! @note Before calling this function, you need to register the callback function.The default image pixel format is JPEG
//**********************************************
    CamStatus startPreview(CAM_VIDEO_MODE mode);

    //**********************************************
    //!
    //! @brief Stop preview
    //!
    //! @return Return operation status 
    //!			
    //**********************************************
    CamStatus stopPreview(void);
    //**********************************************
    //!
    //! @brief Set the exposure mode
    //!
    //! @param   val `0` Turn on automatic exposure `1` Turn off automatic exposure
    //!
    //! @return Return operation status 
    //!			
    //**********************************************
    CamStatus setAutoExposure(uint8_t val);
    //**********************************************
    //!
    //! @brief Set the exposure time Manually
    //!
    //! @param   val Value of exposure line
    //!
    //! @return Return operation status 
    //!			
    //! @note Before calling this function, you need to turn off the auto exposure function
    //**********************************************
    CamStatus setAbsoluteExposure(uint32_t val);
    //**********************************************
    //!
    //! @brief Set the gain mode
    //!
    //! @param   val `0` turn on automatic gain `1` turn off automatic gain
    //!
    //! @return Return operation status 
    //!			
    //**********************************************
    CamStatus setAutoISOSensitive(uint8_t val);
    //**********************************************
    //!
    //! @brief Set the exposure time Manually
    //!
    //! @param  val Value of gain 
    //!
    //! @return Return operation status 
    //!			
    //! @note Before calling this function, you need to turn off the auto gain function
    //**********************************************
    CamStatus setISOSensitivity(int val);
    //**********************************************
    //!
    //! @brief Set white balance mode
    //!
    //! @param  val `0` turn on automatic white balance `1` turn off automatic white balance
    //!
    //! @return Return operation status 
    //!			
    //**********************************************
    CamStatus setAutoWhiteBalance(uint8_t val);
    //**********************************************
    //!
    //! @brief  Set the white balance mode Manually
    //!
    //! @param   mode White balance mode
    //!
    //! @return Return operation status 
    //!			
    //**********************************************
    CamStatus setAutoWhiteBalanceMode(CAM_WHITE_BALANCE mode);
    //**********************************************
    //!
    //! @brief Set special effects
    //!
    //! @param  effect Special effects mode
    //!
    //! @return Return operation status 
    //!			
    //**********************************************
    CamStatus setColorEffect(CAM_COLOR_FX effect);
    //**********************************************
    //!
    //! @brief Set auto focus mode
    //!
    //! @param  val mode of autofocus
    //!
    //! @return Return operation status 	
    //!
    //! @note Only `5MP` cameras support auto focus control
    //**********************************************
    CamStatus setAutoFocus(uint8_t val);
    //**********************************************
    //!
    //! @brief Set saturation level
    //!
    //! @param   level Saturation level
    //!
    //! @return Return operation status 
    //!			
    //**********************************************
    CamStatus setSaturation(CAM_STAURATION_LEVEL level);
    //**********************************************
    //!
    //! @brief Set EV level
    //!
    //! @param  level EV level
    //!
    //! @return Return operation status 
    //!			
    //**********************************************
    CamStatus setEV(CAM_EV_LEVEL level);
    //**********************************************
    //!
    //! @brief Set Contrast level
    //!
    //! @param  level Contrast level
    //!
    //! @return Return operation status 
    //!			
    //**********************************************
    CamStatus setContrast(CAM_CONTRAST_LEVEL level);
    //**********************************************
    //!
    //! @brief Set Brightness level
    //!
    //! @param  level Brightness level
    //!
    //! @return Return operation status 
    //!			
    //**********************************************
    CamStatus setBrightness(CAM_BRIGHTNESS_LEVEL level);
    //**********************************************
    //!
    //! @brief Set Sharpness level
    //!
    //! @param  level Sharpness level
    //!
    //! @return Return operation status 
    //!			
    //! @note Only `3MP` cameras support sharpness control
    //**********************************************
    CamStatus setSharpness(CAM_SHARPNESS_LEVEL level);
    //**********************************************
    //!
    //! @brief Read image data with specified length to buffer 
    //!
    //! @param  buff Buffer for storing camera data
    //! @param  length The length of the available data to be read
    //!
    //! @return Returns the length actually read
    //!
    //! @note Transmission length should be less than `255`
    //**********************************************
    uint8_t readBuff(uint8_t*,uint8_t);
    //**********************************************
    //!
    //! @brief Read a byte from FIFO
    //!
    //! @return Returns Camera data
    //!
    //! @note Before calling this function, make sure that the data is available in the buffer
    //**********************************************
    uint8_t readByte(void);
    //**********************************************
    //!
    //! @brief Debug mode
    //!
    //! @param  buff There are four bytes of buff Byte 1 indicates the device address, Byte 2 indicates the high octet of the register, Byte 3 indicates the low octet of the register, and Byte 4 indicates the value written to the register
    //!
    //**********************************************
    void debugWriteRegister(uint8_t*);
    //**********************************************
    //!
    //! @brief Create callback function
    //!
    //! @param  function Callback function name
    //! @param  blockSize The length of the data transmitted by the callback function at one time
    //!
    //! @note Transmission length should be less than `255`
    //**********************************************
    void registerCallBack(BUFFER_CALLBACK,uint8_t);

    //**********************************************
    //!
    //! @brief Turn on low power mode
    //!
    //**********************************************
    void lowPowerOn(void);

    //**********************************************
    //!
    //! @brief Turn off low power mode
    //!
    //**********************************************
    void lowPowerOff(void);



    //**********************************************
    //!
    //! @brief Get the length of the picture
    //!
    //! @return Return the length of the picture
    //**********************************************
    uint32_t getTotalLength(void);

    //**********************************************
    //!
    //! @brief Get the length of the unread image
    //!
    //! @return Returns the length of the unread image
    //**********************************************
    uint32_t getReceivedLength(void);

    //**********************************************
    //!
    //! @brief return a camera instance
    //!
    //! @return Return a ArducamCamera instance
    //**********************************************
    ArducamCamera* getCameraInstance(void);
};





#endif /*__SMARTSPICAM_H*/