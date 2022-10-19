/*Abrindo arquivos fonte*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Definindo portas e caminhos dos diretorios*/
#define GPIO_RED_NUMBER "20"
#define GPIO_RED_PATH "/sys/class/gpio/gpio20/"

#define GPIO_YEL_NUMBER "16"
#define GPIO_YEL_PATH "/sys/class/gpio/gpio16/"

#define GPIO_GRE_NUMBER "21"
#define GPIO_GRE_PATH "/sys/class/gpio/gpio21/"

#define GPIO_SYSFS "/sys/class/gpio/"

/*Fcao que associa caminho e valor ao arquivo*/
void writeGPIO(char filename[], char value[]){
   FILE* fp;                         
   fp = fopen(filename, "w+");         
   fprintf(fp, "%s", value);           
   fclose(fp);                       
}
/*Comando associado a execução do programa*/
int main(int argc, char* argv[]){
    /*Abrindo portas*/
      writeGPIO(GPIO_SYSFS "export", GPIO_GRE_NUMBER);
      usleep(100000);                 
      writeGPIO(GPIO_GRE_NUMBER "direction", "out");

      writeGPIO(GPIO_SYSFS "export", GPIO_YEL_NUMBER);
      usleep(100000);                 
      writeGPIO(GPIO_YEL_NUMBER "direction", "out");

      writeGPIO(GPIO_SYSFS "export", GPIO_RED_NUMBER);
      usleep(100000);                 
      writeGPIO(GPIO_RED_NUMBER "direction", "out");
     /*Contador e loop para repeticao*/
      int count=1;

      while(count<5){
    
        count++;

        writeGPIO(GPIO_RED_PATH "value", "1");
        usleep(200000);
        writeGPIO(GPIO_RED_PATH "value", "0");
   
   
        writeGPIO(GPIO_GRE_PATH "value", "1");
        usleep(200000);
        writeGPIO(GPIO_GRE_PATH "value", "0");

        writeGPIO(GPIO_YEL_PATH "value", "1");
        usleep(200000);
        writeGPIO(GPIO_YEL_PATH "value", "0");
        /*Execução da sequencia dos LEDs*/
        } 
     /*Fechando portas*/
      writeGPIO(GPIO_SYSFS "unexport", GPIO_GRE_NUMBER);
      writeGPIO(GPIO_SYSFS "unexport", GPIO_YEL_NUMBER);
      writeGPIO(GPIO_SYSFS "unexport", GPIO_RED_NUMBER);
   return 0;
}
/*Fim do programa*/