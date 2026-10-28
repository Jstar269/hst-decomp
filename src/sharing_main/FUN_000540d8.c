/* HSTMATCH module=hstp_trans_main.prx start=0x000540d8 end=0x00054130 symbol=FUN_000540d8 lang=c99 */
/* Clone of src/eboot/FUN_0008871c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int * FUN_000550a0();

/* Deleting destructor: tears the object down and frees it when flag > 0. */
int FUN_000540d8(int self,short flag)
{
  if (self != 0) {
    if (self != 0) {
      FUN_000550a0(self,0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
