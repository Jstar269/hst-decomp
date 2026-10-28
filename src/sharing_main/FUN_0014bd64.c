/* HSTMATCH module=hstp_trans_main.prx start=0x0014bd64 end=0x0014bdbc symbol=FUN_0014bd64 lang=c99 */
/* Clone of src/eboot/FUN_0008871c.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int * FUN_00151fc4();

/* Deleting destructor: tears the object down and frees it when flag > 0. */
int FUN_0014bd64(int self,short flag)
{
  if (self != 0) {
    if (self != 0) {
      FUN_00151fc4(self,0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
