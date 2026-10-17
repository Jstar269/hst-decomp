/* HSTMATCH module=EBOOT.BIN start=0x0011d190 end=0x0011d2b8 symbol=__dt__14Owner_0011d190Fv lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
/* Destructor of an owner of an MSL-style circular deque of pointers: when not empty, delete every element
   from begin() to end() (the iterator wraps at the end of the buffer), then the deque's own destructor
   clears it (0x11d7e4) and frees the buffer. The retail chain of five `this` checks comes from nested
   member layers with implicit destructors (W1..W4 here stand in for the library's base/member layers);
   the element type's empty destructor gives the null check before each delete; end() computes its index
   into a local first. Names provisional. */
struct T_0011d190 {
    int x;
    ~T_0011d190() {}
};
typedef T_0011d190 *Elem_0011d190;
struct Iter_0011d190 {
    Elem_0011d190 *ptr;
    Elem_0011d190 *beg;
    Elem_0011d190 *end;
    Iter_0011d190(Elem_0011d190 *p, Elem_0011d190 *b, Elem_0011d190 *e) : ptr(p), beg(b), end(e) {}
    Iter_0011d190 &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    Elem_0011d190 &operator*() const { return *ptr; }
};
inline bool operator!=(const Iter_0011d190 &x, const Iter_0011d190 &y) { return x.ptr != y.ptr; }
struct Cdeque_0011d190;
extern "C" void FUN_0011d7e4(Cdeque_0011d190 *self); /* clear() */
struct Cdeque_0011d190 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_0011d190 *data_;
    bool empty() const { return size_ == 0; }
    Iter_0011d190 begin() { return Iter_0011d190(data_ + start_, data_, data_ + cap_); }
    Iter_0011d190 end()
    {
        unsigned i = cap_ ? (start_ + size_) % cap_ : 0;
        return Iter_0011d190(data_ + i, data_, data_ + cap_);
    }
    ~Cdeque_0011d190()
    {
        if (data_) {
            FUN_0011d7e4(this);
            operator delete(data_);
        }
    }
};
struct W4_0011d190 { Cdeque_0011d190 c; };
struct W3_0011d190 { W4_0011d190 w; };
struct W2_0011d190 { W3_0011d190 w; };
struct W1_0011d190 { W2_0011d190 w; };
struct Owner_0011d190 {
    W1_0011d190 q;
    ~Owner_0011d190();
};
Owner_0011d190::~Owner_0011d190()
{
    Cdeque_0011d190 &c = q.w.w.w.c;
    if (!c.empty()) {
        Iter_0011d190 e = c.end();
        for (Iter_0011d190 i = c.begin(); i != e; ++i)
            delete *i;
    }
}
