# Coliseum

Hemispherical display to deliver simultaneous auditory and visual stimuli to head-fixed rodents. The device is composed by 15 slices.

<img width="853" alt="Figure 1" src="https://github.com/user-attachments/assets/5e13eda8-5b27-4b1d-b7ce-738c7788625b" />

The device is designed to receive messages sent from the computer serial port, each message will contain digital information for each slide, basically which LED and which speaker goes into "ON state".

The audio signal is continuously generated from the PC and sent to all speakers but only the speakers set to ON will play the auditory signals.


![working principle](https://github.com/FrancisCrickInstitute/Coliseum/assets/54901317/580bf657-3111-4d14-9ac8-2dc616aaf392)

## Bill of materials

## Ordering the PCBs

First you need to create a customer account with [JLCPCB](https://jlcpcb.com/).

Then drag the gerber file from the [slice manufacturing files folder](https://github.com/FrancisCrickInstitute/Coliseum/tree/main/Hardware/Manufacturing%20files/Slice%20PCB) into the instant quote file upload window.

Then select ***PCB quantity 15, PCB thickness 0.8 and color black.***

![PCB order 1](https://github.com/FrancisCrickInstitute/Coliseum/assets/54901317/d6c14ac0-027b-4585-8490-87adf9e373ce)

Select PCB assembly and leave the selection of the top side for the assembly of the LEDs. Then select next.

![PCB order 2](https://github.com/FrancisCrickInstitute/Coliseum/assets/54901317/9c14a00e-6958-44ab-9188-1e450e4f6c3e)

Select next on the following step.

![PCB order 3](https://github.com/FrancisCrickInstitute/Coliseum/assets/54901317/d79734c7-4d62-465b-a705-59eb644f83cc)

After that wou are asked to upload the [BOM and Pick and Place files](https://github.com/FrancisCrickInstitute/Coliseum/tree/main/Hardware/Manufacturing%20files/Slice%20PCB) then click on next.

![PCB order 4](https://github.com/FrancisCrickInstitute/Coliseum/assets/54901317/9d078628-4f92-4f64-885a-fcf27b9654a4)

On the following step you can select which components from the bill of materials you uploaded you want to be asembled on the board, when we ordered them there was no stock of the header, if there is, please ***unselect H1. Just leave selected the LEDs, coloured in red on the caption.***

![PCB order 5](https://github.com/FrancisCrickInstitute/Coliseum/assets/54901317/21cec4ab-8a98-430d-bd16-e5f1e9c4e825)

After clicking on next you will get a message informing that your project has unselected parts, just click on ***"do not place"*** option.

![PCB order 6](https://github.com/FrancisCrickInstitute/Coliseum/assets/54901317/bbc6bc41-0793-4d4d-b6d3-cf2f28442b22)

On the render you ***should not see any part on top of the bottom header H1***, if you zoom in you will be able to see the LEDs in place where they will be once you receive the PCBs. Then you can click next.

![PCB order 7](https://github.com/FrancisCrickInstitute/Coliseum/assets/54901317/4483b402-4b44-41ec-b429-81b106c662fb)

On the last window you can just save the order for further payment.

![PCB order 8](https://github.com/FrancisCrickInstitute/Coliseum/assets/54901317/7de902a3-e47c-49a5-b114-ce16618a91f4)

The same steps have to be repeated for the [control board](https://github.com/FrancisCrickInstitute/Coliseum/tree/main/Hardware/Manufacturing%20files/Control%20PCB/V7) manufacturing files, in that case ***the colour does not mater and can be the default greeen as well as the PCB thickness which can be the standard 1.6 mm***, the number of units is still 15.

## Assembly instructions

### Slice assembly

1- Laser cut the 15 slices acrylic structure. The ai. file "4 Slices Laser cutting file" contained in [the laser cut files folder](https://github.com/FrancisCrickInstitute/Coliseum/tree/main/Hardware/Manufacturing%20files/Laser%20cut) has the 5 mm acrylic PMMA components needed for the main structure. Our file has been generated for a 600 mm x 300 mm laser cutter bed.

![4 Slices (Laser cutting file)](https://github.com/FrancisCrickInstitute/Coliseum/assets/54901317/3352068d-05cf-4662-94ac-4913dfff4e9c)

Then both components of the acrylic structure are glued together, in our case we appyed the [Dymax UV curing glue](https://dymax.com/products/equipment/light-curing-equipment/spot-curing-systems) in the intersection of both parts, this step has to be repeated for each slide.

![acrylic](https://github.com/FrancisCrickInstitute/Coliseum/assets/54901317/88d47f31-b34d-4354-9f91-70372f838cc3)

The third component is the spacer which needs to be cut using 2 mm thick acrylic. You are going to need 150 spacers, a couple for each speaker. They will create the minimum space needed between the speaker membrane and the PCB avoiding the transfer of sound vibrations.

![spacer](https://github.com/FrancisCrickInstitute/Coliseum/assets/54901317/ce95a78d-cf19-4f7b-b7b1-793058ea76b0)

Each of the [speakers](https://www.digikey.co.uk/en/products/detail/visaton-gmbh-co-kg/K-28-WPC-BL-8-OHM/9842354) is attached with the PCB using 2 spacers, [2 M3 x 12 mm screws](https://www.amazon.co.uk/gp/product/B09Q5YYVQ2/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1) and two [M3 nuts](https://www.amazon.co.uk/TERF-Hexagon-Steel-Full-Nuts/dp/B09MDJHJTB/ref=sr_1_6?crid=2JZVZ1J4DZOUH&keywords=M3%2Bnuts&qid=1693322964&sprefix=m3%2Bnuts%2Caps%2C63&sr=8-6&th=1). Then all the Speakers are soldered using single core wire. The wire is cut at approximately 15 mm lengh and both sides stripped with a cable stripping tool.

![figures](https://github.com/FrancisCrickInstitute/Coliseum/assets/54901317/ffcc94fa-3611-4754-89d1-68ef4f58410e)

The assembly of each slice PCB with its structure is done by using five M3 x 16 mm screws and five M3 nuts:

![Assembly](https://github.com/FrancisCrickInstitute/Coliseum/assets/54901317/c5cb132b-21e4-44d3-a3ef-b67c05428bb9)

Once the slice is assembled, the last step is to bent the pins of the [8x2 female header](https://uk.farnell.com/samtec/esq-108-14-g-d/connector-rcpt-16pos-2row-2-54mm/dp/2779427) approximately 30 degrees using a ruler and solder the header into the back side of the PCB.

![Slice assembly](https://github.com/FrancisCrickInstitute/Coliseum/assets/54901317/1a1e5738-ec03-45c5-8eee-9a587f0e3c97)

Once you have repeated the process for all 15 slices you get this.

![Coliseum assembled](https://github.com/FrancisCrickInstitute/Coliseum/assets/54901317/555fda5b-7464-4c15-8a61-a05b114b1dbb)


### Control board assembly

If all components are in stock on [JLCPCB](https://jlcpcb.com/) the boards should arrive fully assembled and the only assembly step is the connection between its 90 degree connector and the slice connector.

![Coliseum board](https://github.com/FrancisCrickInstitute/Coliseum/assets/54901317/dafbde8f-4fe9-458e-9f38-b50ef9ffa261)


### If there is no stock of LEDs in JLCBPCB and you need to solder them my hand

The LEDs can be ordered to [RS components](https://uk.rs-online.com/web/p/leds/6541800).

You will have to check the polarity of each LED using a multimiter in the diode position. The position of the black and red probes will indicate the right polarity of the LED.

![LED assembly 1](https://github.com/FrancisCrickInstitute/Coliseum/assets/54901317/01699e7a-f501-4e25-85c2-5775a5fa2ad3)

Twezzers are needed in order to solder the LEDs, The technique we used was add solder in one pad, then place the LED with the twezzers in contact with that pad while soldering the side where the solder was added. Once the LED is held in position the other pad of the LED can be soldered.

![LED assembly 2](https://github.com/FrancisCrickInstitute/Coliseum/assets/54901317/6243549b-15f5-48e1-8e4c-bce6db7a615f)

Then the polarity can be tested bt probing between the LED pin and GND pin.

![LED assembly 3](https://github.com/FrancisCrickInstitute/Coliseum/assets/54901317/f0615555-74a9-4ec4-aa4a-e229608e2ac3)


