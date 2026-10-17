/* HSTMATCH module=EBOOT.BIN start=0x001e2694 end=0x001e27a0 symbol=FUN_001e2694 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7/v21) corrected by hand: used the owner-relative field offset +0x175c; exact match verified; names and types await human review. */
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

extern void FUN_00103628();
extern void FUN_001e5f00();
extern void FUN_0021e4cc();

void FUN_001e2694(int param_1)
{
  int iVar1;
  
  if (*(int *)(param_1 + 500) != 0) {
    FUN_00103628(*(int *)(param_1 + 500),1);
  }
  iVar1 = *(int *)(param_1 + 0x9b4);
  if (iVar1 != 0) {
    FUN_00103628(iVar1,1);
  }
  iVar1 = *(int *)(param_1 + 0x810);
  if (iVar1 != 0) {
    FUN_00103628(iVar1,1);
  }
  iVar1 = *(int *)(param_1 + 0x175c);
  if (iVar1 != 0) {
    FUN_00103628(iVar1,1);
  }
  iVar1 = *(int *)(param_1 + 0x1954);
  if (iVar1 != 0) {
    FUN_00103628(iVar1,1);
  }
  iVar1 = *(int *)(param_1 + 0x1d68);
  if (iVar1 != 0) {
    FUN_00103628(iVar1,1);
  }
  iVar1 = *(int *)(param_1 + 0x1958);
  if (iVar1 != 0) {
    FUN_00103628(iVar1,1);
  }
  iVar1 = *(int *)(param_1 + 0x1d64);
  if (iVar1 != 0) {
    FUN_0021e4cc(iVar1,1,0);
  }
  iVar1 = *(int *)(param_1 + 0x21e4);
  if (iVar1 != 0) {
    FUN_00103628(iVar1,1);
  }
  iVar1 = *(int *)(param_1 + 0x235c);
  if (iVar1 != 0) {
    FUN_00103628(iVar1,1);
  }
  FUN_001e5f00(param_1);
  if (*(int *)(param_1 + 0x25b8) != 0) {
    FUN_00103628(*(int *)(param_1 + 0x25b8),1);
  }
  return;
}
