/* HSTMATCH module=EBOOT.BIN start=0x00053618 end=0x00053670 symbol=FUN_00053618 lang=c99 */
/* Clone of src/eboot/FUN_0008871c.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int * FUN_00054554();

/* Deleting destructor: tears the object down and frees it when flag > 0. */
int FUN_00053618(int self,short flag)
{
  if (self != 0) {
    if (self != 0) {
      FUN_00054554(self,0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
