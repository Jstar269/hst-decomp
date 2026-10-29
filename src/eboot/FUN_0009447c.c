/* HSTMATCH module=EBOOT.BIN start=0x0009447c end=0x000944bc symbol=FUN_0009447c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern void FUN_00000a00();

/* Plain deleting-destructor wrapper: frees the object when delete_flag > 0. */
int FUN_0009447c(int self,short delete_flag)
{
  if ((self != 0) && (0 < delete_flag)) {
    FUN_00000a00();
  }
  return self;
}
