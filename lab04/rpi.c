#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h> 



int main(){
	int file, count;
    if ((file = open("/dev/ACM3", O_RDWR | O_NOCTTY | O_NDELAY))<0){
      return -1;
    }

    struct termios options;             // cria estruturas para configurar a comunicacao
    tcgetattr(file, &options);          // ajusta os parametros do arquivo
    options.c_cflag = B115200 | CS8 | CREAD | CLOCAL;
    options.c_iflag = IGNPAR | ICRNL;   // ignora erros de paridade
    tcflush(file, TCIFLUSH);            // descarta informacao no arquivo
    tcsetattr(file, TCSANOW, &options); // aplica alteracoes imediatamente

	usleep(100000);                     // Espera 100ms pela resposta do Arduino
    unsigned char receive[100];         // cria um buffer para receber os dados
    if ((count = read(file, (void*)receive, 100))<0){        // recebe os dados
       
       return -1;
    }
    
    return 0;

	int pino_PWM = 23;                         // pwm por software na GPIO23
	int range = 100;                           // periodo do PWM = 100us*range
	wiringPiSetupGpio();                       // usar a numeracao GPIO, nao WPi
	pinMode(pino_PWM,OUTPUT);	           // configura GPIO23 como saida
	softPwmCreate(pino_PWM, 1, range);         // inicializa PWM por software
	while (1) {
		for (receive = 0; receive < range; receive++) {
		  softPwmWrite (pino_PWM, receive); // altera o duty cycle do PWM
		  delay (10) ;                     // aguarda 10ms
                }
		for (receive = range; receive > 0; receive--) {
		  softPwmWrite (pino_PWM, receive);
		  delay (10);
		}
	}
}

