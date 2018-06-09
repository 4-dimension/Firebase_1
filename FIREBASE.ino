
//#include <dht.h>
//
//dht DHT;
//
//#define DHT11_PIN 2
//
//
//void setup() {
// 
// Serial.begin(9600);
//
//
//}
//
//void loop() {
//  int chk = DHT.read11(DHT11_PIN);
//  Serial.print("Temperature = ");
//  Serial.println(DHT.temperature);
//  Serial.print("Humidity = ");
//  Serial.println(DHT.humidity);
//  delay(1000);
//
//}
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.

#define FIREBASE_HOST "node-b07e9.firebaseio.com"

#define FIREBASE_AUTH "68GMJmX0txEREOpEInqGrEQMOs4Um4k0IPLXF4G1"

#define WIFI_SSID "I-D-R"

#define WIFI_PASSWORD "MEHRARH50NG"

#define LED 2

void setup() {

pinMode(LED,OUTPUT);

digitalWrite(LED,0);

Serial.begin(9600);

WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

Serial.print("connecting");

while (WiFi.status() != WL_CONNECTED) {

Serial.print(".");

delay(500);

}

Serial.println();

Serial.print("connected: ");

Serial.println(WiFi.localIP());

Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

Firebase.setInt("LEDStatus",0);

}

void loop() {

                            if(Firebase.getInt("LEDStatus"))
                            
                            {
                            
                            digitalWrite(LED,HIGH);
                            
                            }
                            
                            else
                            
                            {
                            
                            digitalWrite(LED,LOW);
                            
                            }

                           // test();
delay(1000);
                                           



}

//void test(){
  
//   if (Firebase.failed()) // Check for errors {
//                                            
//                                            Serial.print("setting /number failed:");
//                                            
//                                            Serial.println(Firebase.error());
//                                            
//                                            return;
//                                            
//                                            }
//  
//  }
