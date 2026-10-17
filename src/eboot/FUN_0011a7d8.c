/* HSTMATCH module=EBOOT.BIN start=0x0011a7d8 end=0x0011a820 symbol=FUN_0011a7d8 lang=c99 */
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

extern undefined4 DAT_00338b44;

undefined4 FUN_0011a7d8(int param_1)
{
  int iVar1;
  
  if (*(int *)(DAT_00338b44 + 0x8c) == 0) {
    iVar1 = 0;
    do {
      if (*(int *)(param_1 + 0x314) == 5) {
        return 1;
      }
      iVar1 = iVar1 + 1;
      param_1 = param_1 + 4;
    } while (iVar1 < 2);
  }
  return 0;
}
