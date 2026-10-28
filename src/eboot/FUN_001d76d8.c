/* HSTMATCH module=EBOOT.BIN start=0x001d76d8 end=0x001d7734 symbol=FUN_001d76d8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */

extern float FUN_0000bc34(float param_1);

float FUN_001d76d8(int param_1,int param_2)
{
  float fVar1;
  
  fVar1 = (float)FUN_0000bc34(((float)(param_1 % param_2) * 6.2831855f) / (float)param_2);
  return (1.0f - fVar1) * 0.5f;
}
