/* HSTMATCH module=hstp_trans_main.prx start=0x00054ba4 end=0x00054dec symbol=FUN_00054ba4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms (stack-temporary order): the three-way vector sum is an inline helper with a named t (`Vec4 t = a + b; return t + c;`) and the final stores sit two inline levels down (Finish -> Bounds::Set); Vec4 has an out-of-line operator= (__as__4Vec4FRC4Vec4 = 0x54e7c); 0x54e34 is Vec4 subtraction and 0x54dec scalar*Vec4 (both return by value, float scale in $f12). */
struct Vec4 {
  float x, y, z, w;
  Vec4() {}
  Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
  Vec4 &operator=(const Vec4 &);
  float &operator[](int i) { return (&x)[i]; }
} __attribute__((aligned(16)));

struct Mat4 {
  Vec4 r0, r1, r2, r3;
};

struct Bounds {
  Vec4 center;
  Vec4 half;
  void Set(const Vec4 &c, float r, const Vec4 &mx, const Vec4 &mn);
};

extern "C" {
Vec4 *FUN_00022440(Vec4 *, const Vec4 *, const Vec4 *);
Vec4 *FUN_00022570(Vec4 *, const Mat4 *, const Vec4 *);
float FUN_00022500(const Vec4 *, const Vec4 *);
float FUN_00022e6c(float);
Vec4 FUN_00054dec(float, const Vec4 &);
Vec4 FUN_00054e34(const Vec4 &, const Vec4 &);
}

inline Vec4 operator+(const Vec4 &a, const Vec4 &b)
{
  Vec4 r;
  FUN_00022440(&r, &a, &b);
  return r;
}

inline void Bounds::Set(const Vec4 &c, float r, const Vec4 &mx, const Vec4 &mn)
{
  center = c;
  center.w = r;
  half = FUN_00054dec(0.5f, FUN_00054e34(mx, mn));
  half.w = r * r;
}

inline Vec4 Sum3(const Vec4 &a, const Vec4 &b, const Vec4 &c)
{
  Vec4 t = a + b;
  return t + c;
}

inline void Finish(Bounds *o, const Vec4 &c, float r, const Vec4 &mx, const Vec4 &mn) { o->Set(c, r, mx, mn); }

inline const float &Min(const float &a, const float &b) { return b < a ? b : a; }
inline const float &Max(const float &a, const float &b) { return a < b ? b : a; }

extern "C" void FUN_00054ba4(int unused, Bounds *out, const Mat4 *m)
{
  Vec4 center = m->r3;
  Vec4 min, max, sign, v;
  Vec4 sum = Sum3(m->r0, m->r1, m->r2);
  float radius = FUN_00022e6c(FUN_00022500(&sum, &sum));
  min.x = 3.4028235e+38f;
  min.y = 3.4028235e+38f;
  min.z = 3.4028235e+38f;
  min.w = 0.0f;
  max.x = -3.4028235e+38f;
  max.y = -3.4028235e+38f;
  max.z = -3.4028235e+38f;
  max.w = 0.0f;
  sign.x = 1.0f;
  sign.y = 1.0f;
  sign.z = 1.0f;
  sign.w = 1.0f;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        FUN_00022570(&v, m, &sign);
        for (int c = 0; c < 3; c++) {
          min[c] = Min(min[c], v[c]);
          max[c] = Max(max[c], v[c]);
        }
        sign.z = -sign.z;
      }
      sign.y = -sign.y;
    }
    sign.x = -sign.x;
  }
  Finish(out, center, radius, max, min);
}
