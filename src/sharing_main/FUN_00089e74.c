/* HSTMATCH module=hstp_trans_main.prx start=0x00089e74 end=0x00089ecc symbol=FUN_00089e74 lang=c99 */
/* Clone of src/eboot/FUN_0008871c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int * FUN_0008c66c();

/* Deleting destructor: tears the object down and frees it when flag > 0. */
int FUN_00089e74(int self,short flag)
{
  if (self != 0) {
    if (self != 0) {
      FUN_0008c66c(self,0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
