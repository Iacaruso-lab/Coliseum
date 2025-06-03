#include "mbed.h"
#include "SWSPI.h"

SWSPI spi(PA_7, PA_6, PA_5); // mosi, miso, sclk
DigitalOut CS(PC_4);

DigitalOut led1(PB_7);
DigitalOut led2(PB_6);
DigitalOut led3(PB_5);
DigitalOut led4(PB_4);
DigitalOut led5(PB_3);


DigitalOut spkr1(PA_10);
DigitalOut spkr2(PA_9);
DigitalOut spkr3(PA_8);
DigitalOut spkr4(PC_9);
DigitalOut spkr5(PC_8);

int intensity=0;
char read_byte,cmnd_byte,cmnd_led,cmnd_spkr, old_cmnd_led, old_cmnd_spkr,bin_led;

Serial rs485(PA_11, PA_12);
Serial pc(PA_2, PA_3);  // tx, rx

 
int main() {
    CS=1;
    spi.format(10,0);
    spi.frequency(1000000);
    
    // typical baud rates: 110, 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 38400, 57600, 115200, 230400, 460800, 921600
    pc.baud(115200);
    rs485.baud(115200); //highest wprlomg 230400
    pc.printf("Hello there! Let's rave! \n\r");

    while(1) {

     read_byte= rs485.getc();
    
        if(read_byte==0xFF){
            cmnd_byte=rs485.getc();
            cmnd_led= cmnd_byte & 0x0F;
            cmnd_spkr= cmnd_byte>>4;     
            rs485.putc(0xFF);
            //pc.printf("Initialisation byte received. Command:  0x%.2X\n\r",cmnd_byte);
            //pc.printf("SPKR %d",cmnd_spkr);
            //pc.printf("    LED: %d\n\r",cmnd_led);     
            }
        else if (read_byte==0xFE){
            cmnd_spkr= rs485.getc();
            rs485.putc(0xFE);
            //pc.printf("Led Initialisation byte received. Command:  0x%.2X\n\r",cmnd_led);
            //pc.printf("    LED: %d\n\r",cmnd_led);       
            }
        else if (read_byte==0xFD){
            cmnd_led= rs485.getc();
            rs485.putc(0xFD);
            }
        else if (read_byte==0xFA){
            intensity=rs485.getc();
            rs485.putc(0xFA);
            rs485.putc(intensity);
            CS=0;
            spi.write(0b0000000000|intensity); //only using one POT channel, otherwise also send 0b0100000000 OR intensity
            CS=1;
            //pc.printf("I just set the intensity to %d\n\r", intensity);
            }
        else if (read_byte==0xFC){
            bin_led=rs485.getc();
            rs485.putc(0xFC);
            led1=(bin_led)&0000001;
            led2=(bin_led>>1)&0000001;
            led3=(bin_led>>2)&0000001;
            led4=(bin_led>>3)&0000001;
            led5=(bin_led>>4)&0000001; 
   
            //2pc.printf("ledss:  %d %d %d %d %d\n\r", int(led5), int(led4), int(led3), int(led2), int(led1));
            }
        else {
            rs485.putc(read_byte);
            cmnd_byte=0;
            //pc.printf("another one bytes the dust! 0x%.2X\n\r",read_byte);
            }
    

        if (cmnd_led!=old_cmnd_led){  //this if case is not really needed
            old_cmnd_led=cmnd_led;
        switch(cmnd_led){
            case 1:
               led1=1;
               led2=0;
               led3=0;
               led4=0;
               led5=0; 
               break;
             case 2:
               led1=0;
               led2=1;
               led3=0;
               led4=0;
               led5=0; 
               break;
            case 3:
               led1=0;
               led2=0;
               led3=1;
               led4=0;
               led5=0; 
               break;
            case 4:
               led1=0;
               led2=0;
               led3=0;
               led4=1;
               led5=0; 
               break;
            case 5:
               led1=0;
               led2=0;
               led3=0;
               led4=0;
               led5=1; 
               break;   
            default:
               led1=0;
               led2=0;
               led3=0;
               led4=0;
               led5=0; 
               //pc.printf("wrong LED number \n\r");
               
               break;
           }    
         }
         if (cmnd_spkr!=old_cmnd_spkr){  //this if case is not really needed
             old_cmnd_spkr=cmnd_spkr;
         switch(cmnd_spkr){
            case 1:
               spkr1=1;
               spkr2=0;
               spkr3=0;
               spkr4=0;
               spkr5=0; 
               break;
             case 2:
               spkr1=0;
               spkr2=1;
               spkr3=0;
               spkr4=0;
               spkr5=0; 
               break;
            case 3:
               spkr1=0;
               spkr2=0;
               spkr3=1;
               spkr4=0;
               spkr5=0; 
               break;
            case 4:
               spkr1=0;
               spkr2=0;
               spkr3=0;
               spkr4=1;
               spkr5=0; 
               break;
            case 5:
               spkr1=0;
               spkr2=0;
               spkr3=0;
               spkr4=0;
               spkr5=1; 
               break;   
            default:
               spkr1=0;
               spkr2=0;
               spkr3=0;
               spkr4=0;
               spkr5=0; 
               //pc.printf("wrong SPEAKER number \n\r");
               
               break;
       }            
       }       

      
        
     //pc.printf("\n\r");    
        
    }
}
