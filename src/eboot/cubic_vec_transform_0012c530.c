/* HSTMATCH module=EBOOT.BIN start=0x0012c530 end=0x0012c5ac symbol=FUN_0012c530 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128c) corrected by hand: typed Vec4/Mat4/object views instead of undefined4 locals, branch order flipped (flag-set arm first), out/poly locals declared out first, cube computed as (t*t)*t from the squared local; exact match verified; names and types await human review. */
typedef struct { float x, y, z, w; } Vec4;
typedef struct { Vec4 r[4]; } Mat4;
typedef struct {
  Mat4 m;
  char pad40[0x10];
  float f50;
  char pad54[0xc];
  float f60;
  char pad64[4];
  float f68;
  char pad6c[0x94 - 0x6c];
  unsigned char f94;
} Obj;
extern Vec4 *FUN_00022548(Vec4 *out, const Mat4 *m, const Vec4 *v);

void FUN_0012c530(Obj *param_1, float *param_2)
{
  Vec4 r;
  Vec4 v;

  if (param_1->f94 != 0) {
    float t = param_1->f50;
    v.z = t;
    v.y = t * t;
    v.x = v.y * t;
    v.w = 1.0f;
    FUN_00022548(&r, &param_1->m, &v);
    param_2[0] = r.x;
    param_2[2] = r.z;
  }
  else {
    param_2[0] = param_1->f60;
    param_2[2] = param_1->f68;
  }
}
