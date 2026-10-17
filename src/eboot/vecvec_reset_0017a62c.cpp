/* HSTMATCH module=EBOOT.BIN start=0x0017a62c end=0x0017a694 symbol=FUN_0017a62c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector-of-vectors reset to capacity n (the vec_reset_001a710c shape with the element destroy out of line):
   destroy all elements (0x17a694), free and forget the old block, then reserve n through an inline wrapper
   that passes a by-value char flag (move v0,zero; andi; seb). The second argument is an unused empty
   allocator. Names provisional. */
#pragma inline_depth(8)
struct Alloc_0017a62c {};
struct Flag_0017a62c { char v; Flag_0017a62c(char x) : v(x) {} };
struct Elem_0017a62c { int w[3]; };
struct Vec_0017a62c;
extern "C" {
void FUN_0017a694(Vec_0017a62c *v, int n);
void FUN_0017ac68(Vec_0017a62c *v, unsigned n, char f);
}
inline void Reserve2_0017a62c(Vec_0017a62c *v, unsigned n, Flag_0017a62c f) { FUN_0017ac68(v, n, f.v); }
inline void Reserve_0017a62c(Vec_0017a62c *v, unsigned n) { Reserve2_0017a62c(v, n, Flag_0017a62c(0)); }
struct Vec_0017a62c { Elem_0017a62c *data; int size; unsigned capacity; };
extern "C" void FUN_0017a62c(Vec_0017a62c *v, Alloc_0017a62c, unsigned n)
{
    FUN_0017a694(v, v->size);
    if (v->data) {
        delete v->data;
        v->data = 0;
        v->capacity = 0;
    }
    Reserve_0017a62c(v, n);
}
