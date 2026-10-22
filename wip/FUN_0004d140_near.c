/* HSTMATCH module=EBOOT.BIN start=0x0004d140 end=0x0004d268 symbol=FUN_0004d140 lang=c99 */
/* Hand-written reconstruction from the disassembly; names and types await human review. */
extern int FUN_0004ccb8(int, int, int);
extern int FUN_0001c1fc(void *);
extern void FUN_0001c810(void *);
extern int FUN_002b77a0(int, long long, int);
extern void FUN_002b7738(int);
extern int DAT_00311158;
extern unsigned char DAT_0030fbfd;
extern int DAT_0030ab9c;
static inline int Get(int p) { return FUN_0004ccb8(p, 1, 1); }

int FUN_0004d140(int param_1)
{
  int r = 0;
  int h = Get(param_1);
  if (h < 0) goto RET;
  if (DAT_00311158 == 0 && DAT_0030fbfd != 0) {
    r = FUN_0001c1fc(&DAT_0030ab9c);
  } else {
    int x = 0;
    r = FUN_002b77a0(h, 0, 1);
    if (r >= 0) {
      x = FUN_002b77a0(h, 0, 2);
      if (x < 0) x = 0;
      FUN_002b77a0(h, r, 0);
    }
    r = x;
  }
  if (DAT_00311158 == 0) {
    if (DAT_0030fbfd != 0) {
      FUN_0001c810(&DAT_0030ab9c);
      goto RET;
    }
  } else {
    DAT_00311158 = DAT_00311158 - 1;
  }
  FUN_002b7738(h);
RET:
  return r;
}
// near miss from lane km1 (unreviewed)
