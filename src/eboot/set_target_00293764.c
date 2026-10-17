/* HSTMATCH module=EBOOT.BIN start=0x00293764 end=0x002937b4 symbol=FUN_00293764 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inverted if/else branch order; exact match verified; names and types await human review. */

extern void FUN_00057f30(int, int);
extern int * FUN_00288a84(int);

void FUN_00293764(int param_1, int param_2)
{
  *(int *)(param_1 + 0x7c) = param_2;
  if (param_2 != 0) {
    int *p = FUN_00288a84(param_2);
    FUN_00057f30(*(int *)(param_1 + 0x78), *(int *)((char *)p + 0x58));
  }
  else {
    FUN_00057f30(*(int *)(param_1 + 0x78), 0);
  }
}
