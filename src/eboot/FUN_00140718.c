/* HSTMATCH module=EBOOT.BIN start=0x00140718 end=0x00140770 symbol=FUN_00140718 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int * FUN_001466dc();

/* Destructor: runs the base destructor, then frees the object when flag > 0. */
void * FUN_00140718(void *self,short flag)
{
  if (self != 0) {
    if (self != 0) {
      FUN_001466dc(self,0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
