/* HSTMATCH module=EBOOT.BIN start=0x00102a88 end=0x00102c54 symbol=FUN_00102a88 lang=c++ */
/* Hand-written reconstruction from the disassembly; NEAR MISS (4 words short, see trailing comments); names and types await human review. */
extern "C" {
    extern int FUN_00014934(const char *, const char *);
    extern void FUN_001006b0(const void *, const char *);
    extern char DAT_002d8b50;
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
extern "C" void FUN_00107130(Vec<Rec *> *v, Rec **x, Tag f);
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
            FUN_00107130(this, (Rec **)&x, Tag());
        }
    }
};


extern "C" void FUN_00107130(Vec<Rec *> *v, Rec **x, Tag f);
extern "C" void FUN_00107270(Vec<Rec *> *v, It<Rec *> pos, Rec **x, Tag f);

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
    FUN_001006b0(&DAT_002d8b50, name);
    return 0;
}

extern "C" Rec *FUN_00102a88(Container *self, const char *name, int pos)
{
    Rec *n = new Rec;
    Rec *src = Find(self, name);
    *n = *src;
    if (pos >= 0) {
        FUN_00107270(&self->recs, It<Rec *>(self->recs.data_ + pos), &n, Tag());
    } else {
        self->recs.push_back(n);
    }
    return n;
}

// EBOOT NEAR MISS: 111/115 words, 41 differing words after address retargeting.
// The find loop, 44-byte record copy, and inline push_back path match. The remaining
// four-word shortfall is the insert-position iterator: EBOOT retail spills its value
// through sp+56/sp+52 using lwc1/swc1 before FUN_00107270; this candidate keeps it
// in a1. EBOOT calls were retargeted to FUN_001006b0, FUN_00107270, FUN_00107130 and
// the warning string at DAT_002d8b50.
// The Sharing twin pass had the same register-versus-stack difference. It ruled out
// It(T*) temporaries, named locals, begin()+n/operator+ and reference-returning +=,
// aggregate Pos, array-member structs, empty bases, const members, user operator=,
// inline insert wrappers with by-value/const& iterator params, and member insert.
// A user destructor or copy constructor passes the iterator by reference instead of
// by value; a ctor-less iterator breaks the find loop.
// near miss from lane lnm2 (unreviewed)
