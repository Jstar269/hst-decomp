/* HSTMATCH module=hstp_trans_main.prx start=0x00185c10 end=0x00185c54 symbol=FUN_00185c10 lang=c99 */
/* Clone of src/eboot/select_short_by_kind_0017951c.c (hstclone.py tag fm2od3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
unsigned short FUN_00185c10(char *self, int kind)
{
  unsigned short value = 0;
  unsigned short *p = (unsigned short *)(self + 0x59e);
  if (kind != 4)
  {
    switch (kind)
    {
    case 0:
      value = p[0];
      break;
    case 1:
      value = p[1];
      break;
    case 2:
      value = p[2];
      break;
    case 3:
      value = p[3];
      break;
    }
  }
  return value;
}
