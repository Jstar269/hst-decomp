/* HSTMATCH module=EBOOT.BIN start=0x002226b4 end=0x00222a00 symbol=FUN_002226b4 lang=c99 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;

extern char DAT_00309664[];
extern char s_data_menu_decoration_decorationl_002f0f78[];
extern char s_Adata_menu_decoration_decoration_002f0f4b[];
extern char s__data_menu_decoration_kira1_002f0dcf[];
extern char s___data_menu_decoration_kira2_002f0dfa[];
extern char *PTR_s_decoration_002f0e22_2_002f0e34[];
extern int DAT_002f0ec0[];
extern float DAT_002eff88;
extern undefined4 DAT_0034a264;
extern undefined4 DAT_0034a268;
extern undefined4 DAT_0034a26c;

extern void FUN_00102e38();
extern void FUN_00104118();
extern void FUN_00103540();
extern int FUN_00000bcc();
extern undefined4 FUN_00050fc0();
extern void FUN_000511c4();
extern void FUN_00051398(float, int);
extern undefined4 FUN_001039d8();
extern int FUN_001026b8();
extern void FUN_000ffb3c();
extern void FUN_0022305c();

undefined4 *FUN_002226b4(undefined4 *param_1, undefined1 param_2)
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  char **ppuVar7;
  int iVar8;

  FUN_00102e38();
  *param_1 = (undefined4)DAT_00309664;
  param_1[0x27] = 0;
  DAT_0034a264 = (undefined4)param_1;
  *(undefined1 *)((int)param_1 + 0xb1) = param_2;
  if (*(char *)((int)param_1 + 0xb1) == '\0') {
    FUN_00104118(param_1, s_data_menu_decoration_decorationl_002f0f78, 0);
  }
  else {
    FUN_00104118(param_1, s_Adata_menu_decoration_decoration_002f0f4b + 1, 0);
  }
  FUN_00103540(DAT_002eff88, param_1);
  puVar1 = (undefined4 *)FUN_00000bcc(800);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    iVar2 = FUN_00000bcc(0x48);
    uVar3 = 0;
    if (iVar2 != 0) {
      uVar3 = FUN_00050fc0(iVar2);
    }
    *puVar1 = uVar3;
    FUN_000511c4(uVar3, s__data_menu_decoration_kira1_002f0dcf + 1, 0);
    FUN_00051398(DAT_002eff88 + 100.0f, *puVar1);
    iVar2 = 0;
    puVar5 = puVar1;
    do {
      *(undefined1 *)(puVar5 + 8) = 0;
      *(undefined1 *)(puVar5 + 0x14) = 0;
      *(undefined1 *)(puVar5 + 0x20) = 0;
      *(undefined1 *)(puVar5 + 0x2c) = 0;
      *(undefined1 *)(puVar5 + 0x38) = 0;
      *(undefined1 *)(puVar5 + 0x44) = 0;
      *(undefined1 *)(puVar5 + 0x50) = 0;
      iVar2 = iVar2 + 8;
      *(undefined1 *)(puVar5 + 0x5c) = 0;
      puVar5 = puVar5 + 0x60;
    } while (iVar2 < 0x10);
  }
  DAT_0034a268 = (undefined4)puVar1;
  puVar1 = (undefined4 *)FUN_00000bcc(800);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    iVar2 = FUN_00000bcc(0x48);
    uVar3 = 0;
    if (iVar2 != 0) {
      uVar3 = FUN_00050fc0(iVar2);
    }
    *puVar1 = uVar3;
    FUN_000511c4(uVar3, s___data_menu_decoration_kira2_002f0dfa + 2, 0);
    FUN_00051398(DAT_002eff88 + 100.0f, *puVar1);
    iVar2 = 0;
    puVar5 = puVar1;
    do {
      *(undefined1 *)(puVar5 + 8) = 0;
      *(undefined1 *)(puVar5 + 0x14) = 0;
      *(undefined1 *)(puVar5 + 0x20) = 0;
      *(undefined1 *)(puVar5 + 0x2c) = 0;
      *(undefined1 *)(puVar5 + 0x38) = 0;
      *(undefined1 *)(puVar5 + 0x44) = 0;
      *(undefined1 *)(puVar5 + 0x50) = 0;
      iVar2 = iVar2 + 8;
      *(undefined1 *)(puVar5 + 0x5c) = 0;
      puVar5 = puVar5 + 0x60;
    } while (iVar2 < 0x10);
  }
  iVar8 = 0;
  ppuVar7 = PTR_s_decoration_002f0e22_2_002f0e34;
  iVar2 = 0;
  DAT_0034a26c = (undefined4)puVar1;
  do {
    uVar3 = FUN_001039d8(param_1, *ppuVar7, 0);
    *(undefined4 *)((int)param_1 + iVar2 + 0x68) = uVar3;
    iVar8 = iVar8 + 1;
    ppuVar7 = ppuVar7 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar8 < 2);
  iVar8 = 0;
  iVar2 = 0;
  piVar6 = DAT_002f0ec0;
  do {
    *(undefined4 *)((int)param_1 + iVar2 + 0x70) = 0;
    if (param_1[*piVar6 + 0x1a] == 0) {
      iVar4 = *(int *)((int)param_1 + iVar2 + 0x70);
    }
    else {
      uVar3 = FUN_001026b8(param_1[*piVar6 + 0x1a], piVar6[1]);
      *(undefined4 *)((int)param_1 + iVar2 + 0x70) = uVar3;
      iVar4 = *(int *)((int)param_1 + iVar2 + 0x70);
    }
    if (iVar4 != 0) {
      piVar6[2] = *(int *)(iVar4 + 0x24);
    }
    iVar8 = iVar8 + 1;
    iVar2 = iVar2 + 4;
    piVar6 = piVar6 + 3;
  } while (iVar8 < 0xb);
  param_1[0x28] = *(undefined4 *)(param_1[0x22] + 0x20);
  if (*(char *)((int)param_1 + 0xb1) != '\0') {
    param_1[0x29] = *(undefined4 *)(param_1[0x1d] + 0x20);
  }
  param_1[0x18] = 0xffffffff;
  param_1[0x15] = 0xfffffc19;
  *(undefined1 *)(param_1 + 0x2c) = 0;
  *(undefined1 *)((int)param_1 + 0xb2) = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x19] = 0xffffffff;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  iVar2 = param_1[0x1e];
  param_1[0x2f] = (float)(int)*(short *)(iVar2 + 4);
  param_1[0x30] = (float)(int)*(short *)(iVar2 + 8);
  param_1[0x31] = (float)(int)*(short *)(iVar2 + 6);
  param_1[0x32] = (float)(int)*(short *)(iVar2 + 10);
  FUN_000ffb3c(param_1[0x1f], 1);
  *(undefined4 *)param_1[0x1f] = 0xffffff;
  FUN_0022305c(param_1);
  return param_1;
}
// near miss from lane fm10 (unreviewed)
