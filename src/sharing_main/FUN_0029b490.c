/* HSTMATCH module=hstp_trans_main.prx start=0x0029b490 end=0x0029b4fc symbol=FUN_0029b490 lang=c99 */
/* Clone of src/eboot/FUN_00289cf4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern void FUN_0029b620();
extern int * FUN_0029e154();

/* Deleting destructor of the scene resource table: clear its entries, run the base destructor, free when flags > 0. */
int FUN_0029b490(int self,short flags)
{
  if (self != 0) {
    FUN_0029b620();
    if ((self != 0) && (self != 0)) {
      FUN_0029e154(self,0);
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
