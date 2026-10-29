/* HSTMATCH module=hstp_trans_main.prx start=0x001a33d0 end=0x001a3590 symbol=FUN_001a33d0 lang=c99 */
/* Clone of src/eboot/add_sprite_pair_00196aac.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Sprite {
  char pad0[4];
  short x0;
  short y0;
  short x1;
  short y1;
  char pad1[0x18];
  int a24;
  int a28;
} Sprite;
typedef struct Src {
  char pad0[4];
  int x;
  int y;
  float w;
  float h;
} Src;

typedef struct Mgr {
  char pad0[4];
  Sprite *slots[30];
  int vals[30];
} Mgr;
extern void FUN_00105470();

void FUN_001a33d0(Mgr *base, int *n1, int *n2, int mode, int off2, Src *src)
{
  if (*n1 < 6) {
    int i = *n1 + 0xc;
    Sprite *s = base->slots[i];
    int v;
    FUN_00105470(s, 0);
    switch (mode) {
    case 2: mode = 3; break;
    case 3: mode = 2; break;
    }
    v = base->vals[i] + mode;
    s->a24 = v;
    s->a28 = v;
    s->x0 = src->x;
    s->y0 = src->y - 3;
    s->x1 = s->x0 + (int)(src->w * 20.0f);
    s->y1 = s->y0 + (int)(src->h * 20.0f);
    *n1 = *n1 + 1;
  }
  if (*n2 < 0xc) {
    int i = *n2 + 0x12;
    Sprite *s = base->slots[i];
    int v;
    FUN_00105470(s, 0);
    v = base->vals[i] + off2;
    s->a24 = v;
    s->a28 = v;
    s->x0 = src->x;
    s->y0 = src->y - 3;
    s->x1 = s->x0 + (int)(src->w * 20.0f);
    s->y1 = s->y0 + (int)(src->h * 20.0f);
    *n2 = *n2 + 1;
  }
}
