/* HSTMATCH module=EBOOT.BIN start=0x0010a7cc end=0x0010a8a0 symbol=FUN_0010a7cc lang=c99 */
struct Self { char pad0[40]; int f28; };
extern char DAT_002e8f1c[]; extern char DAT_002e8f58[]; extern char DAT_002e8f74[];
extern void FUN_0010a8a0(struct Self *self);
extern int FUN_002b7c58(void); extern int FUN_002b7ce0(void);
extern void FUN_0010a4a8(const char *fmt, ...);
void FUN_0010a7cc(struct Self *self, int *out)
{
  int r, e;
  FUN_0010a8a0(self);
  r = FUN_002b7c58();
  if (r < 0) return;
  switch (r) {
  case 0:
    if (self->f28 < 0) { FUN_0010a4a8(DAT_002e8f58, self->f28); *out = -1; }
    else if (self->f28 == 0) { *out = 1; }
    else { FUN_0010a4a8(DAT_002e8f74, self->f28); *out = -1; }
    return;
  case 3:
    e = FUN_002b7ce0();
    if (e < 0) FUN_0010a4a8(DAT_002e8f1c, e);
    break;
  }
}
// near miss from lane dsn3 (unreviewed)
