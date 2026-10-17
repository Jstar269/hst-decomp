/* HSTMATCH module=hstp_trans_main.prx start=0x00186d20 end=0x00186d88 symbol=FUN_00186d20 lang=c++ */
/* Clone of src/eboot/vecvec_reset_0017a62c.cpp (hstclone.py tag c41): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector-of-vectors reset to capacity n (the vec_reset_001a710c shape with the element destroy out of line):
   destroy all elements (0x17a694), free and forget the old block, then reserve n through an inline wrapper
   that passes a by-value char flag (move v0,zero; andi; seb). The second argument is an unused empty
   allocator. Names provisional. */
#pragma inline_depth(8)
struct Alloc_00186d20 {};
struct Flag_00186d20 { char v; Flag_00186d20(char x) : v(x) {} };
struct Elem_00186d20 { int w[3]; };
struct Vec_00186d20;
extern "C" {
void FUN_00186d88(Vec_00186d20 *v, int n);
void FUN_0018735c(Vec_00186d20 *v, unsigned n, char f);
}
inline void Reserve2_00186d20(Vec_00186d20 *v, unsigned n, Flag_00186d20 f) { FUN_0018735c(v, n, f.v); }
inline void Reserve_00186d20(Vec_00186d20 *v, unsigned n) { Reserve2_00186d20(v, n, Flag_00186d20(0)); }
struct Vec_00186d20 { Elem_00186d20 *data; int size; unsigned capacity; };
extern "C" void FUN_00186d20(Vec_00186d20 *v, Alloc_00186d20, unsigned n)
{
    FUN_00186d88(v, v->size);
    if (v->data) {
        delete v->data;
        v->data = 0;
        v->capacity = 0;
    }
    Reserve_00186d20(v, n);
}
