## Fipsy FPGA Breakout Board 

#### FPGA stands for: Field Programmable Gate Array. 
It's a pretty cool technology that is very versatile. What you have is the https://www.mocomakers.com/fipsy-fpga </br>
Unlike the microcontrollers you have been using for labs an FPGA is an integrated circuit (IC) that (could) contain millions of logic gates that can be configured to perform a certain task. They are also reprogrammable so if you need your IC to perform a different task just connect your FPGA again and program it to do something else! 
### Setup
The assumption is that you have completed all the setup/bootstrapping of your microcontrollers.

If you are using a raspberry pi this link to the Moco Makers documentation works beautifully: </br>
https://www.mocomakers.com/basic-setup-of-the-fipsy-fpga </br>

If you want to use an Arduino Moco Makers also have some documentation but the code has some issues: </br>
https://www.mocomakers.com/wiki/arduino-programmer-for-fipsy

If you are using the Raspberry Pi I recommend using the remote desktop that you set up in the bootstrapping of your microcontrollers. As far as transferring files from your computer to the pi it's really up to you, there are a lot of easy/good ways to do it. I personally used SCP from the command line and it has always worked for me.

The basic idea behind all of this is that you are using Lattice Diamond to create a .jed from some Verilog files. You then need to get this .jed file onto your raspberry pi and use the fispy fpga loader tool to flash your board.

### Projects

#### Making The FPGA Into An Arduino
Unfortunately, I ran into a lot of dead ends when attempting this project. </br>
Upon discussion with Dr. J about all these hurdles and looking into various resources/reaching out to people he told me "In short, it makes sense to program an fpga to replace the serial port chip on the Arduino board, but not a lot more". It seems like the Fipsy FPGA Breakout Board was never meant to become the powerful Arduino it dreamed of :(

However, if someone in the future wants to take this back up, I will include all the links and resources I went through to make your life easier and hopefully get something working one day:
https://www.joelw.id.au/FPGA/CheapFPGADevelopmentBoards  </br>
http://www.nxlab.fer.hr/fpgarduino
https://www.mocomakers.com/wiki/external-resources/


#### Basic Blink
Open up Lattice Dimaond </br>
File -> Open -> Project </br>
Open up the Fipsy-FPGA-edu files you downloaded and navigate to the examples sections </br>
In my case the path looked like this:
```
E:\fpga\Fipsy-FPGA-edu-master\Examples
```
Find and enter the "1.Blinky" example and open the "project_files" folder. </br>
You should then be able to open the "FipsyBaseline.ldf" file and you should see all the project files load up in Lattice

The files are all written in Verilog which is a Hardware Description Language. It's not a programming language rather it is just descriptions of how your hardware should work. 

Navigate to "Fipsy_Top.V". Here is where you will see all the pins defined and whether or not they are going to be used for input/output. As you create your own projects you will modify this file to suit your needs.

Navigate to "FreqDiv20Bit.v" within the Sources/AppModules. Here you see a 20-Bit counter that is being updated on every positive edge of the clock (@posedge CLOCK). After the counter is created the Verilog code selects the 19th bit of this counter as output for the onboard LED. This is done to slow done the blink rate. Here is a good link to visualize this logic if you don't understand: https://www.usdebtclock.org/world-debt-clock.html. If we select a bit that is closer to the MSB (most significant bit/higher order) then the blink rate is going to be slow (it takes longer for the bigger number to change vs. the smaller number). If select a bit that is closer to the LSB (least significant bit/lower order) then the blink rate is going to speed up.

Flash your FPGA board (as described in the setup section). </br>
Try to increase the blink rate until you can no longer see the onboard LED flash. Because this is binary you are going to see the blink rate change in powers of 2!</br>

### 1 Bit ADC
Open up Lattice Dimaond </br>
File -> Open -> Project </br>
Open up the Fipsy-FPGA-edu files you downloaded and navigate to the examples sections </br>
In my case the path looked like this:
```
E:\fpga\Fipsy-FPGA-edu-master\Examples
```
Find and enter the "2.Blinky2HZ" example and open the "project_files" folder. </br>
You should then be able to open the "FipsyBaseline.ldf" file and you should see all the project files load up in Lattice

Let’s wire up a potentiometer to create a 1 bit adc. </br>
First let’s change set a few of our pins to some desired values (see below) and wire power to pin 13, ground to pin 16, and the signal wire to pin 14:</br>
<img src="https://github.com/rickr04/Phys231Projects/blob/main/FPGA/Images/PinsFPGA.PNG" alt="drawing" width="400"/> </br>
Let's also change the condition where our LED lights up (ANDing with the signal pin of our potentiometer)
<img src="https://github.com/rickr04/Phys231Projects/blob/main/FPGA/Images/LEDWIREUP.PNG" alt="drawing" width="400"/> </br>

Flash your FPGA board and when you turn your pot enough your will see the LED start to blink, go the other way and the LED will stop.



#### UART Core Lab 12
Open up Lattice Dimaond </br>
File -> Open -> Project </br>
Open up the Fipsy-FPGA-edu files you downloaded and navigate to the examples sections </br>
In my case the path looked like this:
```
E:\fpga\Fipsy-FPGA-edu-master\Examples
```
Find and enter the "4.SendaString" example and open the "project_files" folder. </br>
You should then be able to open the "FipsyBaseline.ldf" file and you should see all the project files load up in Lattice

This project is similar to core lab 12 except we will only be sending data 1 way.
The Fipsy FPGA Breakout Board is a 3.3 volt device so you should be using your Arduino Nano 33 BLE (don't use other devies that are not voltage compatable!)

Navigate to the "send_string.v" file. This is your top level file and is where all your pin definitions are.

Navigate to the "txstr.v" file. This is the file where the string you want to send is defined. Change the BAUDRATE to ``` `B9600``` from the 115200 it was at. 

Open up and upload the Arduino Nano 33 sketch from core lab 12 (should just work as it). 
Now wire up the tx from the FPGA (defined as pin 8) to (whatever pin you decided was rx in the lab) and connect grounds (any pin that is set low on the FPGA works fine as a ground, use one of the two grounds predefined on the nano).

Flash your FPGA and then open up the serial monitor on the Arduino IDE. You should see the string you defined in "txtstr.v" being transmitted!
