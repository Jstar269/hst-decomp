/* HSTMATCH module=EBOOT.BIN start=0x00236ce4 end=0x00236db4 symbol=FUN_00236ce4 lang=c++ */
/* Clone of src/sharing_main/vec_copy_ctor_00246e48.cpp (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (copy constructor of a vector of 2-byte elements: zero the three fields, then the range initialisation of src/sharing_main/vec_init_range_002468b4.cpp inlined; the size update divides the byte difference as `long`, the src/eboot/vec_init_range_000d5304.cpp idiom that keeps the byte difference in s0); exact match verified; names and types await human review. */
extern "C" void *FUN_000111c0(void *dst, const void *src, unsigned n);
struct Tag_00236ce4 {};
typedef short Elem_00236ce4;
struct Vec_00236ce4 { Elem_00236ce4 *data; int size; unsigned capacity; };
extern "C" void FUN_00237444(Vec_00236ce4 *v, unsigned n, Tag_00236ce4);
static inline void InitRange(Vec_00236ce4 *v, Elem_00236ce4 *first, Elem_00236ce4 *last)
{
    int bytes = (char *)last - (char *)first;
    int n = bytes / (int)sizeof(Elem_00236ce4);
    if (n != 0) {
        FUN_00237444(v, n, Tag_00236ce4());
        FUN_000111c0(v->data + v->size, first, (last - first) * sizeof(Elem_00236ce4));
        v->size += (long)bytes / (long)sizeof(Elem_00236ce4);
    }
}
extern "C" Vec_00236ce4 *FUN_00236ce4(Vec_00236ce4 *v, const Vec_00236ce4 *o)
{
    v->data = 0;
    v->size = 0;
    v->capacity = 0;
    InitRange(v, o->data, o->data + o->size);
    return v;
}
