/* HSTMATCH module=EBOOT.BIN start=0x0015d184 end=0x0015d1c8 symbol=FUN_0015d184 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
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

extern undefined4 DAT_00340400;
extern undefined DAT_0034100c;

void FUN_0015d184(undefined4 param_1,int param_2)
{
  byte bVar1;
  
  (&DAT_0034100c)[param_2] = 1;
  bVar1 = *(byte *)(param_2 + DAT_00340400 + 0x10);
  if (bVar1 < 0xc9) {
    *(byte *)(param_2 + DAT_00340400 + 0x10) = bVar1 + 1;
  }
  return;
}
