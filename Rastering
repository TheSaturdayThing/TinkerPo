// Ed Moriarty / Ashley English,  5-Nov-2021 LED Matrix code

// 6-Nov-2021 Ed: improved the method of addressing rows and columns
//     e.g. address the row / col by grid position and not the pin number

// Need to write functions for enabling and disabling rows and columns rather than using a for loop each time
// 7-Nov-2021 Rev 1 creating random light up

int animationSpeed = 1;
int i, j;

// set the arduino pins associated with rows and columns
const int MAXLROW = 6;
const int MAXLCOL = 6;

const int  lRow[MAXLROW] = {13, 12, 11, 10, 9, 8};
const int  lCol[MAXLCOL] = {7, 6, 5, 4, 3, 2}; 

#define ENABLE_LROW LOW
#define ENABLE_LCOL HIGH

#define DISABLE_LROW HIGH
#define DISABLE_LCOL LOW

void setup()
{
/*
// define rows, LOW = enabled, HIGH = disabled 
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  
  
// define columns, HIGH = enabled, LOW = disabled, 
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  
  for (iRow=8; iRow<=13; iCol++) {
     digitalWrite(iRow, LOW);

  for (iCol=2; iCol<=7; iCol++) {
     digitalWrite(iCol, LOW);
  }
  }
*/
    
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
  

}
void loop()
{
  // loop through all rows
    // foreach row
      // enable and then disable each column one at a time sequentially
      // disable the row
/*
  for (iRow=13; iRow>=8; iRow--) {
    for (iCol=7; iCol>=2; iCol--) {
      digitalWrite(iCol, HIGH);
      digitalWrite(iRow, LOW);
      delay(animationSpeed); // Wait for animationSpeed millisecond(s)
      digitalWrite(iRow, HIGH);
      digitalWrite(iCol, LOW);
    }
  }
 */
  
  for (i=0; i<MAXLROW; i++) {
    digitalWrite(lRow[i], ENABLE_LROW);

    for(j=0; j<MAXLCOL; j++) {
      digitalWrite(lCol[j], ENABLE_LCOL);
      delay(animationSpeed);
    }
    for(j=0; j<MAXLCOL; j++) {
      digitalWrite(lCol[j], DISABLE_LCOL);
    }
    
    digitalWrite(lRow[i], DISABLE_LROW);
  }
    
  // Cause the speed to get slower and slower
  animationSpeed = animationSpeed+i; 
}
