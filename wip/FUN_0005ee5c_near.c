/* HSTMATCH module=EBOOT.BIN start=0x0005ee5c end=0x0005ef18 symbol=FUN_0005ee5c lang=c99 */
struct El;
struct Cont { char pad0[0xa0]; int f_a0; char pad_a4[4]; struct El **f_a8; int f_ac; char pad_b0[4]; unsigned *f_b4; };
extern void FUN_0005f030(struct Cont *self, int n, float v);
extern void FUN_0005d818(struct El *e);
void FUN_0005ee5c(struct Cont *self, int i)
{
  struct El *e;
  if (i < 0) return;
  if ((unsigned)i >= (unsigned)self->f_ac) return;
  if (self->f_a0 == i) FUN_0005f030(self, -1, 0.0f);
  e = self->f_a8[i];
  if (e != 0) {
    if ((self->f_b4[(unsigned)i >> 5] & (1u << (i & 31))) != 0) {
      e = self->f_a8[i];
      if (e != 0) FUN_0005d818(e);
    }
    self->f_a8[i] = 0;
  }
}
// near miss from lane dsn3 (unreviewed)
