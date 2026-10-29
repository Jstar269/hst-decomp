/* HSTMATCH module=hstp_trans_main.prx start=0x000ec490 end=0x000ec4d0 symbol=FUN_000ec490 lang=c99 */
/* Clone of src/eboot/FUN_0009447c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();

/* Plain deleting-destructor wrapper: frees the object when delete_flag > 0. */
int FUN_000ec490(int self,short delete_flag)
{
  if ((self != 0) && (0 < delete_flag)) {
    FUN_00000a00();
  }
  return self;
}
