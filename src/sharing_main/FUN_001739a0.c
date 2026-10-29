/* HSTMATCH module=hstp_trans_main.prx start=0x001739a0 end=0x001739e0 symbol=FUN_001739a0 lang=c99 */
/* Clone of src/eboot/FUN_0009447c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();

/* Plain deleting-destructor wrapper: frees the object when delete_flag > 0. */
int FUN_001739a0(int self,short delete_flag)
{
  if ((self != 0) && (0 < delete_flag)) {
    FUN_00000a00();
  }
  return self;
}
