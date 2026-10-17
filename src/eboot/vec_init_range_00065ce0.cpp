/* HSTMATCH module=EBOOT.BIN start=0x00065ce0 end=0x00065d8c symbol=FUN_00065ce0 lang=c++ */
/* Clone of src/eboot/vec_init_range_00146500.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 4-byte elements: range initialisation from a pointer range (forward-iterator overload, tag in a3,
   called from the copy-construct path of 0x146368). Reserve through 0x14a86c (empty tag by value), copy the
   block with 0x111c0, bump the size. The element count must be a byte difference divided by the element
   size: written as `last - first` MWCC reuses it for the copy length, retail recomputes it. Names provisional. */
extern "C" void *FUN_000111c0(void *dst, const void *src, unsigned n);
struct Tag_00065ce0 {};
typedef void *Elem_00065ce0;
struct Vec_00065ce0 { Elem_00065ce0 *data; int size; unsigned capacity; };
extern "C" void FUN_00066c44(Vec_00065ce0 *v, unsigned n, Tag_00065ce0);
extern "C" void FUN_00065ce0(Vec_00065ce0 *v, Elem_00065ce0 *first, Elem_00065ce0 *last, Tag_00065ce0)
{
    int n = ((char *)last - (char *)first) / (int)sizeof(Elem_00065ce0);
    if (n != 0) {
        FUN_00066c44(v, n, Tag_00065ce0());
        FUN_000111c0(v->data + v->size, first, (last - first) * sizeof(Elem_00065ce0));
        v->size += n;
    }
}
