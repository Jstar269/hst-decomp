/* HSTMATCH module=EBOOT.BIN start=0x00293b94 end=0x00293bd4 symbol=FUN_00293b94 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

short * FUN_00293b94(int param_1,int param_2,int param_3)
{
  short *psVar1;
  
  psVar1 = (short *)(*(int *)(param_1 + param_2 * 0xc) + param_3 * 10);
  if (*psVar1 == -1) {
    psVar1 = (short *)0x0;
  }
  return psVar1;
}
