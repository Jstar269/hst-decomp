/* HSTMATCH module=hstp_trans_main.prx start=0x0029aacc end=0x0029abd0 symbol=FUN_0029aacc lang=c++ */
/* Clone of src/eboot/inplace_merge_00289330.cpp (hstclone.py tag s10171846g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction of std::inplace_merge with _Temporary_buffer for 16-byte elements; exact match verified; names and types await human review. */

struct Elem { int d[4]; };
struct Iter { Elem *p; };
struct TempBufPair { Elem *buffer; int len; };
struct TempBuf;
struct TempBufIter { Elem *p; TempBuf *buf; };

extern "C" {
void FUN_0029ae08(TempBufPair *, int);
void FUN_000009e4(void *);
void FUN_0029ae94(void *ret, Iter first, Iter middle, Iter last, int len1, int len2, TempBufIter *b1, TempBufIter *b2);
}

struct TempBuf {
    int len; int count; Elem *buffer;
};

struct Compare { };

template <class T> static inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }

extern "C" void FUN_0029aacc(Iter first, Iter middle, Iter last, Compare comp) {
    int len1;
    int len2;
    TempBuf buf;
    Iter ret;
    TempBufIter b1;
    TempBufIter b2;
    TempBufPair pair;

    (void)&comp;

    Iter f = *(volatile Iter *)&first;
    len1 = (int)(middle.p - f.p);

    Iter m = *(volatile Iter *)&middle;
    len2 = (int)(last.p - m.p);

    FUN_0029ae08(&pair, Min(len1, len2));

    buf.len = pair.len;
    buf.buffer = pair.buffer;

    b2.p = pair.buffer + pair.len;
    b1.p = pair.buffer;
    b2.buf = &buf;
    b1.buf = &buf;

    buf.count = 0;
    FUN_0029ae94(&ret, first, middle, last, len1, len2, &b1, &b2);

    FUN_000009e4(buf.buffer);
}
