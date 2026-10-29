/* HSTMATCH module=EBOOT.BIN start=0x001d416c end=0x001d41a0 symbol=FUN_001d416c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

/* Linear interpolation between two ints by t (0.0 gives from, 1.0 gives to), truncated. */
int FUN_001d416c(float t,int from,int to)
{
  return (int)((1.0f - t) * (float)from + t * (float)to);
}
