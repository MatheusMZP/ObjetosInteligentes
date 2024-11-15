#include <ESP8266WiFi.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>

#define WIFI_SSID       "Madricar2G"
#define WIFI_PASSWORD   "madricar1989"
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME    "Matheus_24"
#define AIO_KEY         "aio_NlLs512BJSjKXV51QsgTC89wFBEq"

#define SOUND_SENSOR_PIN A0  
#define LED_PIN D2           
#define NOISE_THRESHOLD 600  

WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);


Adafruit_MQTT_Publish noiseAlarm = Adafruit_MQTT_Publish(&mqtt, "Matheus_24/feeds/noisealarm");
Adafruit_MQTT_Publish noiseLevel = Adafruit_MQTT_Publish(&mqtt, "Matheus_24/feeds/noiselevel");

void connectToWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) delay(500);
}

void connectToMQTT() {
  while (mqtt.connect() != 0) {
    mqtt.disconnect();
    delay(5000); 
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("Monitor Serial iniciado corretamente");  // Mensagem de depuração
  pinMode(LED_PIN, OUTPUT);
  connectToWiFi();
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) connectToWiFi();
  if (!mqtt.connected()) connectToMQTT();
  
  int soundLevel = analogRead(SOUND_SENSOR_PIN);  
  Serial.print("Nível de som: ");  
  Serial.println(soundLevel);
  
  noiseLevel.publish(soundLevel);  

  if (soundLevel > NOISE_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);  
    noiseAlarm.publish("Som excessivo!");  
  } else {
    digitalWrite(LED_PIN, LOW);  
    noiseAlarm.publish("Som normal.");  
  }
  
  delay(5000);  
}
