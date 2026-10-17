/* HSTMATCH module=EBOOT.BIN start=0x002667b8 end=0x002667f4 symbol=FUN_002667b8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
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
typedef float undefined4;

extern undefined4 DAT_002fdef8;

void FUN_002667b8(float param_1,int param_2)
{
  float *pfVar1;
  float local_4;
  
  local_4 = param_1;
  if (param_1 < DAT_002fdef8) {
    pfVar1 = &DAT_002fdef8;
  }
  else {
    pfVar1 = &local_4;
  }
  *(float *)(param_2 + 0x110) = *pfVar1;
  return;
}
