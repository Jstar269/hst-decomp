/* HSTMATCH module=hstp_trans_main.prx start=0x002441b4 end=0x002441f4 symbol=FUN_002441b4 lang=c99 */
/* Clone of src/eboot/FUN_0009447c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();

/* Plain deleting-destructor wrapper: frees the object when delete_flag > 0. */
int FUN_002441b4(int self,short delete_flag)
{
  if ((self != 0) && (0 < delete_flag)) {
    FUN_00000a00();
  }
  return self;
}
