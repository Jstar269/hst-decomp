/* HSTMATCH module=hstp_trans_main.prx start=0x0029d9cc end=0x0029dc88 symbol=FUN_0029d9cc lang=c++ data=0x003a7e00 */
/* Clone of src/eboot/item_roll_log_0028c204.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x003a7e00-0x003a7e44) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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
extern int DAT_002db150;
extern int DAT_002db154;
extern int DAT_003f344c;
extern unsigned DAT_003f3b24;
void FUN_001d5014(int, int, int, int, int, int);
void FUN_0029baf0(char *, ...);
void FUN_0029ddb0(Pair **out, Pair *first, Pair *last, Tag, int *key);

int FUN_0029d9cc(float fl, Cont *c, Item *it, int p4)
{
  Pair *iter;
  int t = (int)(fl + 6.0f);
  fl = (float)Min(t, DAT_002db150);
  if (it->f14 < 0 || it->f18 < 0) {
    FUN_001d5014(DAT_003f344c, -1, -1, it->f20, (int)fl, 0);
    FUN_0029baf0("Item empty\n");
  } else {
    DAT_003f3b24 = DAT_003f3b24 * 0x343fd + 0x269ec3;
    bool hit = 3.0517578e-05f * (float)((DAT_003f3b24 >> 16) & 0x7fff) < it->f1c;
    int id = it->f18;
    if (hit && it->f14 == 0xe && id == 0) {
      FUN_0029ddb0(&iter, c->beg, c->beg + c->count, Tag(), &c->key);
      if (AtEnd(iter, c->beg + c->count, Tag())) {
        id = iter->a;
        hit = true;
      } else {
        hit = false;
      }
    }
    if (hit) {
      FUN_001d5014(DAT_003f344c, it->f14, id, it->f20, (int)fl, p4);
      FUN_0029baf0("Item Get! (%d:%d)(%.0f%%)\n", it->f14, id, (double)(100.1f * it->f1c));
    } else {
      int t2[4];
      t2[0] = (int)fl;
      FUN_001d5014(DAT_003f344c, -1, -1, it->f24, (int)(float)Min(t2[0], DAT_002db154), 0);
      FUN_0029baf0("Item fail! (%d:%d)(%.0f%%)\n", it->f14, it->f18, (double)(100.1f * it->f1c));
    }
  }
  return 0;
}
}
