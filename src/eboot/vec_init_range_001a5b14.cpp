/* HSTMATCH module=EBOOT.BIN start=0x001a5b14 end=0x001a5bcc symbol=FUN_001a5b14 lang=c++ */
/* Clone of src/eboot/vec_init_range_000d5304.cpp (hstclone.py tag c38): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 4-byte elements: range initialisation from a pointer range (0xc4450 allocates; no tag parameter; same body as vec_init_range_00146500
   but retail keeps the BYTE difference in s0 and divides it again for the size update). MWCC CSEs every
   repeated `bytes / 4` of one type (even through inline helpers, casts to unsigned and reassignments); only
   a division of a different type (long vs int) is recomputed. The copy length uses the pointer difference,
   which MWCC never merges with the char difference. Names provisional. */
extern "C" void *FUN_000111c0(void *dst, const void *src, unsigned n);
struct Tag_001a5b14 {};
typedef void *Elem_001a5b14;
struct Vec_001a5b14 { Elem_001a5b14 *data; int size; unsigned capacity; };
extern "C" void FUN_001a864c(Vec_001a5b14 *v, unsigned n, Tag_001a5b14);
extern "C" void FUN_001a5b14(Vec_001a5b14 *v, Elem_001a5b14 *first, Elem_001a5b14 *last)
{
    int bytes = (char *)last - (char *)first;
    int n = bytes / (int)sizeof(Elem_001a5b14);
    if (n != 0) {
        FUN_001a864c(v, n, Tag_001a5b14());
        FUN_000111c0(v->data + v->size, first, (last - first) * sizeof(Elem_001a5b14));
        v->size += (long)bytes / (long)sizeof(Elem_001a5b14);
    }
}
