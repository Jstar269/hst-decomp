/* HSTMATCH module=EBOOT.BIN start=0x0006de30 end=0x0006df50 symbol=FUN_0006de30 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" void FUN_0006e978(void *p);
extern "C" void FUN_0006eb04(void *p, int flag);
extern "C" void *operator_new(unsigned n);
extern "C" void operator_delete(void *p);

struct Elem {
    virtual ~Elem();
};

struct Sub12 {
    void *p;
    void Reset() { FUN_0006e978(this); }
};

struct Base {
    ~Base() { FUN_0006eb04(this, 0); }
};

struct Iter {
    Elem **p;
    Iter(Elem **q) : p(q) { }
    bool operator!=(const Iter &o) const { return p != o.p; }
};

struct Cont : Base {
    Elem **data;
    int size;
    int pad;
    Sub12 sub;
    ~Cont() { }
    void Clear()
    {
        int n = size;
        Elem **p = data;

        sub.Reset();
        while (p != data + size) {
            if (*p != 0) {
                delete *p;
                *p = 0;
            }
            p++;
        }
        size -= n;
    }
};

extern "C" Cont *DAT_00331c2c;

extern "C" void FUN_0006de30(void)
{
    if (DAT_00331c2c != 0) {
        int n = DAT_00331c2c->size;

        FUN_0006e978(&DAT_00331c2c->sub);
        Iter it(DAT_00331c2c->data);
        while (it != Iter(DAT_00331c2c->data + DAT_00331c2c->size)) {
            if (*it.p != 0) {
                delete *it.p;
                *it.p = 0;
            }
            it.p++;
        }
        DAT_00331c2c->size -= n;
    }
    if (DAT_00331c2c != 0) {
        delete DAT_00331c2c;
        DAT_00331c2c = 0;
    }
}
// PARKED 2026-10-28 (5 compiles): 63/72 words. Recovered: free function over the global
// DAT_00331c2c (Cont: Elem **data +0, int size +4, Sub12 sub +12): FUN_0006e978(&DAT->sub),
// delete every *p and zero it, then DAT->size -= n; then `delete DAT` (inline dtor: sub dtor
// + Base dtor FUN_0006eb04(this,0) + operator delete) and DAT = 0.  Writing the global
// directly (not through a local Cont*) is required: retail reloads DAT_00331c2c inside the
// loop and before each use.
// REMAINING GAP (9 words): retail's loop tests are MATERIALISED booleans
// (`xor p,end; sltiu v1,v1,1; xori v1,v1,1; beqzl v1,exit` at the guard and `bnezl` at the
// back edge) where every plain `while (p != DAT->data + DAT->size)` here gives a direct
// `beql`. Tried: raw pointer loop, `for`, and an MSL-style iterator class with a bool
// operator!= (63/72 - worse).  The materialised form looks like a `bool`-returning inline
// comparison; not found yet.
// near miss from lane dsn2 (unreviewed)
