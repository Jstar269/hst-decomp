/* HSTMATCH module=hstp_trans_main.prx start=0x0004da18 end=0x0004db54 symbol=FUN_0004da18 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: typed the Vec4 locals (slots follow declaration order), restored the dropped float scale argument of FUN_000224c0, rewrote the component loop with walking src/dst pointers; exact match verified; names and types await human review. */

typedef struct Vec4 { float x, y, z, w; } Vec4;
typedef struct Pair { Vec4 a; Vec4 b; } Pair;
typedef struct Obj { char pad[0x30]; float f30; } Obj;

extern void FUN_000224c0(float, Vec4 *, Vec4 *);
extern void FUN_00022440(Vec4 *, Vec4 *, Vec4 *);

void FUN_0004da18(Vec4 *out, Obj *obj, Pair *v)
{
  Vec4 res;
  Vec4 t2;
  Vec4 t3;
  Vec4 t4;
  Vec4 t1;

  if (obj->f30 != 3.4028235e+38f) {
    int i;
    float *src;
    float *dst;

    FUN_000224c0(obj->f30, &t1, &v->b);
    t2 = t1;
    FUN_00022440(&t3, &v->a, &t2);
    res = t3;
    i = 0;
    src = &v->a.x;
    dst = &res.x;
    do {
      if (src[4] == 0.0f) {
        *dst = src[0];
      }
      i++;
      src++;
      dst++;
    } while (i < 3);
  } else {
    FUN_00022440(&t4, &v->a, &v->b);
    res = t4;
  }
  out->x = res.x;
  out->y = res.y;
  out->z = res.z;
  res.w = 1.0f;
  out->w = res.w;
}
