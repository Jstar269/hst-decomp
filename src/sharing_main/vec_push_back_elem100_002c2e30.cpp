/* HSTMATCH module=hstp_trans_main.prx start=0x002c2e30 end=0x002c2f70 symbol=FUN_002c2e30 lang=c++ */
/* Clone of src/eboot/vec_push_back_elem100_002b3370.cpp (hstclone.py tag s10170158a1r4s): addresses substituted; exact match verified; names and types await human review. */
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
extern "C" void FUN_002c34a0(Vec *, const Elem *, Tag);
extern "C" void FUN_002c2e30(Vec *v, const Elem *x)
{
    if (v->size < v->cap) {
        new (v->data + v->size) Elem(*x);
        ++v->size;
    } else {
        FUN_002c34a0(v, x, Tag());
    }
}
