/* HSTMATCH module=EBOOT.BIN start=0x0004f52c end=0x0004f5f0 symbol=FUN_0004f52c lang=c99 */
/* Clone of src/sharing_main/FUN_0004fdb4.c (hstclone.py tag s10170049g1r1e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: locals declared result-first (s1/s0 roles), char* first parameter typed so the callee arg order is move-then-addiu, `if (r != 0) {..} else return fd;` form for the layout; exact match verified; names and types await human review. */
typedef unsigned int undefined4;

extern char DAT_002d0d40[];
extern char DAT_002d0d80[];
extern char DAT_002d0a6c[];
extern char DAT_00311170[];
extern int FUN_00039914(char *, char *, int);
extern void FUN_00049194();
extern int FUN_000491cc();
extern void FUN_0004ea98();
extern void FUN_0004f010();
extern int FUN_0004f6b4();

int FUN_0004f52c(char *param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
{
  int iVar2;
  int iVar1;

  iVar2 = 0;
  iVar1 = FUN_0004f6b4((int)param_1, param_2, DAT_002d0d40, param_3, 0, param_4, 0x40, 0);
  if (iVar1 >= 0) {
    FUN_00049194();
    iVar2 = FUN_00039914(param_1, param_1 + 0x204, 0x240);
    FUN_000491cc();
    if (iVar2 != 0) {
      FUN_0004ea98(DAT_002d0d80);
    } else {
      return iVar1;
    }
  }
  FUN_0004f010(DAT_00311170, iVar2, DAT_002d0a6c, 0x4ca, param_2);
  return -1;
}
