/* HSTMATCH module=EBOOT.BIN start=0x0014e11c end=0x0014e580 symbol=FUN_0014e11c lang=c99 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef int code();

extern char s_SCRIPT__002dc240[];
extern char DAT_002dc24c[];
extern char s_XX_002dc324[];
extern char s__gt_002dc31c[];
extern char DAT_002dc134[];
extern char DAT_003402f0;

extern void FUN_0014f43c();
extern void FUN_0014c610();
extern void FUN_0014f6cc();
extern void FUN_0014f064();
extern void FUN_0014f6e4();
extern void FUN_0014f540();
extern int FUN_0014ba88();
extern void FUN_0014f5e0();

undefined4 FUN_0014e11c(int *param_1, int *param_2)
{
  int v0v, v1v, flag; char *pp; char buf[16]; char d2[8]; int two; char *pa;
  v0v = *(int *)(param_2 + 0x18);
  if (v0v > 0) {
    pp = *(char **)(param_2 + 0x1c);
    v1v = *(int *)(pp + 8);
  } else {
    v1v = 0;
  }
  flag = (unsigned)(v1v ^ 1) < 1;
  v0v = *(int *)(param_2 + 0x18) + 1;
  for (two = 0; two < v0v; two++) {
    FUN_0014c610((void *)0x002dc24c);
  }
  (*(void (**)(char *))(*(char **)param_1 + 28))((char *)param_1);
  FUN_0014c610((void *)0x002dc240);
  FUN_0014f6cc(buf, (char *)param_1 + 8, 0);
  FUN_0014f064(buf, *(void **)((char *)param_1 + 0x10), (char *)param_1 + 12);
  FUN_0014f6e4(d2, 0, 0);
  v0v = *(int *)buf;
  *(int *)((char *)param_1 + 0x2f0) = (unsigned)v0v < 2;
  if (flag) { } else {
    two = 2;
    pa = (char *)(param_2 + 28);
    FUN_0014f43c(buf, (char *)(param_2 + 24), &pa, &two);
    return 0;
  }
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  char *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int *local_a0;
  int *local_9c;
  char auStack_98[4];
  char *local_94;
  char *local_90;
  char auStack_8c[4];
  int *local_88;
  char auStack_84[4];
  int *local_80;
  char auStack_7c[4];
  int *local_78;
  char auStack_74[4];
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68[3];
  undefined4 local_5c;
  char *local_58;
  char auStack_54[20];
  char auStack_40[4];
  undefined4 local_3c;
  int local_38;
  undefined4 local_34[3];
  undefined4 local_28[4];
  char auStack_18[4];
  char auStack_14[4];
  char *local_10;
  uint local_c;
  int iStack_8;
  int *local_4;

  if (param_2[6] < 1) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_2[7] + 8);
  }
  if ((iVar2 == 1) || (iVar2 == 2)) {
    local_5c = 2;
    local_78 = param_2 + 7;
    FUN_0014f43c(auStack_74, param_2 + 6, &local_78, &local_5c);
  }
  else {
    if (DAT_003402f0 != '\0') {
      if (DAT_003402f0 == '\0') {
        iVar2 = *param_1;
      }
      else {
        FUN_0014c610(s_SCRIPT__002dc240);
        if (0 < param_2[6] + 1) {
          do {
            FUN_0014c610(DAT_002dc24c);
          } while (0 < param_2[6]);
        }
        iVar2 = *param_1;
      }
      uVar1 = (**(code **)(iVar2 + 0x1c))(param_1);
      FUN_0014c610(uVar1);
    }
    FUN_0014f6cc(&local_c, param_1 + 2);
    FUN_0014f064(&local_c, param_1[4], param_1 + 3);
    FUN_0014f6e4(auStack_18);
    if (1 < local_c) {
      while (1 < local_c) {
        piVar3 = local_4;
        if (local_4 == &iStack_8) {
          local_38 = *local_4;
        }
        else {
          piVar4 = (int *)local_4[1];
          if (piVar4 != &iStack_8) {
            iVar2 = piVar4[2];
            while (1) {
              if (*(int *)(DAT_002dc134 + *(int *)(piVar3[2] + 4) * 4) <
                  *(int *)(DAT_002dc134 + *(int *)(iVar2 + 4) * 4)) {
                piVar5 = (int *)piVar4[1];
                piVar3 = piVar4;
              }
              else {
                piVar5 = (int *)piVar4[1];
              }
              if (piVar5 == &iStack_8) break;
              iVar2 = piVar5[2];
              piVar4 = piVar5;
            }
          }
          local_38 = *piVar3;
        }
        uVar9 = *(undefined4 *)(local_38 + 8);
        local_3c = *(undefined4 *)(piVar3[1] + 4);
        uVar8 = *(undefined4 *)(*(int *)(local_38 + 4) + 8);
        uVar7 = *(undefined4 *)(*(int *)(*(int *)(local_38 + 4) + 4) + 8);
        FUN_0014f540(local_34, &local_c, &local_38, &local_3c);
        uVar1 = local_34[0];
        local_28[0] = FUN_0014ba88(uVar9, uVar8, uVar7, *param_2);
        local_68[0] = uVar1;
        FUN_0014f5e0(auStack_40, &local_c, local_68, local_28);
        local_58 = auStack_14;
        FUN_0014f5e0(auStack_54, auStack_18, &local_58, local_28);
      }
    }
    iVar2 = (**(code **)(*(int *)local_4[2] + 0x14))((int *)local_4[2], *param_2);
    if (iVar2 == 0) {
      local_70 = 1;
      local_88 = param_2 + 7;
      FUN_0014f43c(auStack_84, param_2 + 6, &local_88, &local_70);
      if (DAT_003402f0 != '\0') {
        FUN_0014c610(s_XX_002dc324);
      }
    }
    else {
      local_80 = param_2 + 7;
      local_6c = 0;
      FUN_0014f43c(auStack_7c, param_2 + 6, &local_80, &local_6c);
      if (DAT_003402f0 != '\0') {
        FUN_0014c610(s__gt_002dc31c);
      }
    }
    if (local_10 != auStack_14) {
      piVar3 = *(int **)(local_10 + 8);
      puVar6 = local_10;
      while (1) {
        if (piVar3 == (int *)0x0) {
          puVar6 = *(char **)(puVar6 + 4);
        }
        else {
          (**(code **)(*piVar3 + 8))(piVar3, 1);
          puVar6 = *(char **)(puVar6 + 4);
        }
        if (puVar6 == auStack_14) break;
        piVar3 = *(int **)(puVar6 + 8);
      }
    }
    local_94 = auStack_14;
    local_90 = local_10;
    FUN_0014f540(auStack_8c, auStack_18, &local_90, &local_94);
    local_a0 = &iStack_8;
    local_9c = local_4;
    FUN_0014f540(auStack_98, &local_c, &local_9c, &local_a0);
  }
  return 0;
}

// NEAR MISS 0x0014e11c (coverage pass, 1 compile): 223/281 words, first diff at +0x0.
// UNDER-expansion by 58 words - the opposite of the other near misses. The suspect is the
// DAT_003402f0 debug block: Ghidra shows FUN_0014c610(&DAT_002dc24c) repeated per element
// (its extraout_v1 loop), which retail expands inline per iteration; this sketch has one
// call in a simple do/while. Also the linked-list sentinels (&iStack_8 / auStack_14) are
// declared as separate locals here but are one struct in the source, which likely explains
// the +0x0 prologue difference.
// near miss from lane fm10 (unreviewed)
