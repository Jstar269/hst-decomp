/* HSTMATCH module=hstp_trans_main.prx start=0x0023212c end=0x002324cc symbol=FUN_0023212c lang=c++ data=0x00399380 */
/* Clone of src/eboot/prize_display_setup_00222bb8.cpp (hstclone.py tag c21sn4s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x00399380-0x003993cc) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idioms: #pragma opt_strength_reduction off with the pointer walks written out by hand [the panes loop walks a Obj pointer by 4, the two 16-entry clears walk s += 0x30 and MWCC unrolls them 8x], the fb1 != 0 arm written first, the float defaults as ternaries 'p3 != 0 ? G : 0.0f', and sel declared before g); names and types await human review. */
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
extern int DAT_0039835c;
extern float DAT_00398354;
extern char DAT_0039855c[];
extern char DAT_003b7ebc[];
extern float DAT_003f35a0;
extern float DAT_003f35a4;
extern float DAT_003f35b0;
extern float DAT_00399378;
extern float DAT_0039937c;
extern char *DAT_003f3598;
extern char *DAT_003f359c;
extern char DAT_003eaad8[];
void FUN_00232608(Obj *);
int FUN_000143b0(char *, const char *, ...);
void FUN_00227ffc(int *, int *, int);
void FUN_00105470(void *, int);
int FUN_00014934(const char *, const char *);
void FUN_0001c684(void *, int, char *);
void FUN_0001c73c(void *);
void *FUN_000518d4(void *);
void FUN_00051ad8(void *, char *, int);
void FUN_00051d38(float, void *);
int FUN_0020d1e0(int, int, int);
void FUN_00113a50(void *);
void FUN_00108dac(Obj *);
int FUN_001c0bb0(void *, int);
}

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
  return value < lo ? lo : (!(value > hi) ? value : hi);
}

extern "C" void FUN_0023212c(Obj *self, int p2, int p3)
{
  char buf[256];
  self->f60 = DAT_0039835c;
  self->f54 = p2;
  self->fb2 = p3;
  self->fb0 = 1;
  self->fa8 = 0;
  self->fac = 0;
  FUN_00232608(self);
  FUN_000143b0(buf, DAT_0039855c);
  if (self->f9c != 0) {
    if (self->f9c != 0) {
      delete self->f9c;
      self->f9c = 0;
    }
  }
  FUN_00227ffc(&self->fa8, &self->fac, self->f54);
  if (self->fb1 != 0) {
    self->fa4->m1(1);
    int sel = self->fa8;
    Node *g = (Node *)self->fa4;
    int i;
    for (i = 0; i < g->count; i++)
      FUN_00105470(g->items[i], i != sel);
    Slot *q = (Slot *)((Node *)self->fa4)->items[self->fa8];
    q->f24 = q->f28 + self->fac;
  }
  FUN_000143b0(buf, "data/menu/menu_common/info_kunsyou%03d", self->fa8 + 1);
  if (self->fb1 == 0) {
    if (FUN_00014934(buf, DAT_0039855c) != 0) {
      FUN_0001c684(DAT_003b7ebc, 1, "game/700_prize/040_prize_display.xb");
      void *m = ::operator new(0x48);
      if (m != 0)
        m = FUN_000518d4(m);
      self->f9c = (Widget *)m;
      FUN_00051ad8(m, buf, 0);
      FUN_00051d38(10.0f + DAT_00398354, self->f9c);
      FUN_0001c73c(DAT_003b7ebc);
    }
  }
  int r = FUN_0020d1e0(9, 4, self->f54);
  char *o = (char *)self->fa0;
  *(int *)(o + 0xf8) = r;
  *(int *)(o + 0x138) = 1;
  FUN_00113a50(o);
  int i = 0;
  Obj *p = self;
  do {
    if (p->panes[0] != 0) {
      if (i == 0) {
        float a = p3 != 0 ? DAT_003f35a0 : 0.0f;
        p->panes[0]->f60 = self->fb4 + a;
        float b = p3 != 0 ? DAT_003f35a4 : 0.0f;
        p->panes[0]->f64 = self->fb8 + b;
      }
      float v = p3 != 0 ? DAT_003f35b0 : 1.0f;
      p->panes[0]->f78 = Clamp(v, DAT_00399378, DAT_0039937c);
    }
    i++;
    p = (Obj *)((char *)p + 4);
  } while (i < 2);
  FUN_00108dac(self);
  FUN_00105470(self->f7c, 1);
  *self->f7c = 0xffffff;
  char *s = DAT_003f3598;
  for (int k = 0; k < 16; k++) {
    s[0x20] = 0;
    s += 0x30;
  }
  s = DAT_003f359c;
  for (int k = 0; k < 16; k++) {
    s[0x20] = 0;
    s += 0x30;
  }
  self->f64 = FUN_001c0bb0(DAT_003eaad8, 12);
}
