/* HSTMATCH module=hstp_trans_main.prx start=0x00127e74 end=0x00127f1c symbol=FUN_00127e74 lang=c++ */
/* Clone of src/eboot/deque_clear_0011c8f0.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque<12-byte T> (42 per block) clear(): destroy [begin(), end()) (0x11e3e8 over iterators made by
   0x11ed04), size = 0, then free all but two blocks and recentre (21), or reset start when at most one block
   remains. Same types as deque_pop_front_0011c998.cpp (its size == 1 path). Names provisional. */
struct Elem_00127e74 { int a, b, c; };
typedef Elem_00127e74 *Block_00127e74;

struct MapIt_00127e74 {
    Block_00127e74 *p_;
    Block_00127e74 *first_;
    Block_00127e74 *beg_;
    Block_00127e74 *last_;
    MapIt_00127e74(const MapIt_00127e74 &o) : p_(o.p_), first_(o.first_), beg_(o.beg_), last_(o.last_) {}
};
struct DequeIt_00127e74 {
    MapIt_00127e74 i_;
    Elem_00127e74 *cur_;
    Elem_00127e74 *end_;
};

struct Map_00127e74 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block_00127e74 *data_;
    unsigned size() const { return size_; }
    Block_00127e74 &front() { return data_[start_]; }
};
struct Deque_00127e74;
extern "C" {
DequeIt_00127e74 FUN_0012a530(Deque_00127e74 *d, unsigned pos);
void FUN_00129790(Deque_00127e74 *d, DequeIt_00127e74 first, DequeIt_00127e74 last);
void FUN_00129110(Map_00127e74 *m);
}
struct Deque_00127e74 {
    Map_00127e74 map_;
    unsigned start_;
    unsigned size_;
    DequeIt_00127e74 begin() { return FUN_0012a530(this, 0); }
    DequeIt_00127e74 end() { return FUN_0012a530(this, size_); }
};

extern "C" void FUN_00127e74(Deque_00127e74 *self)
{
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
}
