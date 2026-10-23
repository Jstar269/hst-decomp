/* HSTMATCH module=EBOOT.BIN start=0x00159f08 end=0x0015a01c symbol=FUN_00159f08 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_00159f08.c) corrected by hand: reordered the local declarations and cursor initializations to match retail register assignments; exact match verified; names and types await human review. */
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

extern undefined DAT_002de04c;
extern undefined DAT_00309070;
extern undefined4 DAT_003403f8;
extern undefined4 DAT_00340400;
extern uint FUN_0001342c();
extern uint * FUN_000149a8();
extern void FUN_0015a2b0();
extern void FUN_0015ced4();
extern code * FUN_0022cd60();

undefined4 * FUN_00159f08(undefined4 *param_1,undefined1 param_2)
{
  int iVar5;
  undefined4 *puVar4;
  undefined4 *puVar3;
  undefined4 *puVar2;
  undefined4 uVar1;
  
  *param_1 = (unsigned int)(&DAT_00309070);
  param_1[3] = 1;
  param_1[9] = 0;
  param_1[10] = 0;
  DAT_00340400 = (unsigned int)(FUN_0022cd60());
  FUN_0015ced4(param_1);
  DAT_003403f8 = (unsigned int)(param_1);
  uVar1 = FUN_0001342c();
  param_1[3] = uVar1;
  param_1[1] = 0;
  param_1[8] = 0;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 7) = param_2;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  iVar5 = 0;
  puVar4 = param_1;
  puVar3 = param_1;
  puVar2 = param_1;
  do {
    puVar4[0xd] = 0;
    puVar3[0x10] = 0;
    puVar3[0x11] = 0;
    puVar3[0x12] = 0;
    puVar3[0x13] = 0x3f800000;
    FUN_000149a8(puVar2 + 0x1c,&DAT_002de04c);
    iVar5 = iVar5 + 1;
    puVar4 = puVar4 + 1;
    puVar3 = puVar3 + 4;
    puVar2 = puVar2 + 0x40;
  } while (iVar5 < 3);
  FUN_000149a8(param_1 + 0xdc,&DAT_002de04c);
  param_1[4] = 100;
  FUN_0015a2b0(param_1,8);
  return param_1;
}
