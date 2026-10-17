/* HSTMATCH module=hstp_trans_main.prx start=0x00067134 end=0x000671e0 symbol=FUN_00067134 lang=c++ */
/* Clone of src/eboot/vec_init_range_00065ce0.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 4-byte elements: range initialisation from a pointer range (forward-iterator overload, tag in a3,
   called from the copy-construct path of 0x146368). Reserve through 0x14a86c (empty tag by value), copy the
   block with 0x111c0, bump the size. The element count must be a byte difference divided by the element
   size: written as `last - first` MWCC reuses it for the copy length, retail recomputes it. Names provisional. */
extern "C" void *FUN_000111c0(void *dst, const void *src, unsigned n);
struct Tag_00067134 {};
typedef void *Elem_00067134;
struct Vec_00067134 { Elem_00067134 *data; int size; unsigned capacity; };
extern "C" void FUN_00068098(Vec_00067134 *v, unsigned n, Tag_00067134);
extern "C" void FUN_00067134(Vec_00067134 *v, Elem_00067134 *first, Elem_00067134 *last, Tag_00067134)
{
    int n = ((char *)last - (char *)first) / (int)sizeof(Elem_00067134);
    if (n != 0) {
        FUN_00068098(v, n, Tag_00067134());
        FUN_000111c0(v->data + v->size, first, (last - first) * sizeof(Elem_00067134));
        v->size += n;
    }
}
