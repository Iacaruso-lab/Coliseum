# Coliseum

Hemispherical display to deliver simultaneous auditory and visual stimuli to head-fixed rodents. The device is composed by 15 slices.

<img width="853" alt="Figure 1" src="Images/Figure%201.png" />

The device is designed to receive messages sent from the computer serial port, each message will contain digital information for each slide, basically which LED and which speaker goes into "ON state".

The audio signal is continuously generated from the PC and sent to all speakers but only the speakers set to ON will play the auditory signals.


![working principle](Images/Figure%202.png)

## Bill of materials

## Ordering the PCBs

First you need to create a customer account with [JLCPCB](https://jlcpcb.com/).

Then drag the gerber file from the [slice manufacturing files folder](Hardware/Manufacturing%20files/Slice%20PCB) into the instant quote file upload window.

Then select ***PCB quantity 15, PCB thickness 0.8 and color black.***

![PCB order 1](Images/Figure%203.png)

Select PCB assembly and leave the selection of the top side for the assembly of the LEDs. Then select next.

![PCB order 2](Images/Figure%204.png)

Select next on the following step.

![PCB order 3](Images/Figure%205.png)

After that wou are asked to upload the [BOM and Pick and Place files](Hardware/Manufacturing%20files/Slice%20PCB) then click on next.

![PCB order 4](Images/Figure%206.png)

On the following step you can select which components from the bill of materials you uploaded you want to be asembled on the board, when we ordered them there was no stock of the header, if there is, please ***unselect H1. Just leave selected the LEDs, coloured in red on the caption.***

![PCB order 5](Images/Figure%207.png)

After clicking on next you will get a message informing that your project has unselected parts, just click on ***"do not place"*** option.

![PCB order 6](Images/Figure%208.png)

On the render you ***should not see any part on top of the bottom header H1***, if you zoom in you will be able to see the LEDs in place where they will be once you receive the PCBs. Then you can click next.

![PCB order 7](Images/Figure%209.png)

On the last window you can just save the order for further payment.

![PCB order 8](Images/Figure%2010.png)

The same steps have to be repeated for the [control board](Hardware/Manufacturing%20files/Control%20PCB/V7) manufacturing files, in that case ***the colour does not mater and can be the default greeen as well as the PCB thickness which can be the standard 1.6 mm***, the number of units is still 15.

## Assembly instructions

### Slice assembly

1- Laser cut the 15 slices acrylic structure. The ai. file "4 Slices Laser cutting file" contained in [the laser cut files folder](https://github.com/FrancisCrickInstitute/Coliseum/tree/main/Hardware/Manufacturing%20files/Laser%20cut) has the 5 mm acrylic PMMA components needed for the main structure. Our file has been generated for a 600 mm x 300 mm laser cutter bed.

![4 Slices (Laser cutting file)](Images/Figure%2011.png)

Then both components of the acrylic structure are glued together, in our case we appyed the [Dymax UV curing glue](https://dymax.com/products/equipment/light-curing-equipment/spot-curing-systems) in the intersection of both parts, this step has to be repeated for each slide.

![acrylic](Images/Figure%2012.png)

The third component is the spacer which needs to be cut using 2 mm thick acrylic. You are going to need 150 spacers, a couple for each speaker. They will create the minimum space needed between the speaker membrane and the PCB avoiding the transfer of sound vibrations.

![spacer](Images/Figure%2013.jpg)

Each of the [speakers](https://www.digikey.co.uk/en/products/detail/visaton-gmbh-co-kg/K-28-WPC-BL-8-OHM/9842354) is attached with the PCB using 2 spacers, [2 M3 x 12 mm screws](https://www.amazon.co.uk/gp/product/B09Q5YYVQ2/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1) and two [M3 nuts](https://www.amazon.co.uk/TERF-Hexagon-Steel-Full-Nuts/dp/B09MDJHJTB/ref=sr_1_6?crid=2JZVZ1J4DZOUH&keywords=M3%2Bnuts&qid=1693322964&sprefix=m3%2Bnuts%2Caps%2C63&sr=8-6&th=1). Then all the Speakers are soldered using single core wire. The wire is cut at approximately 15 mm lengh and both sides stripped with a cable stripping tool.

![figures](Images/Figure%2014.jpg)

The assembly of each slice PCB with its structure is done by using five M3 x 16 mm screws and five M3 nuts:

![Assembly](Images/Figure%2015.jpg)

Once the slice is assembled, the last step is to bent the pins of the [8x2 female header](https://uk.farnell.com/samtec/esq-108-14-g-d/connector-rcpt-16pos-2row-2-54mm/dp/2779427) approximately 30 degrees using a ruler and solder the header into the back side of the PCB.

![Slice assembly](Images/Figure%2016.gif)

Once you have repeated the process for all 15 slices you get this.

![Coliseum assembled](Images/Figure%2017.png)


### Control board assembly

If all components are in stock on [JLCPCB](https://jlcpcb.com/) the boards should arrive fully assembled and the only assembly step is the connection between its 90 degree connector and the slice connector.

![Coliseum board](Images/Figure%2018.png)


### If there is no stock of LEDs in JLCBPCB and you need to solder them my hand

The LEDs can be ordered to [RS components](https://uk.rs-online.com/web/p/leds/6541800).

You will have to check the polarity of each LED using a multimiter in the diode position. The position of the black and red probes will indicate the right polarity of the LED.

![LED assembly 1](Images/Figure%2019.png)

Twezzers are needed in order to solder the LEDs, The technique we used was add solder in one pad, then place the LED with the twezzers in contact with that pad while soldering the side where the solder was added. Once the LED is held in position the other pad of the LED can be soldered.

![LED assembly 2](Images/Figure%2020.png)

Then the polarity can be tested bt probing between the LED pin and GND pin.

![LED assembly 3](Images/Figure%2021.png)


