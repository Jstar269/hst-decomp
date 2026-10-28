/* HSTMATCH module=hstp_trans_main.prx start=0x00113c8c end=0x00113ccc symbol=FUN_00113c8c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */

extern void FUN_00107c9c(float);

void FUN_00113c8c(float param_1,int param_2)
{
  FUN_00107c9c((float)(param_1));
  *(float *)(param_2 + 0x148) = param_1 + 0.5f;
}
