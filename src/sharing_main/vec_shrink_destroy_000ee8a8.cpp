/* HSTMATCH module=hstp_trans_main.prx start=0x000ee8a8 end=0x000ee920 symbol=FUN_000ee8a8 lang=c++ */
/* Clone of src/eboot/vec_shrink_destroy_000e85c4.cpp (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector-like container shrink: size -= n through an inline member taking an empty allocator by value (reserves the extra 16 frame bytes), then the destroy walk over the removed 752-byte elements, calling the sub-object destructor FUN_0005c688(&elem->sub, -1) explicitly. Same shape as vec_shrink_destroy_00146ee0. */
extern "C" void FUN_0005c688(void *, int);
struct Alloc {};
struct Elem {
    char pad[0x30];
    char sub[0x2c0];
};
struct Vec {
    Elem *data; int size;
    void shrink(int n, Alloc) { size -= n; }
};
extern "C" void FUN_000ee8a8(Vec *v, int n)
{
    Elem *p = v->data + v->size;
    v->shrink(n, Alloc());
    for (; n != 0; --n) {
        --p;
        if (p) FUN_0005c688(p->sub, -1);
    }
}
