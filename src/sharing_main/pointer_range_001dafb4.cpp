/* HSTMATCH module=hstp_trans_main.prx start=0x001dafb4 end=0x001db01c symbol=FUN_001dafb4 lang=c++ */
/* Clone of src/eboot/pointer_range_001cc880.cpp (hstclone.py tag s10171846c1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Item { char pad[64]; int field; };
struct Iter;
struct List {
  char pad[64];
  Item **data;
  int size;
  Iter begin();
  Iter end();
};
struct Iter {
  Item **p;
  Iter() {}
  Iter(Item **q) : p(q) {}
  Item *operator*() const { return *p; }
  Iter &operator++() { ++p; return *this; }
};
inline Iter List::begin() { return Iter(data); }
inline Iter List::end() { return Iter(data + size); }
static inline int operator!=(const Iter &a, const Iter &b) { return (a.p == b.p) ^ 1; }
extern "C" void FUN_001dafb4(List *o)
{
  int bad = -1;
  Iter it = o->begin();
  Iter end = o->end();
  if (it != end) {
    do {
      Item *item = *it;
      if (item != 0) item->field = bad;
      ++it;
      end = o->end();
    } while (it != end);
  }
}
