#include <DHT.h> //library DHT
#define DHTPIN 5 //pin DATA konek ke pin 2 Arduino
#define DHTTYPE DHT11 //tipe sensor DHT11
DHT dht(DHTPIN, DHTTYPE); //set sensor + koneksi pin
float humi, temp;//deklarasi variabel 
int trig_pin = 2;
int echo_pin = 3;
long waktu;
float jarak;

void setup()
{
  Serial.begin(9600); //baud 9600
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  digitalWrite(trig_pin, LOW);
  dht.begin();    
}

void loop()
{
  humi = dht.readHumidity();//baca kelembaban
  temp = dht.readTemperature();//baca suhu
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  waktu= pulseIn(echo_pin, HIGH);
  jarak= 0.0001*((float)waktu*340.0)/2.0;
  
    Serial.println(String(humi)+";"+ String(temp)+"*"+ String(jarak));
    delay(500);
  }
