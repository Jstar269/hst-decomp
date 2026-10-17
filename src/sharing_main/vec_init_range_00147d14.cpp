/* HSTMATCH module=hstp_trans_main.prx start=0x00147d14 end=0x00147da0 symbol=FUN_00147d14 lang=c++ */
/* Clone of src/eboot/vec_init_range_0013c6c8.cpp (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 4-byte elements: range initialisation from a pointer range (0xc4450 allocates, the block is copied with 0x111c0); same shape as 0xd5304 but the plain pointer difference is reused for the size update. Names provisional. */
struct Tag {};
typedef int Elem;
struct Vec {
    Elem *data;
    int size;
    unsigned capacity;
};
extern "C" void *FUN_000111c0(void *dst, const void *src, unsigned n);
extern "C" void FUN_000c7cb8(Vec *v, unsigned n, Tag);

extern "C" void FUN_00147d14(Vec *v, Elem *first, Elem *last)
{
    int n = last - first;
    if (n != 0) {
        FUN_000c7cb8(v, n, Tag());
        FUN_000111c0(v->data + v->size, first, n * sizeof(Elem));
        v->size += n;
    }
}
