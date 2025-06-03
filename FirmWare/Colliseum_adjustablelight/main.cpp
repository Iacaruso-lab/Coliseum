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
 
float delay = 10;
char read_byte,cmnd_byte,cmnd_led,cmnd_spkr;
unsigned short  pot_cmnd;
int intensity=0;
char led_no=1;
Serial rs485(PA_11, PA_12);
Serial pc(PA_2, PA_3);  // tx, rx 
  
int main() {
    CS=1;
    spi.format(10,0);
    spi.frequency(1000000);
    
    pc.baud(115200);
    rs485.baud(115200);
    pc.printf("Hello there...\n\r");
             
    CS=0;
    //spi.write(0b0000000000);
      spi.write(0b0011111111);
    CS=1;   
    
    while(1) {
 
        pc.printf("%d \n",led_no);

           led1=led_no & (1 << 0);
           led2=led_no & (1 << 1);
           led3=led_no & (1 << 2);
           led4=led_no & (1 << 3);
           led5=led_no & (1 << 4);
        led_no=led_no*2;
        if (led_no>16){led_no=1;}
        
        for (intensity=0; intensity<256 ; intensity++){
            ThisThread::sleep_for(delay);
            CS=0;
            //ThisThread::sleep_for(0.001);
            spi.write(0b0000000000|intensity);
            CS=1;
            }
        pc.printf("for loop done \n");
    }   
}
