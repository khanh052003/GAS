#define BLYNK_TEMPLATE_ID "TMPL6Emfj2mvN"
#define BLYNK_TEMPLATE_NAME "Gas"
#define BLYNK_AUTH_TOKEN "Tm-4v7ROBUpOfbqMkduxQ3aSHVYbBNTr"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
char auth[] = "Tm-4v7ROBUpOfbqMkduxQ3aSHVYbBNTr";
char ssid[] = "OPPO A3s";
char pass[] = "1234567890";

int n;

void setup()
{

  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  pinMode(16,OUTPUT);
  pinMode(5,OUTPUT);
  timer.setInterval(1000L, sendUptime);
}


void sendUptime()
{
  Blynk.virtualWrite(V1, n);
}

void loop()
{
  Blynk.run();
  timer.run();
  
  n=analogRead(A0);
  Serial.println(n);
  
  if(n>500)
  {
     digitalWrite(16,LOW);
    //digitalWrite(5,HIGH);   
  }
  
  if(n<500)
  {
      digitalWrite(16,HIGH);
      //digitalWrite(5,LOW);
  }

}


