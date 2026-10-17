/* HSTMATCH module=hstp_trans_main.prx start=0x001b48b8 end=0x001b4920 symbol=FUN_001b48b8 lang=c++ */
/* Clone of src/eboot/vecvec_reset_0017a62c.cpp (hstclone.py tag c41): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector-of-vectors reset to capacity n (the vec_reset_001a710c shape with the element destroy out of line):
   destroy all elements (0x17a694), free and forget the old block, then reserve n through an inline wrapper
   that passes a by-value char flag (move v0,zero; andi; seb). The second argument is an unused empty
   allocator. Names provisional. */
#pragma inline_depth(8)
struct Alloc_001b48b8 {};
struct Flag_001b48b8 { char v; Flag_001b48b8(char x) : v(x) {} };
struct Elem_001b48b8 { int w[3]; };
struct Vec_001b48b8;
extern "C" {
void FUN_001b4920(Vec_001b48b8 *v, int n);
void FUN_001b5fb8(Vec_001b48b8 *v, unsigned n, char f);
}
inline void Reserve2_001b48b8(Vec_001b48b8 *v, unsigned n, Flag_001b48b8 f) { FUN_001b5fb8(v, n, f.v); }
inline void Reserve_001b48b8(Vec_001b48b8 *v, unsigned n) { Reserve2_001b48b8(v, n, Flag_001b48b8(0)); }
struct Vec_001b48b8 { Elem_001b48b8 *data; int size; unsigned capacity; };
extern "C" void FUN_001b48b8(Vec_001b48b8 *v, Alloc_001b48b8, unsigned n)
{
    FUN_001b4920(v, v->size);
    if (v->data) {
        delete v->data;
        v->data = 0;
        v->capacity = 0;
    }
    Reserve_001b48b8(v, n);
}
