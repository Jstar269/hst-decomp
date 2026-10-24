/* HSTMATCH module=EBOOT.BIN start=0x001cb980 end=0x001cbccc symbol=FUN_001cb980 lang=c99 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef int code();

extern char *PTR_DAT_002c6430[];
extern char DAT_002ea308[];
extern char s__s__s_02d_002eaa7c[];
extern char DAT_002eaaac;
extern char DAT_002c0e20[];
extern char DAT_002c0e1c[];
extern char DAT_002c0e18[];
extern int DAT_0034a10c;

extern int FUN_0014c384();
extern void FUN_000143b0();
extern void FUN_000149a8();
extern int FUN_00229470();
extern int FUN_00014934();
extern int FUN_0022be84();
extern int FUN_0018c9f4();
extern int FUN_002294f4();
extern void FUN_0018a950();
extern void FUN_001cd88c();
extern int FUN_002297d8();
extern void FUN_0012ad54();
extern void FUN_000935b0();

void FUN_001cb980(int param_1, int *param_2, undefined4 param_3, int param_4)
{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  char **ppuVar5;
  uint uVar6;
  char *puVar7;
  int iVar8;
  int iVar9;
  int local_104;
  undefined1 auStack_100[256];

  if (param_2 != (int *)0x0) {
    iVar1 = (**(code **)(*param_2 + 0x34))(param_2);
    if (iVar1 == 3) {
      puVar7 = *(char **)(*(int *)(param_1 + 100) + param_2[0xc] * 4);
      if (puVar7 == (char *)0x0) {
        puVar7 = DAT_002ea308;
        iVar1 = param_2[1];
      }
      else {
        iVar1 = param_2[1];
      }
      puVar2 = (undefined4 *)FUN_0014c384(iVar1, 8);
      FUN_000143b0(auStack_100, s__s__s_02d_002eaa7c, puVar7, param_3, *puVar2);
      iVar1 = *(int *)(param_1 + 0x15c);
    }
    else {
      FUN_000149a8(auStack_100, param_3);
      iVar1 = *(int *)(param_1 + 0x15c);
    }
    iVar8 = 0;
    local_104 = FUN_00229470(iVar1 + 0x34, *(undefined4 *)(iVar1 + 0x24), auStack_100);
    if (local_104 < (int)DAT_002eaaac) {
      piVar3 = (int *)&DAT_002eaaac;
    }
    else {
      piVar3 = &local_104;
    }
    iVar1 = *piVar3;
    iVar9 = 0x15;
    uVar6 = 0;
    ppuVar5 = PTR_DAT_002c6430;
    do {
      iVar4 = FUN_00014934(param_3, *ppuVar5);
      if (iVar4 == 0) {
        iVar9 = uVar6 + 2;
        break;
      }
      uVar6 = uVar6 + 1;
      ppuVar5 = ppuVar5 + 1;
    } while (uVar6 < 0x13);
    iVar4 = param_2[0xd];
    if (param_4 == 2) {
      iVar8 = FUN_0022be84(iVar4, iVar9, iVar1, 1);
    }
    else if (param_4 == 1) {
      iVar8 = FUN_0022be84(iVar4, iVar9, iVar1, 0);
    }
    else if (param_4 == 0) {
      DAT_0034a10c = DAT_0034a10c * 0x343fd + 0x269ec3;
      iVar8 = (int)((DAT_0034a10c & 0x7fffffff) >> 0x10) % iVar1;
    }
    iVar1 = FUN_0018c9f4(7);
    if (*(int *)(iVar1 + 4) == 0) {
      puVar7 = DAT_002c0e20;
    }
    else if (*(int *)(*(int *)(iVar1 + 8) + 8) < 1) {
      puVar7 = DAT_002c0e1c;
    }
    else if ((iVar4 < 0) || ((*(int **)(iVar1 + 0xc))[1] <= iVar4)) {
      puVar7 = DAT_002c0e18;
    }
    else {
      puVar7 = *(char **)(**(int **)(iVar1 + 0xc) + iVar4 * 4);
    }
    iVar9 = *(int *)(param_1 + 0x15c);
    iVar1 = FUN_002294f4(iVar9 + 0x34, *(undefined4 *)(iVar9 + 0x24), auStack_100, iVar8);
    if (iVar1 != 0) {
      *(undefined1 *)(iVar9 + 99) = 0;
      *(undefined1 *)(iVar9 + 100) = 0;
      *(int *)(iVar9 + 0x68) = iVar1;
      *(undefined4 *)(iVar9 + 0x6c) = 0;
      *(undefined4 *)(iVar9 + 0x70) = 1;
      FUN_0018a950(*(undefined4 *)(iVar9 + 0x20), puVar7);
      FUN_001cd88c(iVar9, 2, 1);
    }
    *(undefined4 *)(iVar9 + 0x74) = 0xffffffff;
    *(undefined4 *)(iVar9 + 0x78) = 0xffffffff;
    iVar1 = FUN_002297d8(iVar9 + 0x34, auStack_100, iVar8);
    if (iVar1 < 0) {
      if (param_2 == (int *)0x0) {
        piVar3 = (int *)0x0;
        iVar1 = 0;
      }
      else {
        piVar3 = param_2 + -0x38;
        iVar1 = *piVar3;
      }
      (**(code **)(iVar1 + 0x84))(piVar3, 0, 1);
      iVar1 = *(int *)(param_1 + 0x15c);
    }
    else {
      piVar3 = param_2;
      if (param_2 != (int *)0x0) {
        piVar3 = param_2 + -0x38;
      }
      FUN_0012ad54(0xbf800000, piVar3, iVar1, 0, 0, 1, 1);
      FUN_000935b0(0, piVar3);
      iVar1 = *(int *)(param_1 + 0x15c);
    }
    *(int **)(iVar1 + 0x5c) = param_2;
  }
  return;
}
// near miss from lane fm10 (unreviewed)
