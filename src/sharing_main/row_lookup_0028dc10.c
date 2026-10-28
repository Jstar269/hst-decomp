/* HSTMATCH module=hstp_trans_main.prx start=0x0028dc10 end=0x0028dc40 symbol=FUN_0028dc10 lang=c99 */
/* Clone of src/eboot/row_lookup_0027c8a0.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char *DAT_003f3b14;
int FUN_0028dc10(int self)
{
  if (*(int *)(self + 0x78) >= 0) {
    return *(int *)(self + 0x7c);
  }
  int idx = *(int *)(self + 0x54);
  return *(int *)((char *)((idx << 6) + (int)DAT_003f3b14) + 0x24);
}
