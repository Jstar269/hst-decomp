/* HSTMATCH module=EBOOT.BIN start=0x00235d50 end=0x00235d90 symbol=FUN_00235d50 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern void FUN_000007f4();
extern void FUN_0008871c();
extern void FUN_00235d90();

enum { ELEM_SIZE = 0xc, ELEM_COUNT = 3 };

/* Constructs an array of ELEM_COUNT elements of ELEM_SIZE bytes (element constructor and destructor passed in). */
int FUN_00235d50(int array)
{
  FUN_000007f4(array,FUN_00235d90,FUN_0008871c,ELEM_SIZE,ELEM_COUNT);
  return array;
}
