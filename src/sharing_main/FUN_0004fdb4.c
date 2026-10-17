/* HSTMATCH module=hstp_trans_main.prx start=0x0004fdb4 end=0x0004fe78 symbol=FUN_0004fdb4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: locals declared result-first (s1/s0 roles), char* first parameter typed so the callee arg order is move-then-addiu, `if (r != 0) {..} else return fd;` form for the layout; exact match verified; names and types await human review. */
typedef unsigned int undefined4;

extern char DAT_003767fc[];
extern char DAT_0037683c[];
extern char DAT_003763c8[];
extern char DAT_003ba4b0[];
extern int FUN_0003993c(char *, char *, int);
extern void FUN_00048fb8();
extern int FUN_00049020();
extern void FUN_0004efe0();
extern void FUN_0004f864();
extern int FUN_0004ff3c();

int FUN_0004fdb4(char *param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
{
  int iVar2;
  int iVar1;

  iVar2 = 0;
  iVar1 = FUN_0004ff3c((int)param_1, param_2, DAT_003767fc, param_3, 0, param_4, 0x40, 0);
  if (iVar1 >= 0) {
    FUN_00048fb8();
    iVar2 = FUN_0003993c(param_1, param_1 + 0x204, 0x240);
    FUN_00049020();
    if (iVar2 != 0) {
      FUN_0004efe0(DAT_0037683c);
    } else {
      return iVar1;
    }
  }
  FUN_0004f864(DAT_003ba4b0, iVar2, DAT_003763c8, 0x4ca, param_2);
  return -1;
}
