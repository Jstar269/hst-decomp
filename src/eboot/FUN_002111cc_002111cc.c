/* HSTMATCH module=EBOOT.BIN start=0x002111cc end=0x00211270 symbol=FUN_002111cc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: compared the parameter from the variable side and retained the scaled random factor with a compound multiply; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern uint FUN_0001342c();

float FUN_002111cc(float param_1,float param_2)
{
  uint uVar1;
  float randValue;
  float scaled;
  float fVar2;
  
  if (param_1 > 0.0f) {
    uVar1 = FUN_0001342c();
    randValue = (float)(int)(uVar1 & 0xfffff800);
    scaled = (param_1 + param_2) * 4.656613e-10f;
    scaled *= randValue;
    fVar2 = -param_2 + scaled;
  }
  else {
    uVar1 = FUN_0001342c();
    randValue = (float)(int)(uVar1 & 0xfffff800);
    scaled = (param_2 - param_1) * 4.656613e-10f;
    scaled *= randValue;
    fVar2 = param_1 + scaled;
  }
  return fVar2;
}
