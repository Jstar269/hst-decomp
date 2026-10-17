/* HSTMATCH module=hstp_trans_main.prx start=0x001285cc end=0x001286f4 symbol=__dt__14Owner_001285ccFv lang=c++ */
/* Clone of src/eboot/dtor_ptr_cdeque_0011d190.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
/* Destructor of an owner of an MSL-style circular deque of pointers: when not empty, delete every element
   from begin() to end() (the iterator wraps at the end of the buffer), then the deque's own destructor
   clears it (0x11d7e4) and frees the buffer. The retail chain of five `this` checks comes from nested
   member layers with implicit destructors (W1..W4 here stand in for the library's base/member layers);
   the element type's empty destructor gives the null check before each delete; end() computes its index
   into a local first. Names provisional. */
struct T_001285cc {
    int x;
    ~T_001285cc() {}
};
typedef T_001285cc *Elem_001285cc;
struct Iter_001285cc {
    Elem_001285cc *ptr;
    Elem_001285cc *beg;
    Elem_001285cc *end;
    Iter_001285cc(Elem_001285cc *p, Elem_001285cc *b, Elem_001285cc *e) : ptr(p), beg(b), end(e) {}
    Iter_001285cc &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    Elem_001285cc &operator*() const { return *ptr; }
};
inline bool operator!=(const Iter_001285cc &x, const Iter_001285cc &y) { return x.ptr != y.ptr; }
struct Cdeque_001285cc;
extern "C" void FUN_00129090(Cdeque_001285cc *self); /* clear() */
struct Cdeque_001285cc {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_001285cc *data_;
    bool empty() const { return size_ == 0; }
    Iter_001285cc begin() { return Iter_001285cc(data_ + start_, data_, data_ + cap_); }
    Iter_001285cc end()
    {
        unsigned i = cap_ ? (start_ + size_) % cap_ : 0;
        return Iter_001285cc(data_ + i, data_, data_ + cap_);
    }
    ~Cdeque_001285cc()
    {
        if (data_) {
            FUN_00129090(this);
            operator delete(data_);
        }
    }
};
struct W4_001285cc { Cdeque_001285cc c; };
struct W3_001285cc { W4_001285cc w; };
struct W2_001285cc { W3_001285cc w; };
struct W1_001285cc { W2_001285cc w; };
struct Owner_001285cc {
    W1_001285cc q;
    ~Owner_001285cc();
};
Owner_001285cc::~Owner_001285cc()
{
    Cdeque_001285cc &c = q.w.w.w.c;
    if (!c.empty()) {
        Iter_001285cc e = c.end();
        for (Iter_001285cc i = c.begin(); i != e; ++i)
            delete *i;
    }
}
