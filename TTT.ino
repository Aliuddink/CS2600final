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

  void callback(char *topic, byte *payload, unsigned int length) {
 Serial.print("Message arrived in topic: ");
 Serial.println(topic);
 Serial.print("Message:");
 for (int i = 0; i < length; i++) {
     Serial.print((char) payload[i]);
 }
 Serial.println();
 Serial.println("-----------------------");
}


void loop() {

  char keyPressed = myKeypad.getKey();
  
  if (count == 0 && inPlay == true)
  {
    if (keyPressed == '1')
    {
      client.publish(topic, "1");  
    }
    else if (keyPressed == '2')
    {
      client.publish(topic, "2");
    }
    else if (keyPressed == '3')
    {
      client.publish(topic, "3");
    }
    else if (keyPressed == '4')
    {
      client.publish(topic, "4");
    }
    else if (keyPressed == '5')
    {
      client.publish(topic, "5");
    }
    else if (keyPressed == '6')
    {
      client.publish(topic, "6");
    }
    else if (keyPressed == '7')
    {
      client.publish(topic, "7");
    }
    else if (keyPressed == '8')
    {
      client.publish(topic, "8");
    }
    else if (keyPressed == '9')
    {
      client.publish(topic, "9");
    }
    else if (keyPressed == '0');
    {
      client.publish(topic, "0");
    }
  }

  client.loop();
}


  /* write a function that checks the win conditions if a row, column, or diagnal is 
filled with the same caracters */
bool WinConditions () 
{
    bool win = false;

    // rows if the entries 1,2,3     4,5,6,     7,8,9 are full of the same char that char wins
   //if (entry[1] != '1' )    
    //{
        if (entry[1] == entry[2] == entry[3] )
        {
            win = true;
            printf ("You won the game 1");
            exit(0); 
        }
    //} else if (entry[4] != '4' ) 
    //{
                if (entry[4] == entry[5] == entry[6] )
        {
            win = true;
            printf ("You won the game 2");
            exit(0); 
        }
    //} else if (entry[7] != '7')
    //{
                if (entry[7] == entry[8] == entry[9] )
        {
            win = true;
            printf ("You won the game 3");
            exit(0);
        }
    //}
    // columns if the entries 1,4,7     2,5,8,     3,6,9 are full of the same char that char wins
      //  if (entry[1] != '1' )    
    //{
        if (entry[1] == entry[4] == entry[7] )
        {
            win = true;
            printf ("You won the game 4"); 
            exit(0);
        }
    //} else if (entry[2] != '2' ) 
    //{
                if (entry[2] == entry[5] == entry[8] )
        {
            win = true;
            printf ("You won the game 5");
            exit(0); 
        }
    //} else if (entry[3] != '3')
    //{
                if (entry[3] == entry[6] == entry[9] )
        {
            win = true;
            printf ("You won the game 6");
            exit(0);
        }
    //}
    // diagnal if the entries 1,5,9     3,5,7 are full of the same char that char wins
      //  if (entry[1] != '1' )    
    //{
        if (entry[1] == entry[5] == entry[9] )
        {
            win = true;
            printf ("You won the game 7");
            exit(0);
        }
    //} else if (entry[3] != '3')
    //{
                if (entry[3] == entry[5] == entry[7] )
        {
            win = true;
            printf ("You won the game 8");
            exit(0);
        }
    //}

    return win; 
}
    bool Draw() 
    {
        bool entryFull = false;

        if (entry[1] != '1'&& entry[2] != '2'&& entry[3] != '3' && entry[4] != '4' &&  entry[5] != '5' && entry[6] != '6' && entry[7] != '7' && entry[8] != '8' && entry[9] != '9')
        {
            entryFull = true;
            printf ("\n the game is a draw");
            exit(0);
        }  


        if (entryFull = true)
        {   
        WinConditions();
        }
    }

    void boardSetup()
{
  //set all lights to off
  digitalWrite(ONE, LOW);
  digitalWrite(TWO, LOW);
  digitalWrite(THREE, LOW);
  digitalWrite(FOUR, LOW);
  digitalWrite(FIVE, LOW);
  digitalWrite(SIX, LOW);
  digitalWrite(SEVEN, LOW);
  digitalWrite(EIGHT, LOW);
  digitalWrite(NINE, LOW);

  //initialize board
  for(int i = 0; i < 9; i++)
  {
    gameBoard[i][0] = i + 0;
  }
}

    void SetLED() //0 = off, 1 = on (P1), 2 = sel (P1), 3 = on (P2), 4 = sel (P2)
    {
    if (LEDVals[Pos] == 2) { LEDVals[Pos] = 1; }
    else if (LEDVals[Pos] == 4) {LEDVals[Pos] = 3; }
    else if (LEDVals[Pos] == 1 || 3) {Serial.println("Cannot set LED to Player, as it is assigned already!"); }
    if ( Player = false ) { Player = true; Serial.println("Players switched."); }
    else { Player = false; Serial.println("Players switched."); }
    }

