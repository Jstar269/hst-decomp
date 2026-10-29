/* HSTMATCH module=hstp_trans_main.prx start=0x00175fec end=0x0017602c symbol=FUN_00175fec lang=c99 */
/* Clone of src/eboot/FUN_0009447c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();

/* Plain deleting-destructor wrapper: frees the object when delete_flag > 0. */
int FUN_00175fec(int self,short delete_flag)
{
  if ((self != 0) && (0 < delete_flag)) {
    FUN_00000a00();
  }
  return self;
}
