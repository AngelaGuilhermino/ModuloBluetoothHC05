#include <SoftwareSerial.h>

SoftwareSerial BT(2, 3);  // RX, TX

void setup() {
  Serial.begin(9600);
  BT.begin(9600);  // Velocidade padrão do HC-05

  pinMode(11, OUTPUT); // Pino do LED no arduíno

  Serial.println("HC-05 pronto. Aguardando comandos...");
}

void loop() {
  if (BT.available()) {
    char c = BT.read(); 
    Serial.print("Recebido: ");
    Serial.println(c);
    if (c == '1') {
      digitalWrite(11, HIGH);
      Serial.println("LED ON");
      BT.println("LED ON");
    } else if (c == '0') {
      digitalWrite(11, LOW);
      Serial.println("LED OFF");
      BT.println("LED OFF"); 
    }
  }

  if (Serial.available()) {
    char c = Serial.read();
    BT.write(c);  // Envia do monitor serial para o celular
  }
}