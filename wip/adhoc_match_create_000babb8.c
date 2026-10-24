/* HSTMATCH module=EBOOT.BIN start=0x000babb8 end=0x000bae04 symbol=FUN_000babb8 lang=c99 */
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern void FUN_000ba3ac(char *, ...);
extern int FUN_002b7de8(int, int, int, int, int, int, int, int, void *);
extern int FUN_002b7dd0(int, int, int, int, int, int, int);
extern void FUN_000bb888(int, int, int, int, int);
extern int FUN_000bbba4(int, int);
extern unsigned int FUN_000bda40(int, int, int, int, int);
extern void FUN_000bc098(void);
extern void FUN_000bc0dc(void);
extern char DAT_002d5080[];
extern char DAT_002d50ac[];
extern char DAT_002d50d4[];
extern char DAT_002d5108[];
extern int DAT_00338ac4;

int FUN_000babb8(int param_1, int param_2, int param_3, int param_4, int param_5)
{
  int iVar1;
  int iVar2;
  int local;
  char cVar3;
  void *pcVar6;

  *(char *)(param_1 + 0x178) = (char)param_2;
  *(int *)(param_1 + 0x18c) = param_3;
  iVar2 = 2;
  if (param_2 != 0) {
    iVar2 = 1;
  }
  pcVar6 = FUN_000bc098;
  if (param_2 == 0) {
    pcVar6 = FUN_000bc0dc;
  }
  iVar1 = FUN_002b7de8(iVar2, param_3, *(undefined2 *)(param_1 + 0xc), 0x800, 5000000, 10000000, 3,
                       500000, pcVar6);
  if (iVar1 < 0) {
    FUN_000ba3ac(DAT_002d5080, iVar1);
    return 0;
  }
  *(int *)(param_1 + 0x16c) = iVar1;
  FUN_000ba3ac(DAT_002d50ac);
  *(int *)(param_1 + 0x174) = param_4;
  if (iVar2 != 1) {
    param_4 = 0;
    param_5 = 0;
  }
  iVar1 = FUN_002b7dd0(*(int *)(param_1 + 0x16c), 0x11, 0x2000, 0x11, 0, param_4, param_5);
  if (iVar1 < 0) {
    FUN_000ba3ac(DAT_002d50d4, iVar1);
    return 0;
  }
  if (param_2 == 0) {
    local = 5;
  }
  else {
    char *pcVar4 = (char *)(param_1 + 0x38);
    char *pcVar5 = (char *)(param_1 + 0x3e);
    iVar2 = 3;
    do {
      *pcVar5 = *pcVar4;
      pcVar5[1] = pcVar4[1];
      iVar2 = iVar2 + -1;
      pcVar4 = pcVar4 + 2;
      pcVar5 = pcVar5 + 2;
    } while (0 < iVar2);
    FUN_000bb888(param_1, param_1 + 0x3e, 0, 0, 0xffffffff);
    *(int *)(param_1 + 400) = 1;
    *(int *)(param_1 + 0x198) = FUN_000bbba4(param_1, param_1 + 0x38);
    local = 4;
  }
  *(int *)(param_1 + 0x28) = local;
  switch (local) {
  case 10:
    break;
  case 8:
  case 4:
    *(int *)(param_1 + 0x17c) =
         FUN_000bda40(DAT_00338ac4, DAT_00338ac4 + 0x38,
                                   *(undefined2 *)(param_1 + 0x10), 0x5a4, 0);
    break;
  }
  FUN_000ba3ac(DAT_002d5108);
  return 1;
}
// NEAR (126/147). Structure understood; the missing words are the switch, which retail emits TWICE
// (0xbad3c chain for the state==4 path with the third test folded to `beq v1,v1`, and a generic
// 0xbad90 chain for the state==5 path), and Ghidra's "removing unreachable block 0x000badb0" shows
// it only modelled one. Inlining the switch into both arms compiles smaller (117), so the real
// source must be a shared `state` local switched once and tail-duplicated by MWCC; could not get the
// duplication. Also note: 0x17c is an int store (`sw`), 0x10-byte copy loop is
// `*d = *s; d[1] = s[1];`, and the two `if (param_2 == 0)` blocks are separate statements
// (retail tests s3 once per block, `beqz` polarity, body of the 2/1 arm placed out of line).
// near miss from lane fm8 (unreviewed)
