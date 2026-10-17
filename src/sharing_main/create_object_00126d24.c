/* HSTMATCH module=hstp_trans_main.prx start=0x00126d24 end=0x00126d74 symbol=FUN_00126d24 lang=c99 */
/* Clone of src/eboot/create_object_0011b468.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern unsigned char DAT_003e47c8;
extern void *FUN_00000bcc(unsigned n);
extern void *FUN_00126808(void *p, int a);

void *FUN_00126d24(int a)
{
  void *p;
  if (DAT_003e47c8 != 0) return 0;
  p = FUN_00000bcc(0xd0);
  if (p != 0) {
    p = FUN_00126808(p, a);
  }
  return p;
}
