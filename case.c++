#include <LiquidCrystal.h>
#include "dht.h"
dht DHT;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int buzzer = 7;

float sensordeluminosidade = A0;
const int pinoDHT11 = A2;
float valorldr = 0;
int led_verde = 10;
int led_amarelo = 9;
int led_vermelho = 8;
int IntensidadeLuz;

int somaldr = 0;
int somatemp = 0;
int somaumi = 0;
int a = 0;



void setup()
{
  Serial.begin(9600);
  pinMode(7, OUTPUT);
	pinMode( 8, OUTPUT);
	pinMode( 9, OUTPUT);
	pinMode( 10, OUTPUT);
	pinMode(sensordeluminosidade, INPUT);
  lcd.begin(16, 2);
  pinMode(pinoDHT11, INPUT);
    
}

void loop()
{
  while (a < 5){
    DHT.read11(pinoDHT11); //lé o pino a2
    valorldr = analogRead(sensordeluminosidade); // lé o pino a0
    IntensidadeLuz = map(valorldr, 0, 1023, 1, 100); // deixa o valor lido no a0 entre 1 a 100
    lcd.clear(); // tela lcd é "limpa"
    delay(10);
    somaldr = somaldr + IntensidadeLuz;
    somatemp = somatemp + DHT.temperature;
    somaumi = somaumi + DHT.humidity;
    a = a + 1;
    Serial.print(a);
    delay(1000);
  }
  IntensidadeLuz = somaldr/5;
  DHT.temperature = somatemp/5;
  DHT.humidity = somaumi/5; 
  somaldr = 0;
  somatemp =0;
  somaumi = 0;
  while(a == 5){
    Serial.print(IntensidadeLuz);  
    if((IntensidadeLuz) >= 0  && (IntensidadeLuz) <= 20){
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW); 
      lcd.setCursor(0, 0);
      lcd.print("Ambiente muito");
      lcd.setCursor(0,1);
      lcd.print("Claro");
      lcd.setCursor(0, 0);
      tone(7, 220, 5000);
      delay(5000); 
      if((DHT.temperature) >= 10 && (DHT.temperature) <= 15 ){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Temp OK");
        lcd.setCursor(0, 10);
        lcd.print(DHT.temperature);
        Serial.print(" / Temperatura: "); 
        Serial.print(DHT.temperature, 0);
        Serial.println("*C"); 
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW); 
        delay(5000);
        if((DHT.humidity) >= 50 && (DHT.humidity) <= 70){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Umidade ok");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          digitalWrite(8, LOW);
          digitalWrite(9, LOW);
          digitalWrite(10, HIGH);
          delay(5000);
        }
        if((DHT.humidity) < 50){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Umidade baixa");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW);
          digitalWrite(10,LOW);
          tone(7, 220, 5000);
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          delay(5000);
        }
        if((DHT.humidity) > 70){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Umidade Alta");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW);
          digitalWrite(10, LOW);
          tone(7, 220, 5000);
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          delay(5000);
        }
      }
      if((DHT.temperature) < 10){
        lcd.clear();
        tone(7, 220, 5000);
        lcd.setCursor(0, 0);
        lcd.print("Temp baixa");
        lcd.setCursor(0, 10);
        lcd.print(DHT.temperature);
        lcd.print("*C");
        digitalWrite(9, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(10,LOW);
        Serial.print(" / Temperatura: "); 
        Serial.print(DHT.temperature, 0);
        Serial.println("*C"); 
        delay(5000);
        if((DHT.humidity) >= 50 && (DHT.humidity) <= 70){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Umidade ok");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          digitalWrite(8, LOW);
          digitalWrite(9, LOW);
          digitalWrite(10, HIGH);
          delay(5000);
        }
        if((DHT.humidity) < 50){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Umidade baixa");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW);
          digitalWrite(10,LOW);
          tone(7, 220, 5000);
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          delay(5000);
        }
        if((DHT.humidity) > 70){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Umidade Alta");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW);
          digitalWrite(10, LOW);
          tone(7, 220, 5000);
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          delay(5000);
        }
      }      
      if((DHT.temperature) > 15){
        lcd.clear();
        tone(7, 220, 5000);
        lcd.setCursor(0, 0);
        lcd.print("Temp alta");
        lcd.setCursor(0, 10);
        lcd.print(DHT.temperature);
        digitalWrite(8,LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10,LOW);
        Serial.print(" / Temperatura: "); 
        Serial.print(DHT.temperature, 0);
        Serial.println("*C"); 
        delay(5000);
        if((DHT.humidity) >= 50 && (DHT.humidity) <= 70){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Umidade ok");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          digitalWrite(8, LOW);
          digitalWrite(9, LOW);
          digitalWrite(10, HIGH);
          delay(5000);
        }
        if((DHT.humidity) < 50){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Umidade baixa");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW);
          digitalWrite(10,LOW);
          tone(7, 220, 5000);
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          delay(5000);
        }
        if((DHT.humidity) > 70){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Umidade Alta");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW);
          digitalWrite(10, LOW);
          tone(7, 220, 5000);
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          delay(5000);
        }
      }  
    }
    if((IntensidadeLuz) > 20 && (IntensidadeLuz) < 50 ){
      digitalWrite(9, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(10,LOW);
      lcd.setCursor(0, 0);
      lcd.print("Ambiente meia");
      lcd.setCursor(0,1);
      lcd.print("Luz");
      delay(5000);
      lcd.setCursor(0, 1);
      tone(7, 220, 5000);
      delay(5000);
      if((DHT.temperature) >= 10 && (DHT.temperature) <= 15 ){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Temp OK");
        lcd.setCursor(0, 10);
        lcd.print(DHT.temperature);
        Serial.print(" / Temperatura: "); 
        Serial.print(DHT.temperature, 0);
        Serial.println("*C"); 
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW); 
        delay(5000);
        if((DHT.humidity) >= 50 && (DHT.humidity) <= 70){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Umidade ok");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          digitalWrite(8, LOW);
          digitalWrite(9, LOW);
          digitalWrite(10, HIGH);
          delay(5000);
        }
        if((DHT.humidity) < 50){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Umidade baixa");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW);
          digitalWrite(10,LOW);
          tone(7, 220, 5000);
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          delay(5000);
        }
        if((DHT.humidity) > 70){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Umidade Alta");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW);
          digitalWrite(10, LOW);
          tone(7, 220, 5000);
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          delay(5000);
        }
      }
      if((DHT.temperature) < 10){
        lcd.clear();
        tone(7, 220, 5000);
        lcd.setCursor(0, 0);
        lcd.print("Temp baixa");
        lcd.setCursor(0, 10);
        lcd.print(DHT.temperature);
        lcd.print("*C");
        digitalWrite(9, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(10,LOW);
        Serial.print(" / Temperatura: "); 
        Serial.print(DHT.temperature, 0);
        Serial.println("*C"); 
        delay(5000);
        if((DHT.humidity) >= 50 && (DHT.humidity) <= 70){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Umidade ok");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          digitalWrite(8, LOW);
          digitalWrite(9, LOW);
          digitalWrite(10, HIGH);
          delay(5000);
        }
        if((DHT.humidity) < 50){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Umidade baixa");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW);
          digitalWrite(10,LOW);
          tone(7, 220, 5000);
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          delay(5000);
        }
        if((DHT.humidity) > 70){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Umidade Alta");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW);
          digitalWrite(10, LOW);
          tone(7, 220, 5000);
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          delay(5000);
        }
      }      
      if((DHT.temperature) > 15){
        lcd.clear();
        tone(7, 220, 5000);
        lcd.setCursor(0, 0);
        lcd.print("Temp alta");
        lcd.setCursor(0, 10);
        lcd.print(DHT.temperature);
        digitalWrite(8,LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10,LOW);
        Serial.print(" / Temperatura: "); 
        Serial.print(DHT.temperature, 0);
        Serial.println("*C"); 
        delay(5000);
        if((DHT.humidity) >= 50 && (DHT.humidity) <= 70){
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("Umidade ok");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          digitalWrite(8, LOW);
          digitalWrite(9, LOW);
          digitalWrite(10, HIGH);
          delay(5000);
        }
        if((DHT.humidity) < 50){
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("Umidade baixa");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW);
          digitalWrite(10,LOW);
          tone(7, 220, 5000);
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          delay(5000);
        }
        if((DHT.humidity) > 70){
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("Umidade Alta");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW);
          digitalWrite(10, LOW);
          tone(7, 220, 5000);
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          delay(5000);
        }
      }                
    } 
    if((IntensidadeLuz) >=  50){
      digitalWrite(10, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      lcd.setCursor(0, 0);
      lcd.print("Luminosidade:");
      lcd.setCursor(0,1);
      lcd.print(IntensidadeLuz); 
      delay(5000);
      if((DHT.temperature) >= 10 && (DHT.temperature) <= 15 ){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Temp OK");
        lcd.setCursor(0, 10);
        lcd.print(DHT.temperature);
        Serial.print(" / Temperatura: "); 
        Serial.print(DHT.temperature, 0);
        Serial.println("*C"); 
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW); 
        delay(5000);
        if((DHT.humidity) >= 50 && (DHT.humidity) <= 70){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Umidade ok");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          digitalWrite(8, LOW);
          digitalWrite(9, LOW);
          digitalWrite(10, HIGH);
          delay(5000);
        }
        if((DHT.humidity) < 50){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Umidade baixa");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW);
          digitalWrite(10,LOW);
          tone(7, 220, 5000);
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          delay(5000);
        }
        if((DHT.humidity) > 70){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Umidade Alta");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW);
          digitalWrite(10, LOW);
          tone(7, 220, 5000);
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          delay(5000);
        }
      }
      if((DHT.temperature) < 10){
        lcd.clear();
        tone(7, 220, 5000);
        lcd.setCursor(0, 0);
        lcd.print("Temp baixa");
        lcd.setCursor(0, 10);
        lcd.print(DHT.temperature);
        lcd.print("*C");
        digitalWrite(9, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(10,LOW);
        Serial.print(" / Temperatura: "); 
        Serial.print(DHT.temperature, 0);
        Serial.println("*C"); 
        delay(5000);
        if((DHT.humidity) >= 50 && (DHT.humidity) <= 70){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Umidade ok");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          digitalWrite(8, LOW);
          digitalWrite(9, LOW);
          digitalWrite(10, HIGH);
          delay(5000);
        }
        if((DHT.humidity) < 50){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Umidade baixa");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW);
          digitalWrite(10,LOW);
          tone(7, 220, 5000);
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          delay(5000);
        }
        if((DHT.humidity) > 70){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Umidade Alta");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW);
          digitalWrite(10, LOW);
          tone(7, 220, 5000);
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          delay(5000);
        }
      }
      if((DHT.temperature) > 15){
        lcd.clear();
        tone(7, 220, 5000);
        lcd.setCursor(0, 0);
        lcd.print("Temp alta");
        lcd.setCursor(0, 10);
        lcd.print(DHT.temperature);
        digitalWrite(8,LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10,LOW);
        Serial.print(" / Temperatura: "); 
        Serial.print(DHT.temperature, 0);
        Serial.println("*C"); 
        delay(5000);
        if((DHT.humidity) >= 50 && (DHT.humidity) <= 70){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Umidade ok");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          digitalWrite(8, LOW);
          digitalWrite(9, LOW);
          digitalWrite(10, HIGH);
          delay(5000);
        }
        if((DHT.humidity) < 50){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Umidade baixa");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW);
          digitalWrite(10,LOW);
          tone(7, 220, 5000);
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          delay(5000);
        }
        if((DHT.humidity) > 70){
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("Umidade Alta");
          lcd.setCursor(1, 0);
          lcd.print(DHT.humidity);
          lcd.print("%");
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW);
          digitalWrite(10, LOW);
          tone(7, 220, 5000);
          Serial.print("Umidade: ");
          Serial.print(DHT.humidity);
          Serial.print("%");
          delay(5000);
        }
      }   		 		
    }
  a = 0;	
  }	
}
