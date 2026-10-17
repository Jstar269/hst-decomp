/* HSTMATCH module=hstp_trans_main.prx start=0x002457b8 end=0x00245840 symbol=FUN_002457b8 lang=c++ */
/* Clone of src/eboot/vec_push_00058594.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Container push_back with out-of-line helpers: compare size against *capacity_ptr() through a less<>
   functor temporary (its slot is the 32-byte frame); with room, construct at end() through the allocator
   reference and grow the size, otherwise take the slow insert path. Names provisional. */
struct Alloc_002457b8 {};
extern "C" {
unsigned *FUN_00245d28(void *v);
int *FUN_00245d20(void *v);
Alloc_002457b8 &FUN_00245cfc(void *v);
void FUN_00245860(int *p, Alloc_002457b8 &alloc, const int &x);
void FUN_00245840(void *v, const int &x);
}
struct Less_002457b8 { bool operator()(const unsigned &a, const unsigned &b) const { return a < b; } };
struct Vec_002457b8 { int *data; unsigned size; };
extern "C" void FUN_002457b8(Vec_002457b8 *v, const int &x)
{
    unsigned size = v->size;
    if (Less_002457b8()(size, *FUN_00245d28(v))) {
        int *end = FUN_00245d20(v);
        FUN_00245860(end, FUN_00245cfc(v), x);
        v->size++;
    } else {
        FUN_00245840(v, x);
    }
}
