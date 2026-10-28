/* HSTMATCH module=hstp_trans_main.prx start=0x00089e18 end=0x00089e74 symbol=FUN_00089e18 lang=c99 */
/* Clone of src/eboot/FUN_000886c0.c (hstclone.py tag x11): addresses substituted; exact match verified; names and types await human review. */

extern int FUN_00000788();
extern void FUN_00000a00();
extern void FUN_00089e74();

/* Deleting destructor: tears the object down and frees it when flag > 0. */
int FUN_00089e18(int self,short flag)
{
  if ((self != 0) && (FUN_00000788(self,FUN_00089e74,0xc,3), 0 < flag)) {
    FUN_00000a00(self);
  }
  return self;
}
