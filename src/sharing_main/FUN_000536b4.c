/* HSTMATCH module=hstp_trans_main.prx start=0x000536b4 end=0x000537c8 symbol=FUN_000536b4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
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

extern undefined DAT_002cc260;
extern undefined4 DAT_003d44bc;
extern uint * FUN_0003697c();
extern uint * FUN_00036cd0();
extern uint * FUN_00037324();
extern undefined4 * FUN_00053504();
extern undefined4 * FUN_00053588();

void FUN_000536b4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6,undefined4 param_7)
{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  uVar1 = (unsigned int)(FUN_00036cd0(*(undefined4 *)(param_1 + 0x28),DAT_003d44bc));
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  puVar2 = (undefined4 *)FUN_00037324(uVar1,DAT_003d44bc);
  *(undefined4 **)(param_1 + 0x28) = puVar2;
  *puVar2 = 0x17000000;
  iVar3 = *(int *)(param_1 + 0x28);
  *(int *)(param_1 + 0x28) = iVar3 + 4;
  *(uint *)(iVar3 + 4) = *(int *)(param_1 + 4) < 0 ^ 1 | 0x1e000000;
  iVar3 = *(int *)(param_1 + 0x28);
  *(int *)(param_1 + 0x28) = iVar3 + 4;
  *(undefined4 *)(iVar3 + 4) = 0xc0000301;
  iVar3 = *(int *)(param_1 + 0x28) + 4;
  *(int *)(param_1 + 0x28) = iVar3;
  uVar1 = (unsigned int)(FUN_00053588(iVar3,&DAT_002cc260));
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  uVar1 = (unsigned int)(FUN_00053504(uVar1,param_2));
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  uVar1 = (unsigned int)(FUN_0003697c(uVar1,param_3,param_4,param_5,0,param_7));
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  return;
}
