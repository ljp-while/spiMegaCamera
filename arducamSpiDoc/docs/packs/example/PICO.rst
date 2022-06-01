Raspberry Pi Pico
========================
.. note::
    This demo is based on a 5MP camera

Hardware connection
*********************

==========   =========================  
Camera pin   Development board pins    
==========   ========================= 
VCC          3V3
GND          GND
SCK          GP2
MISO         GP4
MOSI         GP3
CS           GP7
==========   ========================= 


full_featured
*********************

Select platform
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. image:: /_static/images/pico/selectPlatform.bmp


Select example
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. image:: /_static/images/pico/selectExample.bmp

Download program
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. image:: /_static/images/pico/download.bmp



Effect demonstration
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. image:: /_static/images/GUI/image.bmp


Note
*****************

The SPI pins corresponding to different versions of the library may be different.
The :ref:`Hardware connection <Hardware connection>` diagram of this document is based on version 2.6.1.
If the version of Arduino Mbed OS RP2040 Boaeds is not 2.6.1. Please connect the camera module according to the SPI pin definitions in the pins_arduino.h file.

The SPI pins corresponding to version 2.6.1 are shown in the figure below.

.. image:: /_static/images/pico/V2.6.1.bmp

.. image:: /_static/images/pico/V2.6.1_PIN.bmp

The SPI pins corresponding to version 2.7.2 are shown in the figure below.

.. image:: /_static/images/pico/V2.7.2.bmp

.. image:: /_static/images/pico/V2.7.2_PIN.bmp


