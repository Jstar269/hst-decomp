/* HSTMATCH module=hstp_trans_main.prx start=0x002464b8 end=0x00246540 symbol=FUN_002464b8 lang=c++ */
/* Clone of src/eboot/vec_push_00058594.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Container push_back with out-of-line helpers: compare size against *capacity_ptr() through a less<>
   functor temporary (its slot is the 32-byte frame); with room, construct at end() through the allocator
   reference and grow the size, otherwise take the slow insert path. Names provisional. */
struct Alloc_002464b8 {};
extern "C" {
unsigned *FUN_00246654(void *v);
int *FUN_0024664c(void *v);
Alloc_002464b8 &FUN_00246630(void *v);
void FUN_00246560(int *p, Alloc_002464b8 &alloc, const int &x);
void FUN_00246540(void *v, const int &x);
}
struct Less_002464b8 { bool operator()(const unsigned &a, const unsigned &b) const { return a < b; } };
struct Vec_002464b8 { int *data; unsigned size; };
extern "C" void FUN_002464b8(Vec_002464b8 *v, const int &x)
{
    unsigned size = v->size;
    if (Less_002464b8()(size, *FUN_00246654(v))) {
        int *end = FUN_0024664c(v);
        FUN_00246560(end, FUN_00246630(v), x);
        v->size++;
    } else {
        FUN_00246540(v, x);
    }
}
