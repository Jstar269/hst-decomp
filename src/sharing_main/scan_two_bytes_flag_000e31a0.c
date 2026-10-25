/* HSTMATCH module=hstp_trans_main.prx start=0x000e31a0 end=0x000e31ec symbol=FUN_000e31a0 lang=c99 */
/* Clone of src/eboot/scan_two_bytes_flag_000defb4.c (hstclone.py tag lnmc): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; matching idiom: set the result in the match branch and clear it after loop exhaustion; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
extern char DAT_003eaaf0[];

unsigned char FUN_000e31a0(char *self)
{
  char *table = DAT_003eaaf0;
  int found;
  unsigned i = 0;
  for (; i < 2; i++)
  {
    if (table[i + 9] == '\t')
    {
      found = 1;
      goto done;
    }
  }
  found = 0;
done:
  return found ? *(unsigned char *)(self + 0x5e) : *(unsigned char *)(self + 0x5f);
}
