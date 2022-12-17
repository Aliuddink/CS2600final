#include <WiFi.h>
#include <PubSubClient.h>
#include <Keypad.h>

//from arduino intro files
// define the symbols on the buttons of the keypad
char keys[4][4] = {
 {'1', '2', '3', 'A'},
 {'4', '5', '6', 'B'},
 {'7', '8', '9', 'C'},
 {'*', '0', '#', 'D'}
};
byte rowPins[4] = {14, 27, 26, 25}; // connect to the row pinouts of the keypad
byte colPins[4] = {13, 21, 22, 23}; // connect to the column pinouts of the keypad

// initialize an instance of class NewKeypad
Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);

const char *ssid = "S21 Ultra"; // Enter your WiFi name
const char *password = "Hello123";  // Enter WiFi password

// MQTT Broker
const char *mqtt_broker = "broker.emqx.io";
const char *topic = "esp32/TTT";
const char *mqtt_username = "emqx";
const char *mqtt_password = "public";
const int mqtt_port = 1883;
int count = 0;
int player = 0;
char gameBoard [9][1];
bool inPlay = true;
WiFiClient espClient;
PubSubClient client(espClient);

#define LED_ONE 4
#define LED_TWO 2
#define LED_THREE 15
#define LED_FOUR 5
#define LED_FIVE 34
#define LED_SIX 35
#define LED_SEVEN 32
#define LED_EIGHT 33
#define LED_NINE 18

  void setup() 
  {
     Serial.begin(115200);

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.println("Connecting to WiFi..");
    }
     Serial.println("Connected to the WiFi network");
    //connecting to a mqtt broker
    client.setServer(mqtt_broker, mqtt_port);
    client.setCallback(callback);
    while (!client.connected()) {
        String client_id = "esp32-client-";
        client_id += String(WiFi.macAddress());
        Serial.printf("The client %s connects to the public mqtt broker\n", client_id.c_str());
        if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
            Serial.println("Public emqx mqtt broker connected");
        } else {
            Serial.print("failed with state ");
            Serial.print(client.state());
            delay(2000);
        }
    }
    
    pinMode(LED_ONE, OUTPUT);
    pinMode(LED_TWO, OUTPUT);
    pinMode(LED_THREE, OUTPUT);
    pinMode(LED_FOUR, OUTPUT);
    pinMode(LED_FIVE, OUTPUT);
    pinMode(LED_SIX, OUTPUT);
    pinMode(LED_SEVEN, OUTPUT);
    pinMode(LED_EIGHT, OUTPUT);
    pinMode(LED_NINE, OUTPUT);
    // publish and subscribe
    client.subscribe(topic);

  }
