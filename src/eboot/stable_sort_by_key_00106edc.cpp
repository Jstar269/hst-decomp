/* HSTMATCH module=EBOOT.BIN start=0x00106edc end=0x00106ff0 symbol=FUN_00106edc lang=c++ */
/* Hand-written reconstruction from the disassembly (EBOOT twin of src/sharing_main/stable_sort_by_key_0010cc9c.cpp, identical masked code: addresses substituted); exact match verified (the iterators are a one-pointer class taken by value, which gives retail's prologue: n computed from a0/a1 before the home copies, first in s0 and last in s1; plain pointer parameters swap s0/s1); names and types await human review. */
/* MSL-style stable sort of a range of object pointers by the float at +0x20, larger keys first: ranges of two are
   swapped in place, up to 20 elements go to the insertion sort FUN_001076c8, longer ranges get a temporary buffer
   (FUN_0010763c returns {pointer, count}; freed with operator delete[] FUN_000009e4) and the buffered merge sort
   FUN_00107750, which receives the buffer's begin/end iterators {pointer, &buffer}. Names provisional. */
struct Obj {
    char pad[0x20];
    float key;
};
struct Greater {
    bool operator()(Obj *a, Obj *b) const { return a->key > b->key; }
};
struct It {
    Obj **p;
    It() {}
    It(Obj **q) : p(q) {}
    Obj *&operator*() const { return *p; }
    It &operator--() { --p; return *this; }
};
inline int operator-(const It &a, const It &b) { return a.p - b.p; }

struct Pair {
    Obj **ptr;
    int count;
};
struct TempBuf;
struct BufIt {
    Obj **p;
    TempBuf *owner;
    BufIt(Obj **q, TempBuf *b) : p(q), owner(b) {}
    BufIt(const BufIt &o) : p(o.p), owner(o.owner) {}
};

extern "C" {
void FUN_0010763c(Pair *result, int requested);
void FUN_001076c8(It first, It last, Greater comp);
void FUN_00107750(It first, It last, BufIt buf_begin, BufIt buf_end, Greater comp);
void FUN_000009e4(void *p);
}

struct TempBuf {
    int len;
    int used;
    Obj **ptr;
    TempBuf(int n)
    {
        Pair pr;
        FUN_0010763c(&pr, n);
        len = pr.count;
        used = 0;
        ptr = pr.ptr;
    }
    ~TempBuf() { FUN_000009e4(ptr); }
    BufIt begin() { return BufIt(ptr, this); }
    BufIt end() { return BufIt(ptr + len, this); }
};

extern "C" void FUN_00106edc(It first, It last, Greater comp)
{
    int n = last - first;
    if (n <= 1) {
        return;
    }
    if (n == 2) {
        Obj *b = *--last;
        Obj *a = *first;
        if (comp(b, a)) {
            *first = b;
            *last = a;
        }
        return;
    }
    if (n <= 20) {
        FUN_001076c8(first, last, comp);
        return;
    }
    TempBuf buf(n);
    FUN_00107750(first, last, buf.begin(), buf.end(), comp);
}
