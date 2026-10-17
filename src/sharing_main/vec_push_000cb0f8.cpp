/* HSTMATCH module=hstp_trans_main.prx start=0x000cb0f8 end=0x000cb180 symbol=FUN_000cb0f8 lang=c++ */
/* Clone of src/eboot/vec_push_00058594.cpp (hstclone.py tag x12): addresses substituted; exact match verified; names and types await human review. */
/* Container push_back with out-of-line helpers: compare size against *capacity_ptr() through a less<>
   functor temporary (its slot is the 32-byte frame); with room, construct at end() through the allocator
   reference and grow the size, otherwise take the slow insert path. Names provisional. */
struct Alloc_000cb0f8 {};
extern "C" {
unsigned *FUN_000cb228(void *v);
int *FUN_000cb220(void *v);
Alloc_000cb0f8 &FUN_000cb204(void *v);
void FUN_000cb1a0(int *p, Alloc_000cb0f8 &alloc, const int &x);
void FUN_000cb180(void *v, const int &x);
}
struct Less_000cb0f8 { bool operator()(const unsigned &a, const unsigned &b) const { return a < b; } };
struct Vec_000cb0f8 { int *data; unsigned size; };
extern "C" void FUN_000cb0f8(Vec_000cb0f8 *v, const int &x)
{
    unsigned size = v->size;
    if (Less_000cb0f8()(size, *FUN_000cb228(v))) {
        int *end = FUN_000cb220(v);
        FUN_000cb1a0(end, FUN_000cb204(v), x);
        v->size++;
    } else {
        FUN_000cb180(v, x);
    }
}
