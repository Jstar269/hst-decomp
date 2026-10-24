/* HSTMATCH module=EBOOT.BIN start=0x001ee998 end=0x001eec08 symbol=FUN_001ee998 lang=c99 */
typedef unsigned int undefined4;
typedef int code();

extern char DAT_003094e0[];
extern char DAT_003094fc[];
extern char DAT_00309510[];
extern char DAT_003070bc[];
extern char DAT_00341d93;
extern char DAT_00341d7d;
extern char DAT_00341d7e;
extern char *DAT_003415ac;

extern void FUN_0001cb88();
extern void FUN_001f2f08();
extern void FUN_00219184();
extern void FUN_00216bc4();
extern void FUN_00194110();
extern void FUN_002ad74c();
extern void FUN_00054554();
extern void FUN_00000788();
extern void FUN_00066338();
extern void FUN_00064a08();
extern void FUN_0001f0f0();
extern void FUN_00000a00();
extern void FUN_001ee87c();
extern void FUN_001ee8ec();

undefined4 *FUN_001ee998(undefined4 *param_1, short param_2)
{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;

  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (undefined4)DAT_003094e0;
    param_1[0xf] = (undefined4)DAT_003094fc;
    FUN_0001cb88(0x30ebf4);
    FUN_001f2f08(param_1);
    piVar1 = (int *)param_1[0x161];
    if (piVar1 == (int *)0x0) {
      iVar2 = param_1[0x159];
    }
    else {
      (**(code **)(*piVar1 + 8))(piVar1, 1);
      param_1[0x161] = 0;
      iVar2 = param_1[0x159];
    }
    if (iVar2 == 0) {
      iVar2 = param_1[0x158];
    }
    else {
      FUN_00219184(iVar2, 1);
      param_1[0x159] = 0;
      iVar2 = param_1[0x158];
    }
    if (iVar2 != 0) {
      FUN_00216bc4(iVar2, 1);
      param_1[0x158] = 0;
    }
    FUN_00194110();
    iVar2 = (int)DAT_003415ac;
    if (param_1[0x205f] == 1) {
      if (param_1[0x205e] == 1) {
        DAT_00341d93 = 1;
      }
      else {
        DAT_00341d93 = 0;
      }
    }
    else {
      DAT_00341d93 = 0;
    }
    DAT_00341d7d = 0xff;
    DAT_00341d7e = 0xff;
    if (DAT_003415ac != 0) {
      *(undefined4 *)(DAT_003415ac + 0x74) = 0x3f800000;
      *(undefined4 *)(iVar2 + 0x78) = 0x3f800000;
      iVar2 = (int)DAT_003415ac;
      *(undefined4 *)(**(int **)(iVar2 + 4) + 0x60) = 0x43700000;
      *(undefined4 *)(**(int **)(iVar2 + 4) + 100) = 0x43080000;
    }
    FUN_002ad74c();
    puVar3 = param_1 + 0x2061;
    if (puVar3 != (undefined4 *)0x0) {
      FUN_00054554(puVar3, 0);
    }
    FUN_00000788(param_1 + 0x1ddb, FUN_001ee87c, 0x14, 0x80);
    FUN_00000788(param_1 + 0x4db, FUN_001ee87c, 0x14, 0x500);
    FUN_00000788(param_1 + 0x43f, FUN_001ee8ec, 0xe4, 2);
    if (param_1 != (undefined4 *)0xffffef34) {
      param_1[0x433] = (undefined4)DAT_003070bc;
      if (param_1 + 0x43b != (undefined4 *)0x0) {
        FUN_00066338(param_1 + 0x43b, 0);
      }
      if (param_1 + 0x437 != (undefined4 *)0x0) {
        FUN_00066338(param_1 + 0x437, 0);
      }
      FUN_00064a08(param_1 + 0x433, 0);
    }
    if (param_1 != (undefined4 *)0xffffefac) {
      param_1[0x415] = (undefined4)DAT_003070bc;
      if (param_1 + 0x41d != (undefined4 *)0x0) {
        FUN_00066338(param_1 + 0x41d, 0);
      }
      if (param_1 + 0x419 != (undefined4 *)0x0) {
        FUN_00066338(param_1 + 0x419, 0);
      }
      FUN_00064a08(param_1 + 0x415, 0);
    }
    if (param_1 != (undefined4 *)0xfffffa08) {
      param_1[0x17e] = (undefined4)DAT_003070bc;
      if (param_1 + 0x186 != (undefined4 *)0x0) {
        FUN_00066338(param_1 + 0x186, 0);
      }
      if (param_1 + 0x182 != (undefined4 *)0x0) {
        FUN_00066338(param_1 + 0x182, 0);
      }
      FUN_00064a08(param_1 + 0x17e, 0);
    }
    if (param_1 != (undefined4 *)0xffffffc4) {
      param_1[0xf] = (undefined4)DAT_00309510;
    }
    FUN_0001f0f0(param_1, 0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
// near miss from lane fm10 (unreviewed)
