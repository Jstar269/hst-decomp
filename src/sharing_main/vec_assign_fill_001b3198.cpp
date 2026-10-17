/* HSTMATCH module=hstp_trans_main.prx start=0x001b3198 end=0x001b3218 symbol=FUN_001b3198 lang=c++ */
/* Clone of src/eboot/vec_assign_fill_000d8d4c.cpp (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* vector<int>-style assign(n, x): grow (0xd9064) and reallocate (0xd9148) when n exceeds the capacity, then fill
   n copies from the start and set the size. The empty tag passed by value to the inline fill helper gives the
   32-byte frame. Names provisional. */
struct Vec_001b3198 { int *data; unsigned size; unsigned capacity; };
extern "C" {
unsigned FUN_000553e4(Vec_001b3198 *v, unsigned n);
void FUN_001b4534(Vec_001b3198 *v, unsigned n, unsigned cap);
}
struct Tag_001b3198 {};
inline void Fill_001b3198(int *p, unsigned n, const int &x, Tag_001b3198)
{
    for (; n != 0; --n)
        *p++ = x;
}
extern "C" void FUN_001b3198(Vec_001b3198 *v, unsigned n, const int &x)
{
    if (v->capacity < n) {
        unsigned c = FUN_000553e4(v, n - v->capacity);
        FUN_001b4534(v, n, c);
    }
    Fill_001b3198(v->data, n, x, Tag_001b3198());
    v->size = n;
}
