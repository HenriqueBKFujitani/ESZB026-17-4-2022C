#include <stdio.h>
#include <wiringPi.h>

#define pino_PWM0 18                    // o PWM sera acionado na GPIO18

int main() {                            // este programa deve ser rodado com 'sudo'
   int dc, ciclos;
   wiringPiSetupGpio();                 // usa a numeracao da GPIO
   pinMode(pino_PWM0, PWM_OUTPUT);      // configura a GPIO18 com o PWM por hardware

   // Ajustando a frequencia do PWM em 10kHz com 128 passos de duty cycle
   // frequencia PWM = 19,2 MHz / (divisor * range)
   // 261,6 = 19200000 / (divisor * 129) => divisor = 569
   pwmSetMode(PWM_MODE_MS);             // usando frequencia fixa
   pwmSetRange(129);                    // passos do duty cycle (max=4096)
   pwmSetClock(569);                     // fornece uma frequencia de 261.6Hz (max=4096)
 
   for(ciclos = 0; ciclos < 3; ciclos++){  // variando o duty cycle
      for(dc = 0; dc < 129; dc++){
         pwmWrite(pino_PWM0, dc);
         usleep(10000);
      }
      for(dc = 129; dc >= 0; dc--){
         pwmWrite(pino_PWM0, dc);
         usleep(10000);
      }
   }
   return 0;                            // a saida PWM permanece ligada apos o termino do programa
}
