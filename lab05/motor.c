#include <stdio.h>
#include <wiringPi.h>

#define pino_PWM0 18                    // o PWM sera acionado na GPIO18

int main() {                            // este programa deve ser rodado com 'sudo'
   int dc, ciclos;
   wiringPiSetupGpio();                 // usa a numeracao da GPIO
   pinMode(pino_PWM0, PWM_OUTPUT);      // configura a GPIO18 com o PWM por hardware

   // Ajustando a frequencia do PWM em 10kHz com 128 passos de duty cycle
   // frequencia PWM = 19,2 MHz / (divisor * range)
   // 10000 = 19200000 / (divisor * 256) => divisor = 15
   pwmSetMode(PWM_MODE_MS);             // usando frequencia fixa
   pwmSetRange(255);                    // passos do duty cycle (max=4096)
   pwmSetClock(15);                     // fornece uma frequencia de 10kHz (max=4096)

   for(ciclos = 0; ciclos < 1; ciclos++){  // variando o duty cycle
      for(dc = 0; dc < 255; dc++){
         pwmWrite(pino_PWM0, dc);
         usleep(100000);              //tempo ligado
      }
      for(dc = 255; dc >= 0; dc--){
         pwmWrite(pino_PWM0, dc);
         usleep(10000);
      }
   }
   return 0;     
