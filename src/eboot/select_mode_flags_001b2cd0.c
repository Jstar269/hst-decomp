/* HSTMATCH module=EBOOT.BIN start=0x001b2cd0 end=0x001b2d88 symbol=FUN_001b2cd0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: matched the status return type and branch polarity; exact match verified; names and types await human review. */
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

extern void FUN_001b0ef8();
extern int FUN_0022c988();

void FUN_001b2cd0(int *param_1,undefined4 param_2)
{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  FUN_001b0ef8(iVar2,1,0,param_2,0);
  if (FUN_0022c988(8) != 0) {
    FUN_001b0ef8(iVar2,0xaf,0,0,0);
    *(undefined4 *)(iVar2 + 0x7cc) = 0xaf;
  }
  else {
    FUN_001b0ef8(iVar2,0xae,0,0,0);
    *(undefined4 *)(iVar2 + 0x7cc) = 0xae;
  }
  FUN_001b0ef8(iVar2,0x3e,0,0,0);
  FUN_001b0ef8(iVar2,0x53,0,0,0);
  return;
}
