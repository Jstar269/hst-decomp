/* HSTMATCH module=EBOOT.BIN start=0x00088660 end=0x000886c0 symbol=FUN_00088660 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int * FUN_0008afe8();

/* Deleting destructor: tears the object down and frees it when flag > 0. */
int FUN_00088660(int self,short flag)
{
  if (self != 0) {
    if ((self != 0) && (self != 0)) {
      FUN_0008afe8(self,0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
