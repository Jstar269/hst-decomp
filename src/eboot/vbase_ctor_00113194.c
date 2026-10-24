/* HSTMATCH module=EBOOT.BIN start=0x00113194 end=0x00113314 symbol=FUN_00113194 lang=c99 helpers=FUN_00112cc0@0x00112cc0-0x00112e10 */
/* Ghidra pseudocode (hstgen.py tag from the lane-fm7 near miss) corrected by hand: piVar1 = param_1 + 0xc base for the sub-object members, vbase offsets through a char * local t = (char *)param_1 + 0x110, FUN_00112cc0 defined static in front (placed by helpers=, hand-copied from src/eboot/obj_init_00112cc0.c) with an unused third parameter and the dummy argument &DAT_00307d50; matching idioms: the char * t used for the +4 store, the dummy third argument; exact match verified; names and types await human review. */
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

extern undefined DAT_002bc410;
extern undefined DAT_002d9210;
extern undefined DAT_0030779c;
extern undefined DAT_00307c80;
extern undefined DAT_00307c90;
extern undefined DAT_00307cd4;
extern undefined DAT_00307ce4;
extern undefined DAT_00307d40;
extern undefined DAT_00307d50;
extern undefined4 FUN_00056098();
extern undefined4 * FUN_000fbf84();
extern undefined4 * FUN_000fc00c();
extern undefined4 * FUN_000fc0a0();
extern undefined DAT_00307cf0;
extern undefined DAT_00307cfc;
#pragma opt_strength_reduction off
static int * FUN_00112cc0(int *param_1,short param_2,void *unused)
{
  int *piVar1;
  int iVar2;

  if (param_2 != 0) {
    piVar1 = param_1 + 0x20;
    *param_1 = (int)piVar1;
    FUN_000fc0a0(piVar1);
    FUN_00056098(piVar1 + 0xc);
    *piVar1 = (int)&DAT_0030779c;
    piVar1[0x1c] = 0;
    piVar1[0x1d] = -1;
    piVar1[0x1e] = 0x3f800000;
    piVar1[0x1f] = 0x3f800000;
    FUN_00056098(piVar1 + 0x20);
    piVar1[0x30] = (int)&DAT_002d9210;
    FUN_000fc00c(piVar1,&DAT_002bc410);
    FUN_000fbf84(piVar1 + 0x20,&DAT_002bc410);
  }
  param_1[0x1f] = (int)&DAT_00307cf0;
  *(undefined **)*param_1 = &DAT_00307cfc;
  iVar2 = 0;
  *(int *)(*param_1 + 0xd0) = (int)(param_1 + 0x20) - *param_1;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  piVar1 = param_1;
  do {
    piVar1[4] = -999;
    *(undefined1 *)((int)param_1 + iVar2 + 0x4c) = 1;
    *(undefined1 *)((int)param_1 + iVar2 + 0x5b) = 0;
    *(undefined1 *)((int)param_1 + iVar2 + 0x6a) = 0;
    piVar1[5] = -999;
    *(undefined1 *)((int)param_1 + iVar2 + 0x4d) = 1;
    *(undefined1 *)((int)param_1 + iVar2 + 0x5c) = 0;
    *(undefined1 *)((int)param_1 + iVar2 + 0x6b) = 0;
    piVar1[6] = -999;
    *(undefined1 *)((int)param_1 + iVar2 + 0x4e) = 1;
    *(undefined1 *)((int)param_1 + iVar2 + 0x5d) = 0;
    *(undefined1 *)((int)param_1 + iVar2 + 0x6c) = 0;
    piVar1[7] = -999;
    *(undefined1 *)((int)param_1 + iVar2 + 0x4f) = 1;
    *(undefined1 *)((int)param_1 + iVar2 + 0x5e) = 0;
    *(undefined1 *)((int)param_1 + iVar2 + 0x6d) = 0;
    piVar1[8] = -999;
    *(undefined1 *)((int)param_1 + iVar2 + 0x50) = 1;
    *(undefined1 *)((int)param_1 + iVar2 + 0x5f) = 0;
    *(undefined1 *)((int)param_1 + iVar2 + 0x6e) = 0;
    iVar2 = iVar2 + 5;
    piVar1 = piVar1 + 5;
  } while (iVar2 < 0xf);
  return param_1;
}

#pragma opt_strength_reduction reset


int * FUN_00113194(int *param_1,short param_2)
{
  int *piVar1;
  
  if (param_2 != 0) {
    piVar1 = param_1 + 0xc;
    param_1[0x44] = (int)piVar1;
    param_1[0x4c] = (int)piVar1;
    *param_1 = (int)(param_1 + 0x44);
    param_1[1] = (int)(param_1 + 0x4c);
    FUN_000fc0a0(piVar1);
    FUN_00056098(piVar1 + 0xc);
    *piVar1 = (int)&DAT_0030779c;
    piVar1[0x1c] = 0;
    piVar1[0x1d] = -1;
    piVar1[0x1e] = 0x3f800000;
    piVar1[0x1f] = 0x3f800000;
    FUN_00056098(piVar1 + 0x20);
    piVar1[0x30] = (int)&DAT_002d9210;
    FUN_000fc00c(piVar1,&DAT_002bc410);
    FUN_000fbf84(piVar1 + 0x20,&DAT_002bc410);
    char *t = (char *)param_1 + 0x110;
    *(int *)(t + 4) = (int)&DAT_00307d40;
    *(undefined **)param_1[0x44] = &DAT_00307d50;
    *(int *)(param_1[0x44] + 0xd0) = (int)t + 0x10 - param_1[0x44];
    FUN_00112cc0(param_1 + 0x4c,0,&DAT_00307d50);
  }
  param_1[2] = (int)&DAT_00307c80;
  *(undefined **)(*param_1 + 4) = &DAT_00307cd4;
  **(undefined4 **)*param_1 = (unsigned int)(&DAT_00307c90);
  *(undefined **)(param_1[1] + 0x7c) = &DAT_00307ce4;
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
