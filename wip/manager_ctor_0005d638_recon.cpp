/* HSTMATCH module=EBOOT.BIN start=0x0005d638 end=0x0005d818 symbol=FUN_0005d638 lang=c++ */
/* Hand-written reconstruction from the disassembly; NOT exact yet. */
struct Pair {
  float *data;
  unsigned size;
  unsigned cap;
};

struct Rec {
  unsigned char flag;
  char pad0[3];
  int f4;
  Pair v;
  int count;
  float *tab;
  int f1c;
  int f20;
  Pair w;
};

struct Self {
  void *handle;
  Rec **data;
  unsigned size;
  unsigned cap;
  float limit;
};

struct Tag { char c; };

extern "C" {
void FUN_0005d8c4(Self *);
void *FUN_0004cad0(void *, int *, int, int);
void *FUN_00000bcc(unsigned);
void *FUN_0005cfb4(Rec *, void *);
void FUN_0005dc60(Rec ***, Rec **, struct Tag);
void FUN_0005d8d0(Self *, void *, void *, void *, void *, void *, void *);
}

inline float Max(const float &a, const float &b) { return a < b ? b : a; }

extern "C" void *FUN_0005d638(Self *self, void *src, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7)
{
  int out;
  Rec *slot;
  Rec *hdr;
  Rec *item;
  void *cur;
  int n;
  int i;
  float last;
  float v;

  self->data = 0;
  self->size = 0;
  self->cap = 0;
  FUN_0005d8c4(self);
  hdr = (Rec *)FUN_0004cad0(src, &out, 16, 1);
  self->handle = hdr;
  if (hdr != 0) {
  n = *(int *)hdr;
  cur = (char *)hdr + 4;
  for (i = 0; i < n; i++) {
    item = (Rec *)FUN_00000bcc(48);
    if (item != 0) {
      item->v.data = 0;
      item->v.size = 0;
      item->v.cap = 0;
      item->w.data = 0;
      item->w.size = 0;
      item->w.cap = 0;
      item->flag = 0;
      item->f4 = 0;
      item->count = 0;
      item->tab = 0;
      item->f1c = 0;
      item->f20 = 0;
    }
    slot = item;
    cur = FUN_0005cfb4(item, cur);
    if (self->size < self->cap) {
      self->size = self->size + 1;
      self->data[self->size - 1] = slot;
    } else {
      FUN_0005dc60(&self->data, &slot, Tag());
    }
    last = slot->count > 0 ? slot->tab[slot->count - 1] : 0.0f;
    v = 30.0f * last;
    const float &m = self->limit < v ? v : self->limit;
    self->limit = m;
  }
  if (a2 != 0 && a3 != 0)
    FUN_0005d8d0(self, a2, a3, a4, a5, a6, a7);
  }
  return self;
}
// NEAR MISS -- 120/120 words, only TWO words differ: the t3 parameter home. Ours `sw t3,60(sp)` and
// `lw t2,60(sp)`; retail `sw t3,56(sp)` / `lw t2,56(sp)`. Nothing else differs: same frame (80), same
// locals (float temp 68, `slot` 72, `out` 76), same instruction sequence from 0x5d638 to 0x5d818.
// The batch named wip/item_manager_ctor_0005d638.cpp, which is not in this lane; this was rebuilt from
// hstdis and refined with hstcc stack-layout probes. Shapes that are now VERIFIED word for word against
// retail, in the order they were found:
//  - overflow guard: body wrapped in `if (hdr != 0) { ... }` with ONE trailing `return self;` (an early
//    `if (hdr == 0) return self;` inverts the branch and costs two words);
//  - record zero-init order: v.data/v.size/v.cap, w.data/w.size/w.cap, flag, f4, count, tab, f1c, f20
//    (two 3-word sub-objects first, then the byte member, then the scalars);
//  - capacity test unsigned (`sltu`) with the `beqzl at,GROW; move v0,zero` form;
//  - the max select written as `const float &m = self->limit < v ? v : self->limit; self->limit = m;`
//    (a Max(ref,ref) helper keeps the value in a register and loses the whole bc1fl/addiu/lwc1/swc1 tail);
//  - the append helper's third argument is a BY-VALUE STRUCT (`struct Tag { char c; }`, or an empty
//    `struct Tag {}` - both give identical code), not a char or an int: that is what produces
//    `move v0,zero; seb a2,v0` and, with it, the 16-byte larger frame (48..63 argument home area) that had
//    blocked this function for two lanes. Same idiom as
//    wip/rec28_reserve_copy_00237330.cpp's `Tag` parameter;
//  - tail: `if (a2 != 0 && a3 != 0) FUN_0005d8d0(self, a2, a3, a4, a5, a6, a7); return self;`.
// Ruled out for the last two words: 8th parameter typed void*/int/char/short/unsigned (same offset), a 9th
// parameter added (ignored), the 7th value copied into a local first, and Tag as short/int/2-int (all
// change the call to `seb`-less forms and cost 5-7 words). Retail behaves as if t3 were SPILLED to a
// local slot at 56 while MWCC homes it at 60 in every spelling tried.
// 2026-10-22 last test (lane fm1): the t3 slot is NOT a same-TU effect. Compiling this body with an extra
// function placed before it in the same file (hstcc runprobe.cpp) still emits `sw t3,60(sp)`, so a run
// source covering the previous EBOOT function would not move it either. Remaining options are only an
// allocator-level difference (retail spilled the value, MWCC homes it) or a source statement that makes one
// more value live across the loop; nothing tried reaches it.
// near miss from lane fm1 (unreviewed)
