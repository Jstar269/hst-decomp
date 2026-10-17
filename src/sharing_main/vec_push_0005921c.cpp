/* HSTMATCH module=hstp_trans_main.prx start=0x0005921c end=0x000592a4 symbol=FUN_0005921c lang=c++ */
/* Clone of src/eboot/vec_push_00058594.cpp (hstclone.py tag x12): addresses substituted; exact match verified; names and types await human review. */
/* Container push_back with out-of-line helpers: compare size against *capacity_ptr() through a less<>
   functor temporary (its slot is the 32-byte frame); with room, construct at end() through the allocator
   reference and grow the size, otherwise take the slow insert path. Names provisional. */
struct Alloc_0005921c {};
extern "C" {
unsigned *FUN_000593c8(void *v);
int *FUN_000593c0(void *v);
Alloc_0005921c &FUN_000593a4(void *v);
void FUN_000592c4(int *p, Alloc_0005921c &alloc, const int &x);
void FUN_000592a4(void *v, const int &x);
}
struct Less_0005921c { bool operator()(const unsigned &a, const unsigned &b) const { return a < b; } };
struct Vec_0005921c { int *data; unsigned size; };
extern "C" void FUN_0005921c(Vec_0005921c *v, const int &x)
{
    unsigned size = v->size;
    if (Less_0005921c()(size, *FUN_000593c8(v))) {
        int *end = FUN_000593c0(v);
        FUN_000592c4(end, FUN_000593a4(v), x);
        v->size++;
    } else {
        FUN_000592a4(v, x);
    }
}
