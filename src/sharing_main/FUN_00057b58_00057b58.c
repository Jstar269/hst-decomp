/* HSTMATCH module=hstp_trans_main.prx start=0x00057b58 end=0x00057bdc symbol=FUN_00057b58 lang=c99 */
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
extern uint FUN_0002fe30(int param_1);
extern void FUN_00057bdc();
extern void FUN_00058514();
extern void FUN_000589c0();

void FUN_00057b58(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  
  FUN_00057bdc();
  if (*(int *)(param_1 + 0x8c) != 0) {
    iVar1 = (*(int *)(*(int *)(param_1 + 0x8c) + 8) != 0)
               ? FUN_0002fe30(*(int *)(*(int *)(param_1 + 0x8c) + 8))
               : 0;
    uVar2 = FUN_00010184(0x10,iVar1 << 6);
    *(undefined4 *)(param_1 + 0x160) = uVar2;
    uVar2 = FUN_00010184(0x10,iVar1 << 6);
    *(undefined4 *)(param_1 + 0x164) = uVar2;
    FUN_000589c0(param_1);
  }
  FUN_00058514(param_1);
  return;
}
