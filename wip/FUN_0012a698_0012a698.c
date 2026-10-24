/* HSTMATCH module=EBOOT.BIN start=0x0012a698 end=0x0012a8b4 symbol=FUN_0012a698 lang=c99 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef int code();
typedef unsigned char bool;

extern char DAT_0034179c[];
extern char s_lobby_footNPC1_002da95c[];
extern char s_0Alobby_footstamp1_002da946[];
extern char s_lobby_footstamp2_002da96c[];
extern float DAT_002da938;
extern float DAT_002da93c;
extern float DAT_002da940;
extern float DAT_002da944;
extern int DAT_0033b538;
extern int DAT_0033b53c;
extern int DAT_0033b540;
extern int DAT_0033b544;
extern int DAT_0033b548;
extern int DAT_0033b54c;
extern undefined4 DAT_0034a114;
extern int *DAT_0034a118;

extern undefined4 FUN_001b28f0();
extern int FUN_001cd2a8();
extern void FUN_001b2240();

void FUN_0012a698(int *param_1)
{
  char cVar1;
  bool bVar2;
  bool bVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  float fVar8;
  float fVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 local_8;
  undefined4 local_4;

  iVar6 = param_1[0x16];
  if (iVar6 != 0) {
    if (iVar6 == 0) {
      fVar9 = 1.0f;
      fVar8 = 0.0f;
    }
    else {
      fVar9 = *(float *)(iVar6 + 0x100);
      fVar8 = *(float *)(iVar6 + 0x104);
    }
    iVar5 = param_1[100];
    bVar2 = iVar5 == 4;
    bVar3 = iVar5 == 5;
    if (iVar5 == 0xc) {
      if (*(int *)(iVar6 + 0x110) < 0) {
        iVar6 = *(int *)(iVar6 + 0xf0);
      }
      else {
        iVar6 = -1;
      }
      bVar2 = iVar6 == DAT_0033b538 || iVar6 == DAT_0033b540;
      if (iVar6 != DAT_0033b538 && iVar6 != DAT_0033b540) {
        bVar2 = iVar6 == DAT_0033b53c;
      }
      bVar3 = iVar6 == DAT_0033b54c || iVar6 == DAT_0033b548;
      if (iVar6 != DAT_0033b54c && iVar6 != DAT_0033b548) {
        bVar3 = iVar6 == DAT_0033b544;
      }
    }
    if (bVar2) {
      if ((fVar8 < DAT_002da938) || (DAT_002da938 + fVar9 <= fVar8)) {
        if (fVar8 < DAT_002da93c) {
          return;
        }
        if (DAT_002da93c + fVar9 <= fVar8) {
          return;
        }
        cVar1 = (char)param_1[0x95];
      }
      else {
        cVar1 = (char)param_1[0x95];
      }
      if (cVar1 == '\0') {
        local_4 = FUN_001b28f0(DAT_0034179c, s_lobby_footNPC1_002da95c);
        uVar10 = 0x40c00000;
        uVar11 = 0x42200000;
        uVar7 = 0;
        iVar6 = FUN_001cd2a8(DAT_0034a114);
        if (iVar6 == 0) {
          uVar7 = (**(code **)(*DAT_0034a118 + 0x9c))();
          uVar10 = 0x40000000;
          uVar11 = 0x41200000;
          iVar6 = *param_1;
        }
        else {
          iVar6 = *param_1;
        }
        uVar4 = (**(code **)(iVar6 + 0x9c))(param_1);
        FUN_001b2240(0, 0x3f800000, uVar10, uVar11, DAT_0034179c, &local_4, uVar4, 0, 0, uVar7);
      }
      else {
        FUN_001b28f0(DAT_0034179c, s_0Alobby_footstamp1_002da946 + 2);
      }
    }
    else if (bVar3) {
      if ((fVar8 < DAT_002da940) || (DAT_002da940 + fVar9 <= fVar8)) {
        if (fVar8 < DAT_002da944) {
          return;
        }
        if (DAT_002da944 + fVar9 <= fVar8) {
          return;
        }
        cVar1 = (char)param_1[0x95];
      }
      else {
        cVar1 = (char)param_1[0x95];
      }
      if (cVar1 == '\0') {
        local_8 = FUN_001b28f0(DAT_0034179c, s_lobby_footNPC1_002da95c);
        uVar10 = 0x40c00000;
        uVar11 = 0x42200000;
        uVar7 = 0;
        iVar6 = FUN_001cd2a8(DAT_0034a114);
        if (iVar6 == 0) {
          uVar7 = (**(code **)(*DAT_0034a118 + 0x9c))();
          uVar10 = 0x40000000;
          uVar11 = 0x41200000;
          iVar6 = *param_1;
        }
        else {
          iVar6 = *param_1;
        }
        uVar4 = (**(code **)(iVar6 + 0x9c))(param_1);
        FUN_001b2240(0, 0x3f800000, uVar10, uVar11, DAT_0034179c, &local_8, uVar4, 0, 0, uVar7);
      }
      else {
        FUN_001b28f0(DAT_0034179c, s_lobby_footstamp2_002da96c);
      }
    }
  }
  return;
}

// NEAR MISS 0x0012a698 (coverage pass, 1 compile): 222/135 words (+87!), first diff at +0x0.
// HUGE over-expansion: retail clearly FACTORS THE TWO ARMS ONCE. The bVar2 (type 4) and bVar3
// (type 5) bodies are byte-identical apart from the window constants DAT_002da938/93c vs
// 940/944 and the else-string s_0Alobby_footstamp1 vs s_lobby_footstamp2 - in retail both
// arms almost certainly jump into ONE shared body with those four values selected by the
// branch. Rewrite as: pick (lo, hi, trampoline string) then a single body.
// near miss from lane fm10 (unreviewed)
