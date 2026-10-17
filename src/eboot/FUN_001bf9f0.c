/* HSTMATCH module=EBOOT.BIN start=0x001bf9f0 end=0x001bfa44 symbol=FUN_001bf9f0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1), refined by hstperm.py tag p4 random mutation from try/gen-a1/v0/FUN_001bf9f0.c; exact match verified; names and types await human review. */
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

extern void FUN_001bbd30();

void FUN_001bf9f0(int param_1,int param_2,undefined4 param_3)
{
  int iVar1;
  
  if (param_2 >= 0 && (param_2 < 0x28)) {
    iVar1 = param_1 + param_2 * 0x14 + 0x1058;
  }
  else {
    iVar1 = 0;
  }
  if (iVar1 != 0) {
    FUN_001bbd30(iVar1,param_3,0);
  }
  return;
}
