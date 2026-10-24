/* HSTMATCH module=EBOOT.BIN start=0x001e77f0 end=0x001e7af4 symbol=FUN_001e77f0 lang=c99 */
typedef unsigned int undefined4;

extern void FUN_0010b980();
extern int FUN_001ee200();
extern void FUN_000ffb3c();
extern void FUN_000ffc70();
extern void FUN_00102c54();
extern undefined4 FUN_001fea10();
extern void FUN_0010d4a8();
extern int FUN_0024e2dc();

void FUN_001e77f0(int param_1)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  unsigned int uVar10;
  unsigned int uVar9;
  int iVar8;
  undefined4 *puVar4;
  undefined4 *puVar6;
  int *piVar5;
  int *piVar7;

  iVar1 = FUN_001ee200();
  uVar10 = *(unsigned int *)(iVar1 + 0x8178);
  iVar2 = FUN_001ee200();
  piVar7 = (int *)(iVar2 + 0x8184);
  {
    FUN_0010b980(*(undefined4 *)(param_1 + 0x2460), uVar10, 0);
    uVar9 = 0;
    iVar8 = 0;
    iVar1 = param_1;
    do {
      puVar4 = (undefined4 *)(param_1 + iVar8 + 0x23a0);
      puVar6 = (undefined4 *)(param_1 + iVar8 + 0x23dc);
      piVar5 = (int *)(iVar1 + 0x2364);

      if (uVar9 < *(unsigned int *)(iVar2 + 0x8188)) {
        if (uVar10 == uVar9) {
          FUN_000ffb3c(*puVar4, 0);
          FUN_000ffb3c(*puVar6, 1);
          FUN_000ffb3c(*piVar5, 0);
          *(int *)(*piVar5 + 0x24) = *(int *)(*piVar5 + 0x28) + *(int *)(*piVar7 + uVar9 * 4);
          FUN_000ffc70(*piVar5, 0x80808080);
        }
        else {
          FUN_000ffb3c(*puVar4, 1);
          FUN_000ffb3c(*puVar6, 0);
          FUN_000ffb3c(*piVar5, 0);
          *(int *)(*piVar5 + 0x24) = *(int *)(*piVar5 + 0x28) + *(int *)(*piVar7 + uVar9 * 4);
          FUN_000ffc70(*piVar5, *(undefined4 *)(iVar1 + 0x2374));
        }
      }
      else {
        FUN_000ffb3c(*puVar4, 1);
        FUN_000ffb3c(*puVar6, 1);
        FUN_000ffb3c(*piVar5, 1);
      }
      uVar9 = uVar9 + 1;
      iVar8 = iVar8 + 0x14;
      iVar1 = iVar1 + 0x14;
    } while ((int)uVar9 < 3);
    iVar1 = *(int *)(*piVar7 + uVar10 * 4);
  }
  if (iVar1 == 2) {
    *(float *)(*(int *)(param_1 + 0x2458) + 100) = (float)(*(int *)(param_1 + 0x2358) + 9);
    FUN_00102c54(*(undefined4 *)(param_1 + 0x2458));
    uVar3 = FUN_001fea10(0x11, 0x12, 5);
    iVar1 = *(int *)(param_1 + 0x2458);
    *(undefined4 *)(iVar1 + 0xf8) = uVar3;
    *(undefined4 *)(iVar1 + 0x138) = 1;
    FUN_0010d4a8();
  }
  else if (iVar1 == 1) {
    iVar1 = FUN_0024e2dc();
    if (iVar1 == 3) {
      *(float *)(*(int *)(param_1 + 0x2458) + 100) = (float)(*(int *)(param_1 + 0x2358) + 9);
      FUN_00102c54(*(undefined4 *)(param_1 + 0x2458));
      uVar3 = FUN_001fea10(0x11, 0x12, 6);
      iVar1 = *(int *)(param_1 + 0x2458);
      *(undefined4 *)(iVar1 + 0xf8) = uVar3;
      *(undefined4 *)(iVar1 + 0x138) = 1;
      FUN_0010d4a8();
    }
    else {
      *(float *)(*(int *)(param_1 + 0x2458) + 100) = (float)*(int *)(param_1 + 0x2358);
      FUN_00102c54(*(undefined4 *)(param_1 + 0x2458));
      uVar3 = FUN_001fea10(0x11, 0x12, 4);
      iVar1 = *(int *)(param_1 + 0x2458);
      *(undefined4 *)(iVar1 + 0xf8) = uVar3;
      *(undefined4 *)(iVar1 + 0x138) = 1;
      FUN_0010d4a8();
    }
  }
  else if (iVar1 == 0) {
    *(float *)(*(int *)(param_1 + 0x2458) + 100) = (float)*(int *)(param_1 + 0x2358);
    FUN_00102c54(*(undefined4 *)(param_1 + 0x2458));
    uVar3 = FUN_001fea10(0x11, 0x12, 3);
    iVar1 = *(int *)(param_1 + 0x2458);
    *(undefined4 *)(iVar1 + 0xf8) = uVar3;
    *(undefined4 *)(iVar1 + 0x138) = 1;
    FUN_0010d4a8();
  }
  return;
}
// near miss from lane fm10 (unreviewed)
