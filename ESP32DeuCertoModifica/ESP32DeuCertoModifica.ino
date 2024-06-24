#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

int counter = 0;

LiquidCrystal_I2C lcd(0x27,16,2);//set the LCD address to 0x27 for a 16 chars and 2 line display

const int inputPin = 14;  // Pino de entrada
const int motorPin = 15;    // Pino de saída

void setup(){ 
  Serial.begin(115200);

  lcd.begin(21, 22);// Pino em ordem SDA e SCL 

  lcd.backlight();

   // Configura o pino de entrada
  pinMode(inputPin, INPUT);
  // Configura o pino de saída
  pinMode(motorPin, OUTPUT);
  // Inicializa o LED desligado
  digitalWrite(motorPin, LOW);

  Serial.println("Configuração concluída.");

}
void loop(){
  Serial.println("O ESP32 está funcionando...");
  delay(1000); // Aguarda 5 segundos

  lcd.setCursor(0,0);
  lcd.print("Sillion");
  lcd.setCursor(0,1);


  int sensorValue = digitalRead(inputPin);

  Serial.print("Valor lido no pino 34: ");
  Serial.println(sensorValue);

  if (sensorValue == HIGH) {
    // Se o valor for HIGH, liga o LED
    digitalWrite(motorPin, HIGH);
    Serial.println("Motor ligado.");

    lcd.setCursor(0, 1);  // Linha 1, posição 0
    lcd.print("Motor ligado    "); // A string deve ser preenchida com espaços para limpar caracteres antigos

  } 
  
  else {
    // Caso contrário, desliga o LED
    digitalWrite(motorPin, LOW);
    Serial.println("Motor desligado.");

    lcd.setCursor(0, 1);  // Linha 1, posição 0
    lcd.print("Motor desligado "); // A string deve ser preenchida com espaços para limpar caracteres antigos
  }

}


