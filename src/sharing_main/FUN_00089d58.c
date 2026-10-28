/* HSTMATCH module=hstp_trans_main.prx start=0x00089d58 end=0x00089db8 symbol=FUN_00089d58 lang=c99 */
/* Clone of src/eboot/FUN_00088600.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int * FUN_0008c744();

/* Deleting destructor: tears the object down and frees it when flag > 0. */
int FUN_00089d58(int self,short flag)
{
  if (self != 0) {
    if ((self != 0) && (self != 0)) {
      FUN_0008c744(self,0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
