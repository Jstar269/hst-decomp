/* HSTMATCH module=EBOOT.BIN start=0x001683b0 end=0x001683f0 symbol=FUN_001683b0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern void FUN_00000a00();

/* Deleting-destructor shape without a destructor body: frees obj when delete_flag is positive; returns obj. */
void * FUN_001683b0(void *obj,short delete_flag)
{
  if ((obj != 0) && (0 < delete_flag)) {
    FUN_00000a00();
  }
  return obj;
}
