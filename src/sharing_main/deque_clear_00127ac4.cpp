/* HSTMATCH module=hstp_trans_main.prx start=0x00127ac4 end=0x00127b6c symbol=FUN_00127ac4 lang=c++ */
/* Clone of src/eboot/deque_clear_0011c8f0.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque<12-byte T> (42 per block) clear(): destroy [begin(), end()) (0x11e3e8 over iterators made by
   0x11ed04), size = 0, then free all but two blocks and recentre (21), or reset start when at most one block
   remains. Same types as deque_pop_front_0011c998.cpp (its size == 1 path). Names provisional. */
struct Elem_00127ac4 { int a, b, c; };
typedef Elem_00127ac4 *Block_00127ac4;

struct MapIt_00127ac4 {
    Block_00127ac4 *p_;
    Block_00127ac4 *first_;
    Block_00127ac4 *beg_;
    Block_00127ac4 *last_;
    MapIt_00127ac4(const MapIt_00127ac4 &o) : p_(o.p_), first_(o.first_), beg_(o.beg_), last_(o.last_) {}
};
struct DequeIt_00127ac4 {
    MapIt_00127ac4 i_;
    Elem_00127ac4 *cur_;
    Elem_00127ac4 *end_;
};

struct Map_00127ac4 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block_00127ac4 *data_;
    unsigned size() const { return size_; }
    Block_00127ac4 &front() { return data_[start_]; }
};
struct Deque_00127ac4;
extern "C" {
DequeIt_00127ac4 FUN_00129ed8(Deque_00127ac4 *d, unsigned pos);
void FUN_001295bc(Deque_00127ac4 *d, DequeIt_00127ac4 first, DequeIt_00127ac4 last);
void FUN_00128a38(Map_00127ac4 *m);
}
struct Deque_00127ac4 {
    Map_00127ac4 map_;
    unsigned start_;
    unsigned size_;
    DequeIt_00127ac4 begin() { return FUN_00129ed8(this, 0); }
    DequeIt_00127ac4 end() { return FUN_00129ed8(this, size_); }
};

extern "C" void FUN_00127ac4(Deque_00127ac4 *self)
{
    FUN_001295bc(self, self->begin(), self->end());
    self->size_ = 0;
    if (self->map_.size() > 1) {
        while (self->map_.size() > 2) {
            operator delete(self->map_.front());
            FUN_00128a38(&self->map_);
        }
        self->start_ = 21;
    } else {
        self->start_ = 0;
    }
}
