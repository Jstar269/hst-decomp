/* HSTMATCH module=EBOOT.BIN start=0x000b3ca0 end=0x000b3ce0 symbol=FUN_000b3ca0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
extern void FUN_000007f4();
extern void FUN_000887d4();
extern void FUN_000b3ce0();

/* Construct the two 12-byte elements of the array (element constructor and destructor are passed in). */
int FUN_000b3ca0(int array)
{
  FUN_000007f4(array,FUN_000b3ce0,FUN_000887d4,0xc,2);
  return array;
}
