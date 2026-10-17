/* HSTMATCH module=EBOOT.BIN start=0x001a710c end=0x001a7174 symbol=FUN_001a710c lang=c++ */
/* Clone of src/eboot/vec_reset_000d9148.cpp (hstclone.py tag c23): addresses substituted; exact match verified; names and types await human review. */
/* Container reset to capacity n: clear the size (inline shrink with an empty allocator temporary), free
   and forget the old block, then reserve n through an inline wrapper that passes a by-value char flag
   (move v0,zero; andi; seb). The second argument is an unused empty allocator. Names provisional. */
#pragma inline_depth(8)
struct Alloc_001a710c {};
struct Flag_001a710c { char v; Flag_001a710c(char x) : v(x) {} };
struct Vec_001a710c;
extern "C" void FUN_001a8944(Vec_001a710c *v, unsigned n, char f);
inline void Reserve2_001a710c(Vec_001a710c *v, unsigned n, Flag_001a710c f) { FUN_001a8944(v, n, f.v); }
inline void Reserve_001a710c(Vec_001a710c *v, unsigned n) { Reserve2_001a710c(v, n, Flag_001a710c(0)); }
struct Vec_001a710c {
    int *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_001a710c) { size -= n; }
};
extern "C" void FUN_001a710c(Vec_001a710c *v, Alloc_001a710c, unsigned n)
{
    int k = v->size;
    v->shrink(k, Alloc_001a710c());
    if (v->data) {
        delete v->data;
        v->data = 0;
        v->capacity = 0;
    }
    Reserve_001a710c(v, n);
}
