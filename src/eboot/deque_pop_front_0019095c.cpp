/* HSTMATCH module=EBOOT.BIN start=0x0019095c end=0x001909ec symbol=FUN_0019095c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque of 4-byte elements (128 per 512-byte block), pop_front(), sibling of deque_pop_front_0011c998.cpp
   and deque_push_back_001909ec.cpp: the last element is handled by the out-of-line clear 0x190cc8; otherwise
   advance start and free the front blocks (map pop_front 0x190fd0) while start >= 2 blocks. Names provisional. */
typedef void *Elem_0019095c;
typedef Elem_0019095c *Block_0019095c;
struct Map_0019095c {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block_0019095c *data_;
    Block_0019095c &front() { return data_[start_]; }
};
struct Deque_0019095c {
    Map_0019095c map_;
    unsigned start_;
    unsigned size_;
};
extern "C" {
void FUN_00190cc8(Deque_0019095c *d);
void FUN_00190fd0(Map_0019095c *m);
}
extern "C" void FUN_0019095c(Deque_0019095c *self)
{
    if (self->size_ == 1) {
        FUN_00190cc8(self);
    } else {
        --self->size_;
        if (++self->start_ >= 256) {
            do {
                operator delete(self->map_.front());
                FUN_00190fd0(&self->map_);
                self->start_ -= 128;
            } while (self->start_ >= 256);
        }
    }
}
