/* HSTMATCH module=EBOOT.BIN start=0x0011c998 end=0x0011caa0 symbol=FUN_0011c998 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque<12-byte T> (42 per block) pop_front(): {map (circular deque of block pointers, pop_front
   0x11d864), start offset, size}. The last element: destroy [begin(), end()) (0x11e3e8 over iterators made by
   0x11ed04), then free all but two blocks and recentre (21), or reset start when at most one block remains;
   otherwise advance start and free the front blocks while start >= 2 blocks. The block-count test is written
   `size() > 1` (the `< 2` and `>= 2` spellings give the wrong branch layout / register). Names provisional. */
struct Elem_0011c998 { int a, b, c; };
typedef Elem_0011c998 *Block_0011c998;

struct MapIt_0011c998 {
    Block_0011c998 *p_;
    Block_0011c998 *first_;
    Block_0011c998 *beg_;
    Block_0011c998 *last_;
    MapIt_0011c998(const MapIt_0011c998 &o) : p_(o.p_), first_(o.first_), beg_(o.beg_), last_(o.last_) {}
};
struct DequeIt_0011c998 {
    MapIt_0011c998 i_;
    Elem_0011c998 *cur_;
    Elem_0011c998 *end_;
};

struct Map_0011c998 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block_0011c998 *data_;
    unsigned size() const { return size_; }
    Block_0011c998 &front() { return data_[start_]; }
};
struct Deque_0011c998;
extern "C" {
DequeIt_0011c998 FUN_0011ed04(Deque_0011c998 *d, unsigned pos);
void FUN_0011e3e8(Deque_0011c998 *d, DequeIt_0011c998 first, DequeIt_0011c998 last);
void FUN_0011d864(Map_0011c998 *m);
}
struct Deque_0011c998 {
    Map_0011c998 map_;
    unsigned start_;
    unsigned size_;
    DequeIt_0011c998 begin() { return FUN_0011ed04(this, 0); }
    DequeIt_0011c998 end() { return FUN_0011ed04(this, size_); }
};

extern "C" void FUN_0011c998(Deque_0011c998 *self)
{
    if (self->size_ == 1) {
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
    } else {
        --self->size_;
        if (++self->start_ >= 84) {
            do {
                operator delete(self->map_.front());
                FUN_0011d864(&self->map_);
                self->start_ -= 42;
            } while (self->start_ >= 84);
        }
    }
}
