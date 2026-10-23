/* HSTMATCH module=EBOOT.BIN start=0x001bfa44 end=0x001bfbe8 symbol=FUN_001bfa44 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char undefined1;

extern undefined1 DAT_002e9fec;
extern undefined1 DAT_002e9ff4;
extern undefined1 DAT_002e9ffc;
extern int DAT_0034174c;
extern char DAT_002ea004[];
extern int FUN_0000d62c(int);
extern int FUN_00014d64(int, void *);
extern int FUN_000650e0(int);
extern int FUN_0006517c(int, int, int);
extern void FUN_001be424(char *);

void FUN_001bfa44(int param_1, int param_2, char param_3)
{
  int g;
  int i;
  int item;
  int idx;
  char *p;

  g = DAT_0034174c;
  if (g == 0)
    return;
  if (param_2 < 0)
    return;
  if (!(param_2 < FUN_000650e0(g)))
    return;
  for (i = 0; i < 4; i++) {
    item = FUN_0006517c(g, param_2 + 1, i + 1);
    if (item != 0) {
      if (FUN_00014d64(item, &DAT_002e9fec)) {
      idx = FUN_0000d62c(item + 5);
      if (idx >= 0 && idx < 0x280)
        p = (char *)param_1 + idx + 0x84c;
      else
        p = 0;
      if (p != 0)
        *p = param_3;
    } else if (FUN_00014d64(item, &DAT_002e9ff4)) {
      idx = FUN_0000d62c(item + 5);
      if (idx >= 0 && idx < 0x280)
        p = (char *)param_1 + idx + 0xacc;
      else
        p = 0;
      if (p != 0)
        *p = param_3;
    } else if (FUN_00014d64(item, &DAT_002e9ffc)) {
      idx = FUN_0000d62c(item + 5);
      if (idx >= 0 && idx < 0x280)
        p = (char *)param_1 + idx + 0xd4c;
      else
        p = 0;
      if (p != 0)
        *p = param_3;
      }
    } else {
      FUN_001be424(DAT_002ea004);
    }
  }
}
