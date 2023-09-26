#include <LiquidCrystal_I2C.h>
//Initialize the display at address 0x27
LiquidCrystal_I2C lcd( 0x27 ,16,2 ) ;
long readUltrasonicDistance(int triggerPin, int echoPin)// Define as leituras do sensor como long, variável que pode armazenar até 32 bits de dado 
{
  pinMode(triggerPin, OUTPUT);  // Define o pino"triggerPin" como saída
  digitalWrite(triggerPin, LOW);// Define que o pino está sem tensão neste momento
  delayMicroseconds(10);    // Aguarda por 10 microsegundos (0,01 s)
  digitalWrite(triggerPin, HIGH);// Define que o pino está com tensão neste moemtno
  delayMicroseconds(10);    // Aguarda por 10 microsegundos (0,01 s)
  digitalWrite(triggerPin, LOW);// Define que o pino está sem tensão neste momento
  pinMode(echoPin, INPUT);    // Define o pino "echoPin" como de entrada
  return pulseIn(echoPin, HIGH);
  // Realiza a leitura do pino echoPin e retorna o tempo de viagem da onda sonora em microssegundos
}
float cm1;
 
void setup ()
{
  lcd. init () ;
  Serial.begin(9600);
}
 
void loop  ()
{
  estaPerto();
  mostrarQualquerCoisa();
}

void mostrarQualquerCoisa()
{
  lcd.clear();
  cm1 = 0.01723 * readUltrasonicDistance(12,13);
  lcd. setBacklight ( HIGH ) ;
  lcd. setCursor ( 0,0 ) ;
  lcd. print ( "Genshin" ) ;
  lcd. setCursor ( 0,1 ) ;
  lcd. print ( "Star rail" ) ;
  Serial.println(cm1);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("todos gacha");
  delay(1000);
  lcd.clear();
}

void estaPerto()
{
  if (cm1 < 100)
  {
    while(cm1 < 100)
    {
      cm1 = 0.01723 * readUltrasonicDistance(12,13);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Voce esta perto");
      lcd.setCursor(0, 1);//muda onde esccreve no lcd
      lcd.print("de Peixes");
      delay(1000);
    }
  }
}
