/* HSTMATCH module=EBOOT.BIN start=0x0027db5c end=0x0027dc84 symbol=FUN_0027db5c lang=c++ */

struct Vec4 { float x; float y; float z; float w; };

struct Elem {
  virtual void d0();
  virtual void d1();
  virtual void d2();
  virtual void d3();
  virtual void d4();
  virtual void d5();
  virtual Vec4 *GetPos();
};

typedef char *(*GetM)(void *);

extern "C" {
extern int *DAT_0034a114;
extern int *DAT_0034a118;
}

extern "C" void FUN_0027db5c(Vec4 *out, int unused, int mode, int idx)
{
  Vec4 v;
  Vec4 *p;

  v.x = 0.0f;
  v.y = 0.0f;
  v.z = 0.0f;
  v.w = 1.0f;
  switch (mode) {
  case 1:
    if (DAT_0034a114 != 0 && idx >= 0) {
      Elem *e = *(Elem **)(DAT_0034a114[0x13] + idx * 4);
      if (e != 0) {
        p = e->GetPos();
        v.z = p->z;
        v.x = p->x;
        v.y = p->y;
        v.w = p->w;
      }
    } else {
      if (DAT_0034a118 != 0) {
        p = (Vec4 *)(*(GetM *)(*DAT_0034a118 + 0x9c))(DAT_0034a118);
      } else {
        p = &v;
      }
      v.z = p->z;
      v.x = p->x;
      v.y = p->y;
      v.w = p->w;
    }
    break;
  case 0:
  default:
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    v.w = 1.0f;
    break;
  }
  *out = v;
}
// NEAR 21/74 words (0x0027db5c). Full body reproduces: the switch on mode with case 0/default
// sharing the identity block, both identity writes (prologue and the shared case block), the
// g/index guard with the fallback out of line, the "p == 0 -> keep the identity x" path as
// beqzl into the tail, and the tail struct store.
// Remaining: (1) the copy after each call is scheduled as load/store pairs here, retail hoists
// the z,x,y loads and stores z first (load and store order z,x,y,w both); tried v = *p (worse,
// 23), const Vec4 *p (no change), field order x,y,z,w (no change).
// (2) the DAT_0034a118 call at vtable+0x9c still rings v0: retail uses t9, which this compiler
// only emits for a real C++ virtual (the element call at vtable+0x20 becomes t9 exactly that way,
// with 6 dummy virtuals first). Tellingly the 0x9c slot needs 37 dummy virtuals, so it is
// probably an interface table, not a vtable; left as a v0 ring.
// near miss from lane fm5 (unreviewed)
