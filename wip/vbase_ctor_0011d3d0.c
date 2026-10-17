/* HSTMATCH module=hstp_trans_main.prx start=0x0011d3d0 end=0x0011d550 symbol=FUN_0011d3d0 lang=c99 */
/* Hand-written near miss derived from the EBOOT twin wip/vbase_ctor_00113194.c (Ghidra pseudocode, hstgen.py tag sh2/v0c); 3 words differ; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined DAT_002cc260;
extern undefined DAT_0037ffe4;
extern undefined DAT_003b0a68;
extern undefined DAT_003b0f4c;
extern undefined DAT_003b0f5c;
extern undefined DAT_003b0fa0;
extern undefined DAT_003b0fb0;
extern undefined DAT_003b100c;
extern undefined DAT_003b101c;
extern undefined4 FUN_00056cac();
extern undefined4 * FUN_001016c0();
extern undefined4 * FUN_00101748();
extern undefined4 * FUN_001017dc();
extern int * FUN_0011cc90(int *, int, void *);

int * FUN_0011d3d0(int *param_1,short param_2)
{
  int *piVar1;
  
  if (param_2 != 0) {
    piVar1 = param_1 + 0xc;
    param_1[0x44] = (int)piVar1;
    param_1[0x4c] = (int)piVar1;
    *param_1 = (int)(param_1 + 0x44);
    param_1[1] = (int)(param_1 + 0x4c);
    FUN_001017dc(piVar1);
    FUN_00056cac(piVar1 + 0xc);
    *piVar1 = (int)&DAT_003b0a68;
    piVar1[0x1c] = 0;
    piVar1[0x1d] = -1;
    piVar1[0x1e] = 0x3f800000;
    piVar1[0x1f] = 0x3f800000;
    FUN_00056cac(piVar1 + 0x20);
    piVar1[0x30] = (int)&DAT_0037ffe4;
    FUN_00101748(piVar1,&DAT_002cc260);
    FUN_001016c0(piVar1 + 0x20,&DAT_002cc260);
    param_1[0x45] = (int)&DAT_003b100c;
    *(undefined **)param_1[0x44] = &DAT_003b101c;
    *(int *)(param_1[0x44] + 0xd0) = (int)((char *)param_1 + 0x110) + 0x10 - param_1[0x44];
    FUN_0011cc90(param_1 + 0x4c,0,&DAT_003b101c);
  }
  param_1[2] = (int)&DAT_003b0f4c;
  *(undefined **)(*param_1 + 4) = &DAT_003b0fa0;
  **(undefined4 **)*param_1 = (unsigned int)(&DAT_003b0f5c);
  *(undefined **)(param_1[1] + 0x7c) = &DAT_003b0fb0;
  *(int *)(*(int *)*param_1 + 0xd0) = (int)(param_1 + 0xc) - *(int *)*param_1;
  *(int *)(*param_1 + 0x10) = (int)(param_1 + 0x44) - *param_1;
  *(int *)(param_1[1] + 0x80) = (int)(param_1 + 0x4c) - param_1[1];
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0x42c80000;
  return param_1;
}
// 0x11d3d0: 3 words differ, only the register of the constant stored to 276(s1) (&DAT_003b100c): ours v0, retail v1 (lui/addiu/sw).
// Same as the EBOOT twin 0x113194. Everything else, including retail's a2 for &DAT_003b101c, is exact with the dummy third argument of FUN_0011cc90.
// Ruled out here (all keep the 3-word diff): lang=c++ with prototyped externs, return types void/int/pointer of FUN_001016c0/FUN_00101748,
// a local for (char *)param_1 + 0x110 (set at block start / before the constant store / as the finished offset). A single-use local is
// forward-substituted back to its use, so it cannot hold v0 across the constant store.
