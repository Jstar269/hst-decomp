/* HSTMATCH module=hstp_trans_main.prx start=0x000d8f34 end=0x000d8f80 symbol=FUN_000d8f34 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh128a) corrected by hand: Ghidra's void return hides that the function returns the new object (`p = ctor(p, b, a)` under the null check, result in v0 at the join); same shape as the matched EBOOT twin src/eboot/new_object_factory_000d5244.c; exact match verified; names and types await human review. */
/* Allocates 0x44 bytes (operator new 0xbcc) and constructs the object with 0x6a3e8(this, b, a); returns it (null if the allocation failed). */
extern void *FUN_00000bcc(int);
extern void *FUN_0006a3e8(void *, int, int);

void *FUN_000d8f34(int a, int b)
{
  void *p = FUN_00000bcc(0x44);
  if (p != 0) {
    p = FUN_0006a3e8(p, b, a);
  }
  return p;
}
