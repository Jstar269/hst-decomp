/* HSTMATCH module=EBOOT.BIN start=0x001622d8 end=0x00162338 symbol=FUN_001622d8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int * FUN_00165a00();

/* Deleting destructor (short flag): runs the base destructor, frees self when flag > 0. */
int FUN_001622d8(int self,short flag)
{
  if (self != 0) {
    if ((self != 0) && (self != 0)) {
      FUN_00165a00(self,0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
