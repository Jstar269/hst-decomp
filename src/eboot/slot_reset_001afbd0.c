/* HSTMATCH module=EBOOT.BIN start=0x001afbd0 end=0x001afcd4 symbol=FUN_001afbd0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: while (iVar3 >= 0) loop test, declaration order (pointer after the index), the two small clear loops written with block-scoped counter and pointer, with opt_unroll_loops and opt_strength_reduction off (rolled loops); exact match verified; names and types await human review. */
#pragma opt_unroll_loops off
#pragma opt_strength_reduction off
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

extern int FUN_00062418();

void FUN_001afbd0(int param_1)
{
  uint uVar1;
  int iVar3;
  int *piVar2;
  
  iVar3 = 0x1d9;
  piVar2 = (int *)(param_1 + 0x764);
  do {
    if ((iVar3 != 0x58) && (*piVar2 != 0)) {
      FUN_00062418(*piVar2,1);
      *piVar2 = 0;
    }
    iVar3 = iVar3 + -1;
    piVar2 = piVar2 + -1;
  } while (iVar3 >= 0);
  *(undefined4 *)(param_1 + 0x79c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x7a0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x7a4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x7a8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x7ac) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x7b0) = 0x1da;
  *(undefined4 *)(param_1 + 0x7b4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x7b8) = 0x1da;
  *(undefined4 *)(param_1 + 0x7bc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x7c0) = 0x1da;
  *(undefined4 *)(param_1 + 0x7c4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x7c8) = 0x1da;
  uVar1 = 0;
  iVar3 = param_1;
  do {
    *(undefined4 *)(iVar3 + 0x768) = 0;
    *(undefined1 *)(param_1 + uVar1 + 0x798) = 0;
    uVar1 = uVar1 + 1;
    iVar3 = iVar3 + 4;
  } while (uVar1 < 4);
  {
    uint k = 0;
    int p = param_1;
    do {
      k = k + 1;
      *(undefined4 *)(p + 0x778) = 0;
      p = p + 4;
    } while (k < 4);
  }
  *(undefined4 *)(param_1 + 0x788) = 0;
  {
    uint k = 0;
    int p = param_1;
    do {
      k = k + 1;
      *(undefined4 *)(p + 0x78c) = 0;
      p = p + 4;
    } while (k < 2);
  }
  *(undefined4 *)(param_1 + 0x794) = 0;
  return;
}
