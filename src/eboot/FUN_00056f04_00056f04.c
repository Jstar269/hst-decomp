/* HSTMATCH module=EBOOT.BIN start=0x00056f04 end=0x00056f88 symbol=FUN_00056f04 lang=c99 */
/* Clone of src/sharing_main/FUN_00057b58_00057b58.c (hstclone.py tag u5cr2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed the helper argument and preserved the zero-or-call result; exact match verified; names and types await human review. */
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

extern int FUN_00010184();
extern uint FUN_0002fe08(int param_1);
extern void FUN_00056f88();
extern void FUN_000578c0();
extern void FUN_00057d6c();

void FUN_00056f04(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  
  FUN_00056f88();
  if (*(int *)(param_1 + 0x8c) != 0) {
    iVar1 = (*(int *)(*(int *)(param_1 + 0x8c) + 8) != 0)
               ? FUN_0002fe08(*(int *)(*(int *)(param_1 + 0x8c) + 8))
               : 0;
    uVar2 = FUN_00010184(0x10,iVar1 << 6);
    *(undefined4 *)(param_1 + 0x160) = uVar2;
    uVar2 = FUN_00010184(0x10,iVar1 << 6);
    *(undefined4 *)(param_1 + 0x164) = uVar2;
    FUN_00057d6c(param_1);
  }
  FUN_000578c0(param_1);
  return;
}
