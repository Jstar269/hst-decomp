/* HSTMATCH module=EBOOT.BIN start=0x0028c204 end=0x0028c4c0 symbol=FUN_0028c204 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Logs an item roll: clamps the float argument through Min against a limit, then either logs an empty item (negative ids) or rolls the LCG and, on a hit for kind 14 with no id yet, looks the id up in the container (find helper returns its iterator through a pointer, end test is an inline helper taking an unused empty tag, which materialises the compare as an int and adds the frame slot). Names provisional. */
struct Tag {};
struct Pair {
  int a;
  int b;
};
struct Cont {
  char pad0[0xc];
  Pair *beg;
  int count;
  char pad14[0x24 - 0x14];
  int key;
};
struct Item {
  char pad0[0x14];
  int f14;
  int f18;
  float f1c;
  int f20;
  int f24;
};
static inline bool AtEnd(Pair *p, Pair *end, Tag) { return !(p == end); }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
extern "C" {
extern int DAT_002cab1c;
extern int DAT_002cab20;
extern int DAT_0034a114;
extern unsigned DAT_0034a7f4;
extern char DAT_002fee8c[];
extern char DAT_002fee98[];
extern char DAT_002feeb4[];
void FUN_001c6bec(int, int, int, int, int, int);
void FUN_0028c0cc(char *, ...);
void FUN_0028c5e8(Pair **out, Pair *first, Pair *last, Tag, int *key);

int FUN_0028c204(float fl, Cont *c, Item *it, int p4)
{
  Pair *iter;
  int t = (int)(fl + 6.0f);
  fl = (float)Min(t, DAT_002cab1c);
  if (it->f14 < 0 || it->f18 < 0) {
    FUN_001c6bec(DAT_0034a114, -1, -1, it->f20, (int)fl, 0);
    FUN_0028c0cc(DAT_002fee8c);
  } else {
    DAT_0034a7f4 = DAT_0034a7f4 * 0x343fd + 0x269ec3;
    bool hit = 3.0517578e-05f * (float)((DAT_0034a7f4 >> 16) & 0x7fff) < it->f1c;
    int id = it->f18;
    if (hit && it->f14 == 0xe && id == 0) {
      FUN_0028c5e8(&iter, c->beg, c->beg + c->count, Tag(), &c->key);
      if (AtEnd(iter, c->beg + c->count, Tag())) {
        id = iter->a;
        hit = true;
      } else {
        hit = false;
      }
    }
    if (hit) {
      FUN_001c6bec(DAT_0034a114, it->f14, id, it->f20, (int)fl, p4);
      FUN_0028c0cc(DAT_002fee98, it->f14, id, (double)(100.1f * it->f1c));
    } else {
      int t2[4];
      t2[0] = (int)fl;
      FUN_001c6bec(DAT_0034a114, -1, -1, it->f24, (int)(float)Min(t2[0], DAT_002cab20), 0);
      FUN_0028c0cc(DAT_002feeb4, it->f14, it->f18, (double)(100.1f * it->f1c));
    }
  }
  return 0;
}
}
