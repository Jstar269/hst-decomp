/* HSTMATCH module=EBOOT.BIN start=0x000f0384 end=0x000f04dc symbol=FUN_000f0384 lang=c99 */
typedef struct Sub { char pad0[0x64]; float a; char pad1[0x78 - 0x68]; float b; } Sub;
typedef struct Obj {
  char pad0[0x54]; unsigned char off;
  char pad1[0x58 - 0x55]; Sub *s0; Sub *s1; Sub *s2;
  char pad2[0x8c - 0x64]; int cnt;
  char pad3[0x94 - 0x90]; float scale;
} Obj;

extern int DAT_00338c20;
extern void FUN_000fb06c(int);
extern void FUN_00103128(Obj *);
extern void FUN_00103480(Obj *);

void FUN_000f0384(Obj *self)
{
  float x;
  float a;
  float old;

  if (self->off == 0) {
    self->cnt = self->cnt + 1;
    old = self->scale;
    x = (float)self->cnt;
    a = 0.0f;
    if (x < 15.0f) {
      x = x / 15.0f;
      a = (1.0f - x) * 18.0f;
    }
    else if (x < 75.0f) {
      x = 1.0f;
    }
    else if (x < 90.0f) {
      x = 1.0f - (x - 75.0f) / 15.0f;
    }
    else {
      x = 0.0f;
    }
    self->scale = x;
    self->s0->a = a;
    self->s0->b = x;
    self->s1->a = a;
    self->s1->b = x;
    self->s2->a = a;
    self->s2->b = x;
    if (old > 0.0f || self->scale > 0.0f) {
      FUN_00103480(self);
    }
    if ((float)self->cnt == 90.0f) {
      FUN_000fb06c(DAT_00338c20);
    }
    FUN_00103128(self);
  }
}
// 4 words off: ours loads scale (lwc1 $f4,148) after the cnt update (addiu v1,v1,1; sw) while retail loads it
// right after the 15.0f constant (lui/mtc1 f2) and BEFORE `addiu v0,v1,1` (new value in v0, not v1); everything else equal.
// With `old` read first in the source the load comes before the lui instead (6 words off); k15 constant locals, ++/+= forms,
// n = cnt + 1 temporaries and reading old after the (float)cnt conversion did not move it. Float register numbers need Ghidra's
// declaration order (x then a then old). Byte flag at +0x54 is unsigned char; FUN_000fb06c(DAT_00338c20) is an empty stub with one argument.
