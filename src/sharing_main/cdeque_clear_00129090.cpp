/* HSTMATCH module=hstp_trans_main.prx start=0x00129090 end=0x00129110 symbol=FUN_00129090 lang=c++ */
/* Clone of src/eboot/cdeque_clear_0011d7e4.cpp (hstclone.py tag c34): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque {cap, size, start, data} of pointers: clear(). When a buffer exists, destroy the
   wrapped part [data, data + (start + size - cap)) and then [data + start, data + min(start + size, cap)); the
   per-element destroy is a trivial pseudo-destructor, so only the empty pointer walks remain. The first range
   must re-read the member (with the cached local, MWCC folds `data == data + n` into `n == 0`). Names
   provisional. */
struct T_00129090;
typedef T_00129090 *Elem_00129090;
template <class T> inline void Destroy_00129090(T *first, T *last)
{
    for (; first != last; ++first)
        first->~T();
}
struct Cdeque_00129090 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_00129090 *data_;
};
extern "C" void FUN_00129090(Cdeque_00129090 *self)
{
    Elem_00129090 *data = self->data_;
    if (data) {
        unsigned start = self->start_;
        unsigned e = start + self->size_;
        unsigned cap = self->cap_;
        if (cap < e) {
            Destroy_00129090(self->data_, self->data_ + (e - cap));
            e = cap;
        }
        Destroy_00129090(data + start, data + e);
        self->size_ = 0;
        self->start_ = 0;
    }
}
