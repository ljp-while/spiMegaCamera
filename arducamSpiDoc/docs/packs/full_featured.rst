

.. note::
    This demo is based on the Arduino UNO development board

setup()
************************
.. code-block:: bash

    myUart.arducamUartBegin(921600);
    myCAM.begin();
    myCAM.takePicture(CAM_IMAGE_MODE_WQXGA2,CAM_IMAGE_PIX_FMT_JPG);
    myCAM.registerCallBack(readBuffer,200);

Initialize serial communication
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Initialize serial communication, used for communication of Arducam Mega software.

Initialize the camera
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Use the begin() function to initialize the camera configuration.After this function runs, the camera will be configured as JPEG data format and the resolution will be the maximum.

- Function prototype:

.. code-block:: bash

    CamStatus begin(ArducamCamera* camera);

take a photo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Start a snapshot with specified resolution and pixel format.After this function runs,the camera will take a picture.Then you can call the readByte() or readBuff() function to get the image data.

- Function prototype:

.. code-block:: bash

    CamStatus takePicture(ArducamCamera*camera, CAM_IMAGE_MODE mode, CAM_IMAGE_PIX_FMT pixel_format);


Register callback function
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Register the callback function. This function will be called in streaming mode.

- Function prototype:

.. code-block:: bash

    void registerCallback(ArducamCamera* camera, BUFFER_CALLBACK function, uint8_t blockSize);

.. warning::

    Transmission length should be less than 255



loop()
************************


Serial data receiving
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: bash

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
            myUart.uartCommandProcessing(&(myCAM.cameraInfo),commandBuff,commandLength);
            commandLength = 0;
        }    
    }

First judge whether there is data in the serial port buffer area.  When there is data in the serial port buffer area, it will judge whether the first byte is 0X55 (0X55 is the header of the protocol).  When the first byte is 0X55, the data in the serial port buffer will be read, and will not exit until it receives 0XAA (0XAA is the end of the protocol).  Then the uartCommandProcessing() function will be called to parse the protocol and execute the commands corresponding to the protocol.


Protocol analysis
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: bash

    uint8_t ArducamLink::uartCommandProcessing(ArducamCamera*camera,uint8_t* buff,uint8_t length)
    {
        CamStatus state;
        uint16_t gainValue = 0;
        uint32_t exposureValue = 0;
        uint32_t exposureLen1 = 0;
        uint32_t exposureLen2 = 0;
        uint32_t exposureLen3 = 0;
        uint8_t cameraResolution = camera->currentpictureMode;
        uint8_t cameraFarmat = camera->currentPixelFormat; 
        switch (buff[0])
        {
            case SET_PICTURE_RESOLUTION:																//Set Camera Resolution
                    cameraResolution = buff[1] & 0x0f;
                    cameraFarmat = (buff[1] & 0x70) >> 4;
                    takePicture(camera,(CAM_IMAGE_MODE)cameraResolution,(CAM_IMAGE_PIX_FMT)cameraFarmat);
                break;
            case SET_VIDEO_RESOLUTION:																//Set Video Resolution
                    cameraResolution = buff[1] & 0x0f;
                    state = startPreview(camera,(CAM_VIDEO_MODE)cameraResolution);
                    if (state == CAM_ERR_NO_CALLBACK)
                    {
    					Serial.println("callback function is not registered");
                    }    
                break;
            case SET_BRIGHTNESS:																//Set brightness
                    setBrightness(camera,(CAM_BRIGHTNESS_LEVEL)buff[1]);
                break;
            case SET_CONTRAST:																//Set Contrast
                    setContrast(camera,(CAM_CONTRAST_LEVEL)buff[1]);
                break;
        ..............


Host communication protocol reference: :ref:`Communication protocol block diagram <Communication protocol block diagram>`



