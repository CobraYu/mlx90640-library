#include <wiringPi.h>
using namespace std;

#define DIR 28
#define STEP 29
#define M1 15
#define M2 16
#define M3 1
#define CW 1
#define CCW 0
#define SPR 200
#define DELAY 0.01
#define HIGH 1
#define LOW 0
#define MICROSTEP 4

int main() {
    wiringPiSetup();
    pinMode(DIR, OUTPUT);
    pinMode(STEP, OUTPUT);
    pinMode(M1, OUTPUT);
    pinMode(M2, OUTPUT);
    pinMode(M3, OUTPUT);
    digitalWrite(DIR,CW);
    digitalWrite(M1,LOW);
    digitalWrite(M2,HIGH);
    digitalWrite(M3,LOW);
    for(int i = 0; i < SPR*MICROSTEP; ++i) {
        digitalWrite(STEP,HIGH);
        delay(DELAY*1000/MICROSTEP);
        digitalWrite(STEP,LOW);
        delay(DELAY*1000/MICROSTEP);
    }
    return 0;
}
