/* HSTMATCH module=hstp_trans_main.prx start=0x0009ed90 end=0x0009ee18 symbol=FUN_0009ed90 lang=c++ */
/* Clone of src/eboot/vec_push_00058594.cpp (hstclone.py tag x12): addresses substituted; exact match verified; names and types await human review. */
/* Container push_back with out-of-line helpers: compare size against *capacity_ptr() through a less<>
   functor temporary (its slot is the 32-byte frame); with room, construct at end() through the allocator
   reference and grow the size, otherwise take the slow insert path. Names provisional. */
struct Alloc_0009ed90 {};
extern "C" {
unsigned *FUN_0009eef4(void *v);
int *FUN_0009eeec(void *v);
Alloc_0009ed90 &FUN_0009eed0(void *v);
void FUN_0009ee38(int *p, Alloc_0009ed90 &alloc, const int &x);
void FUN_0009ee18(void *v, const int &x);
}
struct Less_0009ed90 { bool operator()(const unsigned &a, const unsigned &b) const { return a < b; } };
struct Vec_0009ed90 { int *data; unsigned size; };
extern "C" void FUN_0009ed90(Vec_0009ed90 *v, const int &x)
{
    unsigned size = v->size;
    if (Less_0009ed90()(size, *FUN_0009eef4(v))) {
        int *end = FUN_0009eeec(v);
        FUN_0009ee38(end, FUN_0009eed0(v), x);
        v->size++;
    } else {
        FUN_0009ee18(v, x);
    }
}
