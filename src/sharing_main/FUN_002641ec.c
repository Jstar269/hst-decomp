/* HSTMATCH module=hstp_trans_main.prx start=0x002641ec end=0x00264244 symbol=FUN_002641ec lang=c99 */
/* Clone of src/eboot/FUN_0008871c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int * FUN_0026a904();

/* Deleting destructor: tears the object down and frees it when flag > 0. */
int FUN_002641ec(int self,short flag)
{
  if (self != 0) {
    if (self != 0) {
      FUN_0026a904(self,0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
