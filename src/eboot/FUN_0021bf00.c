/* HSTMATCH module=EBOOT.BIN start=0x0021bf00 end=0x0021bf24 symbol=FUN_0021bf00 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

void FUN_0021bf00(float param_1,float param_2,int param_3)
{
  *(float *)(param_3 + 0xe0) = param_1 - 150.0f;
  *(float *)(param_3 + 0xe4) = param_2 - 200.0f;
}
