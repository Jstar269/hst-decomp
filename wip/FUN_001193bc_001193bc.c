/* HSTMATCH module=EBOOT.BIN start=0x001193bc end=0x001196f0 symbol=FUN_001193bc lang=c99 */
typedef unsigned int undefined4;
typedef unsigned char undefined1;
typedef unsigned char bool;

extern undefined4 DAT_00338b44;
extern undefined4 DAT_00338c20;
extern undefined4 DAT_002bc410;
extern undefined4 DAT_002bc414;
extern undefined4 DAT_002bc418;
extern undefined4 DAT_002bc41c;
extern undefined4 DAT_002bc420;
extern undefined4 DAT_002bc424;
extern undefined4 DAT_002bc428;
extern undefined4 DAT_002bc42c;
extern undefined4 DAT_002bc430;
extern undefined4 DAT_002bc434;
extern undefined4 DAT_002bc438;
extern undefined4 DAT_002bc43c;
extern undefined4 DAT_002bc440;
extern undefined4 DAT_002bc444;
extern undefined4 DAT_002bc448;
extern undefined4 DAT_002bc44c;
extern undefined4 DAT_002d9c64;
extern undefined4 DAT_002d9c68;
extern undefined4 DAT_002d9c6c;
extern undefined4 DAT_002d9c70;
extern undefined4 DAT_002d9c74;
extern undefined4 DAT_002d9c78;
extern undefined4 DAT_002d9c7c;

extern void FUN_000fb0cc();
extern void FUN_00055044();
extern void FUN_00059174();
extern void FUN_0005f0d8();

void FUN_001193bc(int param_1)
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float fVar9;
  float local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  float local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;

  if (DAT_00338b44 != 0) {
    iVar8 = 0;
    iVar7 = param_1;
    do {
      iVar5 = param_1 + iVar8;
      if (*(char *)(iVar5 + 0xb4) != '\0') {
        iVar3 = *(int *)(iVar7 + 0x48);
        iVar6 = *(int *)(iVar3 + 0x158);
        if (*(int *)(iVar3 + 0x15c) < iVar6) {
          bVar1 = 1;
        }
        else {
          iVar4 = iVar3 + iVar6 * 0x34;
          do {
            if (*(int **)(iVar4 + 0xf4) == (int *)0x0) {
              fVar9 = 0.0f;
            }
            else {
              fVar9 = *(float *)(**(int **)(iVar4 + 0xf4) + 8);
            }
            if (*(float *)(iVar4 + 0x104) < fVar9) {
              bVar1 = 0;
              goto LAB_00119470;
            }
            iVar6 = iVar6 + 1;
            iVar4 = iVar4 + 0x34;
          } while (iVar6 <= *(int *)(iVar3 + 0x15c));
          bVar1 = 1;
        }
LAB_00119470:
        if ((bVar1) && (*(char *)(iVar5 + 0xcf) != '\0')) {
          *(undefined1 *)(iVar5 + 0xb4) = 0;
          if (iVar8 == 0x1a) {
            FUN_000fb0cc(DAT_00338c20);
          }
        }
        else {
          local_3c = DAT_002bc414;
          local_38 = DAT_002bc418;
          local_34 = DAT_002bc41c;
          local_30 = DAT_002bc420;
          local_28 = DAT_002bc428;
          local_24 = DAT_002bc42c;
          local_20 = DAT_002bc430;
          local_1c = DAT_002bc434;
          local_14 = DAT_002bc43c;
          local_10 = DAT_002bc440;
          local_c = DAT_002bc444;
          local_8 = DAT_002bc448;
          local_4 = DAT_002bc44c;
          local_40 = (float)DAT_002bc410 * 8.5f;
          local_2c = (float)DAT_002bc424 * 8.5f;
          local_18 = (float)DAT_002bc438 * 8.5f;
          if (iVar8 == 9) {
            local_c = DAT_002d9c64;
            local_40 = local_40 * (float)DAT_002d9c68;
            local_2c = local_2c * (float)DAT_002d9c68;
            local_18 = local_18 * (float)DAT_002d9c68;
LAB_00119698:
            uVar2 = *(undefined4 *)(iVar7 + 0x48);
          }
          else {
            if ((iVar8 == 0xd) && (*(char *)(param_1 + 0xf2) != '\0')) {
              local_c = DAT_002d9c6c;
              local_40 = local_40 * (float)DAT_002d9c70;
              local_2c = local_2c * (float)DAT_002d9c70;
              local_18 = local_18 * (float)DAT_002d9c70;
              goto LAB_00119698;
            }
            if ((((iVar8 == 8) || (iVar8 == 7)) || (iVar8 == 6)) || (iVar8 - 0x12U < 2)) {
              local_c = DAT_002d9c74;
              goto LAB_00119698;
            }
            if (iVar8 - 0x15U < 5) {
              local_c = DAT_002d9c78;
              local_40 = local_40 * (float)DAT_002d9c7c;
              local_2c = local_2c * (float)DAT_002d9c7c;
              local_18 = local_18 * (float)DAT_002d9c7c;
              goto LAB_00119698;
            }
            uVar2 = *(undefined4 *)(iVar7 + 0x48);
          }
          FUN_00055044(uVar2, &local_40);
          *(undefined4 *)(*(int *)(iVar7 + 0x48) + 0x80) = *(undefined4 *)(*(int *)(iVar7 + 0x48) + 0x104);
          uVar2 = *(undefined4 *)(iVar7 + 0x48);
          FUN_00059174(uVar2);
          FUN_0005f0d8(uVar2);
        }
      }
      iVar8 = iVar8 + 1;
      iVar7 = iVar7 + 4;
    } while (iVar8 < 0x1b);
  }
  return;
}
// near miss from lane fm10 (unreviewed)
