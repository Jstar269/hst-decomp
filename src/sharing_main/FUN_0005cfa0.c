/* HSTMATCH module=hstp_trans_main.prx start=0x0005cfa0 end=0x0005cffc symbol=FUN_0005cfa0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */

extern float FUN_0000b8c0(float param_1);
extern float FUN_0000c018(float param_1);

float FUN_0005cfa0(int param_1)
{
  float fVar1;
  
  fVar1 = (float)FUN_0000c018(*(float *)(param_1 + 0x200) * 0.008726646f);
  fVar1 = (float)FUN_0000b8c0(fVar1 * (*(float *)(param_1 + 0x224) / *(float *)(param_1 + 0x220)));
  return fVar1 * 114.59156f;
}
