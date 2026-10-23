/* HSTMATCH module=EBOOT.BIN start=0x0027bf24 end=0x0027c008 symbol=FUN_0027bf24 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int *DAT_0034a7e4;
extern void FUN_0027c2c8(float, int *, void *, void *);
extern int FUN_0027c774(int *, int);

void FUN_0027bf24(int *self, int param_2, int param_3, int param_4)
{
  int idx = -1;
  int i = 0;
  int off = 0;

  self[0x18] = 0;
  self[0x1d] = 0;
  while (i < 0x80) {
    char *r = (char *)DAT_0034a7e4 + off;
    if (param_2 == *(int *)(r + 0x30) && *(int *)(r + 0x3c) > 0) {
      idx = FUN_0027c774(self, i);
      if (idx >= 0) break;
    }
    i++;
    off += 0x40;
  }
  self[0x1e] = idx;
  self[0x1f] = param_3;
  FUN_0027c2c8((float)param_4, self,
               (char *)DAT_0034a7e4 + self[0x15] * 0x40,
               (char *)DAT_0034a7e4 + idx * 0x40);
}
