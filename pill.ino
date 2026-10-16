#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

const char* ssid = "Airtel_elan_4389";
const char* password = "air82733";

#define BOTtoken "86277301:AAFnmPci4EBTWxW0vPHjSYu_kJMHc_o"
#define CHAT_ID "6591814904"

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

// Pins
#define IR1 32
#define IR2 33
#define IR3 34

#define LED1 25
#define LED2 26
#define LED3 27

#define BUZZER 14

void setup() {

Serial.begin(115200);

pinMode(IR1, INPUT);
pinMode(IR2, INPUT);
pinMode(IR3, INPUT);

pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);

pinMode(BUZZER, OUTPUT);

WiFi.begin(ssid, password);

while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}

Serial.println("WiFi Connected");

client.setInsecure();

delay(3000);   // wait 40 sec

morningBox();

delay(3000);   // next 40 sec

afternoonBox();

delay(3000);   // next 40 sec

nightBox();

}

void loop() {}


// MORNING FUNCTION
void morningBox() {

digitalWrite(LED1, HIGH);
digitalWrite(BUZZER, HIGH);

unsigned long startTime = millis();

while (millis() - startTime < 3000) {

if (digitalRead(IR1) == LOW) {

digitalWrite(LED1, LOW);
digitalWrite(BUZZER, LOW);
return;

}

}

bot.sendMessage(CHAT_ID, "Morning medicine not taken!", "");

digitalWrite(LED1, LOW);
digitalWrite(BUZZER, LOW);

}


// AFTERNOON FUNCTION
void afternoonBox() {

digitalWrite(LED2, HIGH);
digitalWrite(BUZZER, HIGH);

unsigned long startTime = millis();

while (millis() - startTime < 3000) {

if (digitalRead(IR2) == LOW) {

digitalWrite(LED2, LOW);
digitalWrite(BUZZER, LOW);
return;

}

}

bot.sendMessage(CHAT_ID, "Afternoon medicine not taken!", "");

digitalWrite(LED2, LOW);
digitalWrite(BUZZER, LOW);

}


// NIGHT FUNCTION
void nightBox() {

digitalWrite(LED3, HIGH);
digitalWrite(BUZZER, HIGH);

unsigned long startTime = millis();

while (millis() - startTime < 3000) {

if (digitalRead(IR3) == LOW) {

digitalWrite(LED3, LOW);
digitalWrite(BUZZER, LOW);
return;

}

}

bot.sendMessage(CHAT_ID, "Night medicine not taken!", "");

digitalWrite(LED3, LOW);
digitalWrite(BUZZER, LOW);

}
