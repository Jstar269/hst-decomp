/* HSTMATCH module=EBOOT.BIN start=0x0004d6a0 end=0x0004d7dc symbol=FUN_0004d6a0 lang=c99 */
/* Clone of src/sharing_main/vec4_combine_0004da18.c (hstclone.py tag s10170158a3r1e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: typed the Vec4 locals (slots follow declaration order), restored the dropped float scale argument of FUN_00022498, rewrote the component loop with walking src/dst pointers; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

typedef struct Vec4 { float x, y, z, w; } Vec4;
typedef struct Pair { Vec4 a; Vec4 b; } Pair;
typedef struct Obj { char pad[0x30]; float f30; } Obj;

extern void FUN_00022498(float, Vec4 *, Vec4 *);
extern void FUN_00022418(Vec4 *, Vec4 *, Vec4 *);

void FUN_0004d6a0(Vec4 *out, Obj *obj, Pair *v)
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

    FUN_00022498(obj->f30, &t1, &v->b);
    t2 = t1;
    FUN_00022418(&t3, &v->a, &t2);
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
    FUN_00022418(&t4, &v->a, &v->b);
    res = t4;
  }
  out->x = res.x;
  out->y = res.y;
  out->z = res.z;
  res.w = 1.0f;
  out->w = res.w;
}
