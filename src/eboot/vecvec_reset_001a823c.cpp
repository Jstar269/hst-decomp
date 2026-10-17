/* HSTMATCH module=EBOOT.BIN start=0x001a823c end=0x001a82a4 symbol=FUN_001a823c lang=c++ */
/* Clone of src/eboot/vecvec_reset_0017a62c.cpp (hstclone.py tag c40): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector-of-vectors reset to capacity n (the vec_reset_001a710c shape with the element destroy out of line):
   destroy all elements (0x17a694), free and forget the old block, then reserve n through an inline wrapper
   that passes a by-value char flag (move v0,zero; andi; seb). The second argument is an unused empty
   allocator. Names provisional. */
#pragma inline_depth(8)
struct Alloc_001a823c {};
struct Flag_001a823c { char v; Flag_001a823c(char x) : v(x) {} };
struct Elem_001a823c { int w[3]; };
struct Vec_001a823c;
extern "C" {
void FUN_001a82a4(Vec_001a823c *v, int n);
void FUN_001a8bcc(Vec_001a823c *v, unsigned n, char f);
}
inline void Reserve2_001a823c(Vec_001a823c *v, unsigned n, Flag_001a823c f) { FUN_001a8bcc(v, n, f.v); }
inline void Reserve_001a823c(Vec_001a823c *v, unsigned n) { Reserve2_001a823c(v, n, Flag_001a823c(0)); }
struct Vec_001a823c { Elem_001a823c *data; int size; unsigned capacity; };
extern "C" void FUN_001a823c(Vec_001a823c *v, Alloc_001a823c, unsigned n)
{
    FUN_001a82a4(v, v->size);
    if (v->data) {
        delete v->data;
        v->data = 0;
        v->capacity = 0;
    }
    Reserve_001a823c(v, n);
}
