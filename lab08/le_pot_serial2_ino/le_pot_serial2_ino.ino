const int analogInPin = A0;            // o potenciômetro esta ligado ao pino A0
int iniciaColeta = 0;
int actualtime = 0;
char charRecebido; // cria uma variavel para armazenar o caractere recebido
int previoustime = 0;
long taxa = 0;
long sendtaxa = 0;
long valor=0;

void setup(){
   // Configura a serial: baud rate de 115200, 8-bit, sem paridade, 1 stop bit
   Serial.begin(115200, SERIAL_8N1);
}


void loop(){
   if (Serial.available()){            // verifica se recebeu algum comando
      charRecebido = Serial.read();    // le o caractere recebido
      switch ( charRecebido ){
          case 'i':                    // inicia coleta
             iniciaColeta = 1;
             break;
             
          case 'p':                    // para a coleta
             iniciaColeta = 0;
             break;
          
          case 't':
          
             
             
             Serial.write(taxa & 0xFF);          // envia byte menos significativo
             Serial.write(taxa >> 8);            // envia byte mais significativo
             break;
       
        
             
          default:                     // outro comando, ignora...
             break;
      }
   }
   if ( iniciaColeta == 1 ){
       int valor = analogRead(analogInPin); // le valor no pino A0 usando conversor ADC de 10-bit
       Serial.write(valor & 0xFF);          // envia byte menos significativo
       Serial.write(valor >> 8);            // envia byte mais significativo
       
       actualtime = millis();
       taxa = actualtime-previoustime;
       previoustime = actualtime;
    
   }
   delay(100);                          // aguarda 100ms
}
