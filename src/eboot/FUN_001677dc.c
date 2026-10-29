/* HSTMATCH module=EBOOT.BIN start=0x001677dc end=0x0016781c symbol=FUN_001677dc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern void FUN_00000a00();

/* Deleting-destructor shape without a destructor body: frees obj when delete_flag is positive; returns obj. */
void * FUN_001677dc(void *obj,short delete_flag)
{
  if ((obj != 0) && (0 < delete_flag)) {
    FUN_00000a00();
  }
  return obj;
}
