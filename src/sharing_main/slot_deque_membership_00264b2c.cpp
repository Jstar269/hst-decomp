/* HSTMATCH module=hstp_trans_main.prx start=0x00264b2c end=0x00264d04 symbol=FUN_00264b2c lang=c++ */
/* Clone of src/eboot/slot_deque_membership_002546b4.cpp (hstclone.py tag s10170158a1r2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: MSL-style deque<int> iterator (128 per block, iterator-at-position is the out-of-line FUN_0026acbc, see deque_make_iter_0026acbc.cpp); `Iter it;` declared then assigned so begin() goes through a temp copy into registers; operator++ stores end_ before cur_; != compares cur_ directly. */
typedef int Elem;
typedef Elem *Block;

struct MapIt {
  Block *ptr;
  Block *beg;
  Block *first;
  Block *end;
  MapIt() {}
  MapIt(const MapIt &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
};

struct Iter {
  MapIt i_;
  Elem *cur_;
  Elem *end_;
  Iter() {}
  Iter(const Iter &o) : i_(o.i_), cur_(o.cur_), end_(o.end_) {}
  Elem &operator*() const { return *cur_; }
  Iter &operator++()
  {
    ++cur_;
    if (cur_ == end_) {
      ++i_.ptr;
      if (i_.ptr == i_.end) i_.ptr = i_.beg;
      Elem *b = *i_.ptr;
      end_ = b + 128;
      cur_ = b;
    }
    return *this;
  }
};
inline bool operator==(const Iter &a, const Iter &b) { return a.cur_ == b.cur_; }
inline bool operator!=(const Iter &a, const Iter &b) { return a.cur_ != b.cur_; }

struct Map {
  unsigned cap_;
  unsigned size_;
  unsigned start_;
  Block *data_;
};

struct Deque;
extern "C" Iter FUN_0026acbc(Deque *d, unsigned pos);

struct Deque {
  Map map_;
  unsigned start_;
  unsigned size_;
  Iter begin() { return FUN_0026acbc(this, 0); }
  Iter end() { return FUN_0026acbc(this, size_); }
};

struct Ent {
  virtual void v0();
  virtual void v1();
  virtual void m(int);
};

struct Self {
  char pad0[0x60];
  int f60[36];
  unsigned char f0[8];
  int count;
  char pad1[0x1dc - 0xfc];
  int f1dc[4];
  Deque dq;
};

extern "C" Ent *DAT_003f468c[];
extern "C" void *DAT_003e1a08;
extern "C" int FUN_00264d0c(Self *, int);
extern "C" void *FUN_0008f108(void *, int);
extern "C" void FUN_00059e58(void *);
extern "C" void FUN_0005fec8(void *);
extern "C" void FUN_0005ffd8(void *, int);

extern "C" void FUN_00264b2c(Self *self)
{
  for (int i = 0; i < self->count; i++) {
    bool found = false;
    if (self->f1dc[i] == 2) {
      found = true;
    } else {
      Iter it;
      for (it = self->dq.begin(); it != self->dq.end(); ++it) {
        if (*it == i) {
          found = true;
          break;
        }
      }
    }
    if (!found && FUN_00264d0c(self, i) != 0 && DAT_003f468c[i] != 0) {
      DAT_003f468c[i]->m(self->f60[i]);
    }
    if (found && self->f0[i] == 0) {
      void *h = FUN_0008f108(DAT_003e1a08, i);
      FUN_00059e58(h);
      FUN_0005fec8(h);
      FUN_0005ffd8(FUN_0008f108(DAT_003e1a08, i), self->f60[i]);
    }
  }
}
