/* HSTMATCH module=EBOOT.BIN start=0x001621c0 end=0x001621e0 symbol=FUN_001621c0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

float FUN_001621c0(int param_1,int param_2)
{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x16c);
  if (param_2 - 1U < 2) {
    fVar1 = fVar1 + *(float *)(param_1 + 0x3c4);
  }
  return fVar1;
}
