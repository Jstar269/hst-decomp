/* HSTMATCH module=EBOOT.BIN start=0x0028a3f4 end=0x0028a69c symbol=FUN_0028a3f4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Started from hstgen.py tag v0. Matching idioms: Vec4 is aligned(16); the by-value Mat4::SetPos(Vec4) setter gives the in-place copy of the last row and its 16-byte parameter slot above m, and it (like the negation of the second row) writes w,z,y,x; the slot-range check is an early-return inline helper whose bound is read through a getter (reloaded per pass); the iterator is a class with a free operator!= and a const-reference Begin() against a non-const End() so begin != end is not folded; the width is loaded before the guard and added to lo inside it; the effect object vptr is stored explicitly (0x307564, restored to 0x30753c) around the out-of-line base ctor 0xce8e8 and the Mat4 copy 0x58694. */
#include "hst/effect_source.h"

struct Vec4 { float x, y, z, w; } __attribute__((aligned(16)));
struct Mat4 { Vec4 r0, r1, r2, r3; void SetPos(Vec4 v) { r3.w = v.w; r3.z = v.z; r3.y = v.y; r3.x = v.x; } };

/* View of the model holder at an entry offset (stride 0x34): its node and bound for entry i. */
struct Ent {
  char pad[0xf4];
  ModelNode *node;
  char padc[0xc];
  float bound;
};

/* Effect launched for a record (a polymorphic object; only the used fields are named). */
struct Fx {
  void *vptr;
  int unk4;
  char pad8[8];
  Mat4 m;
  int unk50;
  float unk54;
  float unk58;
  int unk5c;
  unsigned char unk60;
  char pad61[0x70 - 0x61];
};

struct Game { char pad[0x164]; void *unk164; };

struct It {
  EffectRec *p;
  It(EffectRec *q) : p(q) {}
  EffectRec *operator->() const { return p; }
  It &operator++() { ++p; return *this; }
};
inline bool operator==(const It &a, const It &b) { return a.p == b.p; }
inline bool operator!=(const It &a, const It &b) { return !(a == b); }

/* begin() is const and end() is not, so begin != end is not folded. */
inline It Begin(const EffectRecVec &v) { return It(v.data); }
inline It End(EffectRecVec &v) { return It(v.data + v.count); }

extern "C" {
extern char DAT_0030753c;
extern char DAT_00307564;
extern Game *DAT_0034a114;
void FUN_00055240(Mat4 *, ModelHolder *, int);
void FUN_00022518(Vec4 *, Vec4 *);
void FUN_000224f8(Vec4 *, Vec4 *, Vec4 *);
Fx *FUN_000ce8e8(Fx *);
void FUN_00058694(Mat4 *, Mat4 *);
void FUN_00067790(void *, Fx *);
void FUN_00059174(ModelHolder *);
void FUN_0005f0d8(ModelHolder *);

/* Model holder with the last-entry index behind a getter. */
struct Holder : ModelHolder {
  int Last() const { return unk15c; }
};

/* True when every entry's bound has been reached by its node's value. */
static inline int AllReady(Holder *t)
{
  int i;
  for (i = t->unk158; i <= t->Last(); i++) {
    Ent *e = (Ent *)((char *)t + i * 0x34);
    float v;
    if (e->node != 0) {
      v = e->node->item->value;
    } else {
      v = 0.0f;
    }
    if (e->bound < v) {
      return 0;
    }
  }
  return 1;
}

/* Per-frame update: advances the model holder, clears the waiting flag once all entries are ready, and spawns an effect for every record whose position lies in the holder's current range. */
void FUN_0028a3f4(EffectSource *self)
{
  ModelHolder *s;
  ModelHolder *t;
  float lo, hi, w;
  Mat4 m;
  Fx fx;

  s = self->modelA;
  FUN_00059174(s);
  FUN_0005f0d8(s);
  if (self->started != 0) {
    if (self->waiting != 0 && self->unkac != 0) {
      int ok = AllReady((Holder *)self->modelA);
      if (ok) {
        self->waiting = 0;
      }
    }
  }
  t = self->modelA;
  lo = t->unk104;
  w = t->unk100;
  It it = Begin(self->recs);
  if (it != End(self->recs)) {
    hi = lo + w;
    do {
      float fv = (float)it->pos;
      if (lo <= fv && fv < hi) {
          FUN_00055240(&m, self->modelA, it->nodeId);
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
          fx.unk54 = 1.0f;
          fx.unk58 = 3000.0f;
          fx.unk50 = 0;
          fx.unk5c = 0;
          fx.unk60 = 0;
          fx.unk50 = it->unk4;
          fx.unk54 = it->unkc;
          fx.unk58 = 3500.0f;
          FUN_00067790(DAT_0034a114->unk164, &fx);
          fx.vptr = &DAT_0030753c;
      }
    ++it;
    } while (it != End(self->recs));
  }
}
}
