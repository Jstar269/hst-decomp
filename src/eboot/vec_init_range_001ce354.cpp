/* HSTMATCH module=EBOOT.BIN start=0x001ce354 end=0x001ce400 symbol=FUN_001ce354 lang=c++ */
/* Clone of src/eboot/vec_init_range_00146500.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 4-byte elements: range initialisation from a pointer range (forward-iterator overload, tag in a3,
   called from the copy-construct path of 0x146368). Reserve through 0x14a86c (empty tag by value), copy the
   block with 0x111c0, bump the size. The element count must be a byte difference divided by the element
   size: written as `last - first` MWCC reuses it for the copy length, retail recomputes it. Names provisional. */
extern "C" void *FUN_000111c0(void *dst, const void *src, unsigned n);
struct Tag_001ce354 {};
typedef void *Elem_001ce354;
struct Vec_001ce354 { Elem_001ce354 *data; int size; unsigned capacity; };
extern "C" void FUN_001cf578(Vec_001ce354 *v, unsigned n, Tag_001ce354);
extern "C" void FUN_001ce354(Vec_001ce354 *v, Elem_001ce354 *first, Elem_001ce354 *last, Tag_001ce354)
{
    int n = ((char *)last - (char *)first) / (int)sizeof(Elem_001ce354);
    if (n != 0) {
        FUN_001cf578(v, n, Tag_001ce354());
        FUN_000111c0(v->data + v->size, first, (last - first) * sizeof(Elem_001ce354));
        v->size += n;
    }
}
