/* HSTMATCH module=hstp_trans_main.prx start=0x000da59c end=0x000da65c symbol=FUN_000da59c lang=c++ */
/* Clone of src/eboot/vec_destroy_at_end_000d68ac.cpp (hstclone.py tag c37): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
/* Vector of 24-byte elements {short-string-optimised string, vector of words}: destroy the last n elements
   (size -= n first, then walk back from the old end). Each element's implicit destructor keeps its own
   `if (this)`; the word vector sits under two more implicit layers (W1/W2 stand in for the library's
   member/base layers), giving retail's three `beqz` on this+12. Its destructor clears through
   `int n = size; shrink(n, Alloc());` (the unfolded `size - size` and the empty allocator temporary's
   16-byte frame slot) before freeing the buffer. Names provisional. */
struct String_000da59c {
    unsigned cap;
    unsigned size;
    char *data;
    ~String_000da59c() { if (cap & 1) operator delete(data); }
};
struct Alloc_000da59c {};
struct IVec_000da59c {
    int *data;
    unsigned size;
    unsigned capacity;
    void shrink(int n, Alloc_000da59c) { size -= n; }
    ~IVec_000da59c() { int n = size; shrink(n, Alloc_000da59c()); if (data) operator delete(data); }
};
struct W2_000da59c { IVec_000da59c v; };
struct W1_000da59c { W2_000da59c w; };
struct Elem_000da59c {
    String_000da59c s;
    W1_000da59c v;
};
struct V_000da59c {
    Elem_000da59c *data;
    unsigned size;
    unsigned capacity;
};

extern "C" void FUN_000da59c(V_000da59c *v, unsigned n)
{
    Elem_000da59c *p = v->data + v->size;
    v->size -= n;
    for (; n != 0; --n) {
        --p;
        p->~Elem_000da59c();
    }
}
