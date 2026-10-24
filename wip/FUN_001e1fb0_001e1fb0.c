/* HSTMATCH module=EBOOT.BIN start=0x001e1fb0 end=0x001e22cc symbol=FUN_001e1fb0 lang=c99 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned char bool;

extern char s_data_menu_result_result_get_resu_002ebe78[];
extern char s_game_700_prize_031_prize_display_002ebea8[];
extern char s_data_menu_result_result_get_resu_002ebecc[];
extern char s_game_700_prize_035_prize_display_002ebef8[];
extern char s_data_menu_result_result_get_resu_002ebf28[];
extern char s_data_menu_result_result_get__002ebf68[];
extern char *PTR_s_court_002ebc48[];
extern char DAT_002c8198[];
extern char DAT_002c83a8[];
extern char DAT_002c83cc[];
extern char DAT_002ebd24[];
extern char DAT_002ebf5c[];
extern char DAT_002ebf60[];
extern char DAT_0030ebf4[];

extern void FUN_00104118();
extern void FUN_0001cb88();
extern void FUN_0001cad0();
extern void FUN_00103540();
extern void FUN_001037c8();
extern int FUN_00000bcc();
extern undefined4 FUN_0021d7c4();
extern int FUN_001ee200();
extern void FUN_0021e2d4();
extern void FUN_00216e90();
extern void FUN_00216f14();
extern void FUN_00216fb0();
extern void FUN_0021704c();
extern void FUN_0001ca58();
extern undefined4 FUN_000649c0();
extern void FUN_00064bf4();
extern undefined4 FUN_0006517c();
extern undefined4 FUN_00014d64();
extern void FUN_000143b0();
extern void FUN_000111c0();
extern undefined4 FUN_00102e38();
extern void FUN_001041dc();
extern void FUN_00217778();
extern void FUN_00217704();

void FUN_001e1fb0(int param_1)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  undefined1 auStack_8[8];

  FUN_00104118(*(undefined4 *)(param_1 + 0x195c), s_data_menu_result_result_get_resu_002ebe78, 0);
  FUN_0001cb88(DAT_0030ebf4);
  FUN_0001cad0(DAT_0030ebf4, 1, s_game_700_prize_031_prize_display_002ebea8);
  FUN_00104118(*(undefined4 *)(param_1 + 0x1958), s_data_menu_result_result_get_resu_002ebecc, 0);
  FUN_00103540(0x45354000, *(undefined4 *)(param_1 + 0x1958));
  FUN_001037c8(*(undefined4 *)(param_1 + 0x1958), 0xffffff00);
  iVar2 = FUN_00000bcc(0x210);
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 + 0x1d64) = 0;
  }
  else {
    uVar4 = FUN_0021d7c4(iVar2);
    *(undefined4 *)(param_1 + 0x1d64) = uVar4;
  }
  iVar2 = FUN_001ee200();
  *(undefined4 *)(*(int *)(param_1 + 0x1d64) + 0x170) = *(undefined4 *)(iVar2 + 0x1368);
  FUN_0021e2d4(*(undefined4 *)(param_1 + 0x1d64), 1);
  FUN_0001cb88(DAT_0030ebf4);
  FUN_00216e90(param_1 + 0x1960, *(undefined4 *)(param_1 + 0x1958), PTR_s_court_002ebc48, 3);
  FUN_00216f14(param_1 + 0x196c, param_1 + 0x1960, DAT_002c8198, 0x10);
  FUN_00216fb0(param_1 + 0x1aac, param_1 + 0x1960, DAT_002c83a8, 1);
  FUN_0021704c(param_1 + 0x1ab8, param_1 + 0x1960, DAT_002c83cc, 3);
  iVar2 = FUN_001ee200();
  piVar6 = (int *)(iVar2 + 0x12e0);
  bVar1 = 0;
  iVar2 = 0;
  do {
    if (*piVar6 == 5) {
      iVar7 = piVar6[1];
      if (iVar7 == 0) {
        iVar7 = 1;
      }
      FUN_0001ca58(DAT_0030ebf4, s_game_700_prize_035_prize_display_002ebef8, iVar7);
      iVar3 = FUN_00000bcc(0x10);
      uVar4 = 0;
      if (iVar3 != 0) {
        uVar4 = FUN_000649c0(iVar3);
      }
      FUN_00064bf4(uVar4, s_data_menu_result_result_get_resu_002ebf28, 1, DAT_002ebd24);
      uVar5 = FUN_0006517c(uVar4, 1, 0);
      uVar5 = FUN_00014d64(uVar5, DAT_002ebf5c);
      FUN_000143b0(auStack_8, DAT_002ebf60, iVar7);
      FUN_000111c0(uVar5, auStack_8, 2);
      iVar7 = FUN_00000bcc(0x54);
      if (iVar7 == 0) {
        iVar7 = piVar6[1];
        uVar5 = 0;
      }
      else {
        uVar5 = FUN_00102e38(iVar7);
        iVar7 = piVar6[1];
      }
      *(undefined4 *)(param_1 + iVar7 * 4 + 0x1adc) = uVar5;
      FUN_001041dc(*(undefined4 *)(param_1 + piVar6[1] * 4 + 0x1adc), uVar4,
                   s_data_menu_result_result_get__002ebf68, 0);
      FUN_00103540(0x45354000, *(undefined4 *)(param_1 + piVar6[1] * 4 + 0x1adc));
      FUN_001037c8(*(undefined4 *)(param_1 + piVar6[1] * 4 + 0x1adc), 0xffffff00);
      if (!bVar1) {
        FUN_00217778(param_1 + 0x1bc0, *(undefined4 *)(param_1 + piVar6[1] * 4 + 0x1adc));
      }
      bVar1 = 1;
      FUN_0001cb88(DAT_0030ebf4);
    }
    iVar2 = iVar2 + 1;
    piVar6 = piVar6 + 3;
  } while (iVar2 < 10);
  FUN_00217704(param_1 + 0x1b34, *(undefined4 *)(param_1 + 0x1964));
  FUN_00217704(param_1 + 0x1c4c, *(undefined4 *)(param_1 + 0x1960));
  FUN_00217778(param_1 + 0x1cd8, *(undefined4 *)(param_1 + 0x1d64));
  return;
}

// NEAR MISS 0x001e1fb0 (coverage pass, 1 compile): 201/199 words, 146 differ, first diff at +0x74.
// First shot from the pseudocode, so the shape is already close. Note FUN_00001960+param_1 in
// Ghidra is a FIELD (param_1 + 0x1960), not a function pointer; DAT_0030ebf4 is the handle
// passed to FUN_0001cb88/FUN_0001cad0/FUN_0001ca58; the prize loop walks 10 structs of 3 ints
// at *(u32*)(FUN_001ee200() + 0x12e0) and stores handles at param_1 + piVar6[1]*4 + 0x1adc.
// near miss from lane fm10 (unreviewed)
