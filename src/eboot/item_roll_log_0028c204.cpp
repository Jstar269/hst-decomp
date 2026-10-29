/* HSTMATCH module=EBOOT.BIN start=0x0028c204 end=0x0028c4c0 symbol=FUN_0028c204 lang=c++ data=0x002fee8c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x002fee8c-0x002feed0) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Logs an item roll: clamps the float argument through Min against a limit, then either logs an empty item (negative ids) or rolls the LCG and, on a hit for kind 14 with no id yet, looks the id up in the container (find helper returns its iterator through a pointer, end test is an inline helper taking an unused empty tag, which materialises the compare as an int and adds the frame slot). Names provisional. */
struct Tag {};
struct Pair {
  int first;
  int second;
};
#define ITEM_KIND_LOOKUP 0xe /* kind whose missing id is looked up in the container */
#define ROLL_SCALE 3.0517578e-05f /* 1/32768: scales the 15-bit random value to [0,1) */
struct Cont {
  char pad0[0xc];
  Pair *beg;
  int count;
  char pad14[0x24 - 0x14];
  int key;
};
struct Item {
  char pad0[0x14];
  int kind;     /* 0x14 */
  int id;       /* 0x18 */
  float chance; /* 0x1c probability in [0,1] */
  int unk20;    /* 0x20 */
  int unk24;    /* 0x24 */
};
static inline bool AtEnd(Pair *p, Pair *end, Tag) { return !(p == end); }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
extern "C" {
extern int DAT_002cab1c;
extern int DAT_002cab20;
extern int DAT_0034a114;
extern unsigned DAT_0034a7f4;
void FUN_001c6bec(int, int, int, int, int, int);
void FUN_0028c0cc(char *, ...);
void FUN_0028c5e8(Pair **out, Pair *first, Pair *last, Tag, int *key);

int FUN_0028c204(float value, Cont *c, Item *it, int arg4)
{
  Pair *iter;
  int t = (int)(value + 6.0f);
  value = (float)Min(t, DAT_002cab1c);
  if (it->kind < 0 || it->id < 0) {
    FUN_001c6bec(DAT_0034a114, -1, -1, it->unk20, (int)value, 0);
    FUN_0028c0cc("Item empty\n");
  } else {
    DAT_0034a7f4 = DAT_0034a7f4 * 0x343fd + 0x269ec3;
    bool hit = ROLL_SCALE * (float)((DAT_0034a7f4 >> 16) & 0x7fff) < it->chance;
    int id = it->id; /* may be replaced by the looked-up id */
    if (hit && it->kind == ITEM_KIND_LOOKUP && id == 0) {
      FUN_0028c5e8(&iter, c->beg, c->beg + c->count, Tag(), &c->key);
      if (AtEnd(iter, c->beg + c->count, Tag())) {
        id = iter->first;
        hit = true;
      } else {
        hit = false;
      }
    }
    if (hit) {
      FUN_001c6bec(DAT_0034a114, it->kind, id, it->unk20, (int)value, arg4);
      FUN_0028c0cc("Item Get! (%d:%d)(%.0f%%)\n", it->kind, id, (double)(100.1f * it->chance));
    } else {
      int t2[4];
      t2[0] = (int)value;
      FUN_001c6bec(DAT_0034a114, -1, -1, it->unk24, (int)(float)Min(t2[0], DAT_002cab20), 0);
      FUN_0028c0cc("Item fail! (%d:%d)(%.0f%%)\n", it->kind, it->id, (double)(100.1f * it->chance));
    }
  }
  return 0;
}
}
