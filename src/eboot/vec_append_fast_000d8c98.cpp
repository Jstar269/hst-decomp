/* HSTMATCH module=EBOOT.BIN start=0x000d8c98 end=0x000d8d4c symbol=FUN_000d8c98 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Container append of n copies of x: if n exceeds the capacity or the free room, grow (0xd9064) and take the
   slow append path (0xd8e34); otherwise fill in place and bump the size. The greater<> functor temporary
   gives the 32-byte frame; `n > cap` (not `cap < n`) keeps the first test a plain `sltu at; bnez at`.
   Names provisional. */
extern "C" {
void FUN_000d9064(void *v, unsigned need);
void FUN_000d8e34(void *v, unsigned n, const int &x);
}
struct Greater_000d8c98 { bool operator()(const unsigned &a, const unsigned &b) const { return a > b; } };
struct Vec_000d8c98 { int *data; unsigned size; unsigned capacity; };
extern "C" void FUN_000d8c98(Vec_000d8c98 *v, unsigned n, const int &x)
{
    unsigned cap = v->capacity;
    if (Greater_000d8c98()(n, cap) || cap - n < v->size) {
        FUN_000d9064(v, v->size + n - cap);
    } else {
        int *p = v->data + v->size;
        for (unsigned i = n; i != 0; --i)
            *p++ = x;
        v->size += n;
        return;
    }
    FUN_000d8e34(v, n, x);
}
