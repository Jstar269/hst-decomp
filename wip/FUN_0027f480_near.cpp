/* HSTMATCH module=EBOOT.BIN start=0x0027f480 end=0x0027f814 symbol=FUN_0027f480 lang=c++ */
/* Vec<Elem40> fill-append. Real Elem40 + count-capacity Vec, the container shape already exact in
   vec_reserve_000b6390.cpp. The 5-word relocation guard is an object whose ctor takes &v->capacity,
   so the temporary buffer and the guard are ONE object (retail: sp+76 data, +80 size, +84 cap,
   +88 &owner->cap, +92 remaining). Body decoded from try/lane-work/7f480.dis. */
#include <stddef.h>

inline void *operator new(size_t, void *p) { return p; }
extern "C" {
void FUN_000043b4(void);
void FUN_0027f9b0(void *guard, int n);
void FUN_0027fb58(void *guard, unsigned cap, int fill);
}

struct Elem40 {
    void *vt;
    short a4, a6, a8, a10, a12, a14, a16;
    char s18[10];
    char s1c[9];
    unsigned char b25;
    short a26;
    char pad[8];
    Elem40() {}
    Elem40(const Elem40 &o)
    {
        vt = o.vt;
        a4 = o.a4; a6 = o.a6; a8 = o.a8; a10 = o.a10; a12 = o.a12; a14 = o.a14; a16 = o.a16;
        for (int i = 0; i < 10; i++) s18[i] = o.s18[i];
        for (int i = 0; i < 9; i++) s1c[i] = o.s1c[i];
        b25 = o.b25; a26 = o.a26;
    }
};

struct RangeGuard {
    Elem40 *data;
    unsigned size;
    unsigned cap;
    unsigned *pc;
    int rem;
    RangeGuard(unsigned *p) : data(0), size(0), cap(0), pc(p), rem(0) {}
    ~RangeGuard();
};

template <class T>
struct Vec {
    T *data;
    int size;
    unsigned capacity;

    void fill_append(unsigned n, const T &x)
    {
        RangeGuard g(&capacity);
        const unsigned max = 0x06666666u;
        unsigned need = (unsigned)size + n;
        unsigned extra;
        if (n > max - capacity)
            FUN_000043b4();
        if (capacity < max / 3) {
            unsigned cand = 3 * (capacity + 1) / 5;
            extra = cand < need - capacity ? need - capacity : cand;
        } else if (capacity < 2 * max / 3) {
            unsigned cand = (capacity + 1) / 2;
            extra = cand < need - capacity ? need - capacity : cand;
        } else {
            extra = max - capacity;
        }
        FUN_0027fb58(&g, capacity + extra, 0);
        g.rem = (unsigned)size;
        for (unsigned i = 0; i < n; i++) {
            new (g.data + g.rem + g.size) T(x);
            g.size++;
        }
        while (g.rem != 0) {
            g.rem--;
            g.size++;
            g.data[g.rem] = data[g.rem];
        }
        T *d0 = data; data = g.data; g.data = d0;
        unsigned c0 = capacity; capacity = g.cap; g.cap = c0;
        int s0v = size; size = (int)g.size; g.size = (unsigned)s0v;
        FUN_0027f9b0(&g, -1);
    }
};

extern "C" void FUN_0027f480(Vec<Elem40> *v, unsigned n, const Elem40 *x)
{
    v->fill_append(n, *x);
}

/* NEAR MISS PARK (pass 51). 229/229 words - the instruction sequence is word-for-word retail's;
   the whole body differs only because our frame is 64 bytes and retail's is 96, so every stack
   offset is 32 low and the guard sits at sp+44 instead of sp+76.
   Saved registers now MATCH exactly: ra,s0..s3 with s3=this and s0=n (retail s0=this,s3=n), i.e.
   the colouring follows from the frame, not from the signature.
   MEASURED PROGRESSION: 152/229 (stub body) -> 226/229 (frame 112, Vec tmp + guard both live) ->
   229/229 (this file: the 5-word guard is the ONLY temporary, its &capacity member initialiser
   removed the separate Vec tmp and dropped saved regs to s0..s3).
   RULED OUT (frame lever, 2 spellings): a separate `Vec tmp` object alongside the guard (frame 112);
   naming the three growth candidates as separate locals gone through `if (cand < diff) cand = diff`
   (229/229 again, frame still 64 - it does not grow the frame).
   WHAT IS LEFT: retail holds 64 bytes of locals between the saved-register area (ends sp+31) and the
   guard at sp+76; only sp+48/52/56 are touched by the growth ladder, so sp+32..47 and sp+60..75 hold
   objects this source does not declare (two 16-byte blocks). Frame-matching that is a source-shape
   question about the undeclared temporaries, not about the body. */

/* PASS 52 REFUTATION of the "two 16-byte objects" note above: the whole listing forms only
   sp+48/52/56 (the growth-candidate select) and sp+76 (the guard, passed as a0 to both out-of-line
   calls); there is no `addiu ...,sp,32` or `...,sp,60` anywhere, so sp+32..47 and sp+60..75 are never
   addressed and cannot be declared objects. MEASURED test of the opposite theory (the guard having a
   16-byte prefix filled by 0x27fb58, making it 36 bytes): frame became 80, guard base moved to sp+44,
   i.e. MWCC always places the largest/guard object at the top of the frame, so frame = guard_end.
   Retail's guard base is 76 with a 20-byte guard -> frame 96 exactly, so the 32 extra bytes are
   frame space MWCC reserved for something this function never touches, not objects the body can
   declare. Parked: 229/229 words, body word-identical, frame 64 vs 96. */
// near miss from lane dsn3 (unreviewed)
