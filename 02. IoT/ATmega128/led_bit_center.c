#include <avr/io.h>
#include <util/delay.h>

int main(void){
    int i, left_led = 0x7f, right_led = 0xfe;
    DDRA = 0xff;
    while(1){
        for(int i = 0; i < 3; i++){
            PORTA = left_led & right_led;
            left_led = (left_led >> 1) | 0x80;
            right_led = (right_led << 1) | 0x01;
            _delay_ms(1000);
        }
        for(int i = 0; i < 3; i++){
            PORTA = left_led & right_led;
            left_led = (left_led << 1) | 0x01;
            right_led = right_led >> 1;
            _delay_ms(1000);
        }
    }
}