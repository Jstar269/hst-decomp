/* HSTMATCH module=EBOOT.BIN start=0x0025a4b8 end=0x0025a548 symbol=FUN_0025a4b8 lang=c++ */
/* Clone of src/eboot/deque_pop_front_0019095c.cpp (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque of 4-byte elements (128 per 512-byte block), pop_front(), sibling of deque_pop_front_0011c998.cpp
   and deque_push_back_001909ec.cpp: the last element is handled by the out-of-line clear 0x190cc8; otherwise
   advance start and free the front blocks (map pop_front 0x190fd0) while start >= 2 blocks. Names provisional. */
typedef void *Elem_0025a4b8;
typedef Elem_0025a4b8 *Block_0025a4b8;
struct Map_0025a4b8 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block_0025a4b8 *data_;
    Block_0025a4b8 &front() { return data_[start_]; }
};
struct Deque_0025a4b8 {
    Map_0025a4b8 map_;
    unsigned start_;
    unsigned size_;
};
extern "C" {
void FUN_0025a9e8(Deque_0025a4b8 *d);
void FUN_0025ab10(Map_0025a4b8 *m);
}
extern "C" void FUN_0025a4b8(Deque_0025a4b8 *self)
{
    if (self->size_ == 1) {
        FUN_0025a9e8(self);
    } else {
        --self->size_;
        if (++self->start_ >= 256) {
            do {
                operator delete(self->map_.front());
                FUN_0025ab10(&self->map_);
                self->start_ -= 128;
            } while (self->start_ >= 256);
        }
    }
}
