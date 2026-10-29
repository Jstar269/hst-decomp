/* HSTMATCH module=EBOOT.BIN start=0x000fcb7c end=0x000fcbe4 symbol=FUN_000fcb7c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag q3) corrected by hand: the object typed unsigned char * and the tested member passed to the free call (Ghidra dropped the argument); readability pass; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern void FUN_000104e0();

/* Destructor: releases the owned buffer when the first byte is set, frees the object when flags > 0. */
unsigned char * FUN_000fcb7c(unsigned char *self,short flags)
{
  if (self != (unsigned char *)0x0) {
    if ((*self != '\0') && (*(int *)(self + 4) != 0)) {
      FUN_000104e0(*(int *)(self + 4));
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
