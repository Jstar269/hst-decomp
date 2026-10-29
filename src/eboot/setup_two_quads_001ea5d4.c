/* HSTMATCH module=EBOOT.BIN start=0x001ea5d4 end=0x001ea814 symbol=FUN_001ea5d4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idiom: the quad cursor is the object pointer offset by selB*4 (`cur->quad[0]`, `cur->quad[2]`) and the locals are declared q, t, w, h but t (the texture) is assigned before q; both only steer address folding and register order. */
#include "hst/two_quad_screen.h"

#define SPRITE_ALPHA_SCALE 128.0f /* alpha 1.0 maps to this byte value */
#define COLOR_GRAY 0x808080       /* colour part of the packed quad colour */

typedef struct Tex_001ea5d4 {
  int unk0;
  int unk4;
  int w;
  int h;
} Tex_001ea5d4;

typedef struct Img_001ea5d4 {
  char pad[0x788];
  Tex_001ea5d4 tex;
} Img_001ea5d4;

/* Global with two arrays of images (two per array). */
typedef struct Globals_001ea5d4 {
  char pad[0x70];
  Img_001ea5d4 *a[2];       /* 0x70 */
  Img_001ea5d4 *b[2];       /* 0x78 */
} Globals_001ea5d4;

typedef struct Flags_001ea5d4 {
  char pad[0x45];
  unsigned char unk45;      /* 0x45 */
} Flags_001ea5d4;

extern Globals_001ea5d4 *DAT_003386b0;
extern Flags_001ea5d4 *DAT_00338b44;
extern void FUN_000edec0(float, float, float, float, float, Tex_001ea5d4 *, TwoQuadRec *, int, int);
extern void FUN_000ffc3c(TwoQuadRec *, int);
extern void FUN_001031e8(TwoQuadScreen *);

/* Sizes two quads per pass to the texture of an image, colours them with the sprite's alpha and draws them
   (the second quad only while the global flag is clear). */
void FUN_001ea5d4(TwoQuadScreen *screen)
{
  int i = 0;
  int off = 0;
  unsigned char flag = (DAT_00338b44->unk45 != 0) ^ 1;
  int sa = screen->selA[flag];
  int sb = screen->selB[flag];
  TwoQuadScreen *cur = (TwoQuadScreen *)((char *)screen + sb * 4);
  do {
    TwoQuadRec *q;
    Tex_001ea5d4 *t;
    int w;
    int h;
    TwoQuadSprite *s;
    t = &(*(Img_001ea5d4 **)((char *)DAT_003386b0 + off + 0x70))->tex;
    q = cur->quad[0];
    w = t->w;
    h = t->h;
    q->x2 = q->x + w;
    q->y2 = q->y + h;
    FUN_000ffc3c(q, -12);
    s = screen->spr[sa];
    q->color = (((int)(s->alpha * SPRITE_ALPHA_SCALE) & 0xff) << 24) | COLOR_GRAY;
    FUN_000edec0(s->unk60, s->unk64, 32.0f / (float)w, 1.0f, 1.0f, t, q, 0, 0);
    if ((DAT_00338b44->unk45 != 0) ^ 1) {
      t = &(*(Img_001ea5d4 **)((char *)DAT_003386b0 + off + 0x78))->tex;
      q = cur->quad[2];
      w = t->w;
      h = t->h;
      q->x2 = q->x + w;
      q->y2 = q->y + h;
      FUN_000ffc3c(q, -12);
      q->color = (((int)(s->alpha * SPRITE_ALPHA_SCALE) & 0xff) << 24) | COLOR_GRAY;
      FUN_000edec0(s->unk60, s->unk64, 32.0f / (float)w, 1.0f, 1.0f, t, q, 0, 0);
    }
    i++;
    off += 4;
    cur = (TwoQuadScreen *)((char *)cur + 4);
  } while (i < 2);
  FUN_001031e8(screen);
}
