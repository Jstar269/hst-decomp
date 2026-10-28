/* HSTMATCH module=EBOOT.BIN start=0x00048ef8 end=0x00048f08 symbol=FUN_00048ef8 lang=c99 */
/* Clone of src/eboot/FUN_0008b198.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */

void FUN_00048ef8(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
