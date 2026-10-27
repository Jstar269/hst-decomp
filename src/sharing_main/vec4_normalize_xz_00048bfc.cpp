/* HSTMATCH module=hstp_trans_main.prx start=0x00048bfc end=0x00048c58 symbol=FUN_00048bfc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" float sqrtf(float);

struct Vec4 {
  float x, y, z, w;
};

/* Unit vector of v projected onto the XZ plane (zero vector when v has no XZ extent). */
extern "C" void FUN_00048bfc(Vec4 *out, const Vec4 *v)
{
  float len = sqrtf(v->x * v->x + v->z * v->z);
  Vec4 r;
  if (len != 0.0f) {
    len = 1.0f / len;
  }
  r.x = v->x * len;
  r.y = 0.0f;
  r.z = v->z * len;
  r.w = 0.0f;
  *out = r;
}
