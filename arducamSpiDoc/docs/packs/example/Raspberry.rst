Raspberry Pi
==================
.. note::
    This demo is based on a 5MP camera

Hardware connection
*********************

==========   =========================  
Camera pin   Development board pins    
==========   ========================= 
VCC          3.3V
GND          GND
SCK          SCLK
MISO         MISO
MOSI         MOSI
CS           GPIO.3
==========   ========================= 


capture
****************


Download library files
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    git clone https://github.com/ArduCAM/Arducam_Mega.git

.. image:: /_static/images/Raspberry/downloadLib.bmp


Jump to the capture folder
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    cd Arducam_Mega/examples/RaspberryPi/capture

.. image:: /_static/images/Raspberry/captureCdCmd.bmp


Compile the driver
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    make

.. image:: /_static/images/Raspberry/captureMake.bmp


Effect demonstration
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    sudo ./Arducam_Mega

.. image:: /_static/images/Raspberry/captureRun.bmp


preview
****************

Download library files
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    git clone https://github.com/ArduCAM/Arducam_Mega.git

.. image:: /_static/images/Raspberry/downloadLib.bmp

Jump to the preview folder
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    cd Arducam_Mega/examples/RaspberryPi/preview

.. image:: /_static/images/Raspberry/previewCdCmd.bmp


Compile the driver
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    make

.. image:: /_static/images/Raspberry/previewMake.bmp


Compile the driver
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    sudo ./Auducam_Mega

.. image:: /_static/images/Raspberry/previewRun.bmp