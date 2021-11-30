//library for led matrix
#include <LedControl.h>

//Button States
int buttonStateRight = 0;
int buttonStateLeft = 0;
int buttonStateUp = 0;
int buttonStateDown = 0;
int buttonStateConfirm = 0;
//Button Pins
int moveLeftPin = 3;
int moveRightPin = 2;
int moveUpPin = 4;
int moveDownPin = 5;
int confirmPin = 6;
//LED matrix pins
int DIN = 12;
int CS =  11;
int CLK = 10;
const int buzzer = 9;

LedControl lc = LedControl(DIN, CLK, CS);

//byte array of the led matrix
byte G[8] = {0x7E, 0x7E, 0x60, 0x60, 0x6E, 0x66, 0x7E, 0x7E};
byte O[8] = {B00111100, B01111110, B01100110, B01100110, B01100110, B01100110, B01111110, B00111100};

//byte array of the led matrix hex form
byte intro[8] = {0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA};
byte intro2[8] = {0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55};
byte all[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

//byte array of the led matrix
byte m[8] = {0xE7, 0xFF, 0xFF, 0xDB, 0xDB, 0xDB, 0xC3, 0xC3};
byte mphase[8] = {0xCE, 0xFE, 0xFE, 0xB2, 0xB2, 0xB2, 0x82, 0x82};
byte mphase2[8] = {0x9C, 0xFC, 0xFC, 0x6C, 0x6C, 0x6C, 0x0C, 0x0C};
byte mphase3[8] = {0x38, 0xF8, 0xF8, 0xD8, 0xD8, 0xD8, 0x18, 0x18};
byte mphase4[8] = {0x70, 0xF0, 0xF0, 0xB0, 0xB0, 0xB0, 0x30, 0x30};
byte mphase5[8] = {0xE3, 0xE3, 0xE3, 0x63, 0x63, 0x63, 0x63, 0x63};
byte mphase6[8] = {0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6};
byte mphase7[8] = {0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C};

//byte array of the led matrix binary form
byte h[8] = {B01100110, B01100110, B01100110, B01111110, B01111110, B01100110, B01100110, B01100110};
byte hleft[8] = {B11001100, B11001100, B11001100, B11111100, B11111100, B11001100, B11001100, B11001100};
byte hleft2[8] = {B10011001, B10011001, B10011001, B11111001, B11111001, B10011001, B10011001, B10011001};
byte hleft3[8] = {B00110011, B00110011, B00110011, B11110011, B11110011, B00110011, B00110011, B00110011};
byte hleft4[8] = {B01100110, B01100110, B01100110, B11100110, B11100110, B01100110, B01100110, B01100110};
byte hleft5[8] = {B11001100, B11001100, B11001100, B11001100, B11001100, B11001100, B11001100, B11001100};
byte hleft6[8] = {B10011001, B10011001, B10011000, B10011000, B10011000, B10011000, B10011000, B10011000};
byte hleft7[8] = {B00110011, B00110011, B00110000, B00110000, B00110000, B00110000, B00110000, B00110000};
byte hleft8[8] = {B01100111, B01100111, B01100001, B01100001, B01100001, B01100001, B01100001, B01100001};
byte hleft9[8] = {B11001111, B11001111, B11000011, B11000011, B11000011, B11000011, B11000011, B11000011};
byte hleft10[8] = {B10011111, B10011111, B10000110, B10000110, B10000110, B10000110, B10000110, B10000110};
byte hleft11[8] = {B00111111, B00111111, B00001100, B00001100, B00001100, B00001100, B00001100, B00001100};
byte hleft12[8] = {B01111110, B01111110, B00011000, B00011000, B00011000, B00011000, B00011000, B00011000};

//all leds off
byte off[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

//moving leds
byte iphase[8] = {0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18};
byte iphase1[8] = {0x30, 0x31, 0x31, 0x31, 0x30, 0x30, 0x30, 0x31};
byte iphase2[8] = {0x61, 0x63, 0x63, 0x63, 0x61, 0x60, 0x61, 0x63};
byte iphase3[8] = {0xC3, 0xC7, 0xC6, 0xC7, 0xC3, 0xC0, 0xC3, 0xC7};
byte iphase4[8] = {0x87, 0x8F, 0x8C, 0x8F, 0x87, 0x80, 0x87, 0x8F};

byte sphase[8] = {0x0F, 0x1F, 0x18, 0x1F, 0x0F, 0x01, 0x0F, 0x1F};
byte sphase1[8] = {0x1F, 0x3E, 0x30, 0x3E, 0x1F, 0x03, 0x1F, 0x3E};
byte sphase2[8] = {0x3E, 0x7C, 0x60, 0x7C, 0x3E, 0x06, 0x3E, 0x7C};
byte sphase3[8] = {0x7C, 0xF8, 0xC0, 0xF8, 0x7C, 0x0C, 0x7C, 0xF8};
byte sphase4[8] = {0x78, 0xF0, 0x80, 0xF0, 0xF8, 0x18, 0xF8, 0xF0};
byte sphase5[8] = {0xF0, 0xE1, 0x01, 0xE1, 0xF0, 0x30, 0xF0, 0xE1};
byte sphase6[8] = {0xE1, 0xC3, 0x03, 0x81, 0xE0, 0x60, 0xE1, 0xC3};
byte sphase7[8] = {0xC3, 0x87, 0x06, 0x07, 0x83, 0xC0, 0xC3, 0x87};
byte sphase8[8] = {0x87, 0x0F, 0x0C, 0x0F, 0x07, 0x80, 0x87, 0x0F};
byte cross[8] = {B00000000, B01000010, B00100100, B00011000, B00011000, B00100100, B01000010, B00000000};
byte skull[8] = {B01111110, B11111111, B10011001, B10011001, B11100111, B01100110, B00111100, B00100100};
byte winner[8] = {0x00, 0x66, 0xFF, 0xFF, 0xFF, 0x7E, 0x3C, 0x18};

const int ship_Size = 4;

//random x and y values
int randX[ship_Size];
int randY[ship_Size];
int randNumberH;
int randNumberV;
int directionRand;
//random direction change from horizontal or vertical
//place holder for each ship x and y coords
int pos1x;
int pos1y;
int pos2x;
int pos2y;
int pos3x;
int pos3y;
int pos4x;
int pos4y;

//current x and y
int x = 0;
int y = 0;
//guess states
boolean guess1 = true;
boolean guess2 = true;
boolean guess3 = true;
boolean guess4 = true;
//user lives
int lives = 10;


void setup()
{
  //serial monitor
  Serial.begin(9600);

  randomSeed(analogRead(0));

  //inputs
  pinMode(moveLeftPin, INPUT);
  pinMode(moveRightPin, INPUT);
  pinMode(moveUpPin, INPUT);
  pinMode(moveDownPin, INPUT);
  pinMode(confirmPin, INPUT);
  pinMode(buzzer, OUTPUT);

  //The  matrix is in power-saving mode on startup
  lc.shutdown(0, false);
  //led brightness
  lc.setIntensity(0, 10);

  //start game
  introScreen();

  //testing values
  for (int i = 0; i <= 3; i++)
  {
    Serial.println("X");
    Serial.println(randX[i]);
    Serial.println("Y");
    Serial.println(randY[i]);
  }
}

void loop()
{
  //reading button states
  buttonStateRight = digitalRead(moveRightPin);
  buttonStateLeft = digitalRead(moveLeftPin);
  buttonStateUp = digitalRead(moveUpPin);
  buttonStateDown = digitalRead(moveDownPin);
  buttonStateConfirm = digitalRead(confirmPin);

  //start position
  lc.setLed(0, y, x, HIGH);

  //function calls
  pressed();
  checkHit();
  hitmark();
  win();
  death();
}

//using byte array to assign the leds to the led matrix
void printByte(byte character [])
{
  int i = 0;
  for (i = 0; i < 8; i++)
  {
    lc.setRow(0, i, character[i]);
  }
}


//assigns random consecutive coordinates on the grid
void randomShip()
{
  //random x and y coords between the dimensions
  randNumberH = random(8);
  randNumberV = random(8);

  //checks if the last x/y value of ship exceeds the limit. then decreases the start position by the amount it exceeds.
  if ((randNumberH + 3) > 7)
  {
    int range = (randNumberH + 3) - 7;
    randNumberH = randNumberH - range;
  }

  if ((randNumberV + 3) > 7)
  {
    int range = (randNumberV + 3) - 7;
    randNumberV = randNumberV - range;
  }

  Serial.println("Direction 0 is Horizontal 1 is Vertical: ");
  //if directionRand is 0 changes the x values if 1, changes y values
  directionRand = random(2);
  Serial.println(directionRand);

  //assigns the values in the array
  for (int i = 0; i <= 3; i++)
  {
    randY[i] = randNumberV;
    randX[i] = randNumberH;

    if (directionRand == 0)
    {
      randNumberH = randNumberH + 1;
    }
    else
    {
      randNumberV = randNumberV + 1;
    }
  }
}

//checks if the current x value is equal to the random value.
void checkHit()
{
  if (buttonStateConfirm == LOW)
  {
    audio(0);
    //if the random value and current value are equal then the random value will have a -1 so its out of the dimension of the led matrix
    if (randX[0] == x && randY[0] == y)
    {
      hit();
      pos1x = x;
      pos1y = y;
      randX[0] = -1;
      randY[0] = -1;
      guess1 = false;
    }
    else if (randX[1] == x && randY[1] == y)
    {
      hit();
      pos2x = x;
      pos2y = y;
      randX[1] = -1;
      randY[1] = -1;
      guess2 = false;
    }

    else if (randX[2] == x && randY[2] == y)
    {
      hit();
      pos3x = x;
      pos3y = y;
      randX[2] = -1;
      randY[2] = -1;
      guess3 = false;
    }

    else if (randX[3] == x && randY[3] == y)
    {
      hit();
      pos4x = x;
      pos4y = y;
      randX[3] = -1;
      randY[3] = -1;
      guess4 = false;
    }

    else
    {
      //makes it so the user does not guess their previous guess again. so no action is made.
      if (pos1x == x && pos1y == y && guess1 == false)
      {
        return;
      }
      if (pos2x == x && pos2y == y && guess2 == false)
      {
        return;
      }
      if (pos3x == x && pos3y == y && guess3 == false)
      {
        return;
      }
      if (pos4x == x && pos4y == y && guess4 == false)
      {
        return;
      }
      //incorrect choice lives lost
      else
      {
        miss();
        lives--;
        Serial.println("Current Lives: ");
        Serial.print(lives);
      }
    }
  }
}

//keep the led on when the led is hit
void hitmark()
{
  if (randX[0] == -1 && randY[0] == -1)
  {
    lc.setLed(0, pos1y, pos1x, true);
  }
  if (randX[1] == -1 && randY[1] == -1)
  {
    lc.setLed(0, pos2y, pos2x, true);
  }
  if (randX[2] == -1 && randY[2] == -1)
  {
    lc.setLed(0, pos3y, pos3x, true);
  }
  if (randX[3] == -1 && randY[3] == -1)
  {
    lc.setLed(0, pos4y, pos4x, true);
  }
}

//player wins if all the guesses are false meaning they have all been guessed
void win()
{
  if (guess1 == false && guess2 == false && guess3 == false && guess4 == false && lives != 0)
  {
    for (int i = 0; i <= 5; i++)
    {
      printByte(winner);
      audio(2);
      delay(120);
      printByte(off);
      delay(200);
    }
    lc.clearDisplay(0);
  }
}

//death screen when all lives lost
void death()
{
  if (lives == 0)
  {
    Serial.println("GAME OVER");
    for (int i = 0; i <= 5; i++)
    {
      printByte(skull);
      audio(2);
      delay(120);
      printByte(off);
      delay(200);
    }
    lc.clearDisplay(0);
  }
}

//navigation through the led matrix. led turns on when the button pressed and previous is turned off
void pressed()
{
  //move right
  if (buttonStateRight == LOW)
  {
    audio(0);
    x = x + 1;
    lc.setLed(0, y, x, HIGH);
    lc.setLed(0, y, x - 1, LOW);
    delay(250);
    if (x > 7)
    {
      lc.setLed(0, y, x, LOW);
      lc.setLed(0, y, 0, HIGH);
      x = 0;
    }
  }

  //move left
  if (buttonStateLeft == LOW)
  {
    audio(0);
    lc.setLed(0, y, x, LOW);
    x = x - 1;
    lc.setLed(0, y, x, HIGH);
    delay(250);

    if (x < 0)
    {
      lc.setLed(0, y, 0, LOW);
      lc.setLed(0, y, 7, HIGH);
      x = 7;
    }
  }

  //move down
  if (buttonStateDown == LOW)
  {
    audio(0);
    y++;
    lc.setLed(0, y, x, HIGH);
    lc.setLed(0, y - 1, x, LOW);
    delay(250);

    if (y > 7)
    {
      audio(0);
      lc.setLed(0, y, x, LOW);
      lc.setLed(0, 0, x, HIGH);
      y = 0;
    }
  }

  //move up
  if (buttonStateUp == LOW)
  {
    audio(0);
    lc.setLed(0, y, x, LOW);
    y = y - 1;
    lc.setLed(0, y, x, HIGH);
    delay(250);

    if (y < 0)
    {
      lc.setLed(0, y, x, LOW);
      lc.setLed(0, 7, x, HIGH);
      y = 7;
    }
  }
}

//leds when the program starts
void introScreen()
{
  printByte(intro);
  delay(500);
  printByte(intro2);
  delay(500);
  printByte(intro);
  delay(500);
  printByte(G);
  delay(500);
  printByte(O);
  delay(500);
  printByte(all);
  delay(500);
  lc.clearDisplay(0);
  randomShip();
}

//hit text sliding
void hit()
{
  printByte(h);
  delay(100);
  printByte(hleft);
  delay(60);
  printByte(hleft2);
  delay(60);
  printByte(hleft3);
  delay(60);
  printByte(hleft4);
  delay(60);
  printByte(hleft5);
  delay(60);
  printByte(hleft6);
  delay(60);
  printByte(hleft7);
  delay(60);
  printByte(hleft8);
  delay(60);
  printByte(hleft9);
  delay(60);
  printByte(hleft10);
  delay(60);
  printByte(hleft11);
  delay(60);
  printByte(hleft12);
  delay(100);
  for (int i = 0; i < 8; i++)
  {
    printByte(all);
    audio(0);
    delay(60);
    printByte(off);
    delay(100);
  }
}

//miss text sliding `
void miss()
{
  printByte(off);
  printByte(m);
  delay(100);
  printByte(mphase);
  delay(60);
  printByte(mphase2);
  delay(60);
  printByte(mphase3);
  delay(60);
  printByte(mphase4);
  delay(60);
  printByte(mphase5);
  delay(60);
  printByte(mphase6);
  delay(60);
  printByte(mphase7);
  delay(60);
  printByte(iphase);
  delay(60);
  printByte(iphase1);
  delay(60);
  printByte(iphase2);
  delay(60);
  printByte(iphase3);
  delay(60);
  printByte(iphase4);
  delay(60);
  printByte(sphase);
  delay(60);
  printByte(sphase1);
  delay(60);
  printByte(sphase2);
  delay(60);
  printByte(sphase3);
  delay(60);
  printByte(sphase4);
  delay(60);
  printByte(sphase5);
  delay(60);
  printByte(sphase6);
  delay(60);
  printByte(sphase7);
  delay(60);
  printByte(sphase8);
  delay(60);
  printByte(sphase);
  delay(60);
  printByte(sphase1);
  delay(60);
  printByte(sphase2);
  delay(60);
  printByte(sphase3);
  delay(60);
  printByte(sphase4);
  delay(60);
  printByte(sphase6);
  delay(60);
  for (int i = 0; i < 8; i++)
  {
    printByte(cross);
    audio(0);
    delay(60);
    printByte(off);
    delay(100);
  }
}

//audio for each action
void audio(int x)
{
  for (int i = 0; i <= x; i++)
  {
    tone(buzzer, 500);
    delay(20);
    noTone(buzzer);
    delay(20);
  }
}
