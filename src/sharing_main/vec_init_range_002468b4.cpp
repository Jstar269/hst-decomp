/* HSTMATCH module=hstp_trans_main.prx start=0x002468b4 end=0x0024696c symbol=FUN_002468b4 lang=c++ */
/* Hand-written reconstruction from the disassembly (range initialisation of a vector of 2-byte elements, called by src/sharing_main/vec_pair_copy_ctor_00245c7c.cpp; the same body as src/eboot/vec_init_range_000d5304.cpp with the reserve tag: `int n = bytes / 2` for the test and the reserve argument, `(long)bytes / (long)sizeof` for the size update keeps the byte difference in s0); exact match verified; names and types await human review. */
extern "C" void *FUN_000111c0(void *dst, const void *src, unsigned n);
struct Tag_002468b4 {};
typedef short Elem_002468b4;
struct Vec_002468b4 { Elem_002468b4 *data; int size; unsigned capacity; };
extern "C" void FUN_002475a8(Vec_002468b4 *v, unsigned n, Tag_002468b4);
extern "C" void FUN_002468b4(Vec_002468b4 *v, Elem_002468b4 *first, Elem_002468b4 *last, Tag_002468b4)
{
    int bytes = (char *)last - (char *)first;
    int n = bytes / (int)sizeof(Elem_002468b4);
    if (n != 0) {
        FUN_002475a8(v, n, Tag_002468b4());
        FUN_000111c0(v->data + v->size, first, (last - first) * sizeof(Elem_002468b4));
        v->size += (long)bytes / (long)sizeof(Elem_002468b4);
    }
}
