/* HSTMATCH module=EBOOT.BIN start=0x00202a68 end=0x00202aec symbol=FUN_00202a68 lang=c99 */

struct Rec { float a; int b; float c; int d; };
struct Self { char pad[0x14]; int f14; int f18; struct Rec recs[12]; };

int FUN_00202a68(struct Self *self, int kind, int num, int *out, float f)
{
  int i;

  i = self->f14;
  if (i < 0xc) {
    self->recs[self->f14].b = kind;
    self->recs[self->f14].a = f;
    self->recs[self->f14].c = (float)num;
    self->recs[self->f14].d = *out;
    if (kind == 6) {
      self->f18 = self->f14;
    }
    i = self->f14;
    self->f14 = i + 1;
  }
  return i;
}
// NEAR 32/33 words (0x00202a68). The 0x10-byte record at self+0x1c indexed by self->f14 is right:
// four stores in retail's order (kind at +4 of the record, the float arg at +0, (float)num at +8,
// *out at +12), the `kind == 6 -> f18 = f14` copy, the increment and the returned old index.
// Left: retail lays the body out of line (`bnezl v1,body` with `sll v0,v0,4` in the delay, then a
// `b` to the return), ours inlines it after `beqz at,end`. Trying a second `return i` inside the
// guard and an explicit `int *out` use did not change it; the body layout is the only difference.
// near miss from lane fm5 (unreviewed)
