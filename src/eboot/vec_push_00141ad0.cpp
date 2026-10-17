/* HSTMATCH module=EBOOT.BIN start=0x00141ad0 end=0x00141b58 symbol=FUN_00141ad0 lang=c++ */
/* Clone of src/eboot/vec_push_0009c864.cpp (hstclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Container push_back with out-of-line helpers: compare size against *capacity_ptr() through a less<>
   functor temporary (its slot is the 32-byte frame); with room, construct at end() through the allocator
   reference and grow the size, otherwise take the slow insert path. Names provisional. */
struct Alloc_00141ad0 {};
extern "C" {
unsigned *FUN_00141c34(void *v);
int *FUN_00141c2c(void *v);
Alloc_00141ad0 &FUN_00141c10(void *v);
void FUN_00141b78(int *p, Alloc_00141ad0 &alloc, const int &x);
void FUN_00141b58(void *v, const int &x);
}
struct Less_00141ad0 { bool operator()(const unsigned &a, const unsigned &b) const { return a < b; } };
struct Vec_00141ad0 { int *data; unsigned size; };
extern "C" void FUN_00141ad0(Vec_00141ad0 *v, const int &x)
{
    unsigned size = v->size;
    if (Less_00141ad0()(size, *FUN_00141c34(v))) {
        int *end = FUN_00141c2c(v);
        FUN_00141b78(end, FUN_00141c10(v), x);
        v->size++;
    } else {
        FUN_00141b58(v, x);
    }
}
