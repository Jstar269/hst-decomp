/* HSTMATCH module=hstp_trans_main.prx start=0x0016e864 end=0x0016e8c4 symbol=FUN_0016e864 lang=c99 */
/* Clone of src/eboot/FUN_00088600.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int * FUN_00171bf0();

/* Deleting destructor: tears the object down and frees it when flag > 0. */
int FUN_0016e864(int self,short flag)
{
  if (self != 0) {
    if ((self != 0) && (self != 0)) {
      FUN_00171bf0(self,0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
