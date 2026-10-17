/* HSTMATCH module=hstp_trans_main.prx start=0x000d1700 end=0x000d1788 symbol=FUN_000d1700 lang=c++ */
/* Clone of src/eboot/vec_push_00058594.cpp (hstclone.py tag x12): addresses substituted; exact match verified; names and types await human review. */
/* Container push_back with out-of-line helpers: compare size against *capacity_ptr() through a less<>
   functor temporary (its slot is the 32-byte frame); with room, construct at end() through the allocator
   reference and grow the size, otherwise take the slow insert path. Names provisional. */
struct Alloc_000d1700 {};
extern "C" {
unsigned *FUN_000d1854(void *v);
int *FUN_000d184c(void *v);
Alloc_000d1700 &FUN_000d1838(void *v);
void FUN_000d17a8(int *p, Alloc_000d1700 &alloc, const int &x);
void FUN_000d1788(void *v, const int &x);
}
struct Less_000d1700 { bool operator()(const unsigned &a, const unsigned &b) const { return a < b; } };
struct Vec_000d1700 { int *data; unsigned size; };
extern "C" void FUN_000d1700(Vec_000d1700 *v, const int &x)
{
    unsigned size = v->size;
    if (Less_000d1700()(size, *FUN_000d1854(v))) {
        int *end = FUN_000d184c(v);
        FUN_000d17a8(end, FUN_000d1838(v), x);
        v->size++;
    } else {
        FUN_000d1788(v, x);
    }
}
