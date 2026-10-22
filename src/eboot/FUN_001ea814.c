/* HSTMATCH module=EBOOT.BIN start=0x001ea814 end=0x001ea854 symbol=FUN_001ea814 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: the duplicated store (`*out = object; *out = object ? ctor(object) : object;`)
   is one `if (object != 0) object = ctor(object);` followed by a single `*out = object;` - retail then copies that
   store into the likely branch's delay slot; exact match verified; names and types await human review. */
extern void *FUN_00000bcc(unsigned int);
extern void *FUN_001e84e0(void *);

void **FUN_001ea814(void **out)
{
  void *object = FUN_00000bcc(0x444);
  if (object != 0)
    object = FUN_001e84e0(object);
  *out = object;
  return out;
}
