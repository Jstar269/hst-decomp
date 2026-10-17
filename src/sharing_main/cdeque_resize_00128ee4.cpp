/* HSTMATCH module=hstp_trans_main.prx start=0x00128ee4 end=0x00129090 symbol=FUN_00128ee4 lang=c++ */
/* Clone of src/eboot/cdeque_resize_0011d638.cpp (hstclone.py tag s10170049c1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idiom: the iterator constructor reads the container fields through a non-const Cdeque pointer, and Iter has a user-declared copy constructor so it is passed by invisible reference); names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: resize(n). Growing inserts n - size() default
   elements at end() (0x12c2b8), shrinking to zero clears (0x1289b8), otherwise erases [begin() + n, end())
   (0x12be9c). The iterators {ptr, beg, first, end} are built in the caller's frame and passed by reference.
   Names provisional. */
#pragma inline_depth(8)
typedef void *T_00128ee4;

struct Cdeque_00128ee4;
struct Iter_00128ee4 {
    T_00128ee4 *ptr;
    T_00128ee4 *beg;
    T_00128ee4 *first;
    T_00128ee4 *end;
    Iter_00128ee4(Cdeque_00128ee4 *c, unsigned i);
    Iter_00128ee4(const Iter_00128ee4 &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    Iter_00128ee4 &operator+=(int n)
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
    Iter_00128ee4 operator+(int n) const
    {
        Iter_00128ee4 t(*this);
        t += n;
        return t;
    }
};

extern "C" {
void FUN_00129090(Cdeque_00128ee4 *self);                                                      /* clear */
void FUN_0012d098(Cdeque_00128ee4 *self, Iter_00128ee4 pos, unsigned n, const T_00128ee4 &x); /* insert(pos, n, x) */
Iter_00128ee4 FUN_0012cc7c(Cdeque_00128ee4 *self, Iter_00128ee4 first, Iter_00128ee4 last);   /* erase */
}

struct Cdeque_00128ee4 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    T_00128ee4 *data_;
    Iter_00128ee4 begin() { return Iter_00128ee4(this, start_); }
    Iter_00128ee4 end() { return Iter_00128ee4(this, cap_ != 0 ? (start_ + size_) % cap_ : 0); }
};

inline Iter_00128ee4::Iter_00128ee4(Cdeque_00128ee4 *c, unsigned i)
    : ptr(c->data_ + i), beg(c->data_), first(c->data_ + c->start_), end(c->data_ + c->cap_) {}

extern "C" void FUN_00128ee4(Cdeque_00128ee4 *self, unsigned n)
{
    if (self->size_ < n) {
        FUN_0012d098(self, self->end(), n - self->size_, T_00128ee4());
    } else if (n < self->size_) {
        if (n != 0)
            FUN_0012cc7c(self, self->begin() + n, self->end());
        else
            FUN_00129090(self);
    }
}
