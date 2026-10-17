/* HSTMATCH module=EBOOT.BIN start=0x0011bb50 end=0x0011bba0 symbol=FUN_0011bb50 lang=c99 */
/* Clone of src/eboot/create_object_0011b468.c (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern unsigned char DAT_0033b488;
extern void *FUN_00000bcc(unsigned n);
extern void *FUN_0011b634(void *p, int a);

void *FUN_0011bb50(int a)
{
  void *p;
  if (DAT_0033b488 != 0) return 0;
  p = FUN_00000bcc(0xd0);
  if (p != 0) {
    p = FUN_0011b634(p, a);
  }
  return p;
}
