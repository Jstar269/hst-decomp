/* HSTMATCH module=hstp_trans_main.prx start=0x001512c0 end=0x00151348 symbol=FUN_001512c0 lang=c++ */
/* Clone of src/eboot/vec_push_00058594.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Container push_back with out-of-line helpers: compare size against *capacity_ptr() through a less<>
   functor temporary (its slot is the 32-byte frame); with room, construct at end() through the allocator
   reference and grow the size, otherwise take the slow insert path. Names provisional. */
struct Alloc_001512c0 {};
extern "C" {
unsigned *FUN_00151424(void *v);
int *FUN_0015141c(void *v);
Alloc_001512c0 &FUN_00151400(void *v);
void FUN_00151368(int *p, Alloc_001512c0 &alloc, const int &x);
void FUN_00151348(void *v, const int &x);
}
struct Less_001512c0 { bool operator()(const unsigned &a, const unsigned &b) const { return a < b; } };
struct Vec_001512c0 { int *data; unsigned size; };
extern "C" void FUN_001512c0(Vec_001512c0 *v, const int &x)
{
    unsigned size = v->size;
    if (Less_001512c0()(size, *FUN_00151424(v))) {
        int *end = FUN_0015141c(v);
        FUN_00151368(end, FUN_00151400(v), x);
        v->size++;
    } else {
        FUN_00151348(v, x);
    }
}
