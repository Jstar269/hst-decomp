/* HSTMATCH module=hstp_trans_main.prx start=0x0012880c end=0x001289b8 symbol=FUN_0012880c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idiom: the iterator constructor reads the container fields through a non-const Cdeque pointer, and Iter has a user-declared copy constructor so it is passed by invisible reference); names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: resize(n). Growing inserts n - size() default
   elements at end() (0x12c2b8), shrinking to zero clears (0x1289b8), otherwise erases [begin() + n, end())
   (0x12be9c). The iterators {ptr, beg, first, end} are built in the caller's frame and passed by reference.
   Names provisional. */
#pragma inline_depth(8)
typedef void *T_0012880c;

struct Cdeque_0012880c;
struct Iter_0012880c {
    T_0012880c *ptr;
    T_0012880c *beg;
    T_0012880c *first;
    T_0012880c *end;
    Iter_0012880c(Cdeque_0012880c *c, unsigned i);
    Iter_0012880c(const Iter_0012880c &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    Iter_0012880c &operator+=(int n)
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
    Iter_0012880c operator+(int n) const
    {
        Iter_0012880c t(*this);
        t += n;
        return t;
    }
};

extern "C" {
void FUN_001289b8(Cdeque_0012880c *self);                                                      /* clear */
void FUN_0012c2b8(Cdeque_0012880c *self, Iter_0012880c pos, unsigned n, const T_0012880c &x); /* insert(pos, n, x) */
Iter_0012880c FUN_0012be9c(Cdeque_0012880c *self, Iter_0012880c first, Iter_0012880c last);   /* erase */
}

struct Cdeque_0012880c {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    T_0012880c *data_;
    Iter_0012880c begin() { return Iter_0012880c(this, start_); }
    Iter_0012880c end() { return Iter_0012880c(this, cap_ != 0 ? (start_ + size_) % cap_ : 0); }
};

inline Iter_0012880c::Iter_0012880c(Cdeque_0012880c *c, unsigned i)
    : ptr(c->data_ + i), beg(c->data_), first(c->data_ + c->start_), end(c->data_ + c->cap_) {}

extern "C" void FUN_0012880c(Cdeque_0012880c *self, unsigned n)
{
    if (self->size_ < n) {
        FUN_0012c2b8(self, self->end(), n - self->size_, T_0012880c());
    } else if (n < self->size_) {
        if (n != 0)
            FUN_0012be9c(self, self->begin() + n, self->end());
        else
            FUN_001289b8(self);
    }
}
