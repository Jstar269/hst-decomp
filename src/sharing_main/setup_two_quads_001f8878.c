/* HSTMATCH module=hstp_trans_main.prx start=0x001f8878 end=0x001f8ab8 symbol=FUN_001f8878 lang=c99 */
/* Clone of src/eboot/setup_two_quads_001ea5d4.c (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idiom: the quad cursor is the object pointer offset by selB*4 (`cur->quad[0]`, `cur->quad[2]`) and the locals are declared q, t, w, h but t (the texture) is assigned before q; both only steer address folding and register order. */
#include "hst/types.h"

typedef struct Quad_001f8878 {
  u32 color;
  short x;
  short y;
  short x2;
  short y2;
} Quad_001f8878;

typedef struct Tex_001f8878 {
  int f0;
  int f4;
  int w;
  int h;
} Tex_001f8878;

typedef struct Img_001f8878 {
  char pad[0x788];
  Tex_001f8878 tex;
} Img_001f8878;

typedef struct Spr_001f8878 {
  char pad0[0x60];
  float f60;
  float f64;
  char pad1[0x78 - 0x68];
  float f78;
} Spr_001f8878;

typedef struct Globals_001f8878 {
  char pad[0x70];
  Img_001f8878 *a[2];
  Img_001f8878 *b[2];
} Globals_001f8878;

typedef struct Flags_001f8878 {
  char pad[0x45];
  unsigned char f45;
} Flags_001f8878;

typedef struct Obj_001f8878 {
  char pad0[0x5c];
  Spr_001f8878 *spr[8];
  Quad_001f8878 *quad[4];
  char pad1[0x42c - 0x8c];
  int selA[2];
  int selB[2];
} Obj_001f8878;

extern Globals_001f8878 *DAT_003e19f0;
extern Flags_001f8878 *DAT_003e1e84;
extern void FUN_000f3588(float, float, float, float, float, Tex_001f8878 *, Quad_001f8878 *, int, int);
extern void FUN_00105570(Quad_001f8878 *, int);
extern void FUN_00108aec(Obj_001f8878 *);

void FUN_001f8878(Obj_001f8878 *o)
{
  int i = 0;
  int off = 0;
  unsigned char flag = (DAT_003e1e84->f45 != 0) ^ 1;
  int sa = o->selA[flag];
  int sb = o->selB[flag];
  Obj_001f8878 *cur = (Obj_001f8878 *)((char *)o + sb * 4);
  do {
    Quad_001f8878 *q;
    Tex_001f8878 *t;
    int w;
    int h;
    Spr_001f8878 *s;
    t = &(*(Img_001f8878 **)((char *)DAT_003e19f0 + off + 0x70))->tex;
    q = cur->quad[0];
    w = t->w;
    h = t->h;
    q->x2 = q->x + w;
    q->y2 = q->y + h;
    FUN_00105570(q, -12);
    s = o->spr[sa];
    q->color = (((int)(s->f78 * 128.0f) & 0xff) << 24) | 0x808080;
    FUN_000f3588(s->f60, s->f64, 32.0f / (float)w, 1.0f, 1.0f, t, q, 0, 0);
    if ((DAT_003e1e84->f45 != 0) ^ 1) {
      t = &(*(Img_001f8878 **)((char *)DAT_003e19f0 + off + 0x78))->tex;
      q = cur->quad[2];
      w = t->w;
      h = t->h;
      q->x2 = q->x + w;
      q->y2 = q->y + h;
      FUN_00105570(q, -12);
      q->color = (((int)(s->f78 * 128.0f) & 0xff) << 24) | 0x808080;
      FUN_000f3588(s->f60, s->f64, 32.0f / (float)w, 1.0f, 1.0f, t, q, 0, 0);
    }
    i++;
    off += 4;
    cur = (Obj_001f8878 *)((char *)cur + 4);
  } while (i < 2);
  FUN_00108aec(o);
}
