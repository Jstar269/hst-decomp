/* HSTMATCH module=EBOOT.BIN start=0x002340b4 end=0x002340f4 symbol=FUN_002340b4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
extern void FUN_00000a00();

/* Deleting-destructor wrapper: frees the object when the flag is positive. */
int FUN_002340b4(int self,short deleteFlag)
{
  if ((self != 0) && (0 < deleteFlag)) {
    FUN_00000a00();
  }
  return self;
}
