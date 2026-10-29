/* HSTMATCH module=EBOOT.BIN start=0x0021bf00 end=0x0021bf24 symbol=FUN_0021bf00 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

/* Stores a screen position (x, y) minus a fixed offset into the object. */
void FUN_0021bf00(float x,float y,int obj)
{
  *(float *)(obj + 0xe0) = x - 150.0f;
  *(float *)(obj + 0xe4) = y - 200.0f;
}
