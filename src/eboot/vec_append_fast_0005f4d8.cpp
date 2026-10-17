/* HSTMATCH module=EBOOT.BIN start=0x0005f4d8 end=0x0005f58c symbol=FUN_0005f4d8 lang=c++ */
/* Clone of src/eboot/vec_append_fast_000d8c98.cpp (hstclone.py tag c26): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Container append of n copies of x: if n exceeds the capacity or the free room, grow (0xd9064) and take the
   slow append path (0xd8e34); otherwise fill in place and bump the size. The greater<> functor temporary
   gives the 32-byte frame; `n > cap` (not `cap < n`) keeps the first test a plain `sltu at; bnez at`.
   Names provisional. */
extern "C" {
void FUN_0005fa78(void *v, unsigned need);
void FUN_0005f848(void *v, unsigned n, const int &x);
}
struct Greater_0005f4d8 { bool operator()(const unsigned &a, const unsigned &b) const { return a > b; } };
struct Vec_0005f4d8 { int *data; unsigned size; unsigned capacity; };
extern "C" void FUN_0005f4d8(Vec_0005f4d8 *v, unsigned n, const int &x)
{
    unsigned cap = v->capacity;
    if (Greater_0005f4d8()(n, cap) || cap - n < v->size) {
        FUN_0005fa78(v, v->size + n - cap);
    } else {
        int *p = v->data + v->size;
        for (unsigned i = n; i != 0; --i)
            *p++ = x;
        v->size += n;
        return;
    }
    FUN_0005f848(v, n, x);
}
