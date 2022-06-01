
flow chart
****************

.. image:: /_static/images/flowChart/streamingMode.jpg


Function usage
****************

startPreview()
~~~~~~~~~~~~~~

- Function prototype:

.. code-block:: bash

    CamStatus startPreview(ArducamCamera*camera, CAM_VIDEO_MODE mode);

The function of this function is: Start preview with specified resolution mode.The default image pixel format is JPEG.Then process the image data in the callback function.

.. warning::

    Before calling this function, you need to register the callback function.

registerCallback()
~~~~~~~~~~~~~~~~~~~~~~~~~~

- Function prototype:

.. code-block:: bash

    void registerCallback(ArducamCamera* camera, BUFFER_CALLBACK function, uint8_t blockSize);

The function of this function is: Create callback function.

.. warning::

    Transmission length should be less than 255


stopPreview()
~~~~~~~~~~~~~~~~~~~~~~~~~~

- Function prototype:

.. code-block:: bash

    CamStatus stopPreview(ArducamCamera*camera);

The function of this function is: Stop preview

