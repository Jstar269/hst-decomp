/* HSTMATCH module=EBOOT.BIN start=0x00222bb8 end=0x00222f58 symbol=FUN_00222bb8 lang=c++ data=0x002f0fb4 */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idioms: #pragma opt_strength_reduction off with the pointer walks written out by hand [the panes loop walks a Obj pointer by 4, the two 16-entry clears walk s += 0x30 and MWCC unrolls them 8x], the fb1 != 0 arm written first, the float defaults as ternaries 'p3 != 0 ? G : 0.0f', and sel declared before g); names and types await human review. Data: its string literals (2 strings, 0x002f0fb4-0x002f1000) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#pragma opt_strength_reduction off

struct Widget {
  virtual ~Widget();
};
struct Choice {
  virtual void m0();
  virtual void m1(int v);
};
struct Group {
  char pad[0x10];
  int *items;
  int count;
};
struct Slot {
  char pad[0x24];
  int f24;
  int f28;
};
struct Pane {
  char pad[0x60];
  float f60;
  float f64;
  char pad2[0x78 - 0x68];
  float f78;
};
struct Node {
  char pad[0x10];
  void **items;
  int count;
};
struct Obj {
  char pad0[0x54];
  int f54;
  char pad1[0x60 - 0x58];
  int f60;
  int f64;
  Pane *panes[2];
  char pad3[0x7c - 0x70];
  unsigned *f7c;
  char pad4[0x9c - 0x80];
  Widget *f9c;
  void *fa0;
  Choice *fa4;
  int fa8;
  int fac;
  unsigned char fb0;
  unsigned char fb1;
  unsigned char fb2;
  char padb3;
  float fb4;
  float fb8;
};

extern "C" {
extern int DAT_002eff90;
extern float DAT_002eff88;
extern char DAT_002f0190[];
extern char DAT_0030ebf4[];
extern float DAT_0034a270;
extern float DAT_0034a274;
extern float DAT_0034a280;
extern float DAT_002f0fac;
extern float DAT_002f0fb0;
extern char *DAT_0034a268;
extern char *DAT_0034a26c;
extern char DAT_0034179c[];
void FUN_00223094(Obj *);
int FUN_000143b0(char *, const char *, ...);
void FUN_00218ae4(int *, int *, int);
void FUN_000ffb3c(void *, int);
int FUN_00014934(const char *, const char *);
void FUN_0001cad0(void *, int, char *);
void FUN_0001cb88(void *);
void *FUN_00050fc0(void *);
void FUN_000511c4(void *, char *, int);
void FUN_00051398(float, void *);
int FUN_001fea10(int, int, int);
void FUN_0010d4a8(void *);
void FUN_00103480(Obj *);
int FUN_001b2af0(void *, int);
}

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
  return value < lo ? lo : (!(value > hi) ? value : hi);
}

extern "C" void FUN_00222bb8(Obj *self, int p2, int p3)
{
  char buf[256];
  self->f60 = DAT_002eff90;
  self->f54 = p2;
  self->fb2 = p3;
  self->fb0 = 1;
  self->fa8 = 0;
  self->fac = 0;
  FUN_00223094(self);
  FUN_000143b0(buf, DAT_002f0190);
  if (self->f9c != 0) {
    if (self->f9c != 0) {
      delete self->f9c;
      self->f9c = 0;
    }
  }
  FUN_00218ae4(&self->fa8, &self->fac, self->f54);
  if (self->fb1 != 0) {
    self->fa4->m1(1);
    int sel = self->fa8;
    Node *g = (Node *)self->fa4;
    int i;
    for (i = 0; i < g->count; i++)
      FUN_000ffb3c(g->items[i], i != sel);
    Slot *q = (Slot *)((Node *)self->fa4)->items[self->fa8];
    q->f24 = q->f28 + self->fac;
  }
  FUN_000143b0(buf, "data/menu/menu_common/info_kunsyou%03d", self->fa8 + 1);
  if (self->fb1 == 0) {
    if (FUN_00014934(buf, DAT_002f0190) != 0) {
      FUN_0001cad0(DAT_0030ebf4, 1, "game/700_prize/040_prize_display.xb");
      void *m = ::operator new(0x48);
      if (m != 0)
        m = FUN_00050fc0(m);
      self->f9c = (Widget *)m;
      FUN_000511c4(m, buf, 0);
      FUN_00051398(10.0f + DAT_002eff88, self->f9c);
      FUN_0001cb88(DAT_0030ebf4);
    }
  }
  int r = FUN_001fea10(9, 4, self->f54);
  char *o = (char *)self->fa0;
  *(int *)(o + 0xf8) = r;
  *(int *)(o + 0x138) = 1;
  FUN_0010d4a8(o);
  int i = 0;
  Obj *p = self;
  do {
    if (p->panes[0] != 0) {
      if (i == 0) {
        float a = p3 != 0 ? DAT_0034a270 : 0.0f;
        p->panes[0]->f60 = self->fb4 + a;
        float b = p3 != 0 ? DAT_0034a274 : 0.0f;
        p->panes[0]->f64 = self->fb8 + b;
      }
      float v = p3 != 0 ? DAT_0034a280 : 1.0f;
      p->panes[0]->f78 = Clamp(v, DAT_002f0fac, DAT_002f0fb0);
    }
    i++;
    p = (Obj *)((char *)p + 4);
  } while (i < 2);
  FUN_00103480(self);
  FUN_000ffb3c(self->f7c, 1);
  *self->f7c = 0xffffff;
  char *s = DAT_0034a268;
  for (int k = 0; k < 16; k++) {
    s[0x20] = 0;
    s += 0x30;
  }
  s = DAT_0034a26c;
  for (int k = 0; k < 16; k++) {
    s[0x20] = 0;
    s += 0x30;
  }
  self->f64 = FUN_001b2af0(DAT_0034179c, 12);
}
