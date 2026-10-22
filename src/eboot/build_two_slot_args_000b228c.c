/* HSTMATCH module=EBOOT.BIN start=0x000b228c end=0x000b237c symbol=FUN_000b228c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_002beb78[];
extern void FUN_000b237c(int, int, unsigned char, float, int, unsigned char, float, int, int, int, float);

void FUN_000b228c(int param_1, int index, unsigned char flag, float value)
{
  int ids[2];
  unsigned char flags[2];
  float vals[2];
  int i;

  if (index < 0) {
    ids[0] = -1;
    ids[1] = -1;
    flags[0] = 0;
    flags[1] = 0;
    vals[0] = -1.0f;
    vals[1] = -1.0f;
  }
  else {
    char k = DAT_002beb78[index * 0x10];
    if (k < 0) {
      ids[1] = -1;
      flags[1] = 0;
      vals[1] = -1.0f;
      ids[0] = index;
      flags[0] = flag;
      vals[0] = value;
    }
    else {
      for (i = 0; i < 2; i++) {
        if (i == k) {
          ids[i] = index;
          flags[i] = flag;
          vals[i] = value;
        }
        else {
          ids[i] = 0x7fff;
          flags[i] = 0;
          vals[i] = 0.0f;
        }
      }
    }
  }
  FUN_000b237c(param_1, ids[0], flags[0], vals[0], ids[1], flags[1], vals[1],
               1, 0, 0, 0.0f);
}
