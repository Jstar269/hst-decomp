/* HSTMATCH module=EBOOT.BIN start=0x00169e68 end=0x00169ea0 symbol=FUN_00169e68 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

void FUN_00169e68(float *param_1,float *param_2,float *param_3,float *param_4)
{
  *param_1 = *param_2;
  param_1[1] = *param_3;
  param_1[3] = *param_4;
  param_1[2] = (*param_3 + *param_2) / 2.0f;
}
