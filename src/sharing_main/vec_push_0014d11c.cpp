/* HSTMATCH module=hstp_trans_main.prx start=0x0014d11c end=0x0014d1a4 symbol=FUN_0014d11c lang=c++ */
/* Clone of src/eboot/vec_push_00058594.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Container push_back with out-of-line helpers: compare size against *capacity_ptr() through a less<>
   functor temporary (its slot is the 32-byte frame); with room, construct at end() through the allocator
   reference and grow the size, otherwise take the slow insert path. Names provisional. */
struct Alloc_0014d11c {};
extern "C" {
unsigned *FUN_0014d280(void *v);
int *FUN_0014d278(void *v);
Alloc_0014d11c &FUN_0014d25c(void *v);
void FUN_0014d1c4(int *p, Alloc_0014d11c &alloc, const int &x);
void FUN_0014d1a4(void *v, const int &x);
}
struct Less_0014d11c { bool operator()(const unsigned &a, const unsigned &b) const { return a < b; } };
struct Vec_0014d11c { int *data; unsigned size; };
extern "C" void FUN_0014d11c(Vec_0014d11c *v, const int &x)
{
    unsigned size = v->size;
    if (Less_0014d11c()(size, *FUN_0014d280(v))) {
        int *end = FUN_0014d278(v);
        FUN_0014d1c4(end, FUN_0014d25c(v), x);
        v->size++;
    } else {
        FUN_0014d1a4(v, x);
    }
}
