/* HSTMATCH module=EBOOT.BIN start=0x001a5bcc end=0x001a5c4c symbol=FUN_001a5bcc lang=c++ */
/* Clone of src/eboot/vec_assign_fill_000d8d4c.cpp (hstclone.py tag c31): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* vector<int>-style assign(n, x): grow (0xd9064) and reallocate (0xd9148) when n exceeds the capacity, then fill
   n copies from the start and set the size. The empty tag passed by value to the inline fill helper gives the
   32-byte frame. Names provisional. */
struct Vec_001a5bcc { int *data; unsigned size; unsigned capacity; };
extern "C" {
unsigned FUN_00054898(Vec_001a5bcc *v, unsigned n);
void FUN_001a6f68(Vec_001a5bcc *v, unsigned n, unsigned cap);
}
struct Tag_001a5bcc {};
inline void Fill_001a5bcc(int *p, unsigned n, const int &x, Tag_001a5bcc)
{
    for (; n != 0; --n)
        *p++ = x;
}
extern "C" void FUN_001a5bcc(Vec_001a5bcc *v, unsigned n, const int &x)
{
    if (v->capacity < n) {
        unsigned c = FUN_00054898(v, n - v->capacity);
        FUN_001a6f68(v, n, c);
    }
    Fill_001a5bcc(v->data, n, x, Tag_001a5bcc());
    v->size = n;
}
