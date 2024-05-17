// SLAVE CODE
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int x;
int s = 0;
int h = 0;
int o = 0;
int o2 = 0;
int t = 0;
int e = 0;
int r = 0;
int resetTargets = 0;
int Sharp = 0;
int sHarp = 0;
int shArp = 0;
int shaRp = 0;
int sharP = 0;
int multiplier = 1;
int balls = 0;
int gutterBall = 0;
long points = 0;
long highScore = 0;
int startButton = 0;
int loopCount = 0;
int bumperPoints = 100;

void setup(){
Serial.begin(115200);
  // Start the I2C Bus as Slave on address 7
  Wire.begin(9);  
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(29, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(3, OUTPUT); //handles kickout
  // initialize the LCD
  lcd.begin(16,2);

  // Turn on the blacklight
  lcd.setBacklight((uint8_t)1);
  // First row
  lcd.setCursor(0,0);
  lcd.print("Points: ");

  // Second row
  lcd.setCursor(0,1);
  lcd.print("Balls: ");
  points = 0;
  
  }


void  receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the  I2C
 
  }
  

void loop(){
  
  xFactor();

  }


void xFactor(){

  if (x == 1){ //S on SHOOTER
     s = 1;
     x = 0;
     handleShooter();
     points = points + 1000 * multiplier;
     refreshLED(); 
 }

 if (x == 2){ //H on SHOOTER
    h = 1;
    x = 0;
    handleShooter();
    points = points + 1000 * multiplier;
    refreshLED();
 }

 if (x == 3){ //O on SHOOTER
     o = 1;
     x = 0;
     handleShooter();
     points = points + 1000 * multiplier;
     refreshLED(); 
 }


  if (x == 4){ //O on SHOOTER (2nd)
     o2 = 1;
     x = 0;
     handleShooter();
     points = points + 1000 * multiplier;
     refreshLED(); 
 }


   if (x == 5){ //T on SHOOTER
     t = 1;
     x = 0;
     handleShooter();
     points = points + 1000 * multiplier;
     refreshLED(); 
 }
   if (x == 6){ //E on SHOOTER
     e = 1;
     x = 0;
     handleShooter();
     points = points + 1000 * multiplier;
     refreshLED();
 }


    if (x == 7){ //R on SHOOTER
     r = 1;
     x = 0;
     handleShooter();
     points = points + 1000 * multiplier;
     refreshLED(); 
 }
    if (x == 8){ //All targets have been knocked down for SHOOTER
     x = 0;
     s = 0;
     h = 0;
     o = 0;
     o2= 0;
     t = 0;
     e = 0;
     r = 0;
     multiplier = multiplier + 1;
     resetTargets = 1;
     handleShooter();
     refreshLED();  
 }

   if (x == 9){ //S on SHARP
     Sharp = 1;
     x = 0;
     points = points + 1000 * multiplier;
     refreshLED();
     handleSharp();  
 }

   if (x == 10){ //H on SHARP
     sHarp = 1;
     x = 0;
     points = points + 1000 * multiplier;
     refreshLED();
     handleSharp();  
 }

    if (x == 11){ //A on SHARP
     shArp = 1;
     x = 0;
     points = points + 1000 * multiplier;
     refreshLED();
     handleSharp();
 }

    if (x == 12){ //R on SHARP
     shaRp = 1;
     x = 0;
     points = points + 1000 * multiplier;
     refreshLED();
     handleSharp();
 }

    if (x == 13){ //P on SHARP
     sharP = 1;
     x = 0;
     points = points + 1000 * multiplier;
     refreshLED();
     handleSharp();  
 }

    if (x == 14){ //outhole - ball gets kicked out to player
     x = 0;
     gutterBall = 1;
     resetTargets = 1;
     handleGame();  
 }

   if (x == 15){ //Kickout Hole (someone poisoned the waterhole)
     x = 0;
     points = points + 2000 * multiplier;
     multiplier = multiplier + 1;
     refreshLED();
 }

   if (x == 16){ //upper top bumper
     x = 0;
     points = points + bumperPoints * multiplier;
     refreshLED(); 
 }

    if (x == 17){ //upper bottom bumper
     x = 0;
     points = points + bumperPoints * multiplier;
     refreshLED();  
 }

    if (x == 18){ //lower top bumper
     x = 0;
     points = points + bumperPoints * multiplier;
     refreshLED();
 }

    if (x == 19){ //lower bottom bumper
     x = 0;
     points = points + bumperPoints * multiplier;
     refreshLED();
 }

    if (x == 21){ //50k points
     x = 0;
     points = points + 50000 * multiplier;
     refreshLED(); 
 }

   if (x == 22){ //1k lane
     x = 0;
     points = points + 1000 * multiplier;
     refreshLED();  
 }

   if (x == 23){ //xtra ball lane
     x = 0;
     points = points + 1000 * multiplier;
     refreshLED(); 
 }

   if (x == 24){ //special roll over
     x = 0;
     points = points + 1000 * multiplier;
     refreshLED();
 }

    if (x == 25){ //horse
     x = 0;
     points = points + 100 * multiplier;
     refreshLED();  
 }

    if (x == 26){ //slingshot
     x = 0;
     points = points + 100 * multiplier;
     refreshLED(); 
 }

   if (x == 27){ //loop 1
     x = 0;
     points = points + 100 * multiplier;
     refreshLED();
 }

     if (x == 28){ //loop 2
     x = 0;
     points = points + 100 * multiplier;
     refreshLED(); 
 }

     if (x == 29){ //loop 3
     x = 0;
     points = points + 100 * multiplier;
     refreshLED(); 
 }

     if (x == 30){ //loop 4
     x = 0;
     points = points + 100 * multiplier;
     refreshLED();  
 }

     if (x == 31){ //loop 5
     x = 0;
     points = points + 100 * multiplier;
     refreshLED();
 }

     if (x == 32){ //rails
     x = 0;
     points = points + 10 * multiplier;
     refreshLED();
 }


    if (x == 33){ //startButton
     x = 0;
     startButton = 1;
     handleGame();
 }

     if (x == 34){ //bumper multiplier
     bumperPoints = 1000;
     digitalWrite(34, HIGH);
     digitalWrite(35, HIGH);
     x = 0;
  
 }
  
  
  
  }

