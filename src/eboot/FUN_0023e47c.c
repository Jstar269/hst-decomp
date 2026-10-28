/* HSTMATCH module=EBOOT.BIN start=0x0023e47c end=0x0023e4d4 symbol=FUN_0023e47c lang=c99 */
/* Clone of src/eboot/FUN_0008871c.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int * FUN_0023e5c0();

/* Deleting destructor: tears the object down and frees it when flag > 0. */
int FUN_0023e47c(int self,short flag)
{
  if (self != 0) {
    if (self != 0) {
      FUN_0023e5c0(self,0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
