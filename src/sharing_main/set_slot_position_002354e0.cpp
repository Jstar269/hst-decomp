/* HSTMATCH module=hstp_trans_main.prx start=0x002354e0 end=0x002355a4 symbol=FUN_002354e0 lang=c++ */
/* Clone of src/eboot/set_slot_position_00225f6c.cpp (hstclone.py tag s10170158a3r1s): addresses substituted; exact match verified; names and types await human review. */
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
extern const float DAT_003995c4;
extern const float DAT_003995c8;
extern const float DAT_003995cc;
extern const float DAT_003995d0;
extern "C" void FUN_00108558(Node *);

template <class T> inline const T &max(const T &a, const T &b) { return a < b ? b : a; }

extern "C" void FUN_002354e0(float x, float y, Owner *o, int idx)
{
  Mgr *m = o->h->mgr;
  m->xs[idx] = x + DAT_003995c4;
  m->ys[idx] = y + DAT_003995c8;
  m->nodes[idx]->f60 = (x + DAT_003995cc) - 188.0f;
  m->nodes[idx]->f64 = (y + DAT_003995d0) - 120.0f;
  FUN_00108558(m->nodes[idx]);
  int next = idx + 1;
  m->count = max(m->count, next);
}
