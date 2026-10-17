/* HSTMATCH module=hstp_trans_main.prx start=0x0026ad70 end=0x0026ae98 symbol=__dt__14Owner_0026ad70Fv lang=c++ */
/* Clone of src/eboot/dtor_ptr_cdeque_0011d190.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
/* Destructor of an owner of an MSL-style circular deque of pointers: when not empty, delete every element
   from begin() to end() (the iterator wraps at the end of the buffer), then the deque's own destructor
   clears it (0x11d7e4) and frees the buffer. The retail chain of five `this` checks comes from nested
   member layers with implicit destructors (W1..W4 here stand in for the library's base/member layers);
   the element type's empty destructor gives the null check before each delete; end() computes its index
   into a local first. Names provisional. */
struct T_0026ad70 {
    int x;
    ~T_0026ad70() {}
};
typedef T_0026ad70 *Elem_0026ad70;
struct Iter_0026ad70 {
    Elem_0026ad70 *ptr;
    Elem_0026ad70 *beg;
    Elem_0026ad70 *end;
    Iter_0026ad70(Elem_0026ad70 *p, Elem_0026ad70 *b, Elem_0026ad70 *e) : ptr(p), beg(b), end(e) {}
    Iter_0026ad70 &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    Elem_0026ad70 &operator*() const { return *ptr; }
};
inline bool operator!=(const Iter_0026ad70 &x, const Iter_0026ad70 &y) { return x.ptr != y.ptr; }
struct Cdeque_0026ad70;
extern "C" void FUN_0026af40(Cdeque_0026ad70 *self); /* clear() */
struct Cdeque_0026ad70 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_0026ad70 *data_;
    bool empty() const { return size_ == 0; }
    Iter_0026ad70 begin() { return Iter_0026ad70(data_ + start_, data_, data_ + cap_); }
    Iter_0026ad70 end()
    {
        unsigned i = cap_ ? (start_ + size_) % cap_ : 0;
        return Iter_0026ad70(data_ + i, data_, data_ + cap_);
    }
    ~Cdeque_0026ad70()
    {
        if (data_) {
            FUN_0026af40(this);
            operator delete(data_);
        }
    }
};
struct W4_0026ad70 { Cdeque_0026ad70 c; };
struct W3_0026ad70 { W4_0026ad70 w; };
struct W2_0026ad70 { W3_0026ad70 w; };
struct W1_0026ad70 { W2_0026ad70 w; };
struct Owner_0026ad70 {
    W1_0026ad70 q;
    ~Owner_0026ad70();
};
Owner_0026ad70::~Owner_0026ad70()
{
    Cdeque_0026ad70 &c = q.w.w.w.c;
    if (!c.empty()) {
        Iter_0026ad70 e = c.end();
        for (Iter_0026ad70 i = c.begin(); i != e; ++i)
            delete *i;
    }
}
