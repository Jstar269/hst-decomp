/* HSTMATCH module=EBOOT.BIN start=0x0026a4b4 end=0x0026b25c symbol=FUN_0026a4b4 lang=c++ rodata=0x2ca904 */
#pragma opt_strength_reduction off
struct Rect {
  char pad[4];
  short x0;
  short y0;
  short x1;
  short y1;
  short W() const { return x1 - x0; }
};

static inline short Width(const Rect *r) { return r->x1 - r->x0; }
static inline short Height(const Rect *r) { return r->y1 - r->y0; }

struct Sub {
  virtual void v0(); virtual void v1(int);
  char pad[0xdc - 4];
  int sel;
  char pade0[8];
  unsigned char fe8;
  unsigned char fe9;
  unsigned char fea;
};

struct Mgr {
  virtual void v0(); virtual void v1(); virtual void v2();
};

struct Obj {
  virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
  virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
  virtual int v8();
  char pad4[0x54 - 4];
  unsigned char f54;
  unsigned char f55;
  Sub *sub;
  int mode;
  int arr60[11];
  int counter;
  int arr90[3];
  Rect *rects[6];
  short xs[6];
  short ys[6];
  float scales[6];
};

extern "C" {
extern void *DAT_003386c8;
extern void *DAT_0034a120;
extern char *DAT_002cfc8c;
extern unsigned char DAT_003417be;
extern int DAT_0034179c;
void FUN_00103128(Obj *);
void FUN_0026b25c(Obj *);
void FUN_0026b2f0(Obj *);
void FUN_0025336c(int, int);
void FUN_000ffca4(Rect *);
void FUN_000ffb3c(Rect *, int);
void FUN_00269ab0(Obj *, int);
void *FUN_001d9cc4(void *);
int FUN_002a17e0(void *);
Mgr *FUN_0008d994(void *);
void FUN_00103628(Mgr *, int);
void FUN_001b1c44(int *, int);
void FUN_000114c0(void *, int, int);
void FUN_0010b8cc(Sub *, int, int);
}

static inline void ScaleRect(Rect *r, float scale)
{
  r->x0 = (short)(int)((float)(int)r->x0 * scale);
  r->x1 = (short)(int)((float)(int)r->x1 * scale);
  r->y0 = (short)(int)((float)(int)r->y0 * scale);
  r->y1 = (short)(int)((float)(int)r->y1 * scale);
}

