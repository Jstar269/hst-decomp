/* HSTMATCH module=EBOOT.BIN start=0x001182ac end=0x00118304 symbol=FUN_001182ac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int FUN_0011cfcc();

/* Deleting-destructor wrapper: destroys the object, frees it when flag > 0. */
void * FUN_001182ac(void *self,short flag)
{
  if (self != 0) {
    if (self != 0) {
      FUN_0011cfcc(self,0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
