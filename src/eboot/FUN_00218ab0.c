/* HSTMATCH module=EBOOT.BIN start=0x00218ab0 end=0x00218ae4 symbol=FUN_00218ab0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

/* Divides by ten; the value 500 maps to bucket 9. */
int FUN_00218ab0(int value)
{
  int bucket;
  
  if (value == 500) {
    bucket = 9;
  }
  else {
    bucket = value / 10;
  }
  return bucket;
}
