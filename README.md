# Geographical Environment Module (GEM)


<img src="Images/1.jpg" width="360" />  

<img src="Images/2.jpg" width="220"/><img src="Images/3.jpg" width="189"/>

(Upper)Version 1 (Lower)Version 2


# Content
1 - About this project<br/>
2 - System Block Diagram<br/>
3 - Required Software<br/>
4 - Key Hardware Components<br/>
5 - File Structure<br/>
6 - Operation & Results<br/> 
7 - Reference Sites<br/>
8 - Todos / Improvements<br/>

# 1 - About this project
Geographical Environment Module (GEM) is a LoRaWAN-enabled environment sensing system intended for agricultural and environment protection monitoring. This repository shows a demo system, it consists of one gateway and upto twelve nodes. The goal is to capture several environmental parameters, and send them through the LoRaWAN network to a data-logging system/computer. The data can then be further analyzed by other applications.

This repository is a technical archive for a computer engineering capstone project at Univeristy of California, Santa Barbara. For general information regarding the project, please visit https://web.ece.ucsb.edu/~yoga/capstone/projects/2022/

Student Contributors:<br/>
Alejandro Diera<br/>
Larry Mai<br/>
Michael Sanchez<br/>
Sawyer Essabhoy<br/>
Yuen Ming Pang<br/>

*Special thanks to Laritech, Inc., Prof. Isukapalli, Chris Cheney, and Brycen Westgarth for thei help and guidance.<br/>

# 2 - System Block Diagram
<img src="Images/8.jpg" width="600" />
- "ESP32 Transmitter" only relays messages to attached RFM95W transceiver. This can be removed in future iterations.<br/>
- Program should be compatible with most STM32 series chips with the mentioned peripehrals with minor modifications.<br/>

# 3 - Required Software
| Name | Function |
| ------ | ------ |
| STM32CubeIDE | STM32 chip programmer and debugger |
| Arduino IDE | ESP32 module programmer |
| MATLAB2022a | Real-time data monitoring |

# 4 - Key Hardware Components
| Gateway | Function |
| ------ | ------ |
| SparkFun WRL-18074 (embedded RFM95W) | LoRaWAN gateway |

| Node | Function |
| ------ | ------ |
| STM32L072RBT6 | central processor |
| SparkFun WRL-18074 (embedded RFM95W) | LoRaWAN node |
| Adafruit PA1010D | GPS |
| Adafruit BMP180 | Barometric sensor |
| Adafruit DHT22 | Air temperature & moisture |
| Adafruit Waterproof 1-Wire DS18B20 Compatible Digital temperature sensor | Soil temperature |
| LDR | Light intensity |
| SparkFun SEN-13322 | Soil moisture |
| 5V + 3.3V supply | Power supply |

# 5 - File Structure
 | Important File | Content |
 | ------ | ------ |
 | Code_Chip | Main processor program |
 | Code_Gateway | Code for gateway w/ library |
 | Code_Node | Code for node w/ library |
 | Code_MATLAB | Real-time MATLAB plotting script |
 | PCB_V2 | Schematic and PCB |

# 6 - Operation & Results
<img src="Images/6.png" width="2000" />
- Node boot time until first message received by gateway should be within 5s.<br/>
- Demo reached a maximum range from gateway of around 40m. Improvement needed.<br/>
- Fluctuations and drifting were observed.<br/>
<br/>
<img src="Images/9.png" width="600" />
- On MATLAB, readings from multiple nodes can be displayed in real time. Each row here represents one node.<br/>

# 7 - Reference Sites
| Name | Link |
| ------ | ------ |
| STM32L072RBT6 | [STMicroelectronics][Chip] |
| SparkFun WRL-18074 | [SparkFun][LoRaWAN] |
| Adafruit PA1010D | [Adafruit][GPS] |
| Adafruit BMP180 | [Adafruit][BMP180] |
| Adafruit DHT22 | [Adafruit][DHT22] |
| Adafruit Waterproof 1-Wire DS18B20 Compatible Digital temperature sensor | [Adafruit][DS18B20] |
| SparkFun SEN-13322 | [SparkFun][Soil] |



# 8 - Todos / Improvements
- Reduce power consumption<br/>
- Replace sensors with high quality alternatives<br/>
- Remove redundant sensors<br/>
- Remove GPS and use LoRaWAN localization<br/>
- Find a LoRaWAN solution without the SparkFun gateway (e.g. direct integration with a RFM95W chip)<br/>
- Add mounting points on PCB and design a protective case<br/>


   [Chip]: <https://www.st.com/en/microcontrollers-microprocessors/stm32l072rb.html>
   [LoRaWAN]: <https://www.sparkfun.com/products/18074>
   [GPS]: <https://www.adafruit.com/product/4415>
   [BMP180]: <https://www.adafruit.com/product/1603>
   [DHT22]: <https://www.adafruit.com/product/385>
   [DS18B20]: <https://www.adafruit.com/product/381>
   [Soil]: <https://www.sparkfun.com/products/13322>
