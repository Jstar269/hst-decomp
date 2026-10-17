/* HSTMATCH module=EBOOT.BIN start=0x000cdb04 end=0x000cdb8c symbol=FUN_000cdb04 lang=c++ */
/* Clone of src/eboot/vec_push_0009c864.cpp (hstclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Container push_back with out-of-line helpers: compare size against *capacity_ptr() through a less<>
   functor temporary (its slot is the 32-byte frame); with room, construct at end() through the allocator
   reference and grow the size, otherwise take the slow insert path. Names provisional. */
struct Alloc_000cdb04 {};
extern "C" {
unsigned *FUN_000cdc58(void *v);
int *FUN_000cdc50(void *v);
Alloc_000cdb04 &FUN_000cdc3c(void *v);
void FUN_000cdbac(int *p, Alloc_000cdb04 &alloc, const int &x);
void FUN_000cdb8c(void *v, const int &x);
}
struct Less_000cdb04 { bool operator()(const unsigned &a, const unsigned &b) const { return a < b; } };
struct Vec_000cdb04 { int *data; unsigned size; };
extern "C" void FUN_000cdb04(Vec_000cdb04 *v, const int &x)
{
    unsigned size = v->size;
    if (Less_000cdb04()(size, *FUN_000cdc58(v))) {
        int *end = FUN_000cdc50(v);
        FUN_000cdbac(end, FUN_000cdc3c(v), x);
        v->size++;
    } else {
        FUN_000cdb8c(v, x);
    }
}
