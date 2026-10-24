/* HSTMATCH module=EBOOT.BIN start=0x0025418c end=0x00254378 symbol=FUN_0025418c lang=c99 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef int (*FN2)(int *, int);

extern int FUN_00000bcc(int);
extern int FUN_00091830(int);
extern void FUN_00254378(char *, int);
extern int FUN_0005b670(int);
extern int FUN_0000c000(float);
extern void FUN_0005bc58(int);
extern void FUN_002530b8(int, int);
extern void FUN_00254e18(int);
extern char DAT_002fcf04[];
extern int DAT_0034b340;

void FUN_0025418c(undefined4 *param_1, int param_2)
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;

  iVar7 = 0;
  puVar3 = param_1;
  puVar5 = param_1;
  puVar6 = param_1;
  do {
    *(undefined1 *)((int)param_1 + iVar7 + 4) = 0;
    puVar6[2] = 0;
    *(undefined1 *)(puVar5 + 6) = 0;
    *(undefined1 *)((int)param_1 + iVar7 + 0x5c) = 0;
    puVar6[0x18] = 0;
    *(undefined1 *)((int)param_1 + iVar7 + 0xf0) = 0;
    puVar6[0x3f] = 0;
    puVar6[0x43] = 0;
    puVar6[0x47] = 0;
    puVar6[0x4b] = 0;
    puVar6[0x4f] = 0;
    puVar6[0x53] = 0;
    puVar6[0x57] = 0;
    puVar6[0x5b] = 0;
    puVar6[0x5f] = 0;
    puVar6[99] = 0;
    puVar3[0x67] = 0xff;
    puVar3[0x68] = 0xff;
    puVar3[0x69] = 0xff;
    puVar3[0x6a] = 0xff;
    iVar7 = iVar7 + 1;
    puVar6[0x77] = 0;
    puVar6 = puVar6 + 1;
    puVar5 = (undefined4 *)((int)puVar5 + 0x11);
    puVar3 = puVar3 + 4;
  } while (iVar7 < 4);
  param_1[0x3d] = 0;
  *param_1 = 0;
  param_1[0x3e] = param_2;
  iVar7 = 0;
  if (0 < param_2) {
    piVar8 = &DAT_0034b340;
    puVar3 = param_1;
    do {
      piVar4 = (int *)*piVar8;
      if (piVar4 == (int *)0x0) {
        iVar1 = *piVar8;
      }
      else {
        if (piVar4 != (int *)0x0) {
          if (piVar4 == (int *)0x0) {
            *piVar8 = 0;
          }
          else {
            (*(FN2 *)(*piVar4 + 8))(piVar4, 1);
            *piVar8 = 0;
          }
        }
        iVar1 = *piVar8;
      }
      if (iVar1 == 0) {
        iVar2 = FUN_00000bcc(0xe0);
        iVar1 = 0;
        if (iVar2 != 0) {
          iVar1 = FUN_00091830(iVar2);
        }
        *piVar8 = iVar1;
        FUN_00254378(DAT_002fcf04, iVar7);
      }
      *(undefined1 *)((int)param_1 + iVar7 + 0xf0) = 0;
      iVar1 = FUN_00000bcc(0x2c0);
      if (iVar1 == 0) {
        puVar3[0x18] = 0;
        iVar1 = 0;
      }
      else {
        iVar1 = FUN_0005b670(iVar1);
        puVar3[0x18] = iVar1;
      }
      *(undefined4 *)(iVar1 + 0x200) = 0x41f00000;
      uVar9 = FUN_0000c000(*(float *)(iVar1 + 0x200) * 0.008726646f);
      *(undefined4 *)(iVar1 + 0x214) = uVar9;
      *(undefined4 *)(puVar3[0x18] + 0x210) = 0x10;
      *(undefined4 *)(puVar3[0x18] + 0x20c) = 0xfff0;
      FUN_0005bc58(puVar3[0x18]);
      FUN_002530b8((int)(param_1 + 0x1c), puVar3[0x18]);
      iVar7 = iVar7 + 1;
      piVar8 = piVar8 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar7 < param_2);
  }
  FUN_00254e18((int)param_1);
  return;
}
// NEAR (137/123). The register-block init loop at the top and the *shape* of the per-slot body are
// right, but the `if (p) delete p;` prologue of the slot loop compiles completely differently:
// retail keeps Ghidra's redundant nested null tests (`beqzl a0 -> after; lw v0,0(s1); beqz a0 -> ...;
// beqzl a0 -> ...; sw zero,0(s1); lw t9,0(a0); lw t9,8(t9); jalr; li a1,1; sw zero,0(s1)`), i.e. the
// source's checks were NOT folded away - this translation's `if (piVar4 != 0) { if (piVar4 == 0) ... }`
// lets MWCC delete the dead inner test, losing those words and two saved registers (s6/s7 vs s0-s5).
// Something non-foldable is in the original (a macro/inline helper reading the slot twice, or a
// `T *&` reference parameter). Everything else to check: 0x34b340 slot table, `*(iVar1+0x200) =
// 0x41f00000`, `FUN_0000c000(*(float*)(iVar1+0x200) * 0.008726646f)` with the LITERAL first
// (mul.s f12,f1,f0), stores 0x10 to +0x210 and 0xfff0 to +0x20c.
// near miss from lane fm8 (unreviewed)
