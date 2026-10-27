/* HSTMATCH module=EBOOT.BIN start=0x00236750 end=0x00236808 symbol=FUN_00236750 lang=c++ */
/* Hand-written reconstruction from the disassembly (EBOOT twin of src/sharing_main/vec_init_range_002468b4.cpp; 2-byte-element instance of the range initialisation src/eboot/vec_init_range_000d5304.cpp, reserve through src/eboot/vec_reserve_t_00237444.cpp with an unused empty tag argument; matching idiom: the size update divides the kept byte difference as `long`, retail's recomputed division after the copy, which an `int` division would CSE); exact match verified; names and types await human review. */
/* Vector of 2-byte elements: range initialisation from a pointer range. The element count is a byte
   difference divided by the element size; the copy length uses the pointer difference (never merged
   with the char difference) and the size update redoes the division in a different type. Names provisional. */
extern "C" void *FUN_000111c0(void *dst, const void *src, unsigned n);
struct Tag_00236750 {};
struct Elem_00236750 { char b[2]; };
struct Vec_00236750 { Elem_00236750 *data; int size; unsigned capacity; };
extern "C" void FUN_00237444(Vec_00236750 *v, unsigned n, Tag_00236750);
extern "C" void FUN_00236750(Vec_00236750 *v, Elem_00236750 *first, Elem_00236750 *last)
{
    int bytes = (char *)last - (char *)first;
    int n = bytes / (int)sizeof(Elem_00236750);
    if (n != 0) {
        FUN_00237444(v, n, Tag_00236750());
        FUN_000111c0(v->data + v->size, first, (last - first) * sizeof(Elem_00236750));
        v->size += (long)bytes / (long)sizeof(Elem_00236750);
    }
}
