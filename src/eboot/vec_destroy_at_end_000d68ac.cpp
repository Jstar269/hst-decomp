/* HSTMATCH module=EBOOT.BIN start=0x000d68ac end=0x000d696c symbol=FUN_000d68ac lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
/* Vector of 24-byte elements {short-string-optimised string, vector of words}: destroy the last n elements
   (size -= n first, then walk back from the old end). Each element's implicit destructor keeps its own
   `if (this)`; the word vector sits under two more implicit layers (W1/W2 stand in for the library's
   member/base layers), giving retail's three `beqz` on this+12. Its destructor clears through
   `int n = size; shrink(n, Alloc());` (the unfolded `size - size` and the empty allocator temporary's
   16-byte frame slot) before freeing the buffer. Names provisional. */
struct String_000d68ac {
    unsigned cap;
    unsigned size;
    char *data;
    ~String_000d68ac() { if (cap & 1) operator delete(data); }
};
struct Alloc_000d68ac {};
struct IVec_000d68ac {
    int *data;
    unsigned size;
    unsigned capacity;
    void shrink(int n, Alloc_000d68ac) { size -= n; }
    ~IVec_000d68ac() { int n = size; shrink(n, Alloc_000d68ac()); if (data) operator delete(data); }
};
struct W2_000d68ac { IVec_000d68ac v; };
struct W1_000d68ac { W2_000d68ac w; };
struct Elem_000d68ac {
    String_000d68ac s;
    W1_000d68ac v;
};
struct V_000d68ac {
    Elem_000d68ac *data;
    unsigned size;
    unsigned capacity;
};

extern "C" void FUN_000d68ac(V_000d68ac *v, unsigned n)
{
    Elem_000d68ac *p = v->data + v->size;
    v->size -= n;
    for (; n != 0; --n) {
        --p;
        p->~Elem_000d68ac();
    }
}
