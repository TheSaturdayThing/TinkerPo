#include "mxapi.h"
#include "string.h" // This has strlen(), which is called in DisplayString().

#define dRIGHT 0
#define dLEFT 1
#define dRV_ON 1
#define dRV_OFF 0
#define dON 1
#define dOFF 0

unsigned char* GetChar(char c);
unsigned char dBar(unsigned char n);
unsigned char dDot(unsigned char n);

// You wrote this.
// I didn't modify it in any way.
void DisplayColumn (ColNum, ColZero, ColValue, RevVideo, NumFlash, FlashDuration, BlanksPerFlash)
  unsigned char ColNum;  // will be converted to Mod16, identifies column to be displayed       
  unsigned char ColZero; // =0 if ColNum(0) is rightmost on display, =1 if leftmost             
  unsigned char ColValue; // 8 bits, nth bit=1 enables nth row, LSB=>row0=>bottom of display    
  unsigned char RevVideo; // if true, flips meaning of ColValue ... nth bit=1 disables nth row  
  unsigned NumFlash; // Number of times the control loop is run to display the column           
  unsigned FlashDuration; // number of milliseconds to keep column displayed                    
  unsigned BlanksPerFlash; // for pwm brightness control,                                       
{
  unsigned char ModColNum;  // The ColNum arg is converted to Mod 16, just in case                 
  unsigned char ColDisplay; // Actual pin values to be displayed                                   
  int i;
  
  ModColNum = ColNum % 16;
  if (ColZero == dLEFT) ModColNum = 15 - ModColNum;
  PORTD = (1<<ModColNum)     ; // right hand side of board (LSB)                                   
  PORTB = (1<<ModColNum) >> 8; // shift 8 bits to right to show left hand side of board (MSB)      
  
  if (RevVideo) ColDisplay = ColValue;
  else ColDisplay = ~ColValue;
  
  for (i=0; i<NumFlash; i++) {
    PORTA = ColDisplay & 0b00111111;  // clear top 2 bits                                         
    PORTE = ColDisplay >> 6 & 0b00000011; // shift to high order then clear low 6                 
    delay_ms(FlashDuration);
    PORTA = 0b11111111;
    PORTE = 0b11111111;
    delay_ms(FlashDuration*BlanksPerFlash);
    if (FlashDuration == 0) delay_ms(BlanksPerFlash);
  }
}

