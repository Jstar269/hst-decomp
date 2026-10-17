/* HSTMATCH module=EBOOT.BIN start=0x0011cd48 end=0x0011ce50 symbol=FUN_0011cd48 lang=c++ */
/* Clone of src/eboot/deque_pop_front_0011c998.cpp (hstclone.py tag c33): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque<12-byte T> (42 per block) pop_front(): {map (circular deque of block pointers, pop_front
   0x11d864), start offset, size}. The last element: destroy [begin(), end()) (0x11e3e8 over iterators made by
   0x11ed04), then free all but two blocks and recentre (21), or reset start when at most one block remains;
   otherwise advance start and free the front blocks while start >= 2 blocks. The block-count test is written
   `size() > 1` (the `< 2` and `>= 2` spellings give the wrong branch layout / register). Names provisional. */
struct Elem_0011cd48 { int a, b, c; };
typedef Elem_0011cd48 *Block_0011cd48;

struct MapIt_0011cd48 {
    Block_0011cd48 *p_;
    Block_0011cd48 *first_;
    Block_0011cd48 *beg_;
    Block_0011cd48 *last_;
    MapIt_0011cd48(const MapIt_0011cd48 &o) : p_(o.p_), first_(o.first_), beg_(o.beg_), last_(o.last_) {}
};
struct DequeIt_0011cd48 {
    MapIt_0011cd48 i_;
    Elem_0011cd48 *cur_;
    Elem_0011cd48 *end_;
};

struct Map_0011cd48 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block_0011cd48 *data_;
    unsigned size() const { return size_; }
    Block_0011cd48 &front() { return data_[start_]; }
};
struct Deque_0011cd48;
extern "C" {
DequeIt_0011cd48 FUN_0011f35c(Deque_0011cd48 *d, unsigned pos);
void FUN_0011e5bc(Deque_0011cd48 *d, DequeIt_0011cd48 first, DequeIt_0011cd48 last);
void FUN_0011df3c(Map_0011cd48 *m);
}
struct Deque_0011cd48 {
    Map_0011cd48 map_;
    unsigned start_;
    unsigned size_;
    DequeIt_0011cd48 begin() { return FUN_0011f35c(this, 0); }
    DequeIt_0011cd48 end() { return FUN_0011f35c(this, size_); }
};

extern "C" void FUN_0011cd48(Deque_0011cd48 *self)
{
    if (self->size_ == 1) {
        FUN_0011e5bc(self, self->begin(), self->end());
        self->size_ = 0;
        if (self->map_.size() > 1) {
            while (self->map_.size() > 2) {
                operator delete(self->map_.front());
                FUN_0011df3c(&self->map_);
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
                FUN_0011df3c(&self->map_);
                self->start_ -= 42;
            } while (self->start_ >= 84);
        }
    }
}
