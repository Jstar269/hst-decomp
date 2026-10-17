/* HSTMATCH module=hstp_trans_main.prx start=0x000cb1a0 end=0x000cb204 symbol=FUN_000cb1a0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#pragma inline_depth(8)
inline void *operator new(unsigned, void *p) { return p; }

struct in_tag {};
struct fwd_tag : in_tag {};

struct Vec {
    int *data;
    int size;
    int cap;
};

extern "C" void FUN_000041ec(void *dst, const void *src);
extern "C" void FUN_000d8ff4(Vec *v, int *begin, int *end, fwd_tag);

struct Base {
    char pad[12];
    Base(const Base &o) {
        FUN_000041ec(this, &o);
    }
};

struct Obj : Base {
    Vec vec;
    Obj(const Obj &o) : Base(o) {
        vec.data = 0;
        vec.size = 0;
        vec.cap = 0;
        FUN_000d8ff4(&vec, o.vec.data, o.vec.data + o.vec.size, fwd_tag());
    }
};

struct Alloc {};

extern "C" void FUN_000cb1a0(Alloc *a, Obj *p, const Obj &x)
{
    new (p) Obj(x);
}
