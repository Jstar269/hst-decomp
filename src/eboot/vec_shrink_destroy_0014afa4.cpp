/* HSTMATCH module=EBOOT.BIN start=0x0014afa4 end=0x0014b028 symbol=FUN_0014afa4 lang=c++ */
/* Clone of src/eboot/vec_shrink_destroy_00146ee0.cpp (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector-like container shrink: size -= n through an inline member taking an empty allocator by value (the temporary reserves the extra 16 frame bytes), then the destroy walk over the removed 40-byte elements (inline dtor frees ptr when flags & 1). */
extern "C" void FUN_00000a00(void *);
struct Alloc {};
struct Elem {
    unsigned flags;
    int a;
    void *ptr;
    int pad[7];
    ~Elem() { if (flags & 1) FUN_00000a00(ptr); }
};
struct Vec {
    Elem *data; int size;
    void shrink(int n, Alloc) { size -= n; }
};
extern "C" void FUN_0014afa4(Vec *v, int n)
{
    Elem *p = v->data + v->size;
    v->shrink(n, Alloc());
    for (; n != 0; --n) {
        --p;
        if (p) p->~Elem();
    }
}
