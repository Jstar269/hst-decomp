/* HSTMATCH module=EBOOT.BIN start=0x0018b86c end=0x0018b8b8 symbol=FUN_0018b86c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
int FUN_0018b86c(unsigned char tab[][4], int param_2, int param_3)
{
  int r;

  if (0 <= param_2 && param_2 < 15 && 0 <= param_3 && param_3 < 4)
    r = tab[param_2][param_3] != 0;
  else
    r = 0;
  return r;
}
