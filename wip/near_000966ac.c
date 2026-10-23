/* HSTMATCH module=EBOOT.BIN start=0x000966ac end=0x00096994 symbol=FUN_000966ac lang=c99 */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined * DAT_003386b0;
extern undefined DAT_003386b8;
extern undefined4 DAT_00338750;
extern undefined4 DAT_00338754;
extern undefined4 DAT_00338af0;
extern undefined * DAT_00338b44;
extern char DAT_002d4378[];
extern void FUN_00096994();
extern void FUN_000969c0();
extern void FUN_000b0d40();
extern void FUN_000b12d8();
extern int FUN_000c4ba0();
extern void FUN_000dcd64();

undefined4 FUN_000966ac(int param_1)
{
  undefined1 uVar1;
  bool bVar2;
  uchar *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  bVar2 = false;
  if (DAT_003386b8 != '\0') {
    bVar2 = *(uchar *)(param_1 + 0x1b4) != '\0';
  }
  if ((((bVar2) && (DAT_00338af0 != 0)) &&
      (pcVar3 = (uchar *)FUN_000c4ba0(DAT_00338af0,*(undefined4 *)(param_1 + 0x148)),
      *pcVar3 != '\0')) && (*(int *)(param_1 + 0x2e8) != *(int *)(pcVar3 + 0x128))) {
    iVar4 = FUN_000c4ba0(DAT_00338af0,*(undefined4 *)(param_1 + 0x148));
    uVar1 = *(undefined1 *)(*(int *)(param_1 + 0x148) + iVar4 + 0xc);
    if (*(uchar *)(DAT_00338b44 + 0x45) == '\0') {
      iVar4 = 4;
    }
    else {
      iVar4 = 2;
    }
    iVar7 = 0;
    if (iVar4 != 0) {
      iVar6 = 0;
      do {
        bVar2 = false;
        if (DAT_003386b8 != '\0') {
          bVar2 = *(uchar *)(*(int *)(DAT_003386b0 + iVar6 + 0x70) + 0x1b4) == '\0';
        }
        if (bVar2) {
          iVar5 = FUN_000c4ba0(DAT_00338af0,iVar7);
          *(undefined1 *)(iVar5 + *(int *)(param_1 + 0x148) + 0xc) = uVar1;
        }
        iVar7 = iVar7 + 1;
        iVar6 = iVar6 + 4;
      } while (iVar7 < iVar4);
    }
    *(undefined4 *)(param_1 + 0x2e8) = *(undefined4 *)(pcVar3 + 0x128);
    bVar2 = false;
    if (((int)DAT_00338750 << 0x1d) >> 0x1e == ((int)pcVar3[0x120] << 0x1d) >> 0x1e) {
      if (((int)DAT_00338750 << 0x1f < 0) || (-1 < (int)pcVar3[0x120] << 0x1f)) {
        if (((int)*(short *)(pcVar3 + 0x124) << 2 | ((int)pcVar3[0x120] << 0x1a) >> 0x1d) <
            ((int)DAT_00338754 << 2 | ((int)DAT_00338750 << 0x1a) >> 0x1d)) {
          bVar2 = true;
        }
      }
      else {
        bVar2 = true;
      }
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      FUN_00096994(DAT_002d4378,*(undefined4 *)(param_1 + 0x144),
                   *(undefined4 *)(param_1 + 0x148));
      uVar10 = *(undefined4 *)(pcVar3 + 0xf4);
      uVar8 = *(undefined4 *)(pcVar3 + 0xf8);
      uVar9 = *(undefined4 *)(pcVar3 + 0xfc);
      *(undefined4 *)(param_1 + 0x2b0) = *(undefined4 *)(pcVar3 + 0xf0);
      *(undefined4 *)(param_1 + 0x2b4) = uVar10;
      *(undefined4 *)(param_1 + 0x2b8) = uVar8;
      *(undefined4 *)(param_1 + 700) = uVar9;
      uVar10 = *(undefined4 *)(pcVar3 + 0x104);
      uVar8 = *(undefined4 *)(pcVar3 + 0x108);
      uVar9 = *(undefined4 *)(pcVar3 + 0x10c);
      *(undefined4 *)(param_1 + 0x2c0) = *(undefined4 *)(pcVar3 + 0x100);
      *(undefined4 *)(param_1 + 0x2c4) = uVar10;
      *(undefined4 *)(param_1 + 0x2c8) = uVar8;
      *(undefined4 *)(param_1 + 0x2cc) = uVar9;
      *(undefined4 *)(param_1 + 0x2d0) = *(undefined4 *)(pcVar3 + 0x110);
      *(undefined4 *)(param_1 + 0x2d4) = *(undefined4 *)(pcVar3 + 0x114);
      *(undefined4 *)(param_1 + 0x2d8) = *(undefined4 *)(pcVar3 + 0x118);
      *(undefined4 *)(param_1 + 0x2dc) = *(undefined4 *)(pcVar3 + 0x11c);
      *(undefined4 *)(param_1 + 0x2e0) = *(undefined4 *)(pcVar3 + 0x120);
      *(undefined2 *)(param_1 + 0x2e4) = *(undefined2 *)(pcVar3 + 0x124);
      *(uchar *)(param_1 + 0x2e6) = pcVar3[0x126];
      *(uchar *)(param_1 + 0x2e7) = pcVar3[0x127];
      *(undefined4 *)(param_1 + 0x2e8) = *(undefined4 *)(pcVar3 + 0x128);
      FUN_000969c0(pcVar3);
      FUN_000dcd64(DAT_00338b44,(int)*(uchar *)(param_1 + 0x2e7));
      if ((int)*(uchar *)(param_1 + 0x2e0) << 0x1f < 0) {
        FUN_000b12d8(param_1,param_1 + 0x2b0);
      }
      else {
        FUN_000b0d40(param_1,param_1 + 0x2b0,1,1);
      }
      return 1;
    }
  }
  return 0;
}
// Best near miss: 139 differing words remain. The retail global DAT_003386b8 load is a byte;
// declaring it unsigned matches lbu and improves the generated baseline by one word. State gating
// and record-copy control flow still differ substantially. Tried volatile and integer flag forms,
// byte-pointer parameters, combined boolean conditions, and typed float record copies.
// near miss from lane km4 (unreviewed)
