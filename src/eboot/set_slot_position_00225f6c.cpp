/* HSTMATCH module=EBOOT.BIN start=0x00225f6c end=0x00226030 symbol=FUN_00225f6c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: typed Mgr/Node views as C++, the four float offsets are extern const (that is what hoists their loads above the member stores), and the tail is std::max-style const& max(count, idx + 1) (stack temp at sp+28); exact match verified; names and types await human review. */
struct Node { char pad[0x60]; float f60; float f64; };
struct Mgr {
  char pad[0x5c];
  Node *nodes[14];
  int count;
  float xs[16];
  float ys[16];
};
struct Holder { char pad[0x24]; Mgr *mgr; };
struct Owner { char pad[0x3c]; Holder *h; };
extern const float DAT_002f11f8;
extern const float DAT_002f11fc;
extern const float DAT_002f1200;
extern const float DAT_002f1204;
extern "C" void FUN_00102c54(Node *);

template <class T> inline const T &max(const T &a, const T &b) { return a < b ? b : a; }

extern "C" void FUN_00225f6c(float x, float y, Owner *o, int idx)
{
  Mgr *m = o->h->mgr;
  m->xs[idx] = x + DAT_002f11f8;
  m->ys[idx] = y + DAT_002f11fc;
  m->nodes[idx]->f60 = (x + DAT_002f1200) - 188.0f;
  m->nodes[idx]->f64 = (y + DAT_002f1204) - 120.0f;
  FUN_00102c54(m->nodes[idx]);
  int next = idx + 1;
  m->count = max(m->count, next);
}
