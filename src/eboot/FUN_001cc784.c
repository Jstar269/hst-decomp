/* HSTMATCH module=EBOOT.BIN start=0x001cc784 end=0x001cc7d0 symbol=FUN_001cc784 lang=c99 */
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

extern uint * FUN_000149a8();
extern int FUN_00014a40();

void FUN_001cc784(int param_1,undefined4 param_2)
{
  uint uVar1;
  
  uVar1 = FUN_00014a40(param_2);
  if (uVar1 < 0x10) {
    FUN_000149a8(param_1 + 0x104,param_2);
  }
  return;
}
