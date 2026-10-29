/* HSTMATCH module=EBOOT.BIN start=0x001183cc end=0x00118424 symbol=FUN_001183cc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int FUN_0011c88c();

/* Deleting-destructor wrapper: destroys the object, frees it when flag > 0. */
void * FUN_001183cc(void *self,short flag)
{
  if (self != 0) {
    if (self != 0) {
      FUN_0011c88c(self,0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
