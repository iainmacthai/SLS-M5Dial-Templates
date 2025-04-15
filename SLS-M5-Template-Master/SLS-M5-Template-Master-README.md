# SLS-M5Dial-Templates
A Series Of Basic Templates for Squareline Studio UI with M5Stack Dial

## SLS-M5-Template-Master
This is the most Basic Template.

It Consists of a single screen UI on the M5Dial that has two buttons that call 2 sepearte functions.
+ Function 1 Blinks an LED on M5Dial Grove PortB GPIO-1
+ Function 2 Blinks an LED on M5Dial Grove PortB GPIO-2

******************************************************************************

## SquareLine Studio Setup (SLS Version : 1.5.1)
### Project Settings
#### PROPERTIES
| Width | Height | Depth | Rotation  | Offset X | Offset Y |Shape      |
|:------|:-------|:------|:----------|:---------|:---------|:----------|
| 240   | 240    | 16 bit | 0 degree | 0        | 0        | Circle    |

| Object naming | Custom variable prefix |
|:--------------|:-----------------------|
| Name          | uic                    |
- [ ] Force exported names to lower case
#### BOARD PROPERTIES
| Board Group | Board                    | Version | LVGL      |
|:------------|:-------------------------|:--------|:----------|
| Arduino     | Arduino with TFT_eSPI    | v1.1.3  | 8.3.11    |

Language: **C** | Res: **320 x 240** | colour: **8, 16, 16 sw, 32** | LVGL: **8.3***

#### FILE EXPORT

| Project Export Root                                                  |
|:---------------------------------------------------------------------|
| C:\your-directory\your-directory\SLS-M5-Template-Master              |

| UI Files Export Path                                                 |
|:---------------------------------------------------------------------|
| C:\your-directory\your-directory\SLS-M5-Template-Master\UI           |

| LVGL Include Path                                                    |
|:---------------------------------------------------------------------|
| Leave Blank !!                                                        |

| Multilanguage support                                                |
|:---------------------------------------------------------------------|
| Disable              |

| Call functions export file                                           |
|:---------------------------------------------------------------------|
| don't export                                                         |

| Image exports mode                                                   |
|:---------------------------------------------------------------------|
| Source code                                                          |

- [ ] Export temporary image
- [ ] Force export all images
- [x] Flat export (exports all files to one folder)

| STDIO Drive   | Root path              |
|:--------------|:-----------------------|
|               | Leave Blank !!         |

| POSIX Drive   | Root path              |
|:--------------|:-----------------------|
|               | Leave Blank !!         |

| WIN32 Drive   | Root path              |
|:--------------|:-----------------------|
|               | Leave Blank !!         |

| FATFS Drive   | Root path              |
|:--------------|:-----------------------|
|               | Leave Blank !!         |

#### PROJECT DESCRIPTION
| Description of your project   |
|:------------------------------|

******************************************************************************

## Arduino IDE Setup (IDE Version : 2.3.2)
### ESP32 Boards Manager Version By Espressif Systems : 3.1.0
| Tools           | Option                        |
| :------------   | :---------------------------- |
| Board:          | ESP32 - M5Dial                |
| Port:           | COM "n" (ESP32 Family Device) |
| Get Board Info: | BN:  ESP32 Family Device      |
|                 | VID: 0x303A                   |
|                 | PID: 0x1001                   |
|                 | SN:  (null)                   |

| Tools                                 | Option                                             |
| :------------------------------------ | :------------------------------------------------- |
| USB CDC On Boot:                      | "Enabled"                                          |
| CPU Frequency:                        | "240Mhz (WiFi)"                                    |
| Core Debug Level:                     | "None"                                             |
| USB DFU On Boot:                      | "Disabled"                                         |
| Erase All Flash Before Sketch Upload: | "Disabled"                                         |
| Events Run On:                        | "Core 1"                                           |
| Flash Mode:                           | "QIO 80Mhz"                                        |
| Flash Size:                           | "4MB (32Mb)"                                       |
| JTAG Adapter:                         | "Disabled"                                         |
| Arduino Runs On:                      | "Core 1"                                           |
| USB Firmware MSC On Boot:             | "Disabled"                                         |
| Partition Scheme:                     | "Default 4MB with spiffs (1.2MB APP/1.5MB SPIFFS)" |
| PSRAM:                                | "Disabled"                                         |
| Upload Mode:                          | "UART0 / Hardware CDC"                             |
| Upload Speed:                         | "921600"                                           |
| USB Mode:                             | "Hardware CDC and JTAG"                            |
| Programmer:                           |                                                    |
| Burn Bootloader:                      |                                                    |
******************************************************************************
## To-Do
- [ ] Download Instructions
- [ ] Repository Folder Structure
- [x] IDE Version & Configuration Settings
- [x] SLS Version & Configuration Settings
- [ ] Required Libraries & Boards Manager Versions
- [ ] LVGL Conf file
- [ ] Images
- [ ] AOB