// Stores data for a font.
// The bitmaps are stored in the code, so they don't eat into variable space.
// The first element of the array is the width of the character.
// The rest of the array contains the column data.
// A character bitmap can have a maximum width of 7 and a maximum height of 8.
unsigned char* GetChar(char c) {
  unsigned char arr[8];
  switch (c) {
    case 'A':
      arr[0] = 6;
      arr[6] = 0b00011111;
      arr[5] = 0b00111111;
      arr[4] = 0b00100100;
      arr[3] = 0b00100100;
      arr[2] = 0b00111111;
      arr[1] = 0b00011111;
      break;
    case 'D':
      arr[0] = 6;
      arr[6] = 0b00011110;
      arr[5] = 0b00111111;
      arr[4] = 0b00100001;
      arr[3] = 0b00100001;
      arr[2] = 0b00111111;
      arr[1] = 0b00111111;
      break;
    case 'E':
      arr[0] = 6;
      arr[6] = 0b00100001;
      arr[5] = 0b00101001;
      arr[4] = 0b00101001;
      arr[3] = 0b00101001;
      arr[2] = 0b00111111;
      arr[1] = 0b00111111;
      break;
    case 'H':
      arr[0] = 6;
      arr[6] = 0b00111111;
      arr[5] = 0b00111111;
      arr[4] = 0b00001000;
      arr[3] = 0b00001000;
      arr[2] = 0b00111111;
      arr[1] = 0b00111111;
      break;
    case 'I':
      arr[0] = 4;
      arr[4] = 0b00100001;
      arr[3] = 0b00111111;
      arr[2] = 0b00111111;
      arr[1] = 0b00100001;
      break;
    case 'M':
      arr[0] = 7;
      arr[7] = 0b00111111;
      arr[6] = 0b00111111;
      arr[5] = 0b00110000;
      arr[4] = 0b00011000;
      arr[3] = 0b00110000;
      arr[2] = 0b00111111;
      arr[1] = 0b00111111;
      break;
    case 'N':
      arr[0] = 6;
      arr[6] = 0b00111111;
      arr[5] = 0b00111111;
      arr[4] = 0b00001100;
      arr[3] = 0b00011000;
      arr[2] = 0b00111111;
      arr[1] = 0b00111111;
      break;
    case 'R':
      arr[0] = 6;
      arr[6] = 0b00011011;
      arr[5] = 0b00111111;
      arr[4] = 0b00100100;
      arr[3] = 0b00100100;
      arr[2] = 0b00111111;
      arr[1] = 0b00111111;
      break;
    case '0':
      arr[0] = 6;
      arr[6] = 0b00011110;
      arr[5] = 0b00111111;
      arr[4] = 0b00100001;
      arr[3] = 0b00100001;
      arr[2] = 0b00111111;
      arr[1] = 0b00011110;
      break;
    case '1':
      arr[0] = 3;
      arr[3] = 0b00111111;
      arr[2] = 0b00111111;
      arr[1] = 0b00010000;
      break;
    case '2':
      arr[0] = 6;
      arr[6] = 0b00010001;
      arr[5] = 0b00111001;
      arr[4] = 0b00101101;
      arr[3] = 0b00100111;
      arr[2] = 0b00110011;
      arr[1] = 0b00010001;
      break;
    case '3':
      arr[0] = 6;
      arr[6] = 0b00010110;
      arr[5] = 0b00111111;
      arr[4] = 0b00101001;
      arr[3] = 0b00101001;
      arr[2] = 0b00100001;
      arr[1] = 0b00100001;
      break;
    case '4':
      arr[0] = 6;
      arr[6] = 0b00111111;
      arr[5] = 0b00111111;
      arr[4] = 0b00000100;
      arr[3] = 0b00110100;
      arr[2] = 0b00111100;
      arr[1] = 0b00001100;
      break;
    case '5':
      arr[0] = 6;
      arr[6] = 0b00100110;
      arr[5] = 0b00101111;
      arr[4] = 0b00101001;
      arr[3] = 0b00101001;
      arr[2] = 0b00111001;
      arr[1] = 0b00111001;
      break;
    case '6':
      arr[0] = 6;
      arr[6] = 0b00000110;
      arr[5] = 0b00101111;
      arr[4] = 0b00101001;
      arr[3] = 0b00101001;
      arr[2] = 0b00111111;
      arr[1] = 0b00011110;
      break;
    case '7':
      arr[0] = 6;
      arr[6] = 0b00110000;
      arr[5] = 0b00111000;
      arr[4] = 0b00101100;
      arr[3] = 0b00100111;
      arr[2] = 0b00100011;
      arr[1] = 0b00100000;
      break;
    case '8':
      arr[0] = 6;
      arr[6] = 0b00010110;
      arr[5] = 0b00111111;
      arr[4] = 0b00101001;
      arr[3] = 0b00101001;
      arr[2] = 0b00111111;
      arr[1] = 0b00010110;
      break;
    case '9':
      arr[0] = 6;
      arr[6] = 0b00011110;
      arr[5] = 0b00111111;
      arr[4] = 0b00100101;
      arr[3] = 0b00100101;
      arr[2] = 0b00111101;
      arr[1] = 0b00011000;
      break;
    case '^':
      arr[0] = 6;
      arr[6] = 0b00000100;
      arr[5] = 0b00000010;
      arr[4] = 0b01111111;
      arr[3] = 0b00111011;
      arr[2] = 0b00011011;
      arr[1] = 0b00001010;
      break;
  }
  return &arr[0];
}

