/* HSTMATCH module=hstp_trans_main.prx start=0x00128364 end=0x0012848c symbol=__dt__14Owner_00128364Fv lang=c++ */
/* Clone of src/eboot/dtor_ptr_cdeque_0011d190.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
/* Destructor of an owner of an MSL-style circular deque of pointers: when not empty, delete every element
   from begin() to end() (the iterator wraps at the end of the buffer), then the deque's own destructor
   clears it (0x11d7e4) and frees the buffer. The retail chain of five `this` checks comes from nested
   member layers with implicit destructors (W1..W4 here stand in for the library's base/member layers);
   the element type's empty destructor gives the null check before each delete; end() computes its index
   into a local first. Names provisional. */
struct T_00128364 {
    int x;
    ~T_00128364() {}
};
typedef T_00128364 *Elem_00128364;
struct Iter_00128364 {
    Elem_00128364 *ptr;
    Elem_00128364 *beg;
    Elem_00128364 *end;
    Iter_00128364(Elem_00128364 *p, Elem_00128364 *b, Elem_00128364 *e) : ptr(p), beg(b), end(e) {}
    Iter_00128364 &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    Elem_00128364 &operator*() const { return *ptr; }
};
inline bool operator!=(const Iter_00128364 &x, const Iter_00128364 &y) { return x.ptr != y.ptr; }
struct Cdeque_00128364;
extern "C" void FUN_001289b8(Cdeque_00128364 *self); /* clear() */
struct Cdeque_00128364 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_00128364 *data_;
    bool empty() const { return size_ == 0; }
    Iter_00128364 begin() { return Iter_00128364(data_ + start_, data_, data_ + cap_); }
    Iter_00128364 end()
    {
        unsigned i = cap_ ? (start_ + size_) % cap_ : 0;
        return Iter_00128364(data_ + i, data_, data_ + cap_);
    }
    ~Cdeque_00128364()
    {
        if (data_) {
            FUN_001289b8(this);
            operator delete(data_);
        }
    }
};
struct W4_00128364 { Cdeque_00128364 c; };
struct W3_00128364 { W4_00128364 w; };
struct W2_00128364 { W3_00128364 w; };
struct W1_00128364 { W2_00128364 w; };
struct Owner_00128364 {
    W1_00128364 q;
    ~Owner_00128364();
};
Owner_00128364::~Owner_00128364()
{
    Cdeque_00128364 &c = q.w.w.w.c;
    if (!c.empty()) {
        Iter_00128364 e = c.end();
        for (Iter_00128364 i = c.begin(); i != e; ++i)
            delete *i;
    }
}
