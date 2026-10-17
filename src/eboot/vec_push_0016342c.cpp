/* HSTMATCH module=EBOOT.BIN start=0x0016342c end=0x001634b4 symbol=FUN_0016342c lang=c++ */
/* Clone of src/eboot/vec_push_0009c864.cpp (hstclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Container push_back with out-of-line helpers: compare size against *capacity_ptr() through a less<>
   functor temporary (its slot is the 32-byte frame); with room, construct at end() through the allocator
   reference and grow the size, otherwise take the slow insert path. Names provisional. */
struct Alloc_0016342c {};
extern "C" {
unsigned *FUN_001639e4(void *v);
int *FUN_001639dc(void *v);
Alloc_0016342c &FUN_001639c0(void *v);
void FUN_001634d4(int *p, Alloc_0016342c &alloc, const int &x);
void FUN_001634b4(void *v, const int &x);
}
struct Less_0016342c { bool operator()(const unsigned &a, const unsigned &b) const { return a < b; } };
struct Vec_0016342c { int *data; unsigned size; };
extern "C" void FUN_0016342c(Vec_0016342c *v, const int &x)
{
    unsigned size = v->size;
    if (Less_0016342c()(size, *FUN_001639e4(v))) {
        int *end = FUN_001639dc(v);
        FUN_001634d4(end, FUN_001639c0(v), x);
        v->size++;
    } else {
        FUN_001634b4(v, x);
    }
}
