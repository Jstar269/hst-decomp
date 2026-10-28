/* HSTMATCH module=EBOOT.BIN start=0x000e8094 end=0x000e80f0 symbol=FUN_000e8094 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */

void FUN_000e8094(int param_1)
{
  int iVar1;
  
  *(float *)(param_1 + 0x40) = *(float *)(param_1 + 0x40) - 0.14285715f;
  iVar1 = *(int *)(param_1 + 0x314) + 10;
  *(int *)(param_1 + 0x314) = iVar1;
  *(int *)(param_1 + 0x314) = iVar1 % 0x168;
  *(float *)(param_1 + 0x310) = *(float *)(param_1 + 0x310) + 0.2f;
  *(int *)(param_1 + 0x318) = *(int *)(param_1 + 0x318) + 1;
}
