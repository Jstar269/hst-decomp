/* HSTMATCH module=EBOOT.BIN start=0x0011debc end=0x0011df3c symbol=FUN_0011debc lang=c++ */
/* Clone of src/eboot/cdeque_clear_0011d7e4.cpp (hstclone.py tag c33): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque {cap, size, start, data} of pointers: clear(). When a buffer exists, destroy the
   wrapped part [data, data + (start + size - cap)) and then [data + start, data + min(start + size, cap)); the
   per-element destroy is a trivial pseudo-destructor, so only the empty pointer walks remain. The first range
   must re-read the member (with the cached local, MWCC folds `data == data + n` into `n == 0`). Names
   provisional. */
struct T_0011debc;
typedef T_0011debc *Elem_0011debc;
template <class T> inline void Destroy_0011debc(T *first, T *last)
{
    for (; first != last; ++first)
        first->~T();
}
struct Cdeque_0011debc {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_0011debc *data_;
};
extern "C" void FUN_0011debc(Cdeque_0011debc *self)
{
    Elem_0011debc *data = self->data_;
    if (data) {
        unsigned start = self->start_;
        unsigned e = start + self->size_;
        unsigned cap = self->cap_;
        if (cap < e) {
            Destroy_0011debc(self->data_, self->data_ + (e - cap));
            e = cap;
        }
        Destroy_0011debc(data + start, data + e);
        self->size_ = 0;
        self->start_ = 0;
    }
}
