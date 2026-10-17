/* HSTMATCH module=EBOOT.BIN start=0x0028a3f4 end=0x0028a69c symbol=FUN_0028a3f4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Started from hstgen.py tag v0. Matching idioms: Vec4 is aligned(16); the by-value Mat4::SetPos(Vec4) setter gives the in-place copy of the last row and its 16-byte parameter slot above m, and it (like the negation of the second row) writes w,z,y,x; the slot-range check is an early-return inline helper whose bound is read through a getter (reloaded per pass); the iterator is a class with a free operator!= and a const begin() so begin != end is not folded; the width is loaded before the guard and added to lo inside it; the effect object vptr is stored explicitly (0x307564, restored to 0x30753c) around the out-of-line base ctor 0xce8e8 and the Mat4 copy 0x58694. */
struct Vec4 { float x, y, z, w; } __attribute__((aligned(16)));
struct Mat4 { Vec4 r0, r1, r2, r3; void SetPos(Vec4 v) { r3.w = v.w; r3.z = v.z; r3.y = v.y; r3.x = v.x; } };
struct Q { char pad[8]; float f8; };
struct P { Q *q; };
struct Ent { char pad[0xf4]; P *p; char padc[0xc]; float f10; };
struct Sub {
  char pad[0x100];
  float f100;
  float f104;
  char pad2[0x158 - 0x108];
  int f158;
  int f15c;
  int Last() const { return f15c; }
};
struct Rec { char pad[4]; short s4; short s6; short s8; char pada[2]; float fc; char pad10[0x1c - 0x10]; };

struct Fx {
  void *vptr;
  int f4;
  char pad8[8];
  Mat4 m;
  int f50;
  float f54;
  float f58;
  int f5c;
  unsigned char f60;
  char pad61[0x70 - 0x61];
};

struct Game { char pad[0x164]; void *f164; };

struct It {
  Rec *p;
  It(Rec *q) : p(q) {}
  Rec *operator->() const { return p; }
  It &operator++() { ++p; return *this; }
};
inline bool operator==(const It &a, const It &b) { return a.p == b.p; }
inline bool operator!=(const It &a, const It &b) { return !(a == b); }

struct RecVec {
  Rec *data;
  int count;
  It begin() const { return It(data); }
  It end() { return It(data + count); }
};

struct Obj {
  char pad[0x54];
  unsigned char f54;
  char pad55[0x74 - 0x55];
  Sub *f74;
  char pad78[0xac - 0x78];
  unsigned char fac;
  char padad[0xe0 - 0xad];
  RecVec recs;
  char pade8[4];
  unsigned char fec;
};

extern "C" {
extern char DAT_0030753c;
extern char DAT_00307564;
extern Game *DAT_0034a114;
void FUN_00055240(Mat4 *, Sub *, int);
void FUN_00022518(Vec4 *, Vec4 *);
void FUN_000224f8(Vec4 *, Vec4 *, Vec4 *);
Fx *FUN_000ce8e8(Fx *);
void FUN_00058694(Mat4 *, Mat4 *);
void FUN_00067790(void *, Fx *);
void FUN_00059174(Sub *);
void FUN_0005f0d8(Sub *);

static inline int AllReady(Sub *t)
{
  int i;
  for (i = t->f158; i <= t->Last(); i++) {
    Ent *e = (Ent *)((char *)t + i * 0x34);
    float v;
    if (e->p != 0) {
      v = e->p->q->f8;
    } else {
      v = 0.0f;
    }
    if (e->f10 < v) {
      return 0;
    }
  }
  return 1;
}

void FUN_0028a3f4(Obj *self)
{
  Sub *s;
  Sub *t;
  float lo, hi, w;
  Mat4 m;
  Fx fx;

  s = self->f74;
  FUN_00059174(s);
  FUN_0005f0d8(s);
  if (self->fec != 0) {
    if (self->f54 != 0 && self->fac != 0) {
      int ok = AllReady(self->f74);
      if (ok) {
        self->f54 = 0;
      }
    }
  }
  t = self->f74;
  lo = t->f104;
  w = t->f100;
  It it = self->recs.begin();
  if (it != self->recs.end()) {
    hi = lo + w;
    do {
      float fv = (float)it->s6;
      if (lo <= fv && fv < hi) {
          FUN_00055240(&m, self->f74, it->s8);
          m.r1.w = -m.r1.w;
          m.r1.z = -m.r1.z;
          m.r1.y = -m.r1.y;
          m.r1.x = -m.r1.x;
          FUN_00022518(&m.r1, &m.r1);
          m.r1.w = 0.0f;
          FUN_000224f8(&m.r0, &m.r1, &m.r2);
          FUN_00022518(&m.r0, &m.r0);
          m.r0.w = 0;
          FUN_000224f8(&m.r2, &m.r0, &m.r1);
          m.SetPos(m.r3);
          FUN_000ce8e8(&fx);
          fx.vptr = &DAT_00307564;
          FUN_00058694(&fx.m, &m);
          fx.f54 = 1.0f;
          fx.f58 = 3000.0f;
          fx.f50 = 0;
          fx.f5c = 0;
          fx.f60 = 0;
          fx.f50 = it->s4;
          fx.f54 = it->fc;
          fx.f58 = 3500.0f;
          FUN_00067790(DAT_0034a114->f164, &fx);
          fx.vptr = &DAT_0030753c;
      }
    ++it;
    } while (it != self->recs.end());
  }
}
}
