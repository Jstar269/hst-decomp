/* HSTMATCH module=EBOOT.BIN start=0x0009c864 end=0x0009c8ec symbol=FUN_0009c864 lang=c++ */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Container push_back with out-of-line helpers: compare size against *capacity_ptr() through a less<>
   functor temporary (its slot is the 32-byte frame); with room, construct at end() through the allocator
   reference and grow the size, otherwise take the slow insert path. Names provisional. */
struct Alloc {};
extern "C" {
unsigned *FUN_0009c9c8(void *v);
int *FUN_0009c9c0(void *v);
Alloc &FUN_0009c9a4(void *v);
void FUN_0009c90c(int *p, Alloc &alloc, const int &x);
void FUN_0009c8ec(void *v, const int &x);
}
struct Less { bool operator()(const unsigned &a, const unsigned &b) const { return a < b; } };
struct Vec { int *data; unsigned size; };
extern "C" void FUN_0009c864(Vec *v, const int &x)
{
    unsigned size = v->size;
    if (Less()(size, *FUN_0009c9c8(v))) {
        int *end = FUN_0009c9c0(v);
        FUN_0009c90c(end, FUN_0009c9a4(v), x);
        v->size++;
    } else {
        FUN_0009c8ec(v, x);
    }
}
