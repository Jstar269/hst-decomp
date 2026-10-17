/* HSTMATCH module=EBOOT.BIN start=0x002546b4 end=0x0025488c symbol=FUN_002546b4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: MSL-style deque<int> iterator (128 per block, iterator-at-position is the out-of-line FUN_0025a80c, see deque_make_iter_0025a80c.cpp); `Iter it;` declared then assigned so begin() goes through a temp copy into registers; operator++ stores end_ before cur_; != compares cur_ directly. */
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
extern "C" Iter FUN_0025a80c(Deque *d, unsigned pos);

struct Deque {
  Map map_;
  unsigned start_;
  unsigned size_;
  Iter begin() { return FUN_0025a80c(this, 0); }
  Iter end() { return FUN_0025a80c(this, size_); }
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

extern "C" Ent *DAT_0034b340[];
extern "C" void *DAT_003386c8;
extern "C" int FUN_00254894(Self *, int);
extern "C" void *FUN_0008d970(void *, int);
extern "C" void FUN_00059174(void *);
extern "C" void FUN_0005f0d8(void *);
extern "C" void FUN_0005f1e8(void *, int);

extern "C" void FUN_002546b4(Self *self)
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
    if (!found && FUN_00254894(self, i) != 0 && DAT_0034b340[i] != 0) {
      DAT_0034b340[i]->m(self->f60[i]);
    }
    if (found && self->f0[i] == 0) {
      void *h = FUN_0008d970(DAT_003386c8, i);
      FUN_00059174(h);
      FUN_0005f0d8(h);
      FUN_0005f1e8(FUN_0008d970(DAT_003386c8, i), self->f60[i]);
    }
  }
}
