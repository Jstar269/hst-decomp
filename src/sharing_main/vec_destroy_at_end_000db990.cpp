/* HSTMATCH module=hstp_trans_main.prx start=0x000db990 end=0x000dba50 symbol=FUN_000db990 lang=c++ */
/* Clone of src/eboot/vec_destroy_at_end_000d68ac.cpp (hstclone.py tag c37): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
/* Vector of 24-byte elements {short-string-optimised string, vector of words}: destroy the last n elements
   (size -= n first, then walk back from the old end). Each element's implicit destructor keeps its own
   `if (this)`; the word vector sits under two more implicit layers (W1/W2 stand in for the library's
   member/base layers), giving retail's three `beqz` on this+12. Its destructor clears through
   `int n = size; shrink(n, Alloc());` (the unfolded `size - size` and the empty allocator temporary's
   16-byte frame slot) before freeing the buffer. Names provisional. */
struct String_000db990 {
    unsigned cap;
    unsigned size;
    char *data;
    ~String_000db990() { if (cap & 1) operator delete(data); }
};
struct Alloc_000db990 {};
struct IVec_000db990 {
    int *data;
    unsigned size;
    unsigned capacity;
    void shrink(int n, Alloc_000db990) { size -= n; }
    ~IVec_000db990() { int n = size; shrink(n, Alloc_000db990()); if (data) operator delete(data); }
};
struct W2_000db990 { IVec_000db990 v; };
struct W1_000db990 { W2_000db990 w; };
struct Elem_000db990 {
    String_000db990 s;
    W1_000db990 v;
};
struct V_000db990 {
    Elem_000db990 *data;
    unsigned size;
    unsigned capacity;
};

extern "C" void FUN_000db990(V_000db990 *v, unsigned n)
{
    Elem_000db990 *p = v->data + v->size;
    v->size -= n;
    for (; n != 0; --n) {
        --p;
        p->~Elem_000db990();
    }
}
