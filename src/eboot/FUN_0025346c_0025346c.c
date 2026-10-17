/* HSTMATCH module=EBOOT.BIN start=0x0025346c end=0x002534b4 symbol=FUN_0025346c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reversed the nested mode and byte arms and made the byte unsigned; exact match verified; names and types await human review. */
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

extern int FUN_001d9cfc();

void FUN_0025346c(int param_1,int param_2)
{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    if (*(unsigned char *)(param_1 + 0x34) != 0) {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  uVar1 = FUN_001d9cfc(param_1 + 0x3c,uVar1);
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  return;
}
