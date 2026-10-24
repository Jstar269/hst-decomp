/* HSTMATCH module=EBOOT.BIN start=0x0024b5a0 end=0x0024b8e8 symbol=FUN_0024b5a0 lang=c99 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef int code();
typedef unsigned int uint;

extern char DAT_00309910[];
extern char *PTR_s_data_court_c04_resort_gimmick_gi_002fb6e4[];
extern char *PTR_s_data_court_c04_resort_gimmick_so_002fb880[];
extern char *PTR_s_data_court_c04_resort_gimmick_gi_002fbc24[];
extern char s_eff01_002fbcf4[];
extern char s_eff02_002fbcfc[];
extern char s_eff03_002fbd04[];
extern char s_shadow_002fbd14[];
extern char DAT_002fbd0c[];
extern undefined4 DAT_002fbcc0[];
extern undefined4 DAT_0034a768;
extern int DAT_0034a76c;
extern int DAT_0034a770;
extern int DAT_0034a774;

extern void FUN_0001f06c();
extern void FUN_00056b98();
extern int FUN_00014934();
extern int FUN_00000bcc();
extern undefined4 FUN_000535d8();
extern void FUN_000537bc();
extern void FUN_00146698();
extern void FUN_000573a0();
extern int FUN_0002fe80();

undefined4 *FUN_0024b5a0(undefined4 *param_1, int param_2)
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;

  FUN_0001f06c();
  *param_1 = (undefined4)DAT_00309910;
  param_1[0xf] = 0;
  FUN_00056b98(param_1 + 0x14);
  param_1[0x81] = 0;
  param_1[0x83] = 0;
  *(undefined1 *)((int)param_1 + 0x249) = 1;
  *(undefined1 *)(param_1 + 0x95) = 0;
  param_1[0x99] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x9a) = 0;
  param_1[0x10] = DAT_002fbcc0[param_2];
  uVar3 = 0;
  if (DAT_0034a76c != 0) {
    do {
      iVar1 = FUN_00014934(PTR_s_data_court_c04_resort_gimmick_gi_002fb6e4[param_2],
                           **(undefined4 **)(DAT_0034a768 + uVar3 * 4));
      if (iVar1 == 0) {
        param_1[0x81] = *(undefined4 *)(DAT_0034a768 + uVar3 * 4);
        break;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)DAT_0034a76c);
  }
  if (param_1[0x81] == 0) {
    iVar1 = FUN_00000bcc(0x30);
    if (iVar1 == 0) {
      param_1[0x81] = 0;
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_000535d8(iVar1);
      param_1[0x81] = uVar2;
    }
    FUN_000537bc(uVar2, PTR_s_data_court_c04_resort_gimmick_gi_002fb6e4[param_2],
                 PTR_s_data_court_c04_resort_gimmick_so_002fb880[param_2], 0, 0, 0, 0);
    if (DAT_0034a76c < DAT_0034a770) {
      iVar1 = DAT_0034a76c * 4;
      DAT_0034a76c = DAT_0034a76c + 1;
      *(undefined4 *)(DAT_0034a768 + iVar1) = param_1[0x81];
    }
    else {
      FUN_00146698(&DAT_0034a768, param_1 + 0x81, 0);
    }
  }
  param_1[0x82] = 0xffffffff;
  (**(code **)(param_1[0x14] + 0xc))(param_1 + 0x14, param_1[0x81]);
  param_1[0x90] = 0;
  param_1[0x83] = param_2;
  FUN_000573a0(param_1 + 0x14, 0, PTR_s_data_court_c04_resort_gimmick_gi_002fbc24[param_2], 0, 0);
  param_1[0x8c] = param_1[0x84];
  param_1[0x8d] = param_1[0x85];
  param_1[0x8e] = param_1[0x86];
  param_1[0x8f] = param_1[0x87];
  param_1[0x91] = 0;
  DAT_0034a774 = DAT_0034a774 + 1;
  switch (param_1[0x83]) {
  case 1:
    if (*(int *)(param_1[0x37] + 8) == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = FUN_0002fe80(*(int *)(param_1[0x37] + 8), s_eff01_002fbcf4);
    }
    param_1[0x96] = uVar2;
    if (*(int *)(param_1[0x37] + 8) == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = FUN_0002fe80(*(int *)(param_1[0x37] + 8), s_eff02_002fbcfc);
    }
    param_1[0x97] = uVar2;
    if (*(int *)(param_1[0x37] + 8) == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = FUN_0002fe80(*(int *)(param_1[0x37] + 8), s_eff03_002fbd04);
    }
    param_1[0x98] = uVar2;
    break;
  case 2:
  case 4:
    iVar1 = param_1[0x37];
    if (*(int *)(iVar1 + 8) == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = FUN_0002fe80(*(int *)(iVar1 + 8), s_eff01_002fbcf4);
    }
    param_1[0x96] = uVar2;
    break;
  }
  if (param_1[0x83] == 5) {
    if (*(int *)(param_1[0x37] + 8) == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = FUN_0002fe80(*(int *)(param_1[0x37] + 8), DAT_002fbd0c);
    }
    param_1[0x9b] = uVar2;
    if (*(int *)(param_1[0x37] + 8) == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = FUN_0002fe80(*(int *)(param_1[0x37] + 8), s_shadow_002fbd14);
    }
    param_1[0x9c] = uVar2;
  }
  return param_1;
}
// near miss from lane fm10 (unreviewed)
