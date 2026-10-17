/* HSTMATCH module=EBOOT.BIN start=0x000d7ca0 end=0x000d7d60 symbol=FUN_000d7ca0 lang=c++ */
/* Clone of src/eboot/vec_destroy_at_end_000d68ac.cpp (hstclone.py tag c36): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
/* Vector of 24-byte elements {short-string-optimised string, vector of words}: destroy the last n elements
   (size -= n first, then walk back from the old end). Each element's implicit destructor keeps its own
   `if (this)`; the word vector sits under two more implicit layers (W1/W2 stand in for the library's
   member/base layers), giving retail's three `beqz` on this+12. Its destructor clears through
   `int n = size; shrink(n, Alloc());` (the unfolded `size - size` and the empty allocator temporary's
   16-byte frame slot) before freeing the buffer. Names provisional. */
struct String_000d7ca0 {
    unsigned cap;
    unsigned size;
    char *data;
    ~String_000d7ca0() { if (cap & 1) operator delete(data); }
};
struct Alloc_000d7ca0 {};
struct IVec_000d7ca0 {
    int *data;
    unsigned size;
    unsigned capacity;
    void shrink(int n, Alloc_000d7ca0) { size -= n; }
    ~IVec_000d7ca0() { int n = size; shrink(n, Alloc_000d7ca0()); if (data) operator delete(data); }
};
struct W2_000d7ca0 { IVec_000d7ca0 v; };
struct W1_000d7ca0 { W2_000d7ca0 w; };
struct Elem_000d7ca0 {
    String_000d7ca0 s;
    W1_000d7ca0 v;
};
struct V_000d7ca0 {
    Elem_000d7ca0 *data;
    unsigned size;
    unsigned capacity;
};

extern "C" void FUN_000d7ca0(V_000d7ca0 *v, unsigned n)
{
    Elem_000d7ca0 *p = v->data + v->size;
    v->size -= n;
    for (; n != 0; --n) {
        --p;
        p->~Elem_000d7ca0();
    }
}
