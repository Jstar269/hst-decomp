/* HSTMATCH module=EBOOT.BIN start=0x0027dc90 end=0x0027dcd8 symbol=FUN_0027dc90 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern int *DAT_0034a7e4;

int *FUN_0027dc90(int param_1,int *param_2)
{
  int *result;
  int *base;
  int i;
  int *p;

  result = 0;
  base = DAT_0034a7e4;
  p = base;
  for (i = 0; i < 0x80; i++) {
    if (param_1 == *(int *)((char *)p + 0x30)) {
      result = (int *)((char *)base + i * 0x40);
      if (param_2 != 0) {
        *param_2 = i;
      }
      break;
    }
    p = (int *)((char *)p + 0x40);
  }
  return result;
}
// near miss from lane od3 (unreviewed)
