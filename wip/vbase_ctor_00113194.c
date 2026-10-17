/* HSTMATCH module=EBOOT.BIN start=0x00113194 end=0x00113314 symbol=FUN_00113194 lang=c99 */
// Near miss (3 words): only the register of the constant stored to 276(s1) differs (ours v0, retail v1 for 0x307d40).
// This variant passes &DAT_00307d50 as a dummy third argument of FUN_00112cc0 (callee ignores it): sharing the constant with an argument register is the only
// thing that moved it from a0 to retail's a2 (without the dummy argument it is 6 words: v0/a0 vs v1/a2).
// Fixed: piVar1 (= param_1 + 0xc, the +0x30 sub-object) for the members at +0x60..+0xc0; vbase offsets written
// `(int)((char *)param_1 + 0x110) + 0x10 - param_1[0x44]` (char* typed so MWCC does not CSE param_1 + 0x44 into a saved register).
// Ruled out: all 6 orders of the three stores, local copies of vb1/off/p0 before the stores, int-typed param_1 + 0x44 forms (extra saved reg).
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
extern int * FUN_00112cc0(int *, int, void *);

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
    param_1[0x45] = (int)&DAT_00307d40;
    *(undefined **)param_1[0x44] = &DAT_00307d50;
    *(int *)(param_1[0x44] + 0xd0) = (int)((char *)param_1 + 0x110) + 0x10 - param_1[0x44];
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
