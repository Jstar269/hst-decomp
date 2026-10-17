/* HSTMATCH module=EBOOT.BIN start=0x00180edc end=0x00181284 symbol=FUN_00180edc lang=c++ */
/* Clone of src/sharing_main/FUN_0018d5d0.cpp (hstclone.py tag s10170158a2r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: the draw loop keeps three explicit induction values declared before it in the order i, t, q, ioff (i counter; t target; q = self stepping 4 for the target array at +0x1228; ioff = byte offset stepping 20 for the rect pointers, read as `(self + (ioff + 0x744))->rect` with the sum parenthesised so 0x744 stays out of the induction value; `self->tgt[i]` instead of q is 6 words off); the target is loaded before the rect pointer; x1/y1/x2/y2 are int locals with the scroll offset pre-added; `Plus(x, 0.0f)` is an inline float add whose 0.0f survives as mtc1/add.s and also fixes the callee-saved float numbering; FUN_00051894 takes (tex, color, 8 floats in f12..f19, 9th float z on the stack). */
struct Rect {
  char pad0[4];
  short x1, y1, x2, y2;
};
struct Vobj {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
};
struct Scale {
  char pad[0x60];
  float f60;
};
struct Sub744 {
  char pad[0x44];
  Rect *rect;
};
struct Obj {
  char pad0[4];
  Vobj *p4;
  void *p8;
  unsigned char on;
  unsigned char on2;
  Vobj *p10;
  char pad1[0x24 - 0x14];
  Scale *p24;
  char pad2[0x788 - 0x28];
  Rect *rects[1];
  char pad3[0x1228 - 0x78c];
  void *tgt[4];
  char pad4[0x1f45 - 0x1238];
  unsigned char flag1f45;
  char pad5[2];
  Vobj *p1f48;
  char pad6[0x2864 - 0x1f4c];
  Vobj *p2864;
};
struct Ctx178 {
  char pad[0x50];
  int f50;
  char pad1[0x59 - 0x54];
  unsigned char f59;
};
struct Game {
  char pad[0x178];
  Ctx178 *c178;
};

extern int DAT_002e096c;
extern int DAT_002e0970;
extern int DAT_00341518;
extern "C" {
void FUN_00051490(void *tex, int a, int b, int w, int h, int c, int d);
void FUN_00051894(void *tex, unsigned color, float u0, float v0, float x0, float y0, float u1, float v1,
                  float x1, float y1, float z);
void FUN_0005185c(void *tex);
void FUN_0005f1e8(void *, int);
int FUN_0016d110(int);
Game *FUN_0016bc70();
int FUN_00179700(int);
}

inline float Plus(float a, float b) { return a + b; }
inline const int &Min(const int &a, const int &b) { return b < a ? b : a; }

extern "C" void FUN_00180edc(Obj *self, int mode)
{
  if (self->on) {
    self->p10->v3();
    if (self->on2) {
      int w = (short)(self->rects[0]->x2 - self->rects[0]->x1);
      int h = (short)(self->rects[0]->y2 - self->rects[0]->y1) + 1;
      float mx = (float)((64 - w) / 2);
      float my = (float)((64 - h) / 2);
      if (mx < 0.0f) mx = 0.0f;
      if (my < 0.0f) my = 0.0f;
      float tr = (float)(h - 64);
      if (tr < 0.0f) tr = 0.0f;
      float ww = (float)Min(w, DAT_002e096c);
      float hh = (float)Min(h, DAT_002e0970);
      int off = (int)self->p24->f60;
      if (mode != 0x7fff && mode != 0x7ffe) {
        int n = FUN_0016d110(mode);
        int i;
        void *t;
        Obj *q;
        int ioff;
        i = 0;
        q = self;
        ioff = 0;
        for (; i < 4; i++) {
          if (i < n) {
            t = *(void **)((char *)q + 0x1228);
            Rect *r = ((Sub744 *)((char *)self + (ioff + 0x744)))->rect;
            int x1 = r->x1 + off;
            int y1 = r->y1 - 1;
            int x2 = r->x2 + off;
            int y2 = r->y2;
            FUN_00051490(t, 0, 0, 480, 272, 0, 0);
            FUN_00051894(t, 0x80808080, mx, my + 1.0f, Plus((float)x1, 0.0f),
                         (float)y1 + tr + 1.0f, mx + ww, my + hh, (float)x2, (float)y2, 16.0f);
            FUN_0005185c(t);
          }
          q = (Obj *)((char *)q + 4);
          ioff += 20;
        }
      }
    }
  }
  if (self->flag1f45) {
    self->p1f48->v3();
    self->p2864->v3();
  }
  if (self->p4) self->p4->v3();
  if (FUN_0016bc70()->c178->f59 != 0 && FUN_0016bc70()->c178->f50 < 2 && self->p8 != 0)
    FUN_0005f1e8(self->p8, FUN_00179700(DAT_00341518));
}
