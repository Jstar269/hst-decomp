/* HSTMATCH module=EBOOT.BIN start=0x0026a0bc end=0x0026a4b4 symbol=FUN_0026a0bc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed structs (rect pointers, short position tables, float scale table), `#pragma opt_strength_reduction off`, tail if/else-if rewritten as a switch (cases 4 then 7, tested in reverse), centering written with const Width()/Height() getters and short temporaries (matching idioms: the ys load declared before the rect pointer reload, `+=` for the second corner, the mode table reached through a local int pointer, the signed /2 on int not short); exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
typedef struct Rect {
  char pad[4];
  short x0;
  short y0;
  short x1;
  short y1;
} Rect;

static inline short Width(const Rect *r) { return r->x1 - r->x0; }
static inline short Height(const Rect *r) { return r->y1 - r->y0; }

typedef struct Sub { char pad[0xdc]; int sel; } Sub;

typedef struct Obj {
  char pad0[0x54];
  unsigned char f54;
  unsigned char f55;
  Sub *sub;
  int mode;
  int arr60[15];
  Rect *rects[6];
  short xs[6];
  short ys[6];
  float scales[6];
} Obj;

extern int DAT_0034a67c;
extern void *DAT_002cfc8c;
extern void FUN_00103540(float, void *);
extern void FUN_001037c8(void *, int);
extern void FUN_0001dfe8(void *, int);
extern void FUN_0001e23c(void *, int, int);
extern void FUN_0010b8cc(void *, int, int);
extern void FUN_000ffca4(Rect *);
extern void FUN_00269ab0(void *, int);

void FUN_0026a0bc(Obj *self)
{
  int i;
  int sel;
  int m = self->mode;
  if (m == 0 || m == 4) {
    int *tab = self->arr60;
    int *p = &tab[m];
    if (*p < 0) {
      if (DAT_0034a67c == 0x4e) {
        *p = 2;
      } else if (DAT_0034a67c == 0x3e) {
        *p = 1;
      }
    }
  }
  FUN_00103540(1010.0f, self);
  FUN_001037c8(self, -1);
  FUN_0001dfe8(DAT_002cfc8c, 0x2000);
  FUN_0001e23c(DAT_002cfc8c, 0x2000, 1);
  FUN_0010b8cc(self->sub, self->arr60[self->mode], 2);
  self->f54 = 1;
  self->f55 = 0;
  sel = self->sub->sel;
  for (i = 0; i < 3; i++) {
    Rect *r;
    float scale;
    FUN_000ffca4(self->rects[i]);
    if (i == sel) {
      scale = 1.0f;
    } else {
      scale = 0.85f;
    }
    self->scales[i] = scale;
    r = self->rects[i];
    r->x0 = (short)(int)((float)(int)r->x0 * scale);
    r->x1 = (short)(int)((float)(int)r->x1 * scale);
    r->y0 = (short)(int)((float)(int)r->y0 * scale);
    r->y1 = (short)(int)((float)(int)r->y1 * scale);
    short sVar7 = self->ys[i];
    r = self->rects[i];
    {
      int iVar4 = Width(r);
      short sVar6 = self->xs[i] - iVar4 / 2;
      short sVar1 = r->x0;
      r->x0 = sVar6;
      r->x1 += sVar6 - sVar1;
      iVar4 = Height(r);
      sVar7 = sVar7 - iVar4 / 2;
      sVar1 = r->y0;
      r->y0 = sVar7;
      r->y1 += sVar7 - sVar1;
    }
  }
  for (i = 0; i < 3; i++) {
    int j = i + 3;
    Rect *r;
    float scale;
    FUN_000ffca4(self->rects[j]);
    if (i == sel) {
      scale = 1.0f;
    } else {
      scale = 0.85f;
    }
    self->scales[j] = scale;
    r = self->rects[j];
    r->x0 = (short)(int)((float)(int)r->x0 * scale);
    r->x1 = (short)(int)((float)(int)r->x1 * scale);
    r->y0 = (short)(int)((float)(int)r->y0 * scale);
    r->y1 = (short)(int)((float)(int)r->y1 * scale);
    short sVar7 = self->ys[j];
    r = self->rects[j];
    {
      int iVar4 = Width(r);
      short sVar6 = self->xs[j] - iVar4 / 2;
      short sVar1 = r->x0;
      r->x0 = sVar6;
      r->x1 += sVar6 - sVar1;
      iVar4 = Height(r);
      sVar7 = sVar7 - iVar4 / 2;
      sVar1 = r->y0;
      r->y0 = sVar7;
      r->y1 += sVar7 - sVar1;
    }
  }
  switch (self->mode) {
  case 4:
    FUN_00269ab0(self, 0);
    break;
  case 7:
    FUN_00269ab0(self, 2);
    break;
  }
}
