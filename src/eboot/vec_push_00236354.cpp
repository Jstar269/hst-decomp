/* HSTMATCH module=EBOOT.BIN start=0x00236354 end=0x002363dc symbol=FUN_00236354 lang=c++ */
/* Clone of src/eboot/vec_push_0009c864.cpp (hstclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Container push_back with out-of-line helpers: compare size against *capacity_ptr() through a less<>
   functor temporary (its slot is the 32-byte frame); with room, construct at end() through the allocator
   reference and grow the size, otherwise take the slow insert path. Names provisional. */
struct Alloc_00236354 {};
extern "C" {
unsigned *FUN_002364f0(void *v);
int *FUN_002364e8(void *v);
Alloc_00236354 &FUN_002364cc(void *v);
void FUN_002363fc(int *p, Alloc_00236354 &alloc, const int &x);
void FUN_002363dc(void *v, const int &x);
}
struct Less_00236354 { bool operator()(const unsigned &a, const unsigned &b) const { return a < b; } };
struct Vec_00236354 { int *data; unsigned size; };
extern "C" void FUN_00236354(Vec_00236354 *v, const int &x)
{
    unsigned size = v->size;
    if (Less_00236354()(size, *FUN_002364f0(v))) {
        int *end = FUN_002364e8(v);
        FUN_002363fc(end, FUN_002364cc(v), x);
        v->size++;
    } else {
        FUN_002363dc(v, x);
    }
}
