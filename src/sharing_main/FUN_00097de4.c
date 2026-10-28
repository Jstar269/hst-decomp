/* HSTMATCH module=hstp_trans_main.prx start=0x00097de4 end=0x00097e3c symbol=FUN_00097de4 lang=c99 */
/* Clone of src/eboot/FUN_0008871c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int * FUN_000b75e8();

/* Deleting destructor: tears the object down and frees it when flag > 0. */
int FUN_00097de4(int self,short flag)
{
  if (self != 0) {
    if (self != 0) {
      FUN_000b75e8(self,0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
