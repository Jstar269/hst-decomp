/* HSTMATCH module=EBOOT.BIN start=0x0011c8f0 end=0x0011c998 symbol=FUN_0011c8f0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque<12-byte T> (42 per block) clear(): destroy [begin(), end()) (0x11e3e8 over iterators made by
   0x11ed04), size = 0, then free all but two blocks and recentre (21), or reset start when at most one block
   remains. Same types as deque_pop_front_0011c998.cpp (its size == 1 path). Names provisional. */
struct Elem_0011c8f0 { int a, b, c; };
typedef Elem_0011c8f0 *Block_0011c8f0;

struct MapIt_0011c8f0 {
    Block_0011c8f0 *p_;
    Block_0011c8f0 *first_;
    Block_0011c8f0 *beg_;
    Block_0011c8f0 *last_;
    MapIt_0011c8f0(const MapIt_0011c8f0 &o) : p_(o.p_), first_(o.first_), beg_(o.beg_), last_(o.last_) {}
};
struct DequeIt_0011c8f0 {
    MapIt_0011c8f0 i_;
    Elem_0011c8f0 *cur_;
    Elem_0011c8f0 *end_;
};

struct Map_0011c8f0 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block_0011c8f0 *data_;
    unsigned size() const { return size_; }
    Block_0011c8f0 &front() { return data_[start_]; }
};
struct Deque_0011c8f0;
extern "C" {
DequeIt_0011c8f0 FUN_0011ed04(Deque_0011c8f0 *d, unsigned pos);
void FUN_0011e3e8(Deque_0011c8f0 *d, DequeIt_0011c8f0 first, DequeIt_0011c8f0 last);
void FUN_0011d864(Map_0011c8f0 *m);
}
struct Deque_0011c8f0 {
    Map_0011c8f0 map_;
    unsigned start_;
    unsigned size_;
    DequeIt_0011c8f0 begin() { return FUN_0011ed04(this, 0); }
    DequeIt_0011c8f0 end() { return FUN_0011ed04(this, size_); }
};

extern "C" void FUN_0011c8f0(Deque_0011c8f0 *self)
{
    FUN_0011e3e8(self, self->begin(), self->end());
    self->size_ = 0;
    if (self->map_.size() > 1) {
        while (self->map_.size() > 2) {
            operator delete(self->map_.front());
            FUN_0011d864(&self->map_);
        }
        self->start_ = 21;
    } else {
        self->start_ = 0;
    }
}
