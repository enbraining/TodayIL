#include <avr/io.h>
#include <util/delay.h>

int main(void){
    DDRA = 0xff;
    int i, left_led, right_led;

    while(1){
        left_led = 0b10000000;
        right_led = 0b00000001;

        for(int i = 0; i < 3; i++){
            PORTA = ~(left_led | right_led);
            _delay_ms(500);
            left_led = left_led >> 1;
            right_led = right_led << 1;
        }

        for(int i = 0; i < 3; i++){
            PORTA = ~(left_led | right_led);
            _delay_ms(500);
            left_led = left_led << 1;
            right_led = right_led >> 1;
        }
    }
}