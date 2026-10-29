/* HSTMATCH module=EBOOT.BIN start=0x00118304 end=0x0011835c symbol=FUN_00118304 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int FUN_0011cc1c();

/* Deleting-destructor wrapper: destroys the object, frees it when flag > 0. */
void * FUN_00118304(void *self,short flag)
{
  if (self != 0) {
    if (self != 0) {
      FUN_0011cc1c(self,0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
