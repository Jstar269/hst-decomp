/* HSTMATCH module=hstp_trans_main.prx start=0x001dc3b8 end=0x001dc3e8 symbol=FUN_001dc3b8 lang=c99 */
/* Clone of src/eboot/entry_field_001cdcdc.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
int FUN_001dc3b8(int self,int i)
{
  int base = *(int *)(self + 0x58);
  if (!base) return -1;
  return *(int *)((char *)(i * 52) + base + 0xf0);
}
