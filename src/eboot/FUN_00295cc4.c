/* HSTMATCH module=EBOOT.BIN start=0x00295cc4 end=0x00295ccc symbol=FUN_00295cc4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p64a); exact match verified; names and types await human review. */

extern void FUN_00113580(float param_1,int param_2);

void FUN_00295cc4(float param_1,int param_2)
{
  FUN_00113580(param_1,*(int *)(param_2 + 100));
}
