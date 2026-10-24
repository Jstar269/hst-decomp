/* HSTMATCH module=EBOOT.BIN start=0x000f31e0 end=0x000f3544 symbol=FUN_000f31e0 lang=c99 */
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef int code();

extern char DAT_003077f4[];
extern char *DAT_00338b44;
extern char s_data_menu_inpane_inp_ingame_inpa_002d80c4[];
extern char s_data_menu_inpane_inp_ingame_inpa_002d80f8[];
extern char *PTR_s_inpane00_singles_L_002d7a7f_1_002d7ac8[];
extern int DAT_002d7b14[];
extern int DAT_002d7cf4[];
extern int DAT_002d80b4[];
extern float DAT_002d6c9c;

extern void FUN_00102e38();
extern void FUN_00104118();
extern void FUN_00103540();
extern void FUN_001037c8();
extern int FUN_00000bcc();
extern undefined4 FUN_000f051c();
extern undefined4 FUN_001039d8();
extern int FUN_001026b8();
extern void FUN_000ffc3c();
extern void FUN_000f3640();
extern void FUN_000f4cac();
extern void FUN_000f4cf0();

undefined4 *FUN_000f31e0(undefined4 *param_1, undefined4 param_2)
{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  char **ppuVar6;
  int *piVar7;
  int *puVar8;
  int iVar9;

  FUN_00102e38();
  *param_1 = (undefined4)DAT_003077f4;
  param_1[0x6e] = 0;
  param_1[0x87] = 0;
  if (*(char *)(DAT_00338b44 + 0x45) == '\0') {
    FUN_00104118(param_1, s_data_menu_inpane_inp_ingame_inpa_002d80c4, 0);
  }
  else {
    FUN_00104118(param_1, s_data_menu_inpane_inp_ingame_inpa_002d80f8, 0);
  }
  FUN_00103540(DAT_002d6c9c, param_1);
  FUN_001037c8(param_1, 0xffffff05);
  iVar2 = FUN_00000bcc(0x84);
  uVar3 = 0;
  if (iVar2 != 0) {
    uVar3 = FUN_000f051c(iVar2);
  }
  param_1[0x6e] = uVar3;
  iVar9 = 0;
  puVar8 = DAT_002d7b14;
  iVar2 = 0;
  ppuVar6 = PTR_s_inpane00_singles_L_002d7a7f_1_002d7ac8;
  do {
    if (*(char *)(DAT_00338b44 + 0x45) == '\0') {
      uVar3 = FUN_001039d8(param_1, *puVar8, 0);
      *(undefined4 *)((int)param_1 + iVar2 + 0x58) = uVar3;
    }
    else {
      uVar3 = FUN_001039d8(param_1, *ppuVar6, 0);
      *(undefined4 *)((int)param_1 + iVar2 + 0x58) = uVar3;
    }
    iVar9 = iVar9 + 1;
    puVar8 = puVar8 + 1;
    iVar2 = iVar2 + 4;
    ppuVar6 = ppuVar6 + 1;
  } while (iVar9 < 4);
  iVar9 = 0;
  piVar7 = DAT_002d7cf4;
  iVar2 = 0;
  do {
    iVar4 = FUN_001026b8(param_1[*piVar7 + 0x16], piVar7[1]);
    *(int *)((int)param_1 + iVar2 + 0x68) = iVar4;
    if (iVar4 == 0) {
      piVar7[2] = 0;
    }
    else {
      piVar7[2] = *(int *)(iVar4 + 0x24);
    }
    iVar9 = iVar9 + 1;
    piVar7 = piVar7 + 3;
    iVar2 = iVar2 + 4;
  } while (iVar9 < 0x50);
  iVar9 = 0;
  piVar7 = DAT_002d80b4;
  iVar2 = 0;
  do {
    if (param_1[*piVar7 + 0x1a] != 0) {
      piVar5 = *(int **)(param_1[*piVar7 + 0x1a] + 0x20);
      *(int **)((int)param_1 + iVar2 + 0x1a8) = piVar5;
      (**(code **)(*piVar5 + 0x1c))(piVar5, 0xfffffff0);
    }
    iVar9 = iVar9 + 1;
    piVar7 = piVar7 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar9 < 4);
  iVar9 = 0;
  iVar2 = 0;
  while (1) {
    if (*(char *)(DAT_00338b44 + 0x45) == '\0') {
      iVar4 = 4;
    }
    else {
      iVar4 = 2;
    }
    if (iVar4 <= iVar9) break;
    FUN_000ffc3c(*(undefined4 *)((int)param_1 + iVar2 + 0xc0), 0xffffff06);
    iVar2 = iVar2 + 4;
    iVar9 = iVar9 + 1;
  }
  param_1[0x70] = param_2;
  FUN_000f3640(param_1);
  iVar2 = (int)*(short *)(param_1[0x58] + 4) + (int)*(short *)(param_1[0x58] + 8);
  uVar1 = (undefined2)(iVar2 >> 1);
  if (iVar2 < 0) {
    uVar1 = (undefined2)(iVar2 + 1 >> 1);
  }
  *(undefined2 *)(param_1 + 0x7f) = uVar1;
  iVar2 = (int)*(short *)(param_1[0x58] + 6) + (int)*(short *)(param_1[0x58] + 10);
  uVar1 = (undefined2)(iVar2 >> 1);
  if (iVar2 < 0) {
    uVar1 = (undefined2)(iVar2 + 1 >> 1);
  }
  *(undefined2 *)(param_1 + 0x80) = uVar1;
  iVar2 = (int)*(short *)(param_1[0x59] + 4) + (int)*(short *)(param_1[0x59] + 8);
  uVar1 = (undefined2)(iVar2 >> 1);
  if (iVar2 < 0) {
    uVar1 = (undefined2)(iVar2 + 1 >> 1);
  }
  *(undefined2 *)((int)param_1 + 0x1fe) = uVar1;
  iVar2 = (int)*(short *)(param_1[0x59] + 6) + (int)*(short *)(param_1[0x59] + 10);
  uVar1 = (undefined2)(iVar2 >> 1);
  if (iVar2 < 0) {
    uVar1 = (undefined2)(iVar2 + 1 >> 1);
  }
  *(undefined2 *)((int)param_1 + 0x202) = uVar1;
  *(undefined4 *)param_1[0x5c] = 0xffffff;
  *(undefined4 *)param_1[0x5d] = 0xffffff;
  *(undefined4 *)param_1[0x62] = 0xffffff;
  *(undefined4 *)param_1[99] = 0xffffff;
  *(undefined4 *)param_1[0x48] = 0x802a237f;
  *(undefined4 *)param_1[0x49] = 0x80004b7f;
  *(undefined4 *)param_1[0x4a] = 0x802a237f;
  *(undefined4 *)param_1[0x4b] = 0x80004b7f;
  *(undefined4 *)param_1[0x4c] = 0x802a237f;
  *(undefined4 *)param_1[0x4d] = 0x80004b7f;
  *(undefined4 *)param_1[0x4e] = 0x802a237f;
  *(undefined4 *)param_1[0x4f] = 0x80004b7f;
  FUN_000f4cac(param_1);
  FUN_000f4cf0(param_1);
  return param_1;
}
// near miss from lane fm10 (unreviewed)
