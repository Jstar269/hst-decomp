/* HSTMATCH module=hstp_trans_main.prx start=0x001e543c end=0x001e544c symbol=FUN_001e543c lang=c99 */
/* Clone of src/eboot/FUN_001d7690.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

void FUN_001e543c(int param_1,int param_2)
{
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x28) + param_2;
}
