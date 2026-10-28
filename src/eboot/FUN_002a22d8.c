/* HSTMATCH module=EBOOT.BIN start=0x002a22d8 end=0x002a234c symbol=FUN_002a22d8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */

void FUN_002a22d8(float param_1,float param_2,int param_3)
{
  *(short *)(param_3 + 4) = (short)(int)((float)(int)*(short *)(param_3 + 4) * param_1);
  *(short *)(param_3 + 8) = (short)(int)((float)(int)*(short *)(param_3 + 8) * param_1);
  *(short *)(param_3 + 6) = (short)(int)((float)(int)*(short *)(param_3 + 6) * param_2);
  *(short *)(param_3 + 10) = (short)(int)((float)(int)*(short *)(param_3 + 10) * param_2);
}
