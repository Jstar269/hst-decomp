/* HSTMATCH module=EBOOT.BIN start=0x00286938 end=0x002869cc symbol=FUN_00286938 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag t0), refined by hstperm.py random mutation from try/gen-s256b/v0/FUN_00286938.c; exact match verified; names and types await human review. */
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

extern undefined4 DAT_0034a114;
extern char DAT_002fe9c8[];
extern int FUN_00000a90();
extern uint * FUN_000149a8();
extern int FUN_00014a40();
extern int * FUN_0014c028();
extern int FUN_0014c274();
extern undefined4 FUN_00155f34();

void FUN_00286938(int param_1,undefined4 param_2)
{
  int uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 4) != 0) {
    FUN_0014c028(*(int *)(param_1 + 4),1);
    *(undefined4 *)(param_1 + 4) = 0;
  }
  uVar1 = FUN_00155f34(*(undefined4 *)(DAT_0034a114 + 0x3c),param_2);
  *(undefined4 *)(param_1 + 4) = uVar1;
  iVar2 = FUN_00014a40(param_2);
  uVar1 = FUN_00000a90(iVar2 + 1);
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  FUN_000149a8(uVar1,param_2);
  if (*(int *)(param_1 + 4) != 0) {
    uVar1 = FUN_0014c274(*(int *)(param_1 + 4),DAT_002fe9c8);
    *(undefined4 *)(param_1 + 0x3c) = uVar1;
  }
  return;
}
