/* HSTMATCH module=EBOOT.BIN start=0x001d31e8 end=0x001d3564 symbol=FUN_001d31e8 lang=c99 */
typedef unsigned int undefined4;
typedef unsigned char byte;
typedef short int16;
typedef unsigned int uint;

extern uint DAT_002eaca4;
extern uint DAT_002eaca8;

extern float FUN_0000bc34(float);
extern void FUN_000ffca4();
extern void FUN_000ffb3c();

void FUN_001d31e8(int param_1)
{
  short sVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  byte bVar9;
  short sVar10;
  uint uVar11;
  float fVar12;
  float fVar13;

  fVar13 = 1.0f;
  if (4 < *(int *)(param_1 + 0x60)) {
    fVar13 = FUN_0000bc34(((float)((*(int *)(param_1 + 0x60) + -5) % 0x14) * 6.2831855f) / 20.0f);
    fVar13 = (1.0f - fVar13) * 0.5f * 0.075f + 1.0f;
  }
  uVar6 = **(uint **)(param_1 + 0x16c);
  uVar5 = (uVar6 >> 0x18) + 0x70;
  uVar11 = DAT_002eaca4;
  if ((DAT_002eaca4 <= uVar5) && (uVar11 = DAT_002eaca8, uVar5 <= DAT_002eaca8)) {
    uVar11 = uVar5;
  }
  **(uint **)(param_1 + 0x16c) = uVar6 & 0xffffff | uVar11 << 0x18;
  if (*(int *)(param_1 + 0x54) == 0) {
    fVar12 = *(float *)(param_1 + 0x178) + (0.93f - *(float *)(param_1 + 0x178)) * 0.7f;
    *(float *)(param_1 + 0x178) = fVar12;
    *(float *)(param_1 + 0x178) = fVar12 * fVar13;
  }
  else {
    *(undefined4 *)(param_1 + 0x178) = 0x3f6e147b;
  }
  *(int *)(*(int *)(param_1 + 0x16c) + 0x24) =
      *(int *)(*(int *)(param_1 + 0x16c) + 0x28) + *(int *)(param_1 + 0xd4);
  FUN_000ffca4(*(undefined4 *)(param_1 + 0x16c));
  iVar2 = *(int *)(param_1 + 0x16c);
  fVar13 = *(float *)(param_1 + 0x178);
  iVar7 = (int)*(short *)(iVar2 + 4) + (int)*(short *)(iVar2 + 8);
  sVar4 = (short)(iVar7 >> 1);
  if (iVar7 < 0) {
    sVar4 = (short)((iVar7 + 1) >> 1);
  }
  iVar7 = (int)sVar4;
  *(short *)(iVar2 + 4) = (short)(int)((float)iVar7 + fVar13 * (float)(*(short *)(iVar2 + 4) - iVar7));
  *(short *)(iVar2 + 8) = (short)(int)((float)iVar7 + fVar13 * (float)(*(short *)(iVar2 + 8) - iVar7));
  iVar7 = (int)*(short *)(iVar2 + 6) + (int)*(short *)(iVar2 + 10);
  sVar4 = (short)(iVar7 >> 1);
  if (iVar7 < 0) {
    sVar4 = (short)((iVar7 + 1) >> 1);
  }
  iVar7 = (int)sVar4;
  *(short *)(iVar2 + 6) = (short)(int)((float)iVar7 + fVar13 * (float)(*(short *)(iVar2 + 6) - iVar7));
  *(short *)(iVar2 + 10) = (short)(int)((float)iVar7 + fVar13 * (float)(*(short *)(iVar2 + 10) - iVar7));
  iVar7 = *(int *)(param_1 + 0x6c);
  iVar2 = (int)*(short *)(iVar7 + 6) + (int)*(short *)(iVar7 + 10);
  if (iVar2 < 0) {
    iVar2 = iVar2 + 1;
  }
  sVar4 = *(short *)(param_1 + 0x176);
  iVar3 = *(int *)(param_1 + 0x16c);
  iVar7 = (int)*(short *)(iVar7 + 4) + (int)*(short *)(iVar7 + 8);
  sVar10 = (short)(iVar7 >> 1);
  if (iVar7 < 0) {
    sVar10 = (short)((iVar7 + 1) >> 1);
  }
  iVar7 = (int)(short)(*(short *)(iVar3 + 8) - *(short *)(iVar3 + 4));
  if (iVar7 < 0) {
    iVar7 = iVar7 + 1;
  }
  sVar10 = sVar10 - (short)(iVar7 >> 1);
  sVar1 = *(short *)(iVar3 + 4);
  *(short *)(iVar3 + 4) = sVar10;
  *(short *)(iVar3 + 8) = *(short *)(iVar3 + 8) + (sVar10 - sVar1);
  iVar7 = (int)(short)(*(short *)(iVar3 + 10) - *(short *)(iVar3 + 6));
  if (iVar7 < 0) {
    iVar7 = iVar7 + 1;
  }
  sVar10 = (sVar4 + (short)(iVar2 >> 1)) - (short)(iVar7 >> 1);
  sVar4 = *(short *)(iVar3 + 6);
  *(short *)(iVar3 + 6) = sVar10;
  *(short *)(iVar3 + 10) = *(short *)(iVar3 + 10) + (sVar10 - sVar4);
  iVar2 = *(int *)(param_1 + 0x54);
  bVar9 = 0;
  if (iVar2 == 0) {
LAB_001d353c:
    bVar9 = 1;
  }
  else if ((iVar2 == 5) && (*(int *)(param_1 + 0x520) == 0)) {
    bVar9 = 1;
  }
  else {
    if (iVar2 != 3) {
      uVar8 = *(undefined4 *)(param_1 + 0x16c);
      goto LAB_001d3544;
    }
    if (*(char *)(param_1 + 0x524) != '\0') goto LAB_001d353c;
  }
  uVar8 = *(undefined4 *)(param_1 + 0x16c);
LAB_001d3544:
  FUN_000ffb3c(uVar8, bVar9 ^ 1);
  return;
}
// near miss from lane fm10 (unreviewed)
