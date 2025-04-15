# SLS-M5Dial-Templates
A collection of basic templates showing the use of an M5 Stack Dial with Square Line Studio to Create UI's

### SLS-M5-Template-Master
This is the most Basic Template.

It Consists of a single screen UI on the M5Dial that has two buttons that call 2 sepearte functions.
+ Function 1 (SLS_Function_1) Blinks an LED on M5Dial Grove PortB GPIO-1
+ Function 2 (SLS_Function_2) Blinks an LED on M5Dial Grove PortB GPIO-2

### SLS-M5-Template-v1.0
This template builds on "SLS-M5-Template-Master".

It again consists of a single screen UI on the M5Dial that has two buttons that call 2 separate functions.
The 2 leds are replaced by an M5Stack Unit 8Encoder connected to Grove Port A, using I2C.
<https://docs.m5stack.com/en/unit/8Encoder>
+ Function 1 (SLS_Function_1) sets all 8 RGB Leds on the Unit 8Encoder Green & also gets the switch state
+ Function 2 (SLS_Function_2) sets all 8 RGB Leds on the Unit 8Encoder Blue & also gets the switch state


### To-Do
- [ ] Confirm I2C implementation used in "SLS-M5-Template-v1.0"
- [ ] TBC
- [ ] TBC
- [ ] TBC
- [ ] TBC
- [ ] TBC
