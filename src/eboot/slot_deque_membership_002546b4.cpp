/* HSTMATCH module=EBOOT.BIN start=0x002546b4 end=0x0025488c symbol=FUN_002546b4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: MSL-style deque<int> iterator (128 per block, iterator-at-position is the out-of-line FUN_0025a80c, see deque_make_iter_0025a80c.cpp); `Iter it;` declared then assigned so begin() goes through a temp copy into registers; operator++ stores end_ before cur_; != compares cur_ directly. */
#include "hst/slot_queue.h"

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

extern "C" Iter FUN_0025a80c(SlotDeque *d, unsigned pos);

/* Iterators at the start and past the end of the queue. */
inline Iter DequeBegin(SlotDeque *q) { return FUN_0025a80c(q, 0); }
inline Iter DequeEnd(SlotDeque *q) { return FUN_0025a80c(q, q->length); }

/* Entry started for a slot; virtual slot 2 is called with the slot's value. */
struct Ent {
  virtual void v0();
  virtual void v1();
  virtual void m(int);
};

extern "C" Ent *DAT_0034b340[];
extern "C" void *DAT_003386c8;
extern "C" int FUN_00254894(SlotQueueObj *, int);
extern "C" void *FUN_0008d970(void *, int);
extern "C" void FUN_00059174(void *);
extern "C" void FUN_0005f0d8(void *);
extern "C" void FUN_0005f1e8(void *, int);

/* Per-frame update: for each slot, checks whether it is pending or queued. A slot that is neither and passes
   the check calls its entry's virtual method; a queued or pending slot whose flag byte at 0xf0 is clear gets its pane helpers called. */
extern "C" void FUN_002546b4(SlotQueueObj *self)
{
  for (int i = 0; i < self->count; i++) {
    bool found = false;
    if (self->state[i] == SLOT_STATE_PENDING) {
      found = true;
    } else {
      Iter it;
      for (it = DequeBegin(&self->queue); it != DequeEnd(&self->queue); ++it) {
        if (*it == i) {
          found = true;
          break;
        }
      }
    }
    if (!found && FUN_00254894(self, i) != 0 && DAT_0034b340[i] != 0) {
      DAT_0034b340[i]->m(self->unk60[i]);
    }
    if (found && self->unkf0[i] == 0) {
      void *h = FUN_0008d970(DAT_003386c8, i);
      FUN_00059174(h);
      FUN_0005f0d8(h);
      FUN_0005f1e8(FUN_0008d970(DAT_003386c8, i), self->unk60[i]);
    }
  }
}
