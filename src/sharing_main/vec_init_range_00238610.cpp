/* HSTMATCH module=hstp_trans_main.prx start=0x00238610 end=0x002386bc symbol=FUN_00238610 lang=c++ */
/* Clone of src/eboot/vec_init_range_00065ce0.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 4-byte elements: range initialisation from a pointer range (forward-iterator overload, tag in a3,
   called from the copy-construct path of 0x146368). Reserve through 0x14a86c (empty tag by value), copy the
   block with 0x111c0, bump the size. The element count must be a byte difference divided by the element
   size: written as `last - first` MWCC reuses it for the copy length, retail recomputes it. Names provisional. */
extern "C" void *FUN_000111c0(void *dst, const void *src, unsigned n);
struct Tag_00238610 {};
typedef void *Elem_00238610;
struct Vec_00238610 { Elem_00238610 *data; int size; unsigned capacity; };
extern "C" void FUN_002386bc(Vec_00238610 *v, unsigned n, Tag_00238610);
extern "C" void FUN_00238610(Vec_00238610 *v, Elem_00238610 *first, Elem_00238610 *last, Tag_00238610)
{
    int n = ((char *)last - (char *)first) / (int)sizeof(Elem_00238610);
    if (n != 0) {
        FUN_002386bc(v, n, Tag_00238610());
        FUN_000111c0(v->data + v->size, first, (last - first) * sizeof(Elem_00238610));
        v->size += n;
    }
}
