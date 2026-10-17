/* HSTMATCH module=EBOOT.BIN start=0x00058594 end=0x0005861c symbol=FUN_00058594 lang=c++ */
/* Clone of src/eboot/vec_push_0009c864.cpp (hstclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Container push_back with out-of-line helpers: compare size against *capacity_ptr() through a less<>
   functor temporary (its slot is the 32-byte frame); with room, construct at end() through the allocator
   reference and grow the size, otherwise take the slow insert path. Names provisional. */
struct Alloc_00058594 {};
extern "C" {
unsigned *FUN_00058740(void *v);
int *FUN_00058738(void *v);
Alloc_00058594 &FUN_0005871c(void *v);
void FUN_0005863c(int *p, Alloc_00058594 &alloc, const int &x);
void FUN_0005861c(void *v, const int &x);
}
struct Less_00058594 { bool operator()(const unsigned &a, const unsigned &b) const { return a < b; } };
struct Vec_00058594 { int *data; unsigned size; };
extern "C" void FUN_00058594(Vec_00058594 *v, const int &x)
{
    unsigned size = v->size;
    if (Less_00058594()(size, *FUN_00058740(v))) {
        int *end = FUN_00058738(v);
        FUN_0005863c(end, FUN_0005871c(v), x);
        v->size++;
    } else {
        FUN_0005861c(v, x);
    }
}
