/* NEAR 197/197 words, 120 differ, first diff +0x2c.
   PROVEN GAIN this pass (was 130 differ, first +0x1c): retail's first select is a TERNARY with
   the opposite polarity from our if/else --
       iVar5 = (FUN_000def58(DAT_00338b44) == 0) ? DAT_002d23fc : DAT_002d23f8;
   retail: beqzl v0 -> lw s0,0x23fc (taken) / b + lw s0,0x23f8 (fallthrough).
   DISPROVED: making select #2 a nested ternary (204/197, 178 differ) -- reverts to 197/197/120.
   REMAINING (first diff +0x2c): select #2 wants beqzl v0 with 0x2408 in the fall-through while we
   emit bnez; retail's inner a4/v tests look redundant across both a4 arms (v<2 -> 0x2400) so the
   original probably nested one ternary per a4 arm rather than sharing one body.
*/
/* HSTMATCH module=EBOOT.BIN start=0x00089e9c end=0x0008a1b0 symbol=FUN_00089e9c lang=c99 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned int uint;

extern char *DAT_00338b44;
extern char *DAT_00340284;
extern char *DAT_002cfc8c;
extern int DAT_002d23f4;
extern int DAT_002d23f8;
extern int DAT_002d23fc;
extern int DAT_002d2400;
extern int DAT_002d2404;
extern int DAT_002d2408;
extern char DAT_003386b8;

extern int FUN_000def58();
extern int FUN_0008ab10();
extern int FUN_0008a72c();
extern int FUN_0008ad40();
extern int FUN_0008add8();
extern int FUN_001b5578();
extern int FUN_0001f558();
extern int FUN_000b35c4();
extern int FUN_00093b00();

void FUN_00089e9c(int param_1)
{
  int iVar5;
  int iVar2;
  int bVar1;
  int iVar3;
  int iVar4;
  uint uVar6;

  iVar2 = FUN_000def58(DAT_00338b44);
  iVar5 = (iVar2 == 0) ? DAT_002d23fc : DAT_002d23f8;
  iVar3 = FUN_000def58(DAT_00338b44);
  iVar2 = DAT_002d2408;
  if (iVar3 == 0) {
    iVar2 = DAT_002d2404;
    if ((*(int *)(DAT_00338b44 + 0xa4) != 0) && (*(int *)(DAT_00338b44 + 0xa4) != 1) &&
        (1 < *(uint *)(DAT_00338b44 + 0xa0))) {
      iVar2 = DAT_002d2400;
    }
  }
  FUN_0008ab10(param_1);
  iVar3 = FUN_000def58(DAT_00338b44);
  if (iVar3 == 0) {
    iVar3 = FUN_0008a72c(param_1, 0);
    if (iVar3 != 0) {
      return;
    }
    iVar3 = *(int *)(param_1 + 0x44);
  }
  else {
    iVar3 = *(int *)(param_1 + 0x44);
  }
  switch (iVar3) {
  case 0:
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;
    break;
  case 1:
    iVar3 = *(int *)(param_1 + 0x48) + 1;
    bVar1 = iVar3 < DAT_002d23f4;
    *(int *)(param_1 + 0x48) = iVar3;
    if (bVar1) {
      iVar3 = *(int *)(param_1 + 0x48);
    }
    else {
      iVar3 = FUN_001b5578(*(undefined4 *)(param_1 + 0xa8));
      if (iVar3 == 0) {
        FUN_0001f558(param_1, 0x15, 0, 0);
        *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;
        break;
      }
      iVar3 = *(int *)(param_1 + 0x48);
    }
    if ((iVar2 <= iVar3) && (((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1c) >> 0x1e == 0)) {
      *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;
    }
  case 2:
    bVar1 = 0;
    if ((*(int *)(DAT_00340284 + 0x8c) == 2) &&
        (uVar6 = *(uint *)(DAT_00340284 + 0x128), -1 < (int)uVar6) && (uVar6 < 4)) {
      iVar3 = uVar6 * 4 + param_1;
      iVar4 = FUN_000b35c4(*(undefined4 *)(iVar3 + 0x70));
      if ((iVar4 != 0) &&
          (iVar3 = FUN_00093b00(*(undefined4 *)(*(int *)(iVar3 + 0x70) + 0x5bc), 0xffffffff),
           iVar3 != 0)) {
        bVar1 = 1;
      }
    }
    if (bVar1 != 0) {
      iVar5 = *(int *)(param_1 + 0x44);
    }
    else {
      iVar3 = *(int *)(param_1 + 0x48) + 1;
      *(int *)(param_1 + 0x48) = iVar3;
      if (((iVar3 < iVar5) ||
           (iVar5 = FUN_001b5578(*(undefined4 *)(param_1 + 0xa8)), iVar5 != 0)) &&
          ((*(int *)(param_1 + 0x48) < iVar2 ||
            (((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1c) >> 0x1e != 0)))) {
        break;
      }
      iVar5 = *(int *)(param_1 + 0x44);
    }
    *(int *)(param_1 + 0x44) = iVar5 + 1;
    break;
  case 3:
    iVar5 = FUN_000def58(DAT_00338b44);
    if (iVar5 == 0) {
      FUN_0008ad40(param_1);
      iVar5 = FUN_0008add8(param_1);
      if (iVar5 != 0) {
        if (*(uint *)(DAT_00338b44 + 0xa4) < 2) {
          *(undefined4 *)(param_1 + 0x40) = 8;
        }
        else {
          *(undefined4 *)(param_1 + 0x40) = 4;
        }
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x40) = 9;
    }
    break;
  }
  if ((DAT_003386b8 != '\0') && (0 < *(int *)(param_1 + 0x6c))) {
    *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + -1;
  }
  return;
}

// NEAR MISS 0x00089e9c (second pass): 197/197 words, 130 words differ, first
// diff at +0x1c. Instruction-for-instruction this is now the same function;
// every remaining difference is the s-register NUMBERING:
//   retail: s0 = DAT_002d23f8/DAT_002d23fc pair, s1 = bVar1,
//           s2 = DAT_002d2408/2404/2400 group, s3 = param_1,
//           s4 = the param_1 + 0x70 pointer
//   ours:   s1 = the 2408/2404/2400 group, s2 = the 23f8/23fc pair,
//           s3 = param_1, s4 = the 0x70 pointer, s0 saved but only used past
//           the first ~90 instructions (a dead-ish save).
// What produced the last improvement: `iVar5 = DAT_002d23fc;` written BEFORE
// the first FUN_000def58 call (196 -> 197 words; the allocator follows the
// order the temporaries are created in the source, so this matters even though
// the generated load is scheduled after the call). Doing the same to
// `iVar2 = DAT_002d2408;` made it worse (198 words, 189 differ), so only the
// first pair wants that order. Declaration order is irrelevant (tried both
// orders for bVar1 and iVar5, no change).
// Ruled out: plain `if` vs ternary (no effect here); moving the second group's
// constant before its call; swapping bVar1/iVar2 declarations.
// near miss from lane fm10 (unreviewed)
