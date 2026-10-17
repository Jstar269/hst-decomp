/* HSTMATCH module=EBOOT.BIN start=0x00062c5c end=0x00062cb4 symbol=FUN_00062c5c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag g2) corrected by hand: default MWCC profile, s0 >= 0 and nested if; exact match verified; names and types await human review. */
typedef unsigned int undefined4;

extern int FUN_000761a8(int, undefined4, undefined4);
extern void FUN_0007771c(int, int);
extern int FUN_000777b4(int);

int FUN_00062c5c(undefined4 param_1, undefined4 param_2)
{
  int iVar1 = FUN_000761a8(0xffffffff, param_1, param_2);
  if (iVar1 >= 0) {
    if (FUN_000777b4(iVar1) == 0) {
      FUN_0007771c(iVar1, 2);
    }
  }
  return iVar1;
}
