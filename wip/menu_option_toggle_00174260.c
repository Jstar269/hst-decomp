/* HSTMATCH module=EBOOT.BIN start=0x00174260 end=0x001744b0 symbol=FUN_00174260 lang=c99 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef int (*FN)(void);
typedef int (*FN1)(int);

extern int FUN_0017947c(int, int, int);
extern int FUN_0017951c(int, int);
extern int FUN_0016bb88(void);
extern void FUN_001b1c44(int);
extern void FUN_00186a2c(int, int, int, int);
extern void FUN_0017d728(int, int, int);
extern void FUN_0017d7ac(int, int, int, int, int);
extern int DAT_0034179c;

void FUN_00174260(int param_1, int param_2)
{
  undefined1 bVar1;
  int uVar2;
  int iVar3;
  int iVar4;
  undefined1 cVar5;
  unsigned char *pcVar6;

  if (param_2 != 0) {
    uVar2 = FUN_0017951c(param_1, *(undefined4 *)(param_1 + 0x5b8));
  }
  else {
    iVar3 = *(int *)(param_1 + 0x5b8) * 0x14 + param_1;
    uVar2 = FUN_0017947c(param_1, *(undefined4 *)(iVar3 + 0x5cc), *(undefined4 *)(iVar3 + 0x5d0));
  }
  pcVar6 = (unsigned char *)(param_1 + 0x59e);
  iVar3 = (*(FN *)(param_1 + 0x558))();
  iVar4 = FUN_0016bb88();
  if (iVar3 < 0) {
    cVar5 = 1;
  }
  else if (iVar3 < 0xf) {
    cVar5 = *(undefined1 *)(iVar3 + iVar4 + 0x1025);
  }
  else {
    cVar5 = 1;
  }
  bVar1 = 0;
  if (cVar5 == 2) {
    bVar1 = 1;
  }
  iVar3 = *(int *)(param_1 + 0x5b8);
  if (iVar3 == 3) {
    FUN_001b1c44(DAT_0034179c);
    *(undefined1 *)(param_1 + 0x5a8) = pcVar6[10] ^ 1;
    FUN_00186a2c(*(undefined4 *)(param_1 + 0x174), *(int *)(param_1 + 0x5b8),
                 *(undefined4 *)(*(int *)(param_1 + 0x5b8) * 0x14 + param_1 + 0x5d8), uVar2);
    uVar2 = (*(FN *)(param_1 + 0x558))();
    uVar2 = (*(FN1 *)(param_1 + 0x550))(uVar2);
    FUN_0017d7ac(*(undefined4 *)(param_1 + 0x178), uVar2, *(undefined1 *)(param_1 + 0x5a7) != '\0',
                 *(undefined1 *)(param_1 + 0x5a8) != '\0', bVar1);
  }
  else if (iVar3 == 2) {
    FUN_001b1c44(DAT_0034179c);
    *(undefined1 *)(param_1 + 0x5a7) = pcVar6[9] ^ 1;
    FUN_00186a2c(*(undefined4 *)(param_1 + 0x174), *(int *)(param_1 + 0x5b8),
                 *(undefined4 *)(*(int *)(param_1 + 0x5b8) * 0x14 + param_1 + 0x5d8), uVar2);
    uVar2 = (*(FN *)(param_1 + 0x558))();
    uVar2 = (*(FN1 *)(param_1 + 0x550))(uVar2);
    FUN_0017d7ac(*(undefined4 *)(param_1 + 0x178), uVar2, *(undefined1 *)(param_1 + 0x5a7) != '\0',
                 *(undefined1 *)(param_1 + 0x5a8) != '\0', bVar1);
  }
  else if (iVar3 == 0) {
    FUN_001b1c44(DAT_0034179c);
    *(undefined1 *)(param_1 + 0x5a6) = pcVar6[8] ^ 1;
    FUN_00186a2c(*(undefined4 *)(param_1 + 0x174), *(int *)(param_1 + 0x5b8),
                 *(undefined4 *)(*(int *)(param_1 + 0x5b8) * 0x14 + param_1 + 0x5d8), uVar2);
    uVar2 = (*(FN *)(param_1 + 0x558))();
    uVar2 = (*(FN1 *)(param_1 + 0x550))(uVar2);
    FUN_0017d728(*(undefined4 *)(param_1 + 0x178), uVar2,
                 *(undefined1 *)(param_1 + 0x5a6) != '\0');
  }
  return;
}
// NEAR (145/148). Frame and prologue match; 3 words missing, all in the cVar5/bVar1 materialisation.
// Retail: `s1 = 0` (`move s1,zero` in the jalr delay slot), then `li v1,2; bnel a0,v1; li s1,1`.
// Also retail keeps the virtual-call result in s4 (5 saved regs); ours uses s2 and 4 saved regs.
// Note the arg shape: `if (param_2 != 0)` is the fallthrough arm and the `== 0` arm goes out of line
// (`beqz a1,...`), i.e. the source is written with the `!= 0` test first.
// The three flag bytes are read through one base pointer at param_1+0x59e (retail: s0 = s3+0x59e,
// offsets 8/9/10 = 0x5a6/0x5a7/0x5a8).
// near miss from lane fm8 (unreviewed)
