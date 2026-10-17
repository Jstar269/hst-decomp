/* HSTMATCH module=EBOOT.BIN start=0x000950e0 end=0x00095104 symbol=FUN_000950e0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe1); exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;


bool FUN_000950e0(int param_1,int param_2)
{
  bool bVar1;
  
  if (*(uint *)(param_1 + 0x1b0) < 3) {
    bVar1 = *(short *)(param_1 + 0x1b8) == param_2;
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}
