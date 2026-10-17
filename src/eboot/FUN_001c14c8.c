/* HSTMATCH module=EBOOT.BIN start=0x001c14c8 end=0x001c1518 symbol=FUN_001c14c8 lang=c99 */
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

extern void FUN_001beffc();
extern void FUN_001c1344();

void FUN_001c14c8(undefined4 *param_1)
{
  int iVar1;
  
  FUN_001beffc(*param_1);
  *(undefined2 *)(param_1 + 0x104) = 0;
  FUN_001c1344(param_1);
  iVar1 = 0;
  do {
    *(undefined1 *)((int)param_1 + 0x412) = 0;
    iVar1 = iVar1 + 1;
    *(undefined1 *)((int)param_1 + 0x413) = 0;
    param_1 = (undefined4 *)((int)param_1 + 2);
  } while (iVar1 < 2);
  return;
}
