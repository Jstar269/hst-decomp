/* HSTMATCH module=hstp_trans_main.prx start=0x000cc190 end=0x000cc2a8 symbol=FUN_000cc190 lang=c++ */
/* Clone of src/eboot/project_scale_000c85f0.cpp (hstclone.py tag c015707): addresses substituted; exact match verified; names and types await human review. */
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

extern "C" void FUN_00051138(void *a, char *b);
extern "C" void FUN_00022570(Vec4 *dst, void *a, Vec4 *b);
extern char DAT_003ba4b0;
extern char *DAT_003da704;
extern char *DAT_003e19f0;
extern char DAT_003d44d0;
extern float DAT_00378884;
extern float DAT_00378888;

extern "C" void FUN_000cc190(Obj *self)
{
  Vec4 v;
  char *s2;
  Sub *s1;
  float f20;

  if (self->p48 == 0)
    return;
  s2 = DAT_003da704;
  s1 = *(Sub **)(DAT_003e19f0 + 0x88);
  FUN_00051138(&DAT_003ba4b0, s2);
  f20 = self->f2f0 * DAT_00378884;
  v = *(Vec4 *)(s1->v);
  FUN_00022570(&v, s2 + 0xd0, &v);
  v.x = f20;
  FUN_00022570(&v, &DAT_003d44d0, &v);
  if (v.w <= 0.0f) {
    ((Tgt *)self->p48)->f0c0 = self->f2f0 * DAT_00378884;
  } else {
    if (v.x <= DAT_00378888)
      f20 = f20 * (DAT_00378888 / v.x);
    ((Tgt *)self->p48)->f0c0 = f20;
  }
}
