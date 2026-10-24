/* HSTMATCH module=EBOOT.BIN start=0x000dc90c end=0x000dcba4 symbol=FUN_000dc90c lang=c99 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned char bool;

extern char DAT_003386b8;
extern char *DAT_003386b0;
extern char DAT_003417b8[];
extern int DAT_0033b460;
extern int DAT_0034179c;

extern void FUN_000dd524();
extern void FUN_000dcca0();
extern undefined4 FUN_000224d8();
extern float FUN_00022e44();
extern void FUN_0011a504();

void FUN_000dc90c(int param_1, uint param_2, int param_3)
{
  char cVar1;
  bool bVar2;
  char *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  float fVar7;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;

  if (*(int *)(param_1 + 0x3c) == 3) {
LAB_000dc998:
    cVar1 = *(char *)(param_1 + 0x5c);
  }
  else {
    if (DAT_003386b8 != '\0') {
      if (*(char *)(param_1 + 0x44) != '\0') {
        if (*(uint *)(param_1 + 0x94) == param_2) {
          *(undefined1 *)(param_1 + 0x5c) = 0;
          *(undefined4 *)(param_1 + 0x9c) = 0xffffffff;
          *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + -1;
        }
        else {
          *(undefined1 *)(param_1 + 0x5c) = 0;
          *(undefined4 *)(param_1 + 0x9c) = 0xffffffff;
          *(undefined1 *)(param_1 + 0x5d) = 0;
          *(undefined1 *)(param_1 + 0x5e) = 0;
          *(undefined1 *)(param_1 + 0x5f) = 0;
          *(undefined1 *)(param_1 + 0x84) = 0;
        }
        *(undefined1 *)(param_1 + 0x85) = 0;
      }
      goto LAB_000dc998;
    }
    cVar1 = *(char *)(param_1 + 0x5c);
  }
  if (cVar1 != '\0') {
    return;
  }
  if (*(int *)(param_1 + 0x90) < 1) {
    uVar5 = *(undefined4 *)(param_1 + 0x98);
  }
  else {
    if (*(int *)(param_1 + 0xac) == 0) {
      *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(param_1 + 0x98);
    }
    uVar5 = *(undefined4 *)(param_1 + 0x98);
  }
  FUN_000dd524(param_1, uVar5);
  iVar4 = *(int *)(param_1 + 0x90) + 1;
  *(int *)(param_1 + 0x90) = iVar4;
  if (iVar4 == 1) {
    FUN_000dcca0(param_1, param_3);
    iVar4 = *(int *)(DAT_003386b0 + 0x88);
    local_10 = *(undefined4 *)(iVar4 + 0x20);
    local_c = *(undefined4 *)(iVar4 + 0x24);
    local_8 = *(undefined4 *)(iVar4 + 0x28);
    local_4 = *(undefined4 *)(iVar4 + 0x2c);
    uVar5 = FUN_000224d8(&local_10, &local_10);
    fVar7 = (float)FUN_00022e44(uVar5);
    *(float *)(param_1 + 0x80) = fVar7 * 3.6f;
  }
  else {
    if (iVar4 != 2) {
      *(uint *)(param_1 + 0x94) = param_2;
      goto LAB_000dcad0;
    }
    if (*(int *)(param_1 + 0xac) == 0) {
      if (*(char *)(param_1 + 0x61) == '\0') {
        *(undefined1 *)(param_1 + 0x5c) = 1;
        *(undefined1 *)(param_1 + 0x85) = 1;
        *(uint *)(param_1 + 0x9c) = param_2 ^ 1;
      }
      else {
        *(undefined1 *)(param_1 + 99) = 0;
        FUN_000dcca0(param_1, *(undefined4 *)(param_1 + 0x98), 0xffffffff);
        *(undefined1 *)(param_1 + 0x5d) = 1;
        *(undefined1 *)(param_1 + 0x5c) = 1;
      }
    }
    else if (*(char *)(*(int *)(param_3 * 4 + DAT_003386b0 + 0x70) + 0x408) == '\0') {
      *(undefined1 *)(param_1 + 0x5c) = 1;
      *(undefined1 *)(param_1 + 0x85) = 1;
      *(uint *)(param_1 + 0x9c) = param_2 ^ 1;
    }
  }
  *(uint *)(param_1 + 0x94) = param_2;
LAB_000dcad0:
  *(int *)(param_1 + 0x98) = param_3;
  *(bool *)(param_1 + 0x60) = *(int *)(*(int *)(param_3 * 4 + DAT_003386b0 + 0x70) + 0x4e8) == 2;
  *(undefined1 *)(param_1 + 0x61) = 0;
  *(undefined1 *)(param_1 + 99) = 0;
  *(undefined4 *)(param_1 + 0xac) = 0;
  *(undefined1 *)(param_1 + 100) = 0;
  *(undefined1 *)(param_1 + 0x65) = 0;
  *(undefined1 *)(param_1 + 0x66) = 0;
  *(undefined1 *)(param_1 + 0x67) = 0;
  *(undefined4 *)(param_1 + 0x68) = 3;
  *(undefined4 *)(param_1 + 0x6c) = 0xd;
  *(undefined1 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined1 *)(param_1 + 0x71) = 0;
  *(undefined1 *)(param_1 + 0x72) = 0;
  *(undefined1 *)(param_1 + 0x73) = 0;
  *(undefined1 *)(param_1 + 0x74) = 0;
  *(undefined1 *)(param_1 + 0x75) = 0;
  puVar3 = DAT_003417b8;
  uVar6 = 0;
  do {
    if (puVar3[9] == '\x04') {
      bVar2 = 1;
LAB_000dcb78:
      if ((bVar2) && (*(char *)(param_1 + 0x60) != '\0')) {
        *(undefined1 *)(param_1 + 0x5c) = 1;
        *(uint *)(param_1 + 0x9c) = param_2 ^ 1;
        FUN_0011a504(0, DAT_0033b460, 0, 0);
      }
      return;
    }
    if (1 < uVar6 + 1) {
      bVar2 = 0;
      goto LAB_000dcb78;
    }
    puVar3 = DAT_003417b8 + 1 + uVar6;
    uVar6 = uVar6 + 1;
  } while (1);
}

// NEAR MISS 0x000dc90c (coverage pass, 1 compile): 186/166 words (+20), first diff at +0x24.
// The trailing scan is Ghidra's rendering of a two-byte short circuit: iterations check
// (&DAT_003417b8)[9] (= 0x3417c1) then (&DAT_003417b9)[9] (= 0x3417c2) and stop, so the
// source is likely bVar2 = DAT_003417c1 == 4 || DAT_003417c2 == 4; - the do/while+goto form
// here over-expands. Everything before it (the state/branch block and the LAB_000dcad0
// reset stores) is already the right shape.
// near miss from lane fm10 (unreviewed)
