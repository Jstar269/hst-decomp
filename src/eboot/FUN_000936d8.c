/* HSTMATCH module=EBOOT.BIN start=0x000936d8 end=0x00093750 symbol=FUN_000936d8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a7); exact match verified; names and types await human review. */
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

extern void FUN_00059100();

void FUN_000936d8(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x58);
  if (iVar1 != 0) {
    FUN_00059100(iVar1,0xffffffff);
    *(undefined4 *)(iVar1 + 0xd0) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x50);
  if (iVar1 != 0) {
    FUN_00059100(iVar1,0xffffffff);
    *(undefined4 *)(iVar1 + 0xd0) = 0;
  }
  iVar1 = *(int *)(param_1 + 100);
  if (iVar1 != 0) {
    FUN_00059100(iVar1,0xffffffff);
    *(undefined4 *)(iVar1 + 0xd0) = 0;
  }
  return;
}
