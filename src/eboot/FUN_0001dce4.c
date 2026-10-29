/* HSTMATCH module=EBOOT.BIN start=0x0001dce4 end=0x0001dd24 symbol=FUN_0001dce4 lang=c99 */
/* Clone of src/eboot/FUN_0009447c.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();

/* Plain deleting-destructor wrapper: frees the object when delete_flag > 0. */
int FUN_0001dce4(int self,short delete_flag)
{
  if ((self != 0) && (0 < delete_flag)) {
    FUN_00000a00();
  }
  return self;
}
