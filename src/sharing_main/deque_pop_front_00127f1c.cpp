/* HSTMATCH module=hstp_trans_main.prx start=0x00127f1c end=0x00128024 symbol=FUN_00127f1c lang=c++ */
/* Clone of src/eboot/deque_pop_front_0011c998.cpp (hstclone.py tag c34): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque<12-byte T> (42 per block) pop_front(): {map (circular deque of block pointers, pop_front
   0x11d864), start offset, size}. The last element: destroy [begin(), end()) (0x11e3e8 over iterators made by
   0x11ed04), then free all but two blocks and recentre (21), or reset start when at most one block remains;
   otherwise advance start and free the front blocks while start >= 2 blocks. The block-count test is written
   `size() > 1` (the `< 2` and `>= 2` spellings give the wrong branch layout / register). Names provisional. */
struct Elem_00127f1c { int a, b, c; };
typedef Elem_00127f1c *Block_00127f1c;

struct MapIt_00127f1c {
    Block_00127f1c *p_;
    Block_00127f1c *first_;
    Block_00127f1c *beg_;
    Block_00127f1c *last_;
    MapIt_00127f1c(const MapIt_00127f1c &o) : p_(o.p_), first_(o.first_), beg_(o.beg_), last_(o.last_) {}
};
struct DequeIt_00127f1c {
    MapIt_00127f1c i_;
    Elem_00127f1c *cur_;
    Elem_00127f1c *end_;
};

struct Map_00127f1c {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block_00127f1c *data_;
    unsigned size() const { return size_; }
    Block_00127f1c &front() { return data_[start_]; }
};
struct Deque_00127f1c;
extern "C" {
DequeIt_00127f1c FUN_0012a530(Deque_00127f1c *d, unsigned pos);
void FUN_00129790(Deque_00127f1c *d, DequeIt_00127f1c first, DequeIt_00127f1c last);
void FUN_00129110(Map_00127f1c *m);
}
struct Deque_00127f1c {
    Map_00127f1c map_;
    unsigned start_;
    unsigned size_;
    DequeIt_00127f1c begin() { return FUN_0012a530(this, 0); }
    DequeIt_00127f1c end() { return FUN_0012a530(this, size_); }
};

extern "C" void FUN_00127f1c(Deque_00127f1c *self)
{
    if (self->size_ == 1) {
        FUN_00129790(self, self->begin(), self->end());
        self->size_ = 0;
        if (self->map_.size() > 1) {
            while (self->map_.size() > 2) {
                operator delete(self->map_.front());
                FUN_00129110(&self->map_);
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
                FUN_00129110(&self->map_);
                self->start_ -= 42;
            } while (self->start_ >= 84);
        }
    }
}
