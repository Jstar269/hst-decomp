/* HSTMATCH module=EBOOT.BIN start=0x000886c0 end=0x0008871c symbol=FUN_000886c0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern int FUN_00000788();
extern void FUN_00000a00();
extern void FUN_0008871c();

/* Deleting destructor: tears the object down and frees it when flag > 0. */
int FUN_000886c0(int self,short flag)
{
  if ((self != 0) && (FUN_00000788(self,FUN_0008871c,0xc,3), 0 < flag)) {
    FUN_00000a00(self);
  }
  return self;
}
