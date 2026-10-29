/* HSTMATCH module=EBOOT.BIN start=0x00218ae4 end=0x00218b18 symbol=FUN_00218ae4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

/* Splits a value into quotient and remainder by 12. */
void FUN_00218ae4(int *out_quot,int *out_rem,int value)
{
  *out_quot = value / 12;
  *out_rem = value % 12;
}
