/* HSTMATCH module=EBOOT.BIN start=0x000e97d4 end=0x000e984c symbol=FUN_000e97d4 lang=c++ */
/* Clone of src/eboot/vec_shrink_destroy_000e85c4.cpp (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector-like container shrink: size -= n through an inline member taking an empty allocator by value (reserves the extra 16 frame bytes), then the destroy walk over the removed 752-byte elements, calling the sub-object destructor FUN_0005ba00(&elem->sub, -1) explicitly. Same shape as vec_shrink_destroy_00146ee0. */
extern "C" void FUN_0005ba00(void *, int);
struct Alloc {};
struct Elem {
    char pad[0x30];
    char sub[0x2c0];
};
struct Vec {
    Elem *data; int size;
    void shrink(int n, Alloc) { size -= n; }
};
extern "C" void FUN_000e97d4(Vec *v, int n)
{
    Elem *p = v->data + v->size;
    v->shrink(n, Alloc());
    for (; n != 0; --n) {
        --p;
        if (p) FUN_0005ba00(p->sub, -1);
    }
}
