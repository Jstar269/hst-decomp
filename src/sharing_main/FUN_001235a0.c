/* HSTMATCH module=hstp_trans_main.prx start=0x001235a0 end=0x001235f8 symbol=FUN_001235a0 lang=c99 */
/* Clone of src/eboot/FUN_0008871c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int * FUN_00127a60();

/* Deleting destructor: tears the object down and frees it when flag > 0. */
int FUN_001235a0(int self,short flag)
{
  if (self != 0) {
    if (self != 0) {
      FUN_00127a60(self,0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
