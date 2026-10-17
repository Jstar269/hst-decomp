/* HSTMATCH module=hstp_trans_main.prx start=0x0016f9b8 end=0x0016fa40 symbol=FUN_0016f9b8 lang=c++ */
/* Clone of src/eboot/vec_push_00058594.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Container push_back with out-of-line helpers: compare size against *capacity_ptr() through a less<>
   functor temporary (its slot is the 32-byte frame); with room, construct at end() through the allocator
   reference and grow the size, otherwise take the slow insert path. Names provisional. */
struct Alloc_0016f9b8 {};
extern "C" {
unsigned *FUN_0016ff70(void *v);
int *FUN_0016ff68(void *v);
Alloc_0016f9b8 &FUN_0016ff4c(void *v);
void FUN_0016fa60(int *p, Alloc_0016f9b8 &alloc, const int &x);
void FUN_0016fa40(void *v, const int &x);
}
struct Less_0016f9b8 { bool operator()(const unsigned &a, const unsigned &b) const { return a < b; } };
struct Vec_0016f9b8 { int *data; unsigned size; };
extern "C" void FUN_0016f9b8(Vec_0016f9b8 *v, const int &x)
{
    unsigned size = v->size;
    if (Less_0016f9b8()(size, *FUN_0016ff70(v))) {
        int *end = FUN_0016ff68(v);
        FUN_0016fa60(end, FUN_0016ff4c(v), x);
        v->size++;
    } else {
        FUN_0016fa40(v, x);
    }
}
