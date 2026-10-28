/* HSTMATCH module=EBOOT.BIN start=0x0005e04c end=0x0005e05c symbol=FUN_0005e04c lang=c99 */
/* Clone of src/eboot/FUN_0008b198.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */

void FUN_0005e04c(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
