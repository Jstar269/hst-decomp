/* HSTMATCH module=EBOOT.BIN start=0x00118598 end=0x001188c8 symbol=FUN_00118598 lang=c99 */
typedef unsigned int undefined4;
typedef unsigned char undefined1;

extern undefined4 DAT_002d9b98;
extern undefined4 DAT_002d9b9c;
extern undefined4 DAT_0033b470;
extern undefined4 DAT_0033b474;
extern undefined4 DAT_0033b478;
extern undefined4 DAT_0033b47c;
extern char DAT_003386b8;
extern undefined4 DAT_00338ac4;
extern undefined4 DAT_003386b0;
extern undefined4 DAT_0034a678;
extern char DAT_003418bc[];

extern int FUN_00000bcc();
extern undefined4 FUN_0005b670();
extern void FUN_0005c7a4();
extern void FUN_0005c810();
extern void FUN_0005bc58();
extern void FUN_0011a4ac();
extern void FUN_0011a4e8();
extern void FUN_00118908();

void FUN_00118598(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;

  iVar3 = 0;
  iVar2 = param_1;
  do {
    *(undefined4 *)(iVar2 + 0x48) = 0;
    *(undefined4 *)(iVar2 + 0x4c) = 0;
    *(undefined4 *)(iVar2 + 0x50) = 0;
    *(undefined4 *)(iVar2 + 0x54) = 0;
    *(undefined4 *)(iVar2 + 0x58) = 0;
    *(undefined4 *)(iVar2 + 0x5c) = 0;
    *(undefined4 *)(iVar2 + 0x60) = 0;
    iVar3 = iVar3 + 8;
    *(undefined4 *)(iVar2 + 100) = 0;
    iVar2 = iVar2 + 0x20;
  } while (iVar3 < 0x13);
  iVar2 = iVar3 * 4 + param_1;
  *(undefined4 *)(iVar2 + 0x48) = 0;
  *(undefined4 *)(iVar2 + 0x4c) = 0;
  *(undefined4 *)(iVar2 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  iVar2 = FUN_00000bcc(0x2c0);
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 + 0xec) = 0;
  }
  else {
    uVar1 = FUN_0005b670(iVar2);
    *(undefined4 *)(param_1 + 0xec) = uVar1;
  }
  local_10 = 0;
  local_c = 0;
  local_4 = 0;
  local_8 = 0xbf800000;
  FUN_0005c7a4(*(undefined4 *)(param_1 + 0xec), 1, &local_10);
  local_14 = 0;
  local_20 = 0x3f800000;
  local_1c = 0x3f800000;
  local_18 = 0x3f800000;
  FUN_0005c810(*(undefined4 *)(param_1 + 0xec), 1, &local_20);
  *(undefined4 *)(*(int *)(param_1 + 0xec) + 0x210) = DAT_002d9b98;
  *(undefined4 *)(*(int *)(param_1 + 0xec) + 0x20c) = DAT_002d9b9c;
  iVar2 = *(int *)(param_1 + 0xec);
  *(undefined4 *)(iVar2 + 0x1d0) = DAT_0033b470;
  *(undefined4 *)(iVar2 + 0x1d4) = DAT_0033b474;
  *(undefined4 *)(iVar2 + 0x1d8) = DAT_0033b478;
  *(undefined4 *)(iVar2 + 0x1dc) = DAT_0033b47c;
  iVar2 = *(int *)(param_1 + 0xec);
  *(undefined4 *)(iVar2 + 0x1e0) = 0;
  *(undefined4 *)(iVar2 + 0x1e4) = 0;
  *(undefined4 *)(iVar2 + 0x1e8) = 0xbf800000;
  *(undefined4 *)(iVar2 + 0x1ec) = 0;
  FUN_0005bc58(*(undefined4 *)(param_1 + 0xec));
  iVar2 = param_1;
  iVar3 = 0;
  while (1) {
    *(undefined1 *)(iVar2 + 0xb4) = 0;
    *(undefined1 *)(iVar2 + 0xcf) = 1;
    *(undefined1 *)(iVar2 + 0xb5) = 0;
    *(undefined1 *)(iVar2 + 0xd0) = 1;
    *(undefined1 *)(iVar2 + 0xb6) = 0;
    *(undefined1 *)(iVar2 + 0xd1) = 1;
    *(undefined1 *)(iVar2 + 0xb7) = 0;
    *(undefined1 *)(iVar2 + 0xd2) = 1;
    *(undefined1 *)(iVar2 + 0xb8) = 0;
    *(undefined1 *)(iVar2 + 0xd3) = 1;
    *(undefined1 *)(iVar2 + 0xb9) = 0;
    *(undefined1 *)(iVar2 + 0xd4) = 1;
    *(undefined1 *)(iVar2 + 0xba) = 0;
    *(undefined1 *)(iVar2 + 0xd5) = 1;
    *(undefined1 *)(iVar2 + 0xbb) = 0;
    *(undefined1 *)(iVar2 + 0xd6) = 1;
    iVar4 = iVar3 + 8;
    if (0x12 < iVar4) break;
    iVar2 = param_1 + iVar4;
    iVar3 = iVar4;
  }
  *(undefined1 *)(iVar4 + param_1 + 0xb4) = 0;
  *(undefined1 *)(iVar4 + param_1 + 0xcf) = 1;
  iVar4 = iVar3 + 9 + param_1;
  *(undefined1 *)(iVar4 + 0xb4) = 0;
  iVar2 = iVar3 + 10 + param_1;
  *(undefined1 *)(iVar4 + 0xcf) = 1;
  *(undefined1 *)(iVar2 + 0xb4) = 0;
  *(undefined1 *)(iVar2 + 0xcf) = 1;
  *(undefined1 *)(param_1 + 0xd6) = 0;
  *(undefined1 *)(param_1 + 0xd5) = 0;
  *(undefined1 *)(param_1 + 0xe2) = 0;
  *(undefined1 *)(param_1 + 0xe1) = 0;
  *(undefined1 *)(param_1 + 0xd7) = 0;
  *(undefined1 *)(param_1 + 0xf0) = 0;
  *(undefined1 *)(param_1 + 0xf1) = 0;
  *(undefined1 *)(param_1 + 0xf2) = 0;
  FUN_0011a4ac(param_1);
  FUN_0011a4e8(param_1);
  FUN_00118908(param_1);
  iVar3 = 0;
  iVar2 = param_1;
  do {
    iVar5 = 0;
    iVar4 = iVar2;
    do {
      *(undefined4 *)(iVar4 + 0x270) = 0;
      *(undefined4 *)(iVar4 + 0x274) = 0;
      *(undefined4 *)(iVar4 + 0x278) = 0;
      *(undefined4 *)(iVar4 + 0x27c) = 0;
      iVar5 = iVar5 + 5;
      *(undefined4 *)(iVar4 + 0x280) = 0;
      iVar4 = iVar4 + 0x14;
    } while (iVar5 < 6);
    *(undefined4 *)(iVar2 + iVar5 * 4 + 0x270) = 0;
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + 0x2c;
  } while (iVar3 < 2);
  *(undefined1 *)(param_1 + 0x2c8) = 0;
  *(undefined1 *)(param_1 + 0x2c9) = 0;
  *(undefined1 *)(param_1 + 0x2ca) = 0;
  *(undefined4 *)(param_1 + 0x2cc) = 0;
  if (DAT_003386b8 == '\0') {
    iVar2 = *(int *)(param_1 + 0x2cc);
  }
  else {
    if (DAT_00338ac4 != 0) {
      *(undefined4 *)(param_1 + 0x2cc) = *(undefined4 *)(DAT_00338ac4 + 0x198);
    }
    iVar2 = *(int *)(param_1 + 0x2cc);
  }
  *(undefined4 *)(param_1 + 0x2d0) =
      *(undefined4 *)(*(int *)(iVar2 * 4 + DAT_003386b0 + 0x70) + 0x144);
  *(undefined4 *)(param_1 + 0x2d4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x2d8) = 0;
  *(undefined1 *)(param_1 + 0x2dc) = 0;
  *(undefined1 *)(param_1 + 0x2dd) = 1;
  switch (DAT_0034a678) {
  case 0x44:
  case 0x31:
    *(undefined1 *)(param_1 + 0x2dd) = 0;
    break;
  default:
    if (DAT_003418bc[*(int *)(param_1 + 0x2cc) * 0x120] != 0) {
      *(undefined1 *)(param_1 + 0x2dd) = 0;
    }
    break;
  }
  *(undefined4 *)(param_1 + 0x314) = 0x1b;
  *(undefined4 *)(param_1 + 0x318) = 0x1b;
  *(undefined1 *)(param_1 + 0x44) = 0;
  return;
}
// near miss from lane fm10 (unreviewed)
