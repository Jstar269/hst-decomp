/* HSTMATCH module=hstp_trans_main.prx start=0x0019cc10 end=0x0019cc68 symbol=FUN_0019cc10 lang=c99 */
/* Clone of src/eboot/FUN_0008871c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int * FUN_0019d108();

/* Deleting destructor: tears the object down and frees it when flag > 0. */
int FUN_0019cc10(int self,short flag)
{
  if (self != 0) {
    if (self != 0) {
      FUN_0019d108(self,0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
