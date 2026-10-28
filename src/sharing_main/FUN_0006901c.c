/* HSTMATCH module=hstp_trans_main.prx start=0x0006901c end=0x00069040 symbol=FUN_0006901c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1gs); exact match verified; names and types await human review. */

float FUN_0006901c(float param_1,float param_2,float param_3)
{
  return param_1 + (param_2 - param_1) * (1.0f - (1.0f - param_3) * (1.0f - param_3));
}
