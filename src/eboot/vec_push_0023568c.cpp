/* HSTMATCH module=EBOOT.BIN start=0x0023568c end=0x00235714 symbol=FUN_0023568c lang=c++ */
/* Clone of src/eboot/vec_push_0009c864.cpp (hstclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Container push_back with out-of-line helpers: compare size against *capacity_ptr() through a less<>
   functor temporary (its slot is the 32-byte frame); with room, construct at end() through the allocator
   reference and grow the size, otherwise take the slow insert path. Names provisional. */
struct Alloc_0023568c {};
extern "C" {
unsigned *FUN_00235bfc(void *v);
int *FUN_00235bf4(void *v);
Alloc_0023568c &FUN_00235bd0(void *v);
void FUN_00235734(int *p, Alloc_0023568c &alloc, const int &x);
void FUN_00235714(void *v, const int &x);
}
struct Less_0023568c { bool operator()(const unsigned &a, const unsigned &b) const { return a < b; } };
struct Vec_0023568c { int *data; unsigned size; };
extern "C" void FUN_0023568c(Vec_0023568c *v, const int &x)
{
    unsigned size = v->size;
    if (Less_0023568c()(size, *FUN_00235bfc(v))) {
        int *end = FUN_00235bf4(v);
        FUN_00235734(end, FUN_00235bd0(v), x);
        v->size++;
    } else {
        FUN_00235714(v, x);
    }
}
