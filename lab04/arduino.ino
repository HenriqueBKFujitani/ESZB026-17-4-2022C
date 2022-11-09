// programa baseado no codigo disponibilizado em:
// Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
// Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/
// Erick Camargo, https://github.com/edlbcamargo/sist_embarcados_git/tree/master/lab04

const int analogInPin = A0;                  // o potenciômetro esta ligado ao pino A0

void setup() {
   // Configurando a serial
   // Baud rate de 115200, 8-bit, sem paridade, 1 stop bit
   Serial.begin(115200, SERIAL_8N1);
}

void loop() {
    int valor = analogRead(analogInPin);      // le valor no pino A0 usando conversor ADC de 10-bit
    float potencial = valor * (5.0f/1023.0f); // converte o valor lido em potencial
    byte charIn;
    if(Serial.available()){       // verifica se recebeu algo pela serial
        charIn = potencial
        Serial.write(charIn);                   // envia o buffer para a RaspberryPi
    }
}