static inline void Place(Obj *self, int j)
{
  Rect *r;
  short sVar7 = self->ys[j];
  r = self->rects[j];
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

static inline void EaseTo(Rect *r, const Rect *t)
{
  short ox = r->x0;
  short nx = (short)((float)ox + 0.5f * (float)(t->x0 - ox));
  r->x0 = nx;
  r->x1 += nx - ox;
}

static inline short MidX(const Rect *r) { return (r->x0 + r->x1) / 2; }

static inline void SetCenter(Rect *s, short cx)
{
  int w = s->W();
  short nx = cx - (short)(w / 2);
  short ox = s->x0;
  short d = nx - ox;
  s->x0 = nx;
  s->x1 = s->x1 + d;
}

static inline void EaseCenter(Rect *r, short target)
{
  short c = MidX(r);
  SetCenter(r, (int)((float)c + 0.5f * (float)(target - c)));
}

static inline bool Flag() { return ((int)DAT_002cfc8c[0x8b] << 26) >> 30 != 0; }

extern "C" void FUN_0026a4b4(Obj *self)
{
  int i;
  int sel;
  if (self->v8() == 0) return;
  FUN_00103128(self);
  sel = self->sub->sel;
  self->arr60[self->mode] = sel;
  switch (self->mode) {
  case 0:
  case 2:
    FUN_0026b25c(self);
    break;
  case 1:
  case 3:
    FUN_0026b2f0(self);
    break;
  case 4:
    FUN_0025336c(2, sel);
    break;
  case 5:
    for (i = 0; i < 3; i++) {
      int j = i + 3;
      Rect *r;
      float scale;
      FUN_000ffca4(self->rects[j]);
      if (i == 0) {
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
    EaseTo(self->rects[1], self->rects[0]);
    EaseTo(self->rects[2], self->rects[0]);
    if (self->rects[2]->x0 - self->rects[0]->x0 < 6) FUN_00269ab0(self, 6);
    break;
  case 6:
    EaseCenter(self->rects[4], self->xs[4]);
    FUN_000ffb3c(self->rects[4], 0);
    EaseCenter(self->rects[5], self->xs[5]);
    FUN_000ffb3c(self->rects[5], 0);
    if (self->xs[5] - MidX(self->rects[5]) < 6) FUN_00269ab0(self, 7);
    break;
  case 7:
    FUN_0025336c(3, sel);
    break;
  case 8:
    EaseTo(self->rects[4], self->rects[3]);
    EaseTo(self->rects[5], self->rects[3]);
    if (self->rects[5]->x0 - self->rects[3]->x0 < 6) FUN_00269ab0(self, 9);
    break;
  case 9:
    EaseCenter(self->rects[1], self->xs[1]);
    FUN_000ffb3c(self->rects[1], 0);
    EaseCenter(self->rects[2], self->xs[2]);
    FUN_000ffb3c(self->rects[2], 0);
    if (self->xs[2] - MidX(self->rects[2]) < 6) FUN_00269ab0(self, 4);
    break;
  case 10:
    if (FUN_002a17e0(FUN_001d9cc4(DAT_0034a120)) == 0) self->f55 = 1;
    break;
  }
  if (self->mode == 4 || self->mode == 7) {
    int base = self->mode == 4 ? 0 : 3;
    for (i = 0; i < 3; i++) {
      int j = i + base;
      Rect *r;
      float target;
      FUN_000ffca4(self->rects[j]);
      if (i == sel) {
        target = 1.0f;
      } else {
        target = 0.85f;
      }
      float scale = self->scales[j] + (target - self->scales[j]) * 0.7f;
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
  }
  FUN_00103628(FUN_0008d994(DAT_003386c8), 0);
  FUN_0008d994(DAT_003386c8)->v2();
  if (self->sub->fea) FUN_001b1c44(&DAT_0034179c, 1);
  if (self->mode == 4 || self->mode == 7) {
    Sub *s = self->sub;
    if (!s->fea && s->fe8) {
      DAT_003417be = 0;
      switch (self->mode) {
      case 4:
        if (sel == 0) {
          FUN_001b1c44(&DAT_0034179c, 3);
          FUN_00269ab0(self, 5);
        } else if (sel == 1) {
          FUN_001b1c44(&DAT_0034179c, 3);
          FUN_00269ab0(self, 10);
          FUN_000ffb3c(self->rects[0], 1);
          FUN_000ffb3c(self->rects[2], 1);
          FUN_000ffb3c(self->rects[3], 1);
          FUN_000ffb3c(self->rects[4], 1);
          FUN_000ffb3c(self->rects[5], 1);
          self->sub->v1(1);
        } else if (sel == 2) {
          FUN_001b1c44(&DAT_0034179c, 3);
          self->f55 = 1;
          FUN_000ffb3c(self->rects[0], 1);
          FUN_000ffb3c(self->rects[1], 1);
          FUN_000ffb3c(self->rects[3], 1);
          FUN_000ffb3c(self->rects[4], 1);
          FUN_000ffb3c(self->rects[5], 1);
          self->sub->v1(1);
        }
        break;
      case 7:
        if (sel == 0) {
          FUN_001b1c44(&DAT_0034179c, 3);
          self->f55 = 1;
        } else if (sel == 1) {
          FUN_001b1c44(&DAT_0034179c, 3);
          self->f55 = 1;
          FUN_000ffb3c(self->rects[0], 1);
          FUN_000ffb3c(self->rects[1], 1);
          FUN_000ffb3c(self->rects[2], 1);
          FUN_000ffb3c(self->rects[3], 1);
          FUN_000ffb3c(self->rects[5], 1);
          self->sub->v1(1);
        } else if (sel == 2) {
          FUN_001b1c44(&DAT_0034179c, 3);
          self->f55 = 1;
          DAT_003417be = 1;
        }
        break;
      }
      self->sub->fe8 = 0;
    } else if (!s->fea && (Flag() ^ 1)) {
      FUN_001b1c44(&DAT_0034179c, 4);
      FUN_000114c0(self->arr60, 0, 0x2c);
      FUN_0010b8cc(self->sub, 0, 0);
      for (i = 0; i < 3; i++) {
        Rect *r;
        float scale;
        FUN_000ffca4(self->rects[i]);
        if (i == 0) {
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
      switch (self->mode) {
      case 4:
        self->v7();
        break;
      case 7:
        FUN_00269ab0(self, 8);
        break;
      }
    }
  }
  self->counter++;
}
// NEAR: 874/874 words, 28 differ. Everything matches except the four EaseCenter sites (cases 6 and 9,
// 0x26a7ec-0x26a81c, 0x26a898-0x26a8c8, 0x26aa80-0x26aab0, 0x26ab2c-0x26ab5c): retail keeps the width in v1 and
// the half in a0, does NOT sign-extend the half, and re-extends cx ("seh v1,a1; subu a2,v1,a0"); ours
// sign-extends the half ("seh v1,v1; subu a2,a1,v1") because of the (short)(w / 2) cast. Without the cast
// (nx = cx - w/2) no seh is emitted at all (870 words).
// Ruled out (all 870/878 words or the same 28): int/short/const short& cx parameter, (int)/(short)/implicit
// float->short argument, short t / int t locals, reusing c, Lerp() helper returning short, single-expression
// nx, member vs free Width, short/int w, declaration order of nx/ox/half, -(w/2)+cx, (short)cx - (short)(w/2).
// Key wins: vtable slots are 8+4n (MWCC header), cases 4/7 tests are a switch (case 4 first), the bitfield
// test is (Flag() ^ 1) with Flag() returning bool, the scale/place loop bodies must be written literally in
// each loop (an inline helper changes the v0/v1 colouring), cx argument needs the (int) cast.
// near miss from lane bg1 (unreviewed)
