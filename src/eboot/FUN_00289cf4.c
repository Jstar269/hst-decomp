/* HSTMATCH module=EBOOT.BIN start=0x00289cf4 end=0x00289d60 symbol=FUN_00289cf4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern void FUN_00289e84();
extern int * FUN_0028c98c();

/* Deleting destructor of the scene resource table: clear its entries, run the base destructor, free when flags > 0. */
int FUN_00289cf4(int self,short flags)
{
  if (self != 0) {
    FUN_00289e84();
    if ((self != 0) && (self != 0)) {
      FUN_0028c98c(self,0);
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
