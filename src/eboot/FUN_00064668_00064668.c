/* HSTMATCH module=EBOOT.BIN start=0x00064668 end=0x000646e8 symbol=FUN_00064668 lang=c99 */
/* Clone of src/sharing_main/FUN_0006552c_0006552c.c (hstclone.py tag u5cr2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: moved the common parent-flag load after the optional child update; exact match verified; names and types await human review. */
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


void FUN_00064668(uint *param_1,uint *param_2)
{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  
  uVar4 = *param_1;
  if ((uint *)*param_2 == param_1) {
    *param_2 = uVar4;
  }
  *param_1 = *(uint *)(uVar4 + 4);
  iVar2 = *(int *)(uVar4 + 4);
  if (iVar2 != 0) {
    *(uint *)(iVar2 + 8) = (uint)param_1 | *(uint *)(iVar2 + 8) & 1;
  }
  uVar1 = *(uint *)(uVar4 + 8);
  *(uint *)(uVar4 + 8) = param_1[2] & 0xfffffffe | uVar1 & 1;
  puVar3 = (uint *)(param_1[2] & 0xfffffffe);
  if (param_1 == (uint *)*puVar3) {
    *puVar3 = uVar4;
  }
  else {
    puVar3[1] = uVar4;
  }
  *(uint **)(uVar4 + 4) = param_1;
  param_1[2] = uVar4 | param_1[2] & 1;
  return;
}
