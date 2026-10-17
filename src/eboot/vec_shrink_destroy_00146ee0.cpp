/* HSTMATCH module=EBOOT.BIN start=0x00146ee0 end=0x00146f64 symbol=FUN_00146ee0 lang=c++ */
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
extern "C" void FUN_00146ee0(Vec *v, int n)
{
    Elem *p = v->data + v->size;
    v->shrink(n, Alloc());
    for (; n != 0; --n) {
        --p;
        if (p) p->~Elem();
    }
}
