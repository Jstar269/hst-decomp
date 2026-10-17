/* HSTMATCH module=EBOOT.BIN start=0x000d8d4c end=0x000d8dcc symbol=FUN_000d8d4c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* vector<int>-style assign(n, x): grow (0xd9064) and reallocate (0xd9148) when n exceeds the capacity, then fill
   n copies from the start and set the size. The empty tag passed by value to the inline fill helper gives the
   32-byte frame. Names provisional. */
struct Vec_000d8d4c { int *data; unsigned size; unsigned capacity; };
extern "C" {
unsigned FUN_000d9064(Vec_000d8d4c *v, unsigned n);
void FUN_000d9148(Vec_000d8d4c *v, unsigned n, unsigned cap);
}
struct Tag_000d8d4c {};
inline void Fill_000d8d4c(int *p, unsigned n, const int &x, Tag_000d8d4c)
{
    for (; n != 0; --n)
        *p++ = x;
}
extern "C" void FUN_000d8d4c(Vec_000d8d4c *v, unsigned n, const int &x)
{
    if (v->capacity < n) {
        unsigned c = FUN_000d9064(v, n - v->capacity);
        FUN_000d9148(v, n, c);
    }
    Fill_000d8d4c(v->data, n, x, Tag_000d8d4c());
    v->size = n;
}
