/* HSTMATCH module=EBOOT.BIN start=0x002b3370 end=0x002b34b0 symbol=FUN_002b3370 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Tag {};
struct Str32 { char c[32]; Str32() {} };
struct Str16 { char c[16]; Str16() {} };
struct Elem {
    int id;
    Str32 a;
    Str32 b;
    char c0, c1, c2;
    unsigned char c3, c4;
    char c5, c6, c7;
    int i4c;
    int i50;
    Str16 name;
};
struct Vec { Elem *data; unsigned size; unsigned cap; };
inline void *operator new(unsigned, void *p) { return p; }
extern "C" void FUN_002b39e0(Vec *, const Elem *, Tag);
extern "C" void FUN_002b3370(Vec *v, const Elem *x)
{
    if (v->size < v->cap) {
        new (v->data + v->size) Elem(*x);
        ++v->size;
    } else {
        FUN_002b39e0(v, x, Tag());
    }
}
