## Fipsy FPGA Breakout Board 

#### FPGA stands for: Field Programmable Gate Array. 
It's a pretty cool technology that is very versatile. What you have is the https://www.mocomakers.com/fipsy-fpga </br>
Unlike the microcontrollers you have been using for labs an FPGA is an integrated circuit (IC) that (could) contain millions of logic gates that can be configured to perform a certain task. They are also reprogrammable so if you need your IC to perform a different task just connect your FPGA again and program it to do something else! 
### Setup
The assumption is that you have completed all the setup/bootstraping of your microcontrollers.

If you are using a raspberry pi this link to the Moco Makers documentation works beautifully: </br>
https://www.mocomakers.com/basic-setup-of-the-fipsy-fpga </br>

If you want to use an Arduino Moco Makers also have some documentation but the code has some issues: </br>
https://www.mocomakers.com/wiki/arduino-programmer-for-fipsy

### Projects

#### Making The FPGA Into An Arduino
Unfortunately I ran into a lot of deadends when attempting this project. </br>
Upon disscusion with Dr. J about all these hurdles and looking into various resources/reaching out to people he told me "In short, it makes sense to program an fpga to replace the serial port chip on the Arduino board, but not a lot more". It seems like the Fipsy FPGA Breakout Board was never meant to become the powerful Arduino it dreamed of :(

However if someone in the future wants to take this back up I will include all the links and resources I went through to make your life easier and hopefully get something working one day:
https://www.joelw.id.au/FPGA/CheapFPGADevelopmentBoards  </br>
http://www.nxlab.fer.hr/fpgarduino
https://www.mocomakers.com/wiki/external-resources/


#### Basic Blink

#### UART 
