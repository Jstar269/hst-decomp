/* HSTMATCH module=EBOOT.BIN start=0x000d5304 end=0x000d53bc symbol=FUN_000d5304 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 4-byte elements: range initialisation from a pointer range (0xc4450 allocates; no tag parameter; same body as vec_init_range_00146500
   but retail keeps the BYTE difference in s0 and divides it again for the size update). MWCC CSEs every
   repeated `bytes / 4` of one type (even through inline helpers, casts to unsigned and reassignments); only
   a division of a different type (long vs int) is recomputed. The copy length uses the pointer difference,
   which MWCC never merges with the char difference. Names provisional. */
extern "C" void *FUN_000111c0(void *dst, const void *src, unsigned n);
struct Tag_000d5304 {};
typedef void *Elem_000d5304;
struct Vec_000d5304 { Elem_000d5304 *data; int size; unsigned capacity; };
extern "C" void FUN_000c4450(Vec_000d5304 *v, unsigned n, Tag_000d5304);
extern "C" void FUN_000d5304(Vec_000d5304 *v, Elem_000d5304 *first, Elem_000d5304 *last)
{
    int bytes = (char *)last - (char *)first;
    int n = bytes / (int)sizeof(Elem_000d5304);
    if (n != 0) {
        FUN_000c4450(v, n, Tag_000d5304());
        FUN_000111c0(v->data + v->size, first, (last - first) * sizeof(Elem_000d5304));
        v->size += (long)bytes / (long)sizeof(Elem_000d5304);
    }
}
