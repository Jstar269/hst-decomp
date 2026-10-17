/* HSTMATCH module=hstp_trans_main.prx start=0x000602c8 end=0x0006037c symbol=FUN_000602c8 lang=c++ */
/* Clone of src/eboot/vec_append_fast_000d8c98.cpp (hstclone.py tag c24): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Container append of n copies of x: if n exceeds the capacity or the free room, grow (0xd9064) and take the
   slow append path (0xd8e34); otherwise fill in place and bump the size. The greater<> functor temporary
   gives the 32-byte frame; `n > cap` (not `cap < n`) keeps the first test a plain `sltu at; bnez at`.
   Names provisional. */
extern "C" {
void FUN_00060868(void *v, unsigned need);
void FUN_00060638(void *v, unsigned n, const int &x);
}
struct Greater_000602c8 { bool operator()(const unsigned &a, const unsigned &b) const { return a > b; } };
struct Vec_000602c8 { int *data; unsigned size; unsigned capacity; };
extern "C" void FUN_000602c8(Vec_000602c8 *v, unsigned n, const int &x)
{
    unsigned cap = v->capacity;
    if (Greater_000602c8()(n, cap) || cap - n < v->size) {
        FUN_00060868(v, v->size + n - cap);
    } else {
        int *p = v->data + v->size;
        for (unsigned i = n; i != 0; --i)
            *p++ = x;
        v->size += n;
        return;
    }
    FUN_00060638(v, n, x);
}
