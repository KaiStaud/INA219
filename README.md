# INA219
Full implemented C++ Library for communicating between MCU and ADC using I2C.
The library uses ST's HAL Layer; the Bus Access functions are abstracted in its functions.
If other vendors MCUs are used, the HAL functions and i2c handles need to replaced with corresponding functions.
For reading the Shunt Current in mA/A, the User needs the Configuration Register beforehand as mentioned in TIs 
Device Dataheet.

A full example of using the Amplifier with an 12V Supply Voltage and 100 mOHm Shunt Resistor is supplied by main.cpp.
