/* HSTMATCH module=EBOOT.BIN start=0x00145af0 end=0x00145b78 symbol=FUN_00145af0 lang=c++ */
/* Clone of src/eboot/vec_push_0009c864.cpp (hstclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Container push_back with out-of-line helpers: compare size against *capacity_ptr() through a less<>
   functor temporary (its slot is the 32-byte frame); with room, construct at end() through the allocator
   reference and grow the size, otherwise take the slow insert path. Names provisional. */
struct Alloc_00145af0 {};
extern "C" {
unsigned *FUN_00145c54(void *v);
int *FUN_00145c4c(void *v);
Alloc_00145af0 &FUN_00145c30(void *v);
void FUN_00145b98(int *p, Alloc_00145af0 &alloc, const int &x);
void FUN_00145b78(void *v, const int &x);
}
struct Less_00145af0 { bool operator()(const unsigned &a, const unsigned &b) const { return a < b; } };
struct Vec_00145af0 { int *data; unsigned size; };
extern "C" void FUN_00145af0(Vec_00145af0 *v, const int &x)
{
    unsigned size = v->size;
    if (Less_00145af0()(size, *FUN_00145c54(v))) {
        int *end = FUN_00145c4c(v);
        FUN_00145b98(end, FUN_00145c30(v), x);
        v->size++;
    } else {
        FUN_00145b78(v, x);
    }
}
