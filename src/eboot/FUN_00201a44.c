/* HSTMATCH module=EBOOT.BIN start=0x00201a44 end=0x00201a84 symbol=FUN_00201a44 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern void FUN_00000a00();

/* Destructor-style stub: frees the object when flag > 0; returns the object. */
int FUN_00201a44(int obj,short flag)
{
  if ((obj != 0) && (0 < flag)) {
    FUN_00000a00();
  }
  return obj;
}
