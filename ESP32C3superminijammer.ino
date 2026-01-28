/* 
         /$$                                     /$$                         /$$         /$$  
       | $$                                    | $$                        | $$       /$$$$  
   /$$$$$$$  /$$$$$$   /$$$$$$  /$$$$$$$      /$$$$$$    /$$$$$$   /$$$$$$$| $$$$$$$ |_  $$  
  /$$__  $$ |____  $$ |____  $$| $$__  $$    |_  $$_/   /$$__  $$ /$$_____/| $$__  $$  | $$  
 | $$  | $$  /$$$$$$$  /$$$$$$$| $$  \ $$      | $$    | $$$$$$$$| $$      | $$  \ $$  | $$  
 | $$  | $$ /$$__  $$ /$$__  $$| $$  | $$      | $$ /$$| $$_____/| $$      | $$  | $$  | $$  
 |  $$$$$$$|  $$$$$$$|  $$$$$$$| $$  | $$      |  $$$$/|  $$$$$$$|  $$$$$$$| $$  | $$ /$$$$$$
  \_______/ \_______/ \_______/|__/  |__//$$$$$$\___/   \_______/ \_______/|__/  |__/|______/
                                        |______/                                             
                                                                                            
 This content is made and designed by @daan_tech1
 For contact, please mail: business.daantech@gmail.com
 TikTok/Twitch/YouTube = @daan_tech1

 ======================================
 WARNING / DISCLAIMER
 ======================================

 This project is intended for EDUCATIONAL PURPOSES ONLy.
 
 The author (@daan_tech1) does NOT take any responsobility for:
 
 misuse of this code
 illegal activities
 damage to hardware, software or other systems
 violations of local laws or regulations

 Use this code at your own risk.
 You are solely responsible for how it is used                                                      

*/

// NEEDED LIBRARYS
#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// PINS CONNECTIONS
#define SCK_PIN   4
#define MISO_PIN  5
#define MOSI_PIN  6
#define CE_PIN    20
#define CSN_PIN   21

SPIClass spi(FSPI);  
RF24 radio(CE_PIN, CSN_PIN);

// This content is made and designed by @daan_tech1
void setup() {
  Serial.begin(115200);
  delay(500);

  spi.begin(SCK_PIN, MISO_PIN, MOSI_PIN);

  Serial.println("Initializing nRF24L01+...");

  if (!radio.begin(&spi)) {
    Serial.println("nRF24L01+ initialization failed!");
    while (1);
  }
// This content is made and designed by @daan_tech1
  Serial.println("nRF24L01+ initialized!");

  radio.setAutoAck(false);
  radio.setRetries(0, 0);
  radio.setPALevel(RF24_PA_MAX, true);
  radio.setDataRate(RF24_2MBPS);
  radio.setCRCLength(RF24_CRC_DISABLED);
  radio.setChannel(0);
  radio.stopListening();
  radio.startConstCarrier(RF24_PA_MAX, 45);

  randomSeed(analogRead(0));
}
// This content is made and designed by @daan_tech1
void loop() {
  byte channel = random(0, 126);
  radio.setChannel(channel);
  delayMicroseconds(random(30, 100));
}
// This content is made and designed by @daan_tech1