/* HSTMATCH module=EBOOT.BIN start=0x000faf9c end=0x000fafb8 symbol=FUN_000faf9c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */

void FUN_000faf9c(char *param_1)
{
  if (0 < *(int *)(param_1 + 0x48)) {
    *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + -1;
  }
}
