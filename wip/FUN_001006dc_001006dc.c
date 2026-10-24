/* HSTMATCH module=EBOOT.BIN start=0x001006dc end=0x00100a1c symbol=FUN_001006dc lang=c99 */
typedef unsigned int undefined4;
typedef unsigned char undefined1;
typedef unsigned int uint;

extern char DAT_002d8a28;
extern char DAT_002d8a54;
extern char DAT_002d8a5c;
extern char DAT_0033b394;
extern char s_______Use_cached_map___s________002d8a60[];

extern void FUN_000511c4();
extern void FUN_00051398();
extern void FUN_000149a8();
extern void FUN_00014788();
extern int FUN_00014cfc();
extern int FUN_00014a58();
extern int FUN_00000bcc();
extern void FUN_000ff7d8();
extern int FUN_00014934();
extern void FUN_001006b0();

void FUN_001006dc(int param_1, undefined4 param_2, char *param_3, undefined4 param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  undefined1 auStack_100[256];

  FUN_000511c4(param_1, param_2, param_4);
  FUN_00051398(0x47c35000, param_1);
  if (param_3 == (char *)0x0) {
    FUN_000149a8(auStack_100, param_2);
    FUN_00014788(auStack_100, &DAT_002d8a28);
    iVar1 = FUN_00014cfc(auStack_100, 0x2f);
    if ((iVar1 == 0) || (iVar2 = FUN_00014a58(iVar1 + 1, &DAT_002d8a54, 4), iVar2 != 0)) {
      puVar4 = (undefined4 *)FUN_00000bcc(0xc);
      if (puVar4 != (undefined4 *)0x0) {
        *puVar4 = 0;
        puVar4[1] = 0;
        puVar4[2] = 0;
      }
      *(undefined4 **)(param_1 + 0x54) = puVar4;
      FUN_000ff7d8(puVar4, auStack_100, 1, &DAT_002d8a5c);
      *(undefined1 *)(param_1 + 0x58) = 1;
    }
    else {
      uVar6 = 0;
      iVar2 = 0x33a6e0;
      piVar5 = (int *)&DAT_0033b394;
      do {
        iVar3 = FUN_00014934(iVar1 + 1, iVar2);
        if ((iVar3 == 0) && (*piVar5 != 0)) {
          iVar2 = *(int *)(&DAT_0033b394 + uVar6 * 4);
          goto LAB_00100950;
        }
        uVar6 = uVar6 + 1;
        iVar2 = iVar2 + 0x41;
        piVar5 = piVar5 + 1;
      } while (uVar6 < 0x32);
      iVar2 = 0;
LAB_00100950:
      *(int *)(param_1 + 0x54) = iVar2;
      if (iVar2 == 0) {
        puVar4 = (undefined4 *)FUN_00000bcc(0xc);
        if (puVar4 != (undefined4 *)0x0) {
          *puVar4 = 0;
          puVar4[1] = 0;
          puVar4[2] = 0;
        }
        *(undefined4 **)(param_1 + 0x54) = puVar4;
        FUN_000ff7d8(puVar4, auStack_100, 1, &DAT_002d8a5c);
        *(undefined1 *)(param_1 + 0x58) = 1;
      }
      else {
        FUN_001006b0(s_______Use_cached_map___s________002d8a60, iVar1 + 1);
      }
    }
  }
  else if (*param_3 != '\0') {
    FUN_000149a8(auStack_100, param_3);
    FUN_00014788(auStack_100, &DAT_002d8a28);
    iVar1 = FUN_00014cfc(auStack_100, 0x2f);
    if ((iVar1 == 0) || (iVar2 = FUN_00014a58(iVar1 + 1, &DAT_002d8a54, 4), iVar2 != 0)) {
      puVar4 = (undefined4 *)FUN_00000bcc(0xc);
      if (puVar4 != (undefined4 *)0x0) {
        *puVar4 = 0;
        puVar4[1] = 0;
        puVar4[2] = 0;
      }
      *(undefined4 **)(param_1 + 0x54) = puVar4;
      FUN_000ff7d8(puVar4, auStack_100, 1, &DAT_002d8a5c);
      *(undefined1 *)(param_1 + 0x58) = 1;
    }
    else {
      uVar6 = 0;
      iVar2 = 0x33a6e0;
      piVar5 = (int *)&DAT_0033b394;
      do {
        iVar3 = FUN_00014934(iVar1 + 1, iVar2);
        if ((iVar3 == 0) && (*piVar5 != 0)) {
          iVar2 = *(int *)(&DAT_0033b394 + uVar6 * 4);
          goto LAB_001007f0;
        }
        uVar6 = uVar6 + 1;
        iVar2 = iVar2 + 0x41;
        piVar5 = piVar5 + 1;
      } while (uVar6 < 0x32);
      iVar2 = 0;
LAB_001007f0:
      *(int *)(param_1 + 0x54) = iVar2;
      if (iVar2 == 0) {
        puVar4 = (undefined4 *)FUN_00000bcc(0xc);
        if (puVar4 != (undefined4 *)0x0) {
          *puVar4 = 0;
          puVar4[1] = 0;
          puVar4[2] = 0;
        }
        *(undefined4 **)(param_1 + 0x54) = puVar4;
        FUN_000ff7d8(puVar4, auStack_100, 1, &DAT_002d8a5c);
        *(undefined1 *)(param_1 + 0x58) = 1;
      }
      else {
        FUN_001006b0(s_______Use_cached_map___s________002d8a60, iVar1 + 1);
      }
    }
  }
  return;
}
// near miss from lane fm10 (unreviewed)
