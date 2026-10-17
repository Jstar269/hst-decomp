/* HSTMATCH module=EBOOT.BIN start=0x000d8160 end=0x000d8228 symbol=FUN_000d8160 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_0034a77c;
extern void FUN_000d7eb8(void);
extern int FUN_0024de88(int, int, unsigned char);
void FUN_000d8160(char *self, int *values)
{
  int mode;
  int i;
  int *p;
  FUN_000d7eb8();
  mode = 0;
  if (FUN_0024de88(DAT_0034a77c, 12, (unsigned char)self[0x67]) != 0) {
    mode = 3;
    goto scan;
  }
  if (FUN_0024de88(DAT_0034a77c, 7, (unsigned char)self[0x67]) != 0) {
    mode = 2;
    goto scan;
  }
  if (FUN_0024de88(DAT_0034a77c, 2, (unsigned char)self[0x67]) != 0)
    mode = 1;
scan:
  i = 0;
  p = values;
  do {
    int v = *p;
    v = mode < v ? mode : v;
    *p = v;
    ++i;
    ++p;
  } while (i < 5);
}
