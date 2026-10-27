/* HSTMATCH module=hstp_trans_main.prx start=0x00246e48 end=0x00246f18 symbol=FUN_00246e48 lang=c++ */
/* Hand-written reconstruction from the disassembly (copy constructor of a vector of 2-byte elements: zero the three fields, then the range initialisation of src/sharing_main/vec_init_range_002468b4.cpp inlined; the size update divides the byte difference as `long`, the src/eboot/vec_init_range_000d5304.cpp idiom that keeps the byte difference in s0); exact match verified; names and types await human review. */
extern "C" void *FUN_000111c0(void *dst, const void *src, unsigned n);
struct Tag_00246e48 {};
typedef short Elem_00246e48;
struct Vec_00246e48 { Elem_00246e48 *data; int size; unsigned capacity; };
extern "C" void FUN_002475a8(Vec_00246e48 *v, unsigned n, Tag_00246e48);
static inline void InitRange(Vec_00246e48 *v, Elem_00246e48 *first, Elem_00246e48 *last)
{
    int bytes = (char *)last - (char *)first;
    int n = bytes / (int)sizeof(Elem_00246e48);
    if (n != 0) {
        FUN_002475a8(v, n, Tag_00246e48());
        FUN_000111c0(v->data + v->size, first, (last - first) * sizeof(Elem_00246e48));
        v->size += (long)bytes / (long)sizeof(Elem_00246e48);
    }
}
extern "C" Vec_00246e48 *FUN_00246e48(Vec_00246e48 *v, const Vec_00246e48 *o)
{
    v->data = 0;
    v->size = 0;
    v->capacity = 0;
    InitRange(v, o->data, o->data + o->size);
    return v;
}