void refreshLED(){
     lcd.clear();
     // First row
     lcd.setCursor(0,0);
     lcd.print("Points: " + String(points));
    
     // Second row
     lcd.setCursor(0,1);
     lcd.print("Balls:" + String(balls) + " Multi:" + String(multiplier));  

  }

void handleShooter(){

 if (s == 1){
     digitalWrite(27, HIGH);
 }
 if (s == 0) {
     digitalWrite(27, LOW);
 }
 if (h == 1){
     digitalWrite(30, HIGH);
 }
 if (h == 0) {
     digitalWrite(30, LOW);
 }
 if (o == 1){
     digitalWrite(28, HIGH);
 }
 if (o == 0) {
     digitalWrite(28, LOW);
 }
 if (o2 == 1){
     digitalWrite(26, HIGH);
 }
 if (o2 == 0) {
     digitalWrite(26, LOW); 
 }
 if (t == 1){
     digitalWrite(33, HIGH);
 }
 if (t == 0) {
      digitalWrite(33, LOW);
 }
 if (e == 1){
     digitalWrite(29, HIGH);
 }
 if (e == 0) {
     digitalWrite(29, LOW);
 }
 if (r == 1){
     digitalWrite(24, HIGH);
 }
 if (r == 0) {
     digitalWrite(24, LOW);
 }

}

void handleSharp(){
 if ((Sharp == 1) && (sHarp == 1) && (shArp == 1) && (shaRp == 1) && (sharP == 1)) {
   balls = balls + 1;
   multiplier = multiplier + 1;
   Sharp = 0;
   sHarp = 0;
   shArp = 0;
   shaRp = 0;
   sharP = 0;
   refreshLED();   
  }
 if (Sharp == 1){
     digitalWrite(23, HIGH);
 }
 if (Sharp == 0) {
     digitalWrite(23, LOW);
 }
 if (sHarp == 1){
     digitalWrite(32  , HIGH);
 }
 if (sHarp == 0) {
     digitalWrite(32, LOW);
 }
 if (shArp == 1){
     digitalWrite(25, HIGH);
 }
 if (shArp == 0){
     digitalWrite(25, LOW);
 }
  if (shaRp == 1){
     digitalWrite(22, HIGH);
 }
 if (shaRp == 0){
     digitalWrite(22, LOW);
 }
 if (sharP == 1){
     digitalWrite(36, HIGH);
 }
 if (sharP == 0){
     digitalWrite(36, LOW);
 }


 
}


void handleGame(){
   if (startButton == 1 && balls == 0) {
     gutterBall = 0;
     points = 0;
     balls = 2;
     bumperPoints = 100;
     multiplier = 1;
     delay(1000);
     digitalWrite(3, HIGH);
     delay(100);
     digitalWrite(3, LOW);
     startButton = 0;
     refreshLED();
 }
    if (startButton == 1 && balls > 0){
     startButton = 0;
     lcd.setCursor(0,1);
     lcd.print("Game on mfer");
        
 }
  if (gutterBall == 1 && balls > 0){
     s = 0;
     h = 0;
     o = 0;
     o2 = 0;
     t = 0;
     e = 0;
     r = 0;
     handleShooter();
     delay(1000);
     digitalWrite(3, HIGH);
     delay(100);
     digitalWrite(3, LOW);
     delay(500);
     gutterBall = 0;
     balls = balls - 1;
     refreshLED();
  
  }

 if (gutterBall == 1 && balls == 0){
     refreshLED();
     s = 0;
     h = 0;
     o = 0;
     o2 = 0;
     t = 0;
     e = 0;
     r = 0;
     Sharp = 0;
     sHarp = 0;
     shArp = 0;
     shaRp = 0;
     sharP = 0;
     digitalWrite(34, LOW);
     digitalWrite(35, LOW);
     bumperPoints = 100;
     handleShooter();
     handleSharp();
     if (points > highScore || points == highScore){
       highScore = points;
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Points: " + String(points));
       lcd.setCursor(0,1);
       lcd.print("New High Score!!!");
       //delay(2000);
       gutterBall = 0;
      }
    if (points < highScore){
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Points: " + String(points));
       lcd.setCursor(0,1);
       //lcd.print("Not high score");
       //delay(2000);
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Points: " + String(points));
       lcd.setCursor(0,1);
       lcd.print("HiScore:" +String(highScore));
       //delay(2000);
       gutterBall = 0;           
     }
    }
  
  }
