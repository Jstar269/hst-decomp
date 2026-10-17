/* HSTMATCH module=EBOOT.BIN start=0x00146500 end=0x001465ac symbol=FUN_00146500 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 4-byte elements: range initialisation from a pointer range (forward-iterator overload, tag in a3,
   called from the copy-construct path of 0x146368). Reserve through 0x14a86c (empty tag by value), copy the
   block with 0x111c0, bump the size. The element count must be a byte difference divided by the element
   size: written as `last - first` MWCC reuses it for the copy length, retail recomputes it. Names provisional. */
extern "C" void *FUN_000111c0(void *dst, const void *src, unsigned n);
struct Tag_00146500 {};
typedef void *Elem_00146500;
struct Vec_00146500 { Elem_00146500 *data; int size; unsigned capacity; };
extern "C" void FUN_0014a86c(Vec_00146500 *v, unsigned n, Tag_00146500);
extern "C" void FUN_00146500(Vec_00146500 *v, Elem_00146500 *first, Elem_00146500 *last, Tag_00146500)
{
    int n = ((char *)last - (char *)first) / (int)sizeof(Elem_00146500);
    if (n != 0) {
        FUN_0014a86c(v, n, Tag_00146500());
        FUN_000111c0(v->data + v->size, first, (last - first) * sizeof(Elem_00146500));
        v->size += n;
    }
}
