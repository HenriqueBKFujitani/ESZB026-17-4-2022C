/*Importando Bibliotecas*/
#include<iostream>
#include<fstream>
#include<string>
#include<unistd.h>
using namespace std;

/*Definindo portas e caminhos dos diretorios*/
#define GPIO_RED_NUMBER "20"
#define GPIO_RED_PATH "/sys/class/gpio/gpio20/"

#define GPIO_YEL_NUMBER "16"
#define GPIO_YEL_PATH "/sys/class/gpio/gpio16/"

#define GPIO_GRE_NUMBER "21"
#define GPIO_GRE_PATH "/sys/class/gpio/gpio21/"

#define GPIO_SYSFS "/sys/class/gpio/"

/*Fcao que associa caminho e valor ao arquivo*/
void writeGPIO(string path, string filename, string value){
   fstream fs;
   fs.open((path + filename).c_str(), fstream::out);
   fs << value;
   fs.close();
}
/*Comando associado a execução do programa*/
int main(int argc, char* argv[]){
    /*Abrindo portas*/
      writeGPIO(string(GPIO_SYSFS), "export", GPIO_GRE_NUMBER);
      usleep(100000);
      writeGPIO(string(GPIO_GRE_PATH), "direction", "out");

      writeGPIO(string(GPIO_SYSFS), "export", GPIO_RED_NUMBER);
      usleep(100000);
      writeGPIO(string(GPIO_RED_PATH), "direction", "out");

      writeGPIO(string(GPIO_SYSFS), "export", GPIO_YEL_NUMBER);
      usleep(100000);
      writeGPIO(string(GPIO_YEL_PATH), "direction", "out");
     /*Contador e loop para repeticao*/
      int count=1;

      while(count<5){
    
        count++;

        writeGPIO(string(GPIO_RED_PATH), "value", "1");
        usleep(2000000);  //2s
        writeGPIO(string(GPIO_RED_PATH), "value", "0");
   
        writeGPIO(string(GPIO_GRE_PATH), "value", "1");
        usleep(1000000);  //1s
        writeGPIO(string(GPIO_GRE_PATH), "value", "0");

        writeGPIO(string(GPIO_YEL_PATH), "value", "1");
        usleep(1000000);  //1s
        writeGPIO(string(GPIO_YEL_PATH), "value", "0");
        /*Execução da sequencia dos LEDs*/
        } 
     /*Fechando portas*/
      writeGPIO(string(GPIO_SYSFS), "unexport", GPIO_GRE_NUMBER);
      writeGPIO(string(GPIO_SYSFS), "unexport", GPIO_RED_NUMBER);
      writeGPIO(string(GPIO_SYSFS), "unexport", GPIO_YEL_NUMBER);
   return 0;
}
/*Fim do programa*/
