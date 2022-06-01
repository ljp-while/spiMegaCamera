esp-idf
==================

.. note::
    This tutorial is based on windows system

Get Started
*************
Refer to official documentation:

https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/

ESP32-C3 
**********

Hardware connection
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
==========   =========================  
Camera pin   Development board pins    
==========   ========================= 
VCC          3V3
GND          GND
SCK          4
MISO         5
MOSI         6
CS           1
==========   ========================= 


Compile and download
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Select board example
^^^^^^^^^^^^^^^^^^^^^

.. image:: /_static/images/esp-idf/selectESP32-C3.png


Configure
^^^^^^^^^^^^^^^^^^^^^

idf.py set-target esp32c3

.. image:: /_static/images/esp-idf/esp32-c3SetTarget.png


Build the Project
^^^^^^^^^^^^^^^^^^^^^
idf.py build

.. image:: /_static/images/esp-idf/esp32-c3Build.png


View the port number
^^^^^^^^^^^^^^^^^^^^^

.. image:: /_static/images/esp-idf/windowsCOMx.png


Flash onto the Device
^^^^^^^^^^^^^^^^^^^^^

idf.py -p COM38 flash

.. image:: /_static/images/esp-idf/esp32-cdDownload.png


Effect demonstration
^^^^^^^^^^^^^^^^^^^^^

.. image:: /_static/images/GUI/image.bmp

ESP32-S 
**********

Hardware connection
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
==========   =========================  
Camera pin   Development board pins    
==========   ========================= 
VCC          3V3
GND          GND
SCK          18
MISO         19
MOSI         23
CS           22
==========   ========================= 


Compile and download
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


Select board example
^^^^^^^^^^^^^^^^^^^^^

.. image:: /_static/images/esp-idf/selectESP32-S.png


Configure
^^^^^^^^^^^^^^^^^^^^^

idf.py set-target esp32

.. image:: /_static/images/esp-idf/esp32-sSetTarget.png


Build the Project
^^^^^^^^^^^^^^^^^^^^^
idf.py build

.. image:: /_static/images/esp-idf/esp32-sBuild.png


View the port number
^^^^^^^^^^^^^^^^^^^^^

.. image:: /_static/images/esp-idf/esp32-sComx.png


Flash onto the Device
^^^^^^^^^^^^^^^^^^^^^

idf.py -p COM39 flash

.. image:: /_static/images/esp-idf/esp32-sDownload.png


Effect demonstration
^^^^^^^^^^^^^^^^^^^^^

.. image:: /_static/images/GUI/image.bmp