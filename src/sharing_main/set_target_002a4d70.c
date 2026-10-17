/* HSTMATCH module=hstp_trans_main.prx start=0x002a4d70 end=0x002a4dc0 symbol=FUN_002a4d70 lang=c99 */
/* Clone of src/eboot/set_target_00293764.c (hstclone.py tag u5fr3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inverted if/else branch order; exact match verified; names and types await human review. */

extern void FUN_00058b84(int, int);
extern int * FUN_0029a220(int);

void FUN_002a4d70(int param_1, int param_2)
{
  *(int *)(param_1 + 0x7c) = param_2;
  if (param_2 != 0) {
    int *p = FUN_0029a220(param_2);
    FUN_00058b84(*(int *)(param_1 + 0x78), *(int *)((char *)p + 0x58));
  }
  else {
    FUN_00058b84(*(int *)(param_1 + 0x78), 0);
  }
}
