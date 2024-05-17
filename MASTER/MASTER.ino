//MASTER

#include <Keypad.h>
#include<Wire.h>
const byte ROWS = 8; //four rows
const byte COLS = 5; //four columns
int  x = 0;

//outhole = X
//Kickout hole = T
//lower bottom bumper = P
//lower top bumper = A
//upper top bumper = 4
//lower top bumber = J
//sling shot = $
//rails = 8 (worth 10 points)
//S in SHOOTER = #
//H in SHOOTER = R
//1st O in SHOOTER = Z
//2nd O in SHOOTER = F
//T in SHOOTER = B
//E in SHOOTER = N
//R in SHOOTER = 9
//Loop 1 = 7
//Loop 2 = W
//Loop 3 = C
//Loop 4 = H
//Loop 5 = 2
//S in SHARP = 5
//H in SHARP = K
//A in SHARP = D
//R in SHARP = 3
//P in SHARP = I
// 50k lane = &
//Spinner = %
//Special = O
//Extra = S
//Start Game Button = Q
//1k lane = U (1000 points)
//Top Target = Y
//Bottom Target = Y



int sLight = 0;
int hLight = 0;
int o1Light = 0;
int o2Light = 0;
int tLight = 0;
int eLight = 0;
int rLight = 0;

//define the cymbols on the buttons of the keypads
char hexaKeys[COLS][ROWS] = {
  {'1','2','3','4','5', '6','7','8'},
  {'9','A','B','C','D','E','F', 'G'},
  {'H','I','J','K', 'L','M','N','O'},
  {'P','Q','R','S','T','U', 'V','W'},
  {'X','Y','Z','@','#','$','%','&'}
};
byte rowPins[ROWS] = {13, 12, 11, 10, 9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {30, 31, 32, 33, 34}; //connect to the column pinouts of the keypad
 
//initialize an instance of class NewKeypad
Keypad kpd = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
String msg; 
void setup(){
  Wire.begin();
  pinMode(A0, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(48, OUTPUT);
  pinMode(49, OUTPUT);
  pinMode(50, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(52, OUTPUT);
  pinMode(53, OUTPUT);
  //pinMode(30, INPUT_PULLUP);
  //pinMode(31, INPUT_PULLUP);
  //pinMode(32, INPUT_PULLUP);
  //pinMode(33, INPUT_PULLUP);
  //pinMode(34, INPUT_PULLUP);
  msg = "";
  Serial.begin(115200);
 
}



void loop(){
  
  digitalWrite(2, LOW);


  
  digitalWrite(47, LOW); //start game // return ball --whistle sound - white wire
  digitalWrite(48, LOW); //targets - gunshot - red wire
  digitalWrite(49, LOW); //roll over - random buzz - yellow wire
  digitalWrite(50, LOW); //out hole - reach for the sky - blue wire
  digitalWrite(51, LOW); //bumpers - coins - grey
  digitalWrite(52, LOW); //slingshot -richocet sound - black wire
  digitalWrite(53, LOW); //horse-gallop - green wire
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);

  if ((sLight == 1) && (hLight == 1) && (o1Light == 1) && (o2Light == 1) && (tLight == 1) && (eLight == 1) && (rLight == 1)) {
    delay(500);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    delay(200);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
   
    sLight = 0;
    hLight = 0;
    o1Light = 0;
    o2Light = 0;
    tLight = 0;
    eLight = 0;
    rLight = 0;
    
    x = 8;
    Wire.beginTransmission(9); // transmit to device #9
    Wire.write(x);              // sends x 
    Wire.endTransmission();    // stop  transmitting
  }



    if (kpd.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            if ( kpd.key[i].stateChanged )   // Only find keys that have changed state.
            {
                switch (kpd.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                      switch (kpd.key[i].kchar) {


                        case 'P': //lower bottom bumper
                            x = 19;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            digitalWrite(51, HIGH); //bumpers
                            digitalWrite(2, HIGH);
                            digitalWrite(3, LOW);
                            digitalWrite(4, LOW);
                            digitalWrite(5, HIGH);
                            delay(100);
                            break;
                        case 'A': //upper bottom bumper
                            x = 17;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            digitalWrite(51, HIGH); //bumpers
                            digitalWrite(2, HIGH);
                            digitalWrite(4, HIGH);
                            digitalWrite(3, HIGH);
                            digitalWrite(5, HIGH);
                            delay(100);
                            break;
                        case 'J': //lower top bumper
                            x = 18;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            digitalWrite(51, HIGH); //bumpers
                            digitalWrite(2, LOW);
                            digitalWrite(3, LOW);
                            digitalWrite(4, LOW);
                            digitalWrite(5, HIGH);
                            delay(100);
                            break;
                        case '4': //upper top bumper
                            x = 16;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            digitalWrite(51, HIGH); //bumpers
                            digitalWrite(2, HIGH);
                            digitalWrite(3, LOW);
                            digitalWrite(4, LOW);
                            digitalWrite(5, LOW);
                            delay(100);
                            break;
                        case '$': //slingshot
                            x = 26;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            digitalWrite(52, HIGH); //slingshot
                            digitalWrite(2, HIGH);
                            digitalWrite(3, LOW);
                            digitalWrite(4, HIGH);
                            digitalWrite(5, HIGH);
                            delay(100);
                            break;

                        case 'Y': //upper target for bumpers mulitplier
                            x = 34;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            digitalWrite(49, HIGH); //roll over
                            delay(100);
                            break;
                        case '&': //50k points
                            x = 21;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            digitalWrite(49, HIGH); //roll over
                            delay(100);
                            break;
                        case '%': //spinner //horse sound
                            x = 25;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            digitalWrite(53, HIGH); //roll over
                            delay(100);
                            break;
                        case '5': //s in Sharp
                            x = 9;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            digitalWrite(49, HIGH); //roll over
                            delay(100);
                            break;
                        case 'K': //h in Sharp
                            x = 10;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            digitalWrite(49, HIGH); //roll over
                            delay(100);
                            break;
                        case 'D': //a in Sharp
                            x = 11;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            digitalWrite(49, HIGH); //roll over
                            delay(100);
                            break;
                        case '3': //r in Sharp
                            x = 12;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            digitalWrite(49, HIGH); //roll over
                            delay(100);
                            break;
                        case 'I': //p in Sharp
                            x = 13;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            digitalWrite(49, HIGH); //roll over
                            delay(100);
                            break;
                        case 'Q': //start button
                            x = 33;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            delay(100);
                            break;
                        case 'U': // 1k Lane
                            x = 22;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            digitalWrite(49, HIGH); //roll over
                            delay(100);
                            break;
                        case 'S': //xtra ball lane
                            x = 23;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            digitalWrite(49, HIGH); //roll over
                            delay(100);
                            break;
                        case 'O': //special lane
                            x = 24;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            digitalWrite(49, HIGH); //roll over
                            delay(100);
                            break;
                        case '8': //rails
                            x = 32;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            digitalWrite(51, HIGH); //coin sound
                            delay(100);
                            break;
                        case '7': //loop 1
                            x = 27;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            digitalWrite(52, HIGH); //slingshot
                            delay(100);
                            break;
                        case 'W': //loop 2 
                            x = 28;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            digitalWrite(52, HIGH); //slingshot
                            delay(100);
                            break;
                        case 'C': //loop 3
                            x = 29;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            digitalWrite(52, HIGH); //slingshot
                            delay(100);
                            break;
                        case 'H': //loop 4
                            x = 30;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            digitalWrite(52, HIGH); //slingshot
                            delay(100);
                            break;
                        case '2': //loop 5
                            x = 31;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            digitalWrite(52, HIGH); //slingshot
                            delay(100);
                            break;
                        }
                    msg = " PRESSED.";
                break;
                    case HOLD:
 switch (kpd.key[i].kchar) {
                        case 'X': //outhole this is where the ball goes out for the player plunger // start game

                            digitalWrite(A0, HIGH);
                            delay(500);
                            digitalWrite(A0, LOW);
                            delay(3000);
                            digitalWrite(47, HIGH); //start game // return ball --whistle sound
                            //digitalWrite(2, LOW);
                            //digitalWrite(3, HIGH);
                            //digitalWrite(4, LOW);
                            //digitalWrite(5, LOW);
                            delay(100);
                            //digitalWrite(2, LOW);
                            delay(100);
                            x = 14;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            
                            sLight = 0;
                            hLight = 0;
                            o1Light = 0;
                            o2Light = 0;
                            tLight = 0;
                            eLight = 0;
                            rLight = 0;
                            digitalWrite(2, LOW);
                            digitalWrite(3, LOW);
                            digitalWrite(4, HIGH);
                            digitalWrite(5, HIGH);
                            delay(100);
                            break;
                        case '#': //s in shooter
                            x = 1;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            
                            sLight = 1;
                            digitalWrite(48, HIGH); //horse
                            delay(100);
                            break;
                        case 'R': //h in shooter
                            x = 2;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting                                                   
                            hLight = 1;
                            
                            digitalWrite(48, HIGH); //horse
                            delay(100);
                            break;
                        case 'Z': //o in shooter
                            x = 3;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            o1Light = 1;
                            
                            digitalWrite(48, HIGH); //horse
                            delay(100);
                            break;
                            
                        case 'F': //o in shooter
                            x = 4;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            o2Light = 1;
                            
                            digitalWrite(48, HIGH); //horse
                            delay(100);
                            break;
                        case 'B': //t in shooter
                            x = 5;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            tLight = 1;
                            
                            digitalWrite(48, HIGH); //horse
                            delay(100);
                            break;
                        case 'N': //e in shooter
                            x = 6;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            eLight = 1;
                            
                            digitalWrite(48, HIGH); //horse
                            delay(100);
                            break;
                        case '9': //r in shooter
                            x = 7;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            rLight = 1;
                            
                            digitalWrite(48, HIGH); //horse
                            delay(100);
                            break;
                        case 'T': //kick out hole - someone poisoned the water hold
                            x = 15;
                            Wire.beginTransmission(9); // transmit to device #9
                            Wire.write(x);              // sends x 
                            Wire.endTransmission();    // stop  transmitting
                            digitalWrite(50, HIGH); //OUT HOLE
                            delay(2000);
                            digitalWrite(3, HIGH);
                            digitalWrite(4, HIGH);
                            delay(100);
                            break;
 }
                    msg = " HOLD.";
                break;
                    case RELEASED:
                    msg = " RELEASED.";
                break;
                    case IDLE:
                    msg = " IDLE.";
                }
                Serial.print("Key ");
                Serial .print(kpd.key[i].kchar);
                Serial.println(msg);
            }
        }
    }
  
}
