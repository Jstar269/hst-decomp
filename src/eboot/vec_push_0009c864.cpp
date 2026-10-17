/* HSTMATCH module=EBOOT.BIN start=0x0009c864 end=0x0009c8ec symbol=FUN_0009c864 lang=c++ */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Container push_back with out-of-line helpers: compare size against *capacity_ptr() through a less<>
   functor temporary (its slot is the 32-byte frame); with room, construct at end() through the allocator
   reference and grow the size, otherwise take the slow insert path. Names provisional. */
struct Alloc_0009c864 {};
extern "C" {
unsigned *FUN_0009c9c8(void *v);
int *FUN_0009c9c0(void *v);
Alloc_0009c864 &FUN_0009c9a4(void *v);
void FUN_0009c90c(int *p, Alloc_0009c864 &alloc, const int &x);
void FUN_0009c8ec(void *v, const int &x);
}
struct Less_0009c864 { bool operator()(const unsigned &a, const unsigned &b) const { return a < b; } };
struct Vec_0009c864 { int *data; unsigned size; };
extern "C" void FUN_0009c864(Vec_0009c864 *v, const int &x)
{
    unsigned size = v->size;
    if (Less_0009c864()(size, *FUN_0009c9c8(v))) {
        int *end = FUN_0009c9c0(v);
        FUN_0009c90c(end, FUN_0009c9a4(v), x);
        v->size++;
    } else {
        FUN_0009c8ec(v, x);
    }
}
