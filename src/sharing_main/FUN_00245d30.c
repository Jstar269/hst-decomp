/* HSTMATCH module=hstp_trans_main.prx start=0x00245d30 end=0x00245db0 symbol=FUN_00245d30 lang=c99 */
/* Clone of src/eboot/FUN_00235c04.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int * FUN_00171a30();

/* Destructor: tears down the part at 0xc and the part at 0, then frees the object if delete_flag > 0. */
int FUN_00245d30(int self,short delete_flag)
{
  int part;
  
  if (self != 0) {
    part = self + 0xc;
    if ((part != 0) && (part != 0)) {
      FUN_00171a30(part,0);
    }
    if ((self != 0) && (self != 0)) {
      FUN_00171a30(self,0);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
