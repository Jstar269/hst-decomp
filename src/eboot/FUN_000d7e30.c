/* HSTMATCH module=EBOOT.BIN start=0x000d7e30 end=0x000d7e70 symbol=FUN_000d7e30 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern void FUN_00000a00();

/* Deleting-destructor shape: frees the object when delete_flag > 0. */
int FUN_000d7e30(int self,short delete_flag)
{
  if ((self != 0) && (0 < delete_flag)) {
    FUN_00000a00();
  }
  return self;
}
