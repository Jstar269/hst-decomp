/* HSTMATCH module=EBOOT.BIN start=0x00205df4 end=0x002060f8 symbol=FUN_00205df4 lang=c99 rodata=0x002c93b0 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef int code();

extern undefined4 DAT_002c93b0;
extern char s__________________________________002ef6d4[];
extern char s_IsFinishBGTask______false__s__d_002ef700[];
extern char s_util_player_cpp_002ef724[];
extern char s__________________________________002ef734[];

extern int FUN_00049094();
extern void FUN_002059ec();
extern void FUN_00092c38();
extern void FUN_00055e48();
extern void FUN_00011090();
extern int FUN_00193474();
extern void FUN_00204c88();
extern void FUN_0020507c();
extern void FUN_002052b8();
extern void FUN_0005743c();
extern void FUN_00094424();
extern void FUN_00092630();

void FUN_00205df4(int *param_1, undefined1 param_2, undefined4 *param_3, undefined4 param_4,
                  undefined4 param_5, undefined4 param_6, undefined1 param_7)
{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  char local_3;
  char local_2;
  char local_1;

  *(undefined1 *)(param_1 + 0x1d) = param_2;
  iVar3 = FUN_00049094(0);
  if (iVar3 == 0) {
    FUN_002059ec(s__________________________________002ef6d4);
    FUN_002059ec(s_IsFinishBGTask______false__s__d_002ef700, s_util_player_cpp_002ef724, 0x3f0);
    FUN_002059ec(s__________________________________002ef734);
  }
  FUN_00049094(1);
  if ((char)param_1[0x1d] == '\0') {
    iVar3 = 0;
    puVar9 = &DAT_002c93b0;
    do {
      if (iVar3 < 0) {
        uVar7 = 0;
      }
      else if (iVar3 < 6) {
        uVar7 = *puVar9;
      }
      else {
        uVar7 = 0;
      }
      FUN_00092c38(*param_1, uVar7);
      iVar3 = iVar3 + 1;
      puVar9 = puVar9 + 1;
    } while (iVar3 < 6);
    iVar3 = param_1[4];
  }
  else {
    iVar3 = param_1[4];
  }
  uVar10 = 0;
  if (iVar3 != 0) {
    iVar3 = 0;
    do {
      if (*(int *)(param_1[3] + iVar3) == 0) {
        uVar4 = param_1[4];
      }
      else {
        FUN_00055e48(*(int *)(param_1[3] + iVar3), 1);
        *(undefined4 *)(param_1[3] + iVar3) = 0;
        uVar4 = param_1[4];
      }
      uVar10 = uVar10 + 1;
      iVar3 = iVar3 + 4;
    } while (uVar10 < uVar4);
  }
  param_1[4] = 0;
  *(undefined1 *)(param_1 + 0x1b) = 0;
  FUN_00011090(param_1 + 0x15, param_3, 0x18);
  local_1 = '\0';
  local_2 = '\0';
  local_3 = '\0';
  iVar3 = FUN_00193474(*param_3);
  uVar1 = *(undefined1 *)(iVar3 + 0xd);
  uVar2 = *(undefined1 *)(iVar3 + 0xc);
  *(undefined1 *)(param_1 + 0x1e) = param_7;
  if ((char)param_1[0x1d] == '\0') {
    FUN_00204c88(*param_1, &local_2, &local_1, &local_3, param_3, param_5, param_6, param_7, uVar1,
                 uVar2, 0);
  }
  else {
    FUN_00204c88(*param_1, &local_2, &local_1, &local_3, param_3, param_5, param_6, param_7, uVar1,
                 uVar2, 0);
    local_2 = '\x01';
    local_1 = '\x01';
    local_3 = '\x01';
  }
  if (local_2 != '\0') {
    FUN_0020507c(param_1, param_1[0x15]);
  }
  if (local_1 != '\0') {
    FUN_002052b8(param_1, 1, param_7);
  }
  if (local_3 == '\0') {
    iVar6 = *param_1;
  }
  else {
    iVar6 = *(int *)(*param_1 + 100);
    if (iVar6 != 0) {
      iVar8 = 0;
      iVar5 = param_1[3];
      while (1) {
        FUN_0005743c(iVar6, iVar8, *(undefined4 *)(iVar5 + iVar8 * 4), param_7);
        iVar8 = iVar8 + 1;
        if (5 < iVar8) break;
        iVar5 = param_1[3];
      }
    }
    iVar6 = *param_1;
  }
  FUN_00094424(iVar6);
  param_1[0x1c] = (uint)*(unsigned char *)(iVar3 + 0x24);
  FUN_00092630(*param_1, param_4);
  (**(code **)(*(int *)*param_1 + 0xc))();
  if (param_1[0x13] == 3) {
    if (param_1[0x14] != 0) {
      param_1[0x14] = 0;
    }
  }
  else {
    param_1[0x14] = 3;
  }
  param_1[0x12] = 1;
  return;
}
// near miss from lane fm10 (unreviewed)
