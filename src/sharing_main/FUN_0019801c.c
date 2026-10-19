/* HSTMATCH module=hstp_trans_main.prx start=0x0019801c end=0x00198068 symbol=FUN_0019801c lang=c99 */
/* Clone of src/eboot/FUN_0018b86c.c (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
int FUN_0019801c(unsigned char tab[][4], int param_2, int param_3)
{
  int r;

  if (0 <= param_2 && param_2 < 15 && 0 <= param_3 && param_3 < 4)
    r = tab[param_2][param_3] != 0;
  else
    r = 0;
  return r;
}
