/* HSTMATCH module=EBOOT.BIN start=0x00166a04 end=0x00166a44 symbol=FUN_00166a04 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern void FUN_00000a00();

/* Destructor with no base work: frees the object when flag > 0. */
void * FUN_00166a04(void *self,short flag)
{
  if ((self != 0) && (0 < flag)) {
    FUN_00000a00();
  }
  return self;
}
