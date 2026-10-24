/* HSTMATCH module=EBOOT.BIN start=0x0023fad8 end=0x0023fe08 symbol=FUN_0023fad8 lang=c99 */
typedef unsigned int undefined4;
typedef unsigned int uint;

extern undefined4 DAT_003098d8;
extern undefined4 DAT_0034a70c;
extern undefined4 DAT_0034a6d0;
extern undefined4 DAT_0034a6d4;
extern undefined4 DAT_0034a6d8;
extern undefined4 DAT_0034a6e8;
extern undefined4 DAT_0034a6ec;
extern undefined4 DAT_0034a6f0;
extern undefined4 DAT_0034a700;
extern undefined4 DAT_0034a704;
extern undefined4 DAT_0034a708;

extern void FUN_00053718();
extern void FUN_0022909c();
extern void FUN_001466dc();
extern void FUN_00055e48();
extern void FUN_0024627c();
extern void FUN_000b42f8();
extern void FUN_0023e544();
extern void FUN_00246328();
extern void FUN_0023e5c0();
extern void FUN_0013c970();
extern void FUN_00056cb0();
extern void FUN_0001f0f0();
extern void FUN_00000a00();

extern unsigned int DAT_0035a70c;
undefined4 *FUN_0023fad8(undefined4 *param_1, short param_2)
{
  int v1v;
  *(unsigned int *)param_1 = 0x003098d8u;
  v1v = (int)(DAT_0035a70c - 1);
  if (v1v > 0) {
    *(int *)((char *)param_1 + 8) = v1v;
  }
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  char local_30;
  char local_2c;
  char local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  uint local_14;
  undefined4 local_10;
  int local_c;
  uint local_8;
  undefined4 local_4;

  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (undefined4)DAT_003098d8;
    DAT_0034a70c = DAT_0034a70c - 1;
    if ((int)DAT_0034a70c < 1) {
      uVar6 = 0;
      if (DAT_0034a6d4 != 0) {
        do {
          iVar4 = *(int *)(DAT_0034a6d0 + uVar6 * 4);
          if (iVar4 != 0) {
            FUN_00053718(iVar4, 1);
            *(undefined4 *)(DAT_0034a6d0 + uVar6 * 4) = 0;
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < (uint)DAT_0034a6d4);
      }
      DAT_0034a6d4 = 0;
      local_c = 0;
      local_8 = 0;
      local_4 = 0;
      FUN_0022909c(&local_c, DAT_0034a6d0, DAT_0034a6d0, (int)local_28);
      uVar2 = DAT_0034a6d8;
      uVar1 = DAT_0034a6d4;
      iVar4 = DAT_0034a6d0;
      DAT_0034a6d8 = local_4;
      local_4 = uVar2;
      DAT_0034a6d0 = local_c;
      local_c = iVar4;
      DAT_0034a6d4 = local_8;
      local_8 = uVar1;
      FUN_001466dc(&local_c, 0);
      uVar6 = 0;
      if (DAT_0034a6ec != 0) {
        do {
          iVar4 = *(int *)(DAT_0034a6e8 + uVar6 * 4);
          if (iVar4 != 0) {
            FUN_00055e48(iVar4, 1);
            *(undefined4 *)(DAT_0034a6e8 + uVar6 * 4) = 0;
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < (uint)DAT_0034a6ec);
      }
      DAT_0034a6ec = 0;
      local_18 = 0;
      local_14 = 0;
      local_10 = 0;
      FUN_0024627c(&local_18, DAT_0034a6e8, DAT_0034a6e8, (int)local_2c);
      uVar2 = DAT_0034a6f0;
      uVar1 = DAT_0034a6ec;
      iVar4 = DAT_0034a6e8;
      DAT_0034a6f0 = local_10;
      local_10 = uVar2;
      DAT_0034a6e8 = local_18;
      local_18 = iVar4;
      DAT_0034a6ec = local_14;
      local_14 = uVar1;
      FUN_000b42f8(&local_18, 0);
      FUN_0023e544(&DAT_0034a700, DAT_0034a704, 0);
      local_24 = 0;
      local_20 = 0;
      local_1c = 0;
      FUN_00246328(&local_24, DAT_0034a700, DAT_0034a700 + DAT_0034a704 * 0xc, (int)local_30);
      uVar1 = DAT_0034a708;
      iVar3 = DAT_0034a704;
      iVar4 = DAT_0034a700;
      DAT_0034a708 = local_1c;
      local_1c = uVar1;
      DAT_0034a700 = local_24;
      local_24 = iVar4;
      DAT_0034a704 = local_20;
      local_20 = iVar3;
      FUN_0023e5c0(&local_24, 0);
    }
    puVar5 = param_1 + 0xa8;
    if ((puVar5 != (undefined4 *)0x0) && (puVar5 != (undefined4 *)0x0)) {
      FUN_0013c970(puVar5, 0);
    }
    FUN_00056cb0(param_1 + 0x18, 0xffffffff);
    FUN_0001f0f0(param_1, 0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
// near miss from lane fm10 (unreviewed)
