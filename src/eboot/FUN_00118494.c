/* HSTMATCH module=EBOOT.BIN start=0x00118494 end=0x001184ec symbol=FUN_00118494 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int FUN_0011c828();

/* Deleting-destructor wrapper: destroys the object, frees it when flag > 0. */
void * FUN_00118494(void *self,short flag)
{
  if (self != 0) {
    if (self != 0) {
      FUN_0011c828(self,0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
