/* HSTMATCH module=hstp_trans_main.prx start=0x0019d3b0 end=0x0019d4d8 symbol=__dt__14Owner_0019d3b0Fv lang=c++ */
/* Clone of src/eboot/dtor_ptr_cdeque_0011d190.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
/* Destructor of an owner of an MSL-style circular deque of pointers: when not empty, delete every element
   from begin() to end() (the iterator wraps at the end of the buffer), then the deque's own destructor
   clears it (0x11d7e4) and frees the buffer. The retail chain of five `this` checks comes from nested
   member layers with implicit destructors (W1..W4 here stand in for the library's base/member layers);
   the element type's empty destructor gives the null check before each delete; end() computes its index
   into a local first. Names provisional. */
struct T_0019d3b0 {
    int x;
    ~T_0019d3b0() {}
};
typedef T_0019d3b0 *Elem_0019d3b0;
struct Iter_0019d3b0 {
    Elem_0019d3b0 *ptr;
    Elem_0019d3b0 *beg;
    Elem_0019d3b0 *end;
    Iter_0019d3b0(Elem_0019d3b0 *p, Elem_0019d3b0 *b, Elem_0019d3b0 *e) : ptr(p), beg(b), end(e) {}
    Iter_0019d3b0 &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    Elem_0019d3b0 &operator*() const { return *ptr; }
};
inline bool operator!=(const Iter_0019d3b0 &x, const Iter_0019d3b0 &y) { return x.ptr != y.ptr; }
struct Cdeque_0019d3b0;
extern "C" void FUN_0019d760(Cdeque_0019d3b0 *self); /* clear() */
struct Cdeque_0019d3b0 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_0019d3b0 *data_;
    bool empty() const { return size_ == 0; }
    Iter_0019d3b0 begin() { return Iter_0019d3b0(data_ + start_, data_, data_ + cap_); }
    Iter_0019d3b0 end()
    {
        unsigned i = cap_ ? (start_ + size_) % cap_ : 0;
        return Iter_0019d3b0(data_ + i, data_, data_ + cap_);
    }
    ~Cdeque_0019d3b0()
    {
        if (data_) {
            FUN_0019d760(this);
            operator delete(data_);
        }
    }
};
struct W4_0019d3b0 { Cdeque_0019d3b0 c; };
struct W3_0019d3b0 { W4_0019d3b0 w; };
struct W2_0019d3b0 { W3_0019d3b0 w; };
struct W1_0019d3b0 { W2_0019d3b0 w; };
struct Owner_0019d3b0 {
    W1_0019d3b0 q;
    ~Owner_0019d3b0();
};
Owner_0019d3b0::~Owner_0019d3b0()
{
    Cdeque_0019d3b0 &c = q.w.w.w.c;
    if (!c.empty()) {
        Iter_0019d3b0 e = c.end();
        for (Iter_0019d3b0 i = c.begin(); i != e; ++i)
            delete *i;
    }
}
