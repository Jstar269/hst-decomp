/* HSTMATCH module=hstp_trans_main.prx start=0x000655ac end=0x0006562c symbol=FUN_000655ac lang=c99 */
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


void FUN_000655ac(uint param_1,uint *param_2)
{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  
  puVar3 = *(uint **)(param_1 + 4);
  if (*param_2 == param_1) {
    *param_2 = (uint)puVar3;
  }
  *(uint *)(param_1 + 4) = *puVar3;
  uVar1 = *puVar3;
  if (uVar1 != 0) {
    *(uint *)(uVar1 + 8) = param_1 | *(uint *)(uVar1 + 8) & 1;
  }
  uVar1 = puVar3[2];
  puVar3[2] = *(uint *)(param_1 + 8) & 0xfffffffe | uVar1 & 1;
  puVar2 = (uint *)(*(uint *)(param_1 + 8) & 0xfffffffe);
  if (param_1 == *puVar2) {
    *puVar2 = (uint)puVar3;
  }
  else {
    puVar2[1] = (uint)puVar3;
  }
  *puVar3 = param_1;
  *(uint *)(param_1 + 8) = (uint)puVar3 | *(uint *)(param_1 + 8) & 1;
  return;
}
