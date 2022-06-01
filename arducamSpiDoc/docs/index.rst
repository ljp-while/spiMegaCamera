.. SPICamera documentation master file, created by
   sphinx-quickstart on Wed Dec  8 10:26:16 2021.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Brief of Arducam Mega SDK
==================================

Arducam has released Arducam Mega SDK for Arducam Mega camera. The SDK is 
a C and C++ package, containing convenience classes and functions that help in most 
common tasks while using Arducam Mega API. We support both C API and C++ 
API. The SDK contains HAL layer and Arducam Mega Cam protocol layer and API.


SDK framework:


.. image:: /_static/images/sdkBrief.png




Arducam SDK library provides C API and C++ API. About API’s function, Users can get 
details from :ref:`C API Reference <C API Reference>` and :ref:`C++ API Reference <C++ API Reference>`. 
The function of the Arducam Mega Cam protocol layer is used to communicate with spi camera. 
The function of the HAL layer is used to compatible with multiple platforms. At present, the 
SDK has supported Arduino UNO/Arduino Mega2560/ ESP32 /ESP8266/STM32/MSP430/PICO/RPI platform. 
The Platform specific SPI bus driver is used to communicate with specific hardware platform. 
If users want to adapt the SDK on your own specific platform, you should modify this layer and HAL layer. 
For the details, please contact support@arducam.com for further support.



Users can refer to :ref:`Quick started <GET STARTED>` to start to use the sdk easily. SDK has provided demos on 
some platforms that SDK has supported. Referring :ref:`Example Guide<Arduino UNO>` for details.


Typical System Block:

.. image:: /_static/images/systemBlock.png





Users can refer to GUI tool to get more about how to use :ref:`Arducam Mega GUI <Welcome to Gui Tool!>`.

.. toctree::
   :maxdepth: 1
   :hidden:
   :caption: CONTENT

   Home <self>
   packs/getStarted.rst

   



.. toctree::
   :maxdepth: 1
   :hidden:
   :caption: Example Code

   packs/example/ArduinoUNO.rst
   packs/example/ArduinoMega.rst
   packs/example/ArduinoDUE.rst
   packs/example/ESP32Node.rst
   packs/example/ESP8266Node.rst
   packs/example/ESP32C3.rst
   packs/example/MSP430.rst  
   packs/example/PICO.rst
   packs/example/STM32F103C8T6.rst  
   packs/example/Raspberry.rst
   packs/example/ArduinoNano33Ble.rst
   packs/example/esp-idf.rst
   packs/example/ArduinoMicrobit.rst

.. toctree::
   :maxdepth: 1
   :hidden:
   :caption: Gui Tool

   packs/GuiTool.rst
   packs/HostCommunicationProtocol.rst

.. toctree::
   :maxdepth: 1
   :hidden:
   :caption: Api References

   packs/C_ApiDoc.rst
   packs/C++_ApiDoc.rst
   
   








