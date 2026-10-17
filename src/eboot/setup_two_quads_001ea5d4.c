/* HSTMATCH module=EBOOT.BIN start=0x001ea5d4 end=0x001ea814 symbol=FUN_001ea5d4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idiom: the quad cursor is the object pointer offset by selB*4 (`cur->quad[0]`, `cur->quad[2]`) and the locals are declared q, t, w, h but t (the texture) is assigned before q; both only steer address folding and register order. */
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

typedef struct Quad_001ea5d4 {
  uint color;
  short x;
  short y;
  short x2;
  short y2;
} Quad_001ea5d4;

typedef struct Tex_001ea5d4 {
  int f0;
  int f4;
  int w;
  int h;
} Tex_001ea5d4;

typedef struct Img_001ea5d4 {
  char pad[0x788];
  Tex_001ea5d4 tex;
} Img_001ea5d4;

typedef struct Spr_001ea5d4 {
  char pad0[0x60];
  float f60;
  float f64;
  char pad1[0x78 - 0x68];
  float f78;
} Spr_001ea5d4;

typedef struct Globals_001ea5d4 {
  char pad[0x70];
  Img_001ea5d4 *a[2];
  Img_001ea5d4 *b[2];
} Globals_001ea5d4;

typedef struct Flags_001ea5d4 {
  char pad[0x45];
  unsigned char f45;
} Flags_001ea5d4;

typedef struct Obj_001ea5d4 {
  char pad0[0x5c];
  Spr_001ea5d4 *spr[8];
  Quad_001ea5d4 *quad[4];
  char pad1[0x42c - 0x8c];
  int selA[2];
  int selB[2];
} Obj_001ea5d4;

extern Globals_001ea5d4 *DAT_003386b0;
extern Flags_001ea5d4 *DAT_00338b44;
extern void FUN_000edec0(float, float, float, float, float, Tex_001ea5d4 *, Quad_001ea5d4 *, int, int);
extern void FUN_000ffc3c(Quad_001ea5d4 *, int);
extern void FUN_001031e8(Obj_001ea5d4 *);

void FUN_001ea5d4(Obj_001ea5d4 *o)
{
  int i = 0;
  int off = 0;
  unsigned char flag = (DAT_00338b44->f45 != 0) ^ 1;
  int sa = o->selA[flag];
  int sb = o->selB[flag];
  Obj_001ea5d4 *cur = (Obj_001ea5d4 *)((char *)o + sb * 4);
  do {
    Quad_001ea5d4 *q;
    Tex_001ea5d4 *t;
    int w;
    int h;
    Spr_001ea5d4 *s;
    t = &(*(Img_001ea5d4 **)((char *)DAT_003386b0 + off + 0x70))->tex;
    q = cur->quad[0];
    w = t->w;
    h = t->h;
    q->x2 = q->x + w;
    q->y2 = q->y + h;
    FUN_000ffc3c(q, -12);
    s = o->spr[sa];
    q->color = (((int)(s->f78 * 128.0f) & 0xff) << 24) | 0x808080;
    FUN_000edec0(s->f60, s->f64, 32.0f / (float)w, 1.0f, 1.0f, t, q, 0, 0);
    if ((DAT_00338b44->f45 != 0) ^ 1) {
      t = &(*(Img_001ea5d4 **)((char *)DAT_003386b0 + off + 0x78))->tex;
      q = cur->quad[2];
      w = t->w;
      h = t->h;
      q->x2 = q->x + w;
      q->y2 = q->y + h;
      FUN_000ffc3c(q, -12);
      q->color = (((int)(s->f78 * 128.0f) & 0xff) << 24) | 0x808080;
      FUN_000edec0(s->f60, s->f64, 32.0f / (float)w, 1.0f, 1.0f, t, q, 0, 0);
    }
    i++;
    off += 4;
    cur = (Obj_001ea5d4 *)((char *)cur + 4);
  } while (i < 2);
  FUN_001031e8(o);
}
