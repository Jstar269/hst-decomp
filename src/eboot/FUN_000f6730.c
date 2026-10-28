/* HSTMATCH module=EBOOT.BIN start=0x000f6730 end=0x000f6774 symbol=FUN_000f6730 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a2); exact match verified; names and types await human review. */

extern void FUN_00103540(float, int);

void FUN_000f6730(int *param_1,int param_2)
{
  if (*param_1 != 0) {
    FUN_00103540((float)((float)param_2),(int)(*param_1));
  }
  param_1[4] = param_2;
}
