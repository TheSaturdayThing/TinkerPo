 // Ashley English,  1-Jan-2022 LED Matrix Random Walk, left half board

int animationSpeed = 5;  //"=0" makes LEDs look like they are being pwm'd
int i, ranNum; 
int r = random(7);
int c = random(15);
int north=0, south=0, east=0, west=0;  // for checking fair random distribution 
  
// set the arduino pins associated with rows and columns
const int MAXLROW = 8;
const int MAXLCOL = 16;
const int  lRow[MAXLROW] = {A15, A14, A13, A12, A11, A10, A9, A8};  //ASSUMES NORTH (UP) is POSITIVE, origin at bottom right
const int  lCol[MAXLCOL] = {52, 50, 48, 46, 44, 42, 40, 38, 39, 41, 43, 45, 47, 49, 51, 53} ;      //ASSUMES EAST (RIGHT) IS POSITIVE, origin at bottom right
// define rows,    LOW = enabled,  HIGH = disabled 
// define columns, LOW = disabled, HIGH = enabled
#define ENABLE_LROW HIGH
#define ENABLE_LCOL LOW
#define DISABLE_LROW LOW
#define DISABLE_LCOL HIGH
void setup()
{
  // set led matrix row and column pins as OUTPUT
  for (i=0; i<MAXLROW; i++) {
    pinMode(lRow[i], OUTPUT);
  }
  for (i=0; i<MAXLCOL; i++) {
    pinMode(lCol[i], OUTPUT);
  }
  
 // initialize the matrix to be completely 'OFF'
  for (i=0; i<MAXLROW; i++) {
     digitalWrite(lRow[i], DISABLE_LROW);
  }
  for (i=0; i<MAXLCOL; i++) {
     digitalWrite(lCol[i], DISABLE_LCOL);
  }
  
  randomSeed(analogRead(0));
  Serial.begin(9600);
  AllOff();
}
void AllOff()
{
  //All rows off
  for(i = 0; i<MAXLROW; i++) digitalWrite(lRow[i], DISABLE_LROW);
  //All columns off
  for(i = 0; i<MAXLCOL; i++) digitalWrite(lCol[i], DISABLE_LCOL);
}
void locationOn(int x, int y)
{
  //Turns on LED at specified location   
  digitalWrite(lRow[x], ENABLE_LROW);
  digitalWrite(lCol[y], ENABLE_LCOL);
}
void locationOff(int x, int y)
{
  //Turns on LED at specified location   
  digitalWrite(lRow[x], DISABLE_LROW);
  digitalWrite(lCol[y], DISABLE_LCOL);
}
void loop()  // *** RANDOM WALK WITH WRAP AROUND ON ALL SIDES  ***
{
//  This wasted a lot of cycles (processing time) ... 
//  instead>increment location, enable led, delay, disable
//  locationOn(r,c);
  
  ranNum = random(4);
  
  //North
  if (ranNum == 0)
  {
    r++; 
    r = r %16;                    
    north++;
    if      (r>7) r=0;
    else if (r<0) r=7;
  }
  
  //West
  else if (ranNum == 1)
  {
    c++;
    c = c %16; 
    west++;
    if      (c>15) c=0;
    else if (c<0) c=15;
  }
  
  //South
  else if (ranNum == 2)
  {
    r--;
    r = r %16; 
    south++;
    if    (r>7) r=0;
    else if (r<0) r=7;
  }
  
  //East
  else if (ranNum == 3)
  {
    c--;
    c = c %16; 
    east++;
    if      (c>15) c=0;
    else if (c<0) c=15;
  }
  
  locationOn(r,c);
  delay(animationSpeed);
  locationOff(r,c);
} 
