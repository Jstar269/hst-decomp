/* HSTMATCH module=hstp_trans_main.prx start=0x0022667c end=0x002266bc symbol=FUN_0022667c lang=c99 */
/* Clone of src/eboot/FUN_0009447c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();

/* Plain deleting-destructor wrapper: frees the object when delete_flag > 0. */
int FUN_0022667c(int self,short delete_flag)
{
  if ((self != 0) && (0 < delete_flag)) {
    FUN_00000a00();
  }
  return self;
}
