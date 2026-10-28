/* HSTMATCH module=hstp_trans_main.prx start=0x002bb62c end=0x002bb644 symbol=FUN_002bb62c lang=c99 */
/* Clone of src/eboot/FUN_002abe70.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

void FUN_002bb62c(char *param_1,int param_2)
{
  if (param_2 != *(int *)(param_1 + 0x54)) {
    *(int *)(param_1 + 0x54) = param_2;
  }
}
