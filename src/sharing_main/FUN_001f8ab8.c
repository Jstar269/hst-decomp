/* HSTMATCH module=hstp_trans_main.prx start=0x001f8ab8 end=0x001f8af8 symbol=FUN_001f8ab8 lang=c99 */
/* Clone of src/eboot/FUN_001ea814.c (hstclone.py tag c23fbop): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: the duplicated store (`*out = object; *out = object ? ctor(object) : object;`)
   is one `if (object != 0) object = ctor(object);` followed by a single `*out = object;` - retail then copies that
   store into the likely branch's delay slot; exact match verified; names and types await human review. */
extern void *FUN_00000bcc(unsigned int);
extern void *FUN_001f6728(void *);

void **FUN_001f8ab8(void **out)
{
  void *object = FUN_00000bcc(0x444);
  if (object != 0)
    object = FUN_001f6728(object);
  *out = object;
  return out;
}
