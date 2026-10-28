/* HSTMATCH module=hstp_trans_main.prx start=0x000dd87c end=0x000dd8d4 symbol=FUN_000dd87c lang=c99 */
/* Clone of src/eboot/FUN_0008871c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int * FUN_000ddf00();

/* Deleting destructor: tears the object down and frees it when flag > 0. */
int FUN_000dd87c(int self,short flag)
{
  if (self != 0) {
    if (self != 0) {
      FUN_000ddf00(self,0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
