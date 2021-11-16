  // Ed Moriarty / Ashley English,  5-Nov-2021 LED Matrix code

  // 6-Nov-2021 Ed: improved the method of addressing rows and columns, e.g. address the row / col by grid position and not the pin number
  	// We should write functions for enabling and disabling rows and columns rather than using a for loop each time
  // 7-Nov-2021 Ashley: Created random LED blinks, reference rows and columns. 
  // 9-Nov-2021 Ashley: NEED TO insert potentiometer, change brightness of leds? Make LEDs more bright each random iteration?
  // create new index for iterations, copy into Github. 
// 9 Nov-2021 Ed cleaned up some code formatting, 
//               added counters for directions, 
//               fixed mod logic, 
//               replaced AllOff in each loop with just turning on and off the single led


// ***   ASHLEY ... show me how you want to use github for revision control  ***


int animationSpeed = 0;  //"=0" makes LEDs look like they are being pwm'd
int i, ranNum; 
int r = random(5);
int c = random(5);
int north=0, south=0, east=0, west=0;  // for checking fair random distribution 
  
// set the arduino pins associated with rows and columns
const int MAXLROW = 6;
const int MAXLCOL = 6;

const int  lRow[MAXLROW] = {8, 9, 10, 11, 12, 13};  //ASSUMES NORTH (UP) is POSITIVE, origin at bottom right
const int  lCol[MAXLCOL] = {2, 3, 4, 5, 6, 7};      //ASSUMES EAST (RIGHT) IS POSITIVE, origin at bottom right

// define rows,    LOW = enabled,  HIGH = disabled 
// define columns, LOW = disabled, HIGH = enabled
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
  //Turns on LED at specified location   ASHLEY: IT WOULD BE GOOD TO VALIDATE ARGUMENTS
  digitalWrite(lRow[x], ENABLE_LROW);
  digitalWrite(lCol[y], ENABLE_LCOL);
}


void locationOff(int x, int y)
{
  //Turns on LED at specified location   ASHLEY: IT WOULD BE GOOD TO VALIDATE ARGUMENTS
  digitalWrite(lRow[x], DISABLE_LROW);
  digitalWrite(lCol[y], DISABLE_LCOL);
}

void loop()  // *** RANDOM WALK WITH WRAP AROUND ON ALL SIDES  ***
{
  //All off to begin, then on at specified location
//  AllOff();           ASHLEY:  this wasted a lot of cycles (processing time) ... 
//						instead>increment location, enable led, delay, disable
//  locationOn(r,c);
  
  ranNum = random(4);
  
  //North
  if (ranNum == 0)
  {
    r++;                        
    north++;
    //Mod6 (Makes sure we stay in bounds)  ASHLEY: NOTE the format of "if"
    //                            "{ ... }" is a way of grouping a set of commands
    //                               if there is only one command to execute then not needed
    //                             It would be best to use mod operator 
    if      (r>5) r=0;
    else if (r<0) r=5;
  }
  
  //West
  else if (ranNum == 1)
  {
    c++;
    west++;
    //Mod6 
    if      (c>5) c=0;
    else if (c<0) c=5;
  }
  
  //South
  else if (ranNum == 2)
  {
    r = --r %6; 
    r--;
    south++;
    //Mod6 
    if    (r>5) r=0;
  else if (r<0) r=5;
  }
  
  //East
  else if (ranNum == 3)
  {
    c = --c %6; 
    c--;
    east++;
    //Mod6 
    if      (c>5) c=0;
    else if (c<0) c=5;
  }
  
  locationOn(r,c);
  delay(animationSpeed);
  locationOff(r,c);
//  animationSpeed= animationSpeed;
} 

