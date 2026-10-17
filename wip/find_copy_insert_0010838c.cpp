/* HSTMATCH module=hstp_trans_main.prx start=0x0010838c end=0x00108558 symbol=FUN_0010838c lang=c++ */
/* Hand-written reconstruction from the disassembly; NEAR MISS (4 words short, see trailing comments); names and types await human review. */
extern "C" {
    extern int FUN_00014934(const char *, const char *);
    extern void FUN_0010532c(const void *, const char *);
    extern char DAT_0037f91c;
}

struct Tag {};

struct Rec {
    int w0;
    short s4, s6, s8, s10, s12;
    unsigned short s14;
    const char *name;
    int w20, w24, w28, w32, w36, w40;
};

template <class T> struct It {
    T *p_;
    It(T *p) : p_(p) {}
    T &operator*() const { return *p_; }
    It &operator++() { ++p_; return *this; }
};
template <class T> inline bool operator==(const It<T> &a, const It<T> &b) { return a.p_ == b.p_; }
template <class T> inline bool operator!=(const It<T> &a, const It<T> &b) { return !(a == b); }

struct Rec;
template <class T> struct Vec;
extern "C" void FUN_0010cef0(Vec<Rec *> *v, Rec **x, Tag f);
template <class T> struct Vec {
    T *data_;
    unsigned size_;
    unsigned cap_;
    It<T> begin() const { return It<T>(data_); }
    It<T> end() { return It<T>(data_ + size_); }
    T &at(unsigned i) { return data_[i]; }
    T &back() { return at(size_ - 1); }
    void push_back(const T &x)
    {
        if (size_ < cap_) {
            ++size_;
            back() = x;
        } else {
            FUN_0010cef0(this, (Rec **)&x, Tag());
        }
    }
};


extern "C" void FUN_0010cef0(Vec<Rec *> *v, Rec **x, Tag f);
extern "C" void FUN_0010d030(Vec<Rec *> *v, It<Rec *> pos, Rec **x, Tag f);

struct Container {
    char pad[0x10];
    Vec<Rec *> recs;
};

static inline Rec *Find(Container *self, const char *name)
{
    for (It<Rec *> it = self->recs.begin(); it != self->recs.end(); ++it) {
        Rec *r = *it;
        if (FUN_00014934(r->name, name) == 0) return r;
    }
    FUN_0010532c(&DAT_0037f91c, name);
    return 0;
}

extern "C" Rec *FUN_0010838c(Container *self, const char *name, int pos)
{
    Rec *n = new Rec;
    Rec *src = Find(self, name);
    *n = *src;
    if (pos >= 0) {
        FUN_0010d030(&self->recs, It<Rec *>(self->recs.data_ + pos), &n, Tag());
    } else {
        self->recs.push_back(n);
    }
    return n;
}

// NEAR MISS: 111/115 words. Everything matches (find loop with !(a==b) iterator, 44-byte record copy as `*n = *src`, inline push_back/back() idiom,
// Tag() argument slots) except the insert-position iterator: retail builds it in a stack slot (`sw v1,56(sp); lwc1 $f0,56(sp); swc1 $f0,52(sp);
// lw a1,52(sp)`, then jal 0x10d030 with the empty tag in a3), ours keeps it in a1 (`addu a1,v1,a1`), 4 words fewer.
// Ruled out (all stay in registers): It(T*) temporary, named local, begin()+n via operator+ (return It(p+n), It t(*this), two-level reference-returning +=),
// aggregate Pos without ctors, struct with array member, empty base, const member, user operator=, inline insert wrapper with by-value or const& It param
// (also with a named local argument), member-function insert (mangled name). A user ~It() keeps the temp in memory but passes it by reference
// (addiu a1,sp,52); a user copy ctor also passes by reference. A ctor-less It breaks the loop (iterators spill).
// Retail has the same temp+copy for `vec.begin()` passed with a tag at 0xc4190 (also unmatched).
