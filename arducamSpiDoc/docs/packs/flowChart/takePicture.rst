
Flow chart
****************

.. image:: /_static/images/flowChart/takePicture.jpg

Function usage
****************

takePicture()
~~~~~~~~~~~~~~

- Function prototype:

.. code-block:: bash

    CamStatus takePicture(ArducamCamera*camera, CAM_IMAGE_MODE mode, CAM_IMAGE_PIX_FMT pixel_format);

Start a snapshot with specified resolution and pixel format.After this function runs,the camera will take a picture.Then you can call the readByte() or readBuff() function to get the image data.



readByte()
~~~~~~~~~~~~~~

- Function prototype:

.. code-block:: bash

    uint8_t readByte(ArducamCamera*camera);

The function of this function is: Read a byte from FIFO.


readBuff()
~~~~~~~~~~~~~~

- Function prototype:

.. code-block:: bash

    uint8_t readBuff(ArducamCamera*camera, uint8_t* buff, uint8_t length);

The function of this function is: Read image data with specified length to buffer.


.. warning::

    Transmission length should be less than 255.