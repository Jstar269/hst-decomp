/* HSTMATCH module=EBOOT.BIN start=0x001ce400 end=0x001ce440 symbol=FUN_001ce400 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the accumulator is a separate register local copied into the address-taken local after the loop, and the callee gets its four arguments; exact match verified; names and types await human review. */
extern int * FUN_001ce8c8(int *a, int *b, int c, int *d);

/* Sum the ints in [first, last), then call the helper over the same range with the sum passed by address. */
void FUN_001ce400(int *first,int *last,char mode)
{
  int *it;
  int sum;
  int total;

  sum = 0;
  for (it = first; it != last; it = it + 1) {
    sum = sum + *it;
  }
  total = sum;
  FUN_001ce8c8(first,last,(int)mode,&total);
  return;
}
