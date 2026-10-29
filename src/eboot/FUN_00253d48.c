/* HSTMATCH module=EBOOT.BIN start=0x00253d48 end=0x00253da0 symbol=FUN_00253d48 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern void FUN_00000a00(void *);
extern int FUN_0025a454(void *, int);

/* Deleting destructor: runs the destructor body, then frees the object when flag > 0. */
void * FUN_00253d48(void *self, short flag)
{
  if (self != 0) {
    if (self != 0) {
      FUN_0025a454(self, 0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
