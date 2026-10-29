/* HSTMATCH module=EBOOT.BIN start=0x000c85f0 end=0x000c8708 symbol=FUN_000c85f0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   Projects the live node's vector (sub+0x10) through two basis calls, then writes a scale into the target's
   field at 0xc0: the flat value when the projected w is non-positive, otherwise the base scale times
   kMax / x when x is inside the range. */
struct Vec4 { float x, y, z, w; };
struct Obj {
  char pad0[0x48];
  char *p48;
  char pad4c[0x2f0 - 0x4c];
  float f2f0;
};
struct Sub { char pad[0x10]; float v[4]; };
struct Tgt { char pad[0xc0]; float f0c0; };

extern "C" void FUN_00050824(void *a, char *b);
extern "C" void FUN_00022548(Vec4 *dst, void *a, Vec4 *b);
extern char DAT_00311170;
extern char *DAT_003313c4;
extern char *DAT_003386b0;
extern char DAT_0032b190;
extern float DAT_002d279c;
extern float DAT_002d27a0;

extern "C" void FUN_000c85f0(Obj *self)
{
  Vec4 v;
  char *s2;
  Sub *s1;
  float f20;

  if (self->p48 == 0)
    return;
  s2 = DAT_003313c4;
  s1 = *(Sub **)(DAT_003386b0 + 0x88);
  FUN_00050824(&DAT_00311170, s2);
  f20 = self->f2f0 * DAT_002d279c;
  v = *(Vec4 *)(s1->v);
  FUN_00022548(&v, s2 + 0xd0, &v);
  v.x = f20;
  FUN_00022548(&v, &DAT_0032b190, &v);
  if (v.w <= 0.0f) {
    ((Tgt *)self->p48)->f0c0 = self->f2f0 * DAT_002d279c;
  } else {
    if (v.x <= DAT_002d27a0)
      f20 = f20 * (DAT_002d27a0 / v.x);
    ((Tgt *)self->p48)->f0c0 = f20;
  }
}
