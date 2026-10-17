/* HSTMATCH module=EBOOT.BIN start=0x0024627c end=0x00246328 symbol=FUN_0024627c lang=c++ */
/* Clone of src/eboot/vec_init_range_00146500.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 4-byte elements: range initialisation from a pointer range (forward-iterator overload, tag in a3,
   called from the copy-construct path of 0x146368). Reserve through 0x14a86c (empty tag by value), copy the
   block with 0x111c0, bump the size. The element count must be a byte difference divided by the element
   size: written as `last - first` MWCC reuses it for the copy length, retail recomputes it. Names provisional. */
extern "C" void *FUN_000111c0(void *dst, const void *src, unsigned n);
struct Tag_0024627c {};
typedef void *Elem_0024627c;
struct Vec_0024627c { Elem_0024627c *data; int size; unsigned capacity; };
extern "C" void FUN_0020673c(Vec_0024627c *v, unsigned n, Tag_0024627c);
extern "C" void FUN_0024627c(Vec_0024627c *v, Elem_0024627c *first, Elem_0024627c *last, Tag_0024627c)
{
    int n = ((char *)last - (char *)first) / (int)sizeof(Elem_0024627c);
    if (n != 0) {
        FUN_0020673c(v, n, Tag_0024627c());
        FUN_000111c0(v->data + v->size, first, (last - first) * sizeof(Elem_0024627c));
        v->size += n;
    }
}
