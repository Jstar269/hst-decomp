/* HSTMATCH module=EBOOT.BIN start=0x0027db5c end=0x0027dc84 symbol=FUN_0027db5c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idioms: 37 placeholder virtuals put GetPos at vtable slot 0x9c; the Vec4 copies go through three float temps. */

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

struct Mgr_27db5c {
  virtual void m0();
  virtual void m1();
  virtual void m2();
  virtual void m3();
  virtual void m4();
  virtual void m5();
  virtual void m6();
  virtual void m7();
  virtual void m8();
  virtual void m9();
  virtual void m10();
  virtual void m11();
  virtual void m12();
  virtual void m13();
  virtual void m14();
  virtual void m15();
  virtual void m16();
  virtual void m17();
  virtual void m18();
  virtual void m19();
  virtual void m20();
  virtual void m21();
  virtual void m22();
  virtual void m23();
  virtual void m24();
  virtual void m25();
  virtual void m26();
  virtual void m27();
  virtual void m28();
  virtual void m29();
  virtual void m30();
  virtual void m31();
  virtual void m32();
  virtual void m33();
  virtual void m34();
  virtual void m35();
  virtual void m36();
  virtual Vec4 *GetPos();
};

extern "C" {
extern int *DAT_0034a114;
extern Mgr_27db5c *DAT_0034a118;
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
        float z = p->z;
        float x = p->x;
        float y = p->y;
        v.z = z;
        v.x = x;
        v.y = y;
        v.w = p->w;
      }
    } else {
      if (DAT_0034a118 != 0) {
        p = DAT_0034a118->GetPos();
      } else {
        p = &v;
      }
      float z = p->z;
      float x = p->x;
      float y = p->y;
      v.z = z;
      v.x = x;
      v.y = y;
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
