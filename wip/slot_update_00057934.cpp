/* HSTMATCH module=EBOOT.BIN start=0x00057934 end=0x00057b08 symbol=FUN_00057934 lang=c++ */
typedef unsigned int u32;
extern "C" void FUN_00058e50(float, void *, int);
extern "C" void FUN_00057f30(void *, int);

struct Slot {
  u32 tex;
  u32 *ptr;
  char pad[0x10];
  float val;
  char pad2[0x34 - 0x1c];
};
struct Ctx {
  char pad0[0xe0];
  u32 **tbl;
  u32 cnt;
  char pad1[8];
  Slot slot[2];
  int lo;
  int hi;
  char pad3[0x180 - 0x160];
  int f180;
};

inline const int &Min(const int &a, const int &b) { return a < b ? a : b; }
inline const int &Max(const int &a, const int &b) { return a < b ? b : a; }

extern "C" int FUN_00057934(float f0, float f1, Ctx *c, u32 id0, u32 id1)
{
  u32 ids[2] = {id0, id1};
  float vals[2] = {f0, f1};
  int changed = 0;
  for (int i = 0; i < 2; i++) {
    u32 id = ids[i];
    Slot *s = &c->slot[i];
    if (id != 0x7fff && c->slot[i].tex != id) {
      s->tex = id;
      if ((int)id >= 0 && id < c->cnt)
        s->ptr = c->tbl[id];
      else
        s->ptr = 0;
      FUN_00058e50(0.0f, c, i);
      changed = 1;
      s->val = vals[i];
    }
  }
  if (changed) {
    c->lo = 0;
    c->hi = 0;
    for (int j = 0; j < 2; j++) {
      if (c->slot[j].ptr != 0) {
        c->lo = Min(j, c->lo);
        c->hi = Max(c->hi, j);
      }
    }
    FUN_00057f30(c, c->f180);
  }
  return changed;
}
// sy1: 117/117 words, 5 differing words (was 112 differing, 115 words). Solved: Ctx layout (slots stride 0x34 at +0xf0, lo/hi at
// 0x158/0x15c, f180), `u32 ids[2] = {id0, id1}; float vals[2] = {f0, f1};` (the zero-fill loops), FUN_00058e50 takes a FLOAT first
// argument (mtc1 zero,$f12), `if ((int)id >= 0 && id < cnt) ptr = tbl[id]; else ptr = 0;`, Min/Max as inline `const int &` helpers
// (j lives at 44(sp)). Left: (1) the likely/normal delay-slot fill of the first two branches is swapped (retail: `beql id==0x7fff`
// with the i++ in the slot, `beq tex==id` with `addiu s0,s2,240` in the slot; ours puts the slot pointer in the first branch's slot,
// because `Slot *s = &c->slot[i]` has to be declared before the `if` to be used for the tex store; declared inside the if, the tex
// store goes through 240(s2) instead); (2) the final j loop test is `sltiu v0,v1,2` in retail, `slti` here (an unsigned j makes
// the Min/Max compares unsigned and costs 6 words).
// near miss from lane sy1 (unreviewed)
