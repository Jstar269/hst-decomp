/* HSTMATCH module=hstp_trans_main.prx start=0x00227ffc end=0x00228030 symbol=FUN_00227ffc lang=c99 */
/* Clone of src/eboot/FUN_00218ae4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

/* Splits a value into quotient and remainder by 12. */
void FUN_00227ffc(int *out_quot,int *out_rem,int value)
{
  *out_quot = value / 12;
  *out_rem = value % 12;
}
