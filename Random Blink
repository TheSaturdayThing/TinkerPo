// Ed Moriarty / Ashley English,  5-Nov-2021 LED Matrix code

  // 6-Nov-2021 Ed: improved the method of addressing rows and columns, e.g. address the row / col by grid position and not the pin number
  // We should write functions for enabling and disabling rows and columns rather than using a for loop each time

int animationSpeed = 1;
int i, ranNum;
int r = 13;
int c = 7;

  
  // set the arduino pins associated with rows and columns
const int MAXLROW = 6;
const int MAXLCOL = 6;

const int  lRow[MAXLROW] = {13, 12, 11, 10, 9, 8};
const int  lCol[MAXLCOL] = {7, 6, 5, 4, 3, 2}; 

  // define rows, LOW = enabled, HIGH = disabled 
  // define columns, LOW = DISABLED, HIGH = enabled
#define ENABLE_LROW LOW
#define ENABLE_LCOL HIGH

#define DISABLE_LROW HIGH
#define DISABLE_LCOL LOW


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
  
}


void AllOff()
{
  //All rows off
  for(i = 0; i<MAXLROW; i++)
  {
    digitalWrite(lRow[i], HIGH);
  }
  //All columns off
  for(i = 0; i<MAXLCOL; i++)
  {
    digitalWrite(lCol[i], LOW);
  }
}


void locationOn(int x, int y)
{
  //Turns on LED at specified location
  digitalWrite(x, LOW);
  digitalWrite(y, HIGH);
}


void loop()
{
  //All off to begin, then on at specified location
  AllOff();
  locationOn(r,c);
  ranNum = random(4);
  
  //North
  if (ranNum == 0)
  {
    r++;
    //Mod8 (Makes sure we stay in bounds)
    if (r > 13)
    {
      r = 8;
    }
  }
  
  //West
  else if (ranNum == 1)
  {
    c++;
    //Mod8 
    if (c > 7)
    {
      c = 2;
    }
  }
  
  //South
  else if (ranNum == 2)
  {
    r--;
    //Mod8 
    if (r < 8)
    {
      r = 13;
    }
  }
  
  //East
  else
  {
    c--;
    //Mod8 
    if (c < 2)
    {
      c = 7;
    }
  }
  
  delay(animationSpeed);
  animationSpeed= animationSpeed+10; 
} 