// You wrote the original version of this, but I modified it so the user
// can specify whether or not characters should "wrap around" the edges
// and whether or not we should pause to accomodate for drawing off-screen.
// Also, I allow you to draw any bitmap whose info can be accessed from GetChar().
void DisplayChar (Char, xoffset, yoffset, ColZero, RevVideo, Wrap, Wait, NumFlash, FlashDuration, BlanksPerFlash)
  char Char;     
  unsigned xoffset;
  unsigned yoffset;
  unsigned char ColZero; // =0 if ColNum(0) is rightmost on display, =1 if leftmost                 
  unsigned char RevVideo; // if true, flips meaning of ColValue ... nth bit=1 disables nth row  
  unsigned char Wrap; // whether or not we should wrap
  unsigned char Wait; // whether or not we should pause to account for offscreen stuff
  unsigned NumFlash; // Number of times the control loop is run to display the column           
  unsigned FlashDuration; // number of milliseconds to keep column displayed                    
  unsigned BlanksPerFlash; // for pwm brightness control,                                       
{
  unsigned char ColDisplay[8]; // Actual pin values to be displayed
  unsigned char i;
  for (i=0; i<8; i++) ColDisplay[i] = GetChar(Char)[i];
  for (i=1; i<=ColDisplay[0]; i++) ColDisplay[i] = ColDisplay[i] << yoffset;
  for (i=1; i<=ColDisplay[0]; i++) {
    if (Wrap || i-1+xoffset < 16)
      DisplayColumn(i-1+xoffset, ColZero, ColDisplay[i], RevVideo, NumFlash, FlashDuration, BlanksPerFlash);
    else if (Wait) delay_ms(NumFlash*FlashDuration*(1+BlanksPerFlash));
  }
}

// This is optimized for displaying longer strings.
// There are several problems with just calling DrawChar() a bunch of times with Wrap == 0:
// 1. If Wait is 0, then you get more efficient drawing, but the timing is off.  This is because
//    that function would ignore any columns that are off-screen.  The best way to see the
//    problem this creates is to try drawing a character in several locations.  This function
//    would then take different lengths of time to execute depending on how many columns we
//    would need to paint.
// 2. If Wait is 1, then you essentially draw every single column, even those that don't appear
//    on screen.  In other words, we will just hang for the amount of time it would normally
//    take to paint a single column.  For longer strings, this is totally impractical.
// This function will always call DrawColumn() the same number of times, so the amount of time
// it takes for this function to complete is essentially the same, since painting the columns
// is the most expensive part of this function timewise.
void DisplayString(Str, xoffset, yoffset, ColZero, RevVideo, NumFlash, FlashDuration, BlanksPerFlash)
  unsigned char Str[]; // the string to display
  int xoffset;
  unsigned yoffset;
  unsigned char ColZero; // =0 if ColNum(0) is rightmost on display, =1 if leftmost                 
  unsigned char RevVideo; // if true, flips meaning of ColValue ... nth bit=1 disables nth row
  unsigned NumFlash; // Number of times the control loop is run to display the column           
  unsigned FlashDuration; // number of milliseconds to keep column displayed                    
  unsigned BlanksPerFlash; // for pwm brightness control,
{
  unsigned char strLength; // the length of Str
  unsigned char values[16]; // a virtual canvas
  unsigned char charData[8]; // the current character we're looking at
  int i, j, place;
  
  strLength = strlen(Str);
  place = xoffset;
  for (i=0; i<16; i++) values[i] = 0;
  for (i=0; i<strLength; i++) {
    for (j=0; j<8; j++) charData[j] = GetChar(Str[i])[j];
    for (j=0; j<charData[0]; j++) {
      if (place+j >=0 && place+j < 16) {
        values[place+j] = charData[j+1];
      }
    }
    place += charData[0]+1;
  }
  for (j=0; j<NumFlash; j++) for (i=0; i<16; i++) {
    DisplayColumn(i, ColZero, values[i] << yoffset, RevVideo, 1, FlashDuration, 0);
  }
}

// dBar and dDot, originally stored in main(), hogged 18 precious bytes of memory.
// We got them back by making dBar and dDot functions instead.

