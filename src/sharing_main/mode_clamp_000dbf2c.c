/* HSTMATCH module=hstp_trans_main.prx start=0x000dbf2c end=0x000dbff4 symbol=FUN_000dbf2c lang=c99 */
/* Clone of src/eboot/mode_clamp_000d8160.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_003f3aac;
extern void FUN_000dbba8(void);
extern int FUN_0025e0c0(int, int, unsigned char);
void FUN_000dbf2c(char *self, int *values)
{
  int mode;
  int i;
  int *p;
  FUN_000dbba8();
  mode = 0;
  if (FUN_0025e0c0(DAT_003f3aac, 12, (unsigned char)self[0x67]) != 0) {
    mode = 3;
    goto scan;
  }
  if (FUN_0025e0c0(DAT_003f3aac, 7, (unsigned char)self[0x67]) != 0) {
    mode = 2;
    goto scan;
  }
  if (FUN_0025e0c0(DAT_003f3aac, 2, (unsigned char)self[0x67]) != 0)
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
