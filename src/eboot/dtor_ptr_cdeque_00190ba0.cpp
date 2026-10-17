/* HSTMATCH module=EBOOT.BIN start=0x00190ba0 end=0x00190cc8 symbol=__dt__14Owner_00190ba0Fv lang=c++ */
/* Clone of src/eboot/dtor_ptr_cdeque_0011d190.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
/* Destructor of an owner of an MSL-style circular deque of pointers: when not empty, delete every element
   from begin() to end() (the iterator wraps at the end of the buffer), then the deque's own destructor
   clears it (0x11d7e4) and frees the buffer. The retail chain of five `this` checks comes from nested
   member layers with implicit destructors (W1..W4 here stand in for the library's base/member layers);
   the element type's empty destructor gives the null check before each delete; end() computes its index
   into a local first. Names provisional. */
struct T_00190ba0 {
    int x;
    ~T_00190ba0() {}
};
typedef T_00190ba0 *Elem_00190ba0;
struct Iter_00190ba0 {
    Elem_00190ba0 *ptr;
    Elem_00190ba0 *beg;
    Elem_00190ba0 *end;
    Iter_00190ba0(Elem_00190ba0 *p, Elem_00190ba0 *b, Elem_00190ba0 *e) : ptr(p), beg(b), end(e) {}
    Iter_00190ba0 &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    Elem_00190ba0 &operator*() const { return *ptr; }
};
inline bool operator!=(const Iter_00190ba0 &x, const Iter_00190ba0 &y) { return x.ptr != y.ptr; }
struct Cdeque_00190ba0;
extern "C" void FUN_00190f50(Cdeque_00190ba0 *self); /* clear() */
struct Cdeque_00190ba0 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_00190ba0 *data_;
    bool empty() const { return size_ == 0; }
    Iter_00190ba0 begin() { return Iter_00190ba0(data_ + start_, data_, data_ + cap_); }
    Iter_00190ba0 end()
    {
        unsigned i = cap_ ? (start_ + size_) % cap_ : 0;
        return Iter_00190ba0(data_ + i, data_, data_ + cap_);
    }
    ~Cdeque_00190ba0()
    {
        if (data_) {
            FUN_00190f50(this);
            operator delete(data_);
        }
    }
};
struct W4_00190ba0 { Cdeque_00190ba0 c; };
struct W3_00190ba0 { W4_00190ba0 w; };
struct W2_00190ba0 { W3_00190ba0 w; };
struct W1_00190ba0 { W2_00190ba0 w; };
struct Owner_00190ba0 {
    W1_00190ba0 q;
    ~Owner_00190ba0();
};
Owner_00190ba0::~Owner_00190ba0()
{
    Cdeque_00190ba0 &c = q.w.w.w.c;
    if (!c.empty()) {
        Iter_00190ba0 e = c.end();
        for (Iter_00190ba0 i = c.begin(); i != e; ++i)
            delete *i;
    }
}
