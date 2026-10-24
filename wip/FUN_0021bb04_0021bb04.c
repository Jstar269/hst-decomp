/* HSTMATCH module=EBOOT.BIN start=0x0021bb04 end=0x0021be48 symbol=FUN_0021bb04 lang=c99 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;

extern char DAT_00309784[];
extern char s_data_menu_lobby_lobbyinpane_item_002f0394[];
extern char s_L_data_menu_lobby_lobbyinpane_it_002f0366[];
extern char *PTR_s_itembanner_002f019b_1_002f01b4[];
extern int DAT_002f0288[];
extern int DAT_002f0360;
extern float DAT_002eff88;

extern void FUN_00102e38();
extern void FUN_00104118();
extern int FUN_00000bcc();
extern undefined4 FUN_0021d7c4();
extern void FUN_0021e2d4();
extern void FUN_00103540();
extern undefined4 FUN_001039d8();
extern int FUN_001026b8();
extern void FUN_00022498();
extern void FUN_0021ca68();

undefined4 *FUN_0021bb04(undefined4 *param_1, undefined1 param_2)
{
  undefined4 uVar1;
  int iVar2;
  unsigned int uVar3;
  int iVar4;
  char **ppuVar5;
  int *piVar6;
  int iVar7;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  FUN_00102e38();
  *param_1 = (undefined4)DAT_00309784;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x34] = 0;
  *(undefined1 *)((int)param_1 + 0xdd) = param_2;
  if (*(char *)((int)param_1 + 0xdd) == '\0') {
    FUN_00104118(param_1, s_data_menu_lobby_lobbyinpane_item_002f0394, 0);
  }
  else {
    FUN_00104118(param_1, s_L_data_menu_lobby_lobbyinpane_it_002f0366 + 2, 0);
    iVar4 = FUN_00000bcc(0x210);
    if (iVar4 == 0) {
      param_1[0x2f] = 0;
      uVar1 = 0;
    }
    else {
      uVar1 = FUN_0021d7c4(iVar4);
      param_1[0x2f] = uVar1;
    }
    FUN_0021e2d4(uVar1, 0);
  }
  FUN_00103540(DAT_002eff88, param_1);
  iVar7 = 0;
  ppuVar5 = PTR_s_itembanner_002f019b_1_002f01b4;
  iVar4 = 0;
  do {
    uVar1 = FUN_001039d8(param_1, *ppuVar5, 0);
    *(undefined4 *)((int)param_1 + iVar4 + 0x68) = uVar1;
    iVar7 = iVar7 + 1;
    ppuVar5 = ppuVar5 + 1;
    iVar4 = iVar4 + 4;
  } while (iVar7 < 2);
  iVar7 = 0;
  piVar6 = DAT_002f0288;
  iVar4 = 0;
  do {
    if (*(char *)((int)param_1 + 0xdd) == '\0') {
      if ((iVar7 < 3) || (0xe < iVar7)) {
        iVar2 = *piVar6;
        goto LAB_0021bc28;
      }
      *(undefined4 *)((int)param_1 + iVar4 + 0x70) = 0;
    }
    else {
      iVar2 = *piVar6;
LAB_0021bc28:
      iVar2 = FUN_001026b8(param_1[iVar2 + 0x1a], piVar6[1]);
      *(int *)((int)param_1 + iVar4 + 0x70) = iVar2;
      piVar6[2] = *(int *)(iVar2 + 0x24);
    }
    iVar7 = iVar7 + 1;
    piVar6 = piVar6 + 3;
    iVar4 = iVar4 + 4;
    if (0x11 < iVar7) {
      iVar4 = *(int *)(param_1[DAT_002f0360 + 0x1c] + 0x20);
      param_1[0x30] = iVar4;
      uVar3 = *(unsigned int *)param_1[DAT_002f0360 + 0x1c];
      *(unsigned int *)(iVar4 + 0x118) = uVar3;
      local_10 = (float)(uVar3 & 0xff);
      local_c = (float)((uVar3 & 0xffff) >> 8);
      local_8 = (float)((uVar3 & 0xffffff) >> 0x10);
      local_4 = (float)(uVar3 >> 0x18);
      FUN_00022498(0x3c03126f, &local_20, &local_10);
      *(undefined4 *)(iVar4 + 0x120) = local_20;
      *(undefined4 *)(iVar4 + 0x124) = local_1c;
      *(undefined4 *)(iVar4 + 0x128) = local_18;
      *(undefined4 *)(iVar4 + 300) = local_14;
      if (*(char *)((int)param_1 + 0xdd) == '\0') {
        param_1[0x31] = 0;
        param_1[0x32] = 0;
        param_1[0x33] = 0;
      }
      else {
        param_1[0x31] = *(undefined4 *)(param_1[0x21] + 0x20);
        param_1[0x32] = *(undefined4 *)(param_1[0x22] + 0x20);
        param_1[0x33] = *(undefined4 *)(param_1[0x23] + 0x20);
      }
      if (*(char *)((int)param_1 + 0xdd) == '\0') {
        iVar4 = param_1[0x1e];
        *(short *)(iVar4 + 8) = *(short *)(iVar4 + 4) + 0x40;
        *(short *)(iVar4 + 10) = *(short *)(iVar4 + 6) + 0x40;
        param_1[0x17] = 0;
      }
      else {
        param_1[0x17] = 0;
      }
      param_1[0x18] = 0;
      param_1[0x19] = 0xffffffff;
      param_1[0x35] = 0;
      param_1[0x36] = 0;
      *(undefined1 *)(param_1 + 0x37) = 0;
      param_1[0x38] = 0;
      param_1[0x39] = 0;
      FUN_0021ca68(param_1);
      return param_1;
    }
  } while (1);
}

// NEAR MISS 0x0021bb04 (coverage pass, 1 compile): 179/209 words, first diff at +0x0
// (frame/saved-regs differ - retail keeps more state than this first sketch). Written from the
// pseudocode including the goto-sharing between the two arms of the 18-iteration loop; the
// tail inside 'if (0x11 < iVar7)' is the constructor epilogue and returns param_1.
// near miss from lane fm10 (unreviewed)
