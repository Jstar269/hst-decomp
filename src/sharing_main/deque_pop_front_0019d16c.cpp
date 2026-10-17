/* HSTMATCH module=hstp_trans_main.prx start=0x0019d16c end=0x0019d1fc symbol=FUN_0019d16c lang=c++ */
/* Clone of src/eboot/deque_pop_front_0019095c.cpp (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque of 4-byte elements (128 per 512-byte block), pop_front(), sibling of deque_pop_front_0011c998.cpp
   and deque_push_back_001909ec.cpp: the last element is handled by the out-of-line clear 0x190cc8; otherwise
   advance start and free the front blocks (map pop_front 0x190fd0) while start >= 2 blocks. Names provisional. */
typedef void *Elem_0019d16c;
typedef Elem_0019d16c *Block_0019d16c;
struct Map_0019d16c {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block_0019d16c *data_;
    Block_0019d16c &front() { return data_[start_]; }
};
struct Deque_0019d16c {
    Map_0019d16c map_;
    unsigned start_;
    unsigned size_;
};
extern "C" {
void FUN_0019d4d8(Deque_0019d16c *d);
void FUN_0019d7e0(Map_0019d16c *m);
}
extern "C" void FUN_0019d16c(Deque_0019d16c *self)
{
    if (self->size_ == 1) {
        FUN_0019d4d8(self);
    } else {
        --self->size_;
        if (++self->start_ >= 256) {
            do {
                operator delete(self->map_.front());
                FUN_0019d7e0(&self->map_);
                self->start_ -= 128;
            } while (self->start_ >= 256);
        }
    }
}
