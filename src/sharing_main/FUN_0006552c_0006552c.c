/* HSTMATCH module=hstp_trans_main.prx start=0x0006552c end=0x000655ac symbol=FUN_0006552c lang=c99 */
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


void FUN_0006552c(uint *param_1,uint *param_2)
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
