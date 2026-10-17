/* HSTMATCH module=EBOOT.BIN start=0x000d5244 end=0x000d5290 symbol=FUN_000d5244 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: Ghidra's void return hides that the function returns the new object (`p = ctor(p, b, a)` under the null check, result in v0 at the join); exact match verified; names and types await human review. */
/* Allocates 0x44 bytes (operator new 0xbcc) and constructs the object with 0x68f94(this, b, a); returns it (null if the allocation failed). */
extern void *FUN_00000bcc(int);
extern void *FUN_00068f94(void *, int, int);

void *FUN_000d5244(int a, int b)
{
  void *p = FUN_00000bcc(0x44);
  if (p != 0) {
    p = FUN_00068f94(p, b, a);
  }
  return p;
}
