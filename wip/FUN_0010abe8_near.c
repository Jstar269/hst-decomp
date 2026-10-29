/* HSTMATCH module=EBOOT.BIN start=0x0010abe8 end=0x0010acbc symbol=FUN_0010abe8 lang=c99 */
struct Self { char pad0[28]; int f1c; };
extern char DAT_002e90ec[]; extern char DAT_002e8f58[]; extern char DAT_002e9130[];
extern void FUN_0010acbc(struct Self *self);
extern int FUN_002b7ca8(void); extern int FUN_002b7c28(void);
extern void FUN_0010a4a8(const char *fmt, ...);
void FUN_0010abe8(struct Self *self, int *out)
{
  int r, e;
  FUN_0010acbc(self);
  r = FUN_002b7ca8();
  if (r >= 0) {
    if (r == 0) {
      if (self->f1c < 0) { FUN_0010a4a8(DAT_002e8f58, self->f1c); *out = -1; }
      else if (self->f1c == 0) { *out = 1; }
      else { FUN_0010a4a8(DAT_002e9130, self->f1c); *out = -1; }
      return;
    }
    if (r == 3) {
      e = FUN_002b7c28();
      if (e < 0) FUN_0010a4a8(DAT_002e90ec, e);
    }
  }
}
// near miss from lane dsn3 (unreviewed)