unsigned char dBar(unsigned char n) {
  return (1 << n) - 1;
}

unsigned char dDot(unsigned char n) {
  if (n == 0) return 0;
  else return 1 << n;
}

void main(void) {
  int i;
  char j;
  unsigned char str[9] = "12345678";
  // The array cannot have more than 9 elements because otherwise the compiler will complain*
  // about not having enough memory.  If the string has nine characters, then the compiler
  // will give a warning about not having a null-terminated string.  I don't know if that
  // would cause DisplayString() to fail, though; I haven't tested this.
  TRISA = 0x00;
  TRISB = 0x00;
  TRISE = 0x00;
  TRISD = 0x00;
  while (1) {
    for (i=16; i>=-54; i--) {
      DisplayString(str, i, 1, dLEFT, dRV_OFF, 20, 1, 0); 
    }
    for (i=16; i>=-54; i--) {
      DisplayString(str, i, i%2==0 ? 0 : 1, dRIGHT, dRV_OFF, 20, 1, 0); 
    }
    for (i=0; i<=8; i++) for (j=0; j<30; j++) {
      DisplayColumn(0, dLEFT, dBar(i), dRV_OFF, 1, 1, 0);
      DisplayColumn(0, dRIGHT, dBar(i), dRV_OFF, 1, 1, 0);
      DisplayColumn(1, dLEFT, dBar(i), dRV_OFF, 1, 1, 0);
      DisplayColumn(1, dRIGHT, dBar(i), dRV_OFF, 1, 1, 0);
      DisplayColumn(2, dLEFT, dBar(i), dRV_OFF, 1, 1, 0);
      DisplayColumn(2, dRIGHT, dBar(i), dRV_OFF, 1, 1, 0);
      DisplayChar(48+i, i==1 ? 6 : 5, 1, dLEFT, dRV_OFF, dOFF, dON, 1, 1, 0);
    }
    for (i=16; i>-60; i--) for (j=0; j<20; j++) {
      DisplayChar('1', i, 1, dLEFT, dRV_OFF, dOFF, dON, 1, 1, 0);
      DisplayChar('2', i+4, 1, dLEFT, dRV_OFF, dOFF, dON, 1, 1, 0);
      DisplayChar('3', i+11, 1, dLEFT, dRV_OFF, dOFF, dON, 1, 1, 0);
      DisplayChar('4', i+18, 1, dLEFT, dRV_OFF, dOFF, dON, 1, 1, 0);
      DisplayChar('5', i+25, 1, dLEFT, dRV_OFF, dOFF, dON, 1, 1, 0);
      DisplayChar('6', i+32, 1, dLEFT, dRV_OFF, dOFF, dON, 1, 1, 0);
      DisplayChar('7', i+39, 1, dLEFT, dRV_OFF, dOFF, dON, 1, 1, 0);
      DisplayChar('8', i+46, 1, dLEFT, dRV_OFF, dOFF, dON, 1, 1, 0);
    }
    for (i=8; i>=0; i--) for (j=0; j<30; j++) {
      DisplayColumn(0, dLEFT, dBar(i), dRV_OFF, 1, 1, 0);
      DisplayColumn(0, dRIGHT, dBar(i), dRV_OFF, 1, 1, 0);
      DisplayColumn(1, dLEFT, dBar(i), dRV_OFF, 1, 1, 0);
      DisplayColumn(1, dRIGHT, dBar(i), dRV_OFF, 1, 1, 0);
      DisplayColumn(2, dLEFT, dBar(i), dRV_OFF, 1, 1, 0);
      DisplayColumn(2, dRIGHT, dBar(i), dRV_OFF, 1, 1, 0);
      DisplayChar(48+i, i==1 ? 6 : 5, 1, dLEFT, dRV_OFF, dOFF, dON, 1, 1, 0);
    }
    for (i=16; i>-54; i--) {
      DisplayString(str, i, 1, dLEFT, dRV_OFF, 3, 20, 0); 
    }
  }
}
