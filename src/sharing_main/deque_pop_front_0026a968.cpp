/* HSTMATCH module=hstp_trans_main.prx start=0x0026a968 end=0x0026a9f8 symbol=FUN_0026a968 lang=c++ */
/* Clone of src/eboot/deque_pop_front_0019095c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque of 4-byte elements (128 per 512-byte block), pop_front(), sibling of deque_pop_front_0011c998.cpp
   and deque_push_back_001909ec.cpp: the last element is handled by the out-of-line clear 0x190cc8; otherwise
   advance start and free the front blocks (map pop_front 0x190fd0) while start >= 2 blocks. Names provisional. */
typedef void *Elem_0026a968;
typedef Elem_0026a968 *Block_0026a968;
struct Map_0026a968 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block_0026a968 *data_;
    Block_0026a968 &front() { return data_[start_]; }
};
struct Deque_0026a968 {
    Map_0026a968 map_;
    unsigned start_;
    unsigned size_;
};
extern "C" {
void FUN_0026ae98(Deque_0026a968 *d);
void FUN_0026afc0(Map_0026a968 *m);
}
extern "C" void FUN_0026a968(Deque_0026a968 *self)
{
    if (self->size_ == 1) {
        FUN_0026ae98(self);
    } else {
        --self->size_;
        if (++self->start_ >= 256) {
            do {
                operator delete(self->map_.front());
                FUN_0026afc0(&self->map_);
                self->start_ -= 128;
            } while (self->start_ >= 256);
        }
    }
}
