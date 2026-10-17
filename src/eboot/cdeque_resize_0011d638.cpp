/* HSTMATCH module=EBOOT.BIN start=0x0011d638 end=0x0011d7e4 symbol=FUN_0011d638 lang=c++ */
/* Clone of src/sharing_main/cdeque_resize_0012880c.cpp (hstclone.py tag u6fr2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idiom: the iterator constructor reads the container fields through a non-const Cdeque pointer, and Iter has a user-declared copy constructor so it is passed by invisible reference); names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: resize(n). Growing inserts n - size() default
   elements at end() (0x12c2b8), shrinking to zero clears (0x1289b8), otherwise erases [begin() + n, end())
   (0x12be9c). The iterators {ptr, beg, first, end} are built in the caller's frame and passed by reference.
   Names provisional. */
#pragma inline_depth(8)
typedef void *T_0011d638;

struct Cdeque_0011d638;
struct Iter_0011d638 {
    T_0011d638 *ptr;
    T_0011d638 *beg;
    T_0011d638 *first;
    T_0011d638 *end;
    Iter_0011d638(Cdeque_0011d638 *c, unsigned i);
    Iter_0011d638(const Iter_0011d638 &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    Iter_0011d638 &operator+=(int n)
    {
        int cap = end - beg;
        int i = n + (ptr - beg);
        if (i < 0)
            i += cap;
        else if (i >= cap)
            i -= cap;
        ptr = beg + i;
        return *this;
    }
    Iter_0011d638 operator+(int n) const
    {
        Iter_0011d638 t(*this);
        t += n;
        return t;
    }
};

extern "C" {
void FUN_0011d7e4(Cdeque_0011d638 *self);                                                      /* clear */
void FUN_001210e4(Cdeque_0011d638 *self, Iter_0011d638 pos, unsigned n, const T_0011d638 &x); /* insert(pos, n, x) */
Iter_0011d638 FUN_00120cc8(Cdeque_0011d638 *self, Iter_0011d638 first, Iter_0011d638 last);   /* erase */
}

struct Cdeque_0011d638 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    T_0011d638 *data_;
    Iter_0011d638 begin() { return Iter_0011d638(this, start_); }
    Iter_0011d638 end() { return Iter_0011d638(this, cap_ != 0 ? (start_ + size_) % cap_ : 0); }
};

inline Iter_0011d638::Iter_0011d638(Cdeque_0011d638 *c, unsigned i)
    : ptr(c->data_ + i), beg(c->data_), first(c->data_ + c->start_), end(c->data_ + c->cap_) {}

extern "C" void FUN_0011d638(Cdeque_0011d638 *self, unsigned n)
{
    if (self->size_ < n) {
        FUN_001210e4(self, self->end(), n - self->size_, T_0011d638());
    } else if (n < self->size_) {
        if (n != 0)
            FUN_00120cc8(self, self->begin() + n, self->end());
        else
            FUN_0011d7e4(self);
    }
}
