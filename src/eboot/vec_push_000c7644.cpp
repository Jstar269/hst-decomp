/* HSTMATCH module=EBOOT.BIN start=0x000c7644 end=0x000c76cc symbol=FUN_000c7644 lang=c++ */
/* Clone of src/eboot/vec_push_0009c864.cpp (hstclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Container push_back with out-of-line helpers: compare size against *capacity_ptr() through a less<>
   functor temporary (its slot is the 32-byte frame); with room, construct at end() through the allocator
   reference and grow the size, otherwise take the slow insert path. Names provisional. */
struct Alloc_000c7644 {};
extern "C" {
unsigned *FUN_000c7774(void *v);
int *FUN_000c776c(void *v);
Alloc_000c7644 &FUN_000c7750(void *v);
void FUN_000c76ec(int *p, Alloc_000c7644 &alloc, const int &x);
void FUN_000c76cc(void *v, const int &x);
}
struct Less_000c7644 { bool operator()(const unsigned &a, const unsigned &b) const { return a < b; } };
struct Vec_000c7644 { int *data; unsigned size; };
extern "C" void FUN_000c7644(Vec_000c7644 *v, const int &x)
{
    unsigned size = v->size;
    if (Less_000c7644()(size, *FUN_000c7774(v))) {
        int *end = FUN_000c776c(v);
        FUN_000c76ec(end, FUN_000c7750(v), x);
        v->size++;
    } else {
        FUN_000c76cc(v, x);
    }
}
