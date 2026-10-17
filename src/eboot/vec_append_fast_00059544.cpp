/* HSTMATCH module=EBOOT.BIN start=0x00059544 end=0x000595f8 symbol=FUN_00059544 lang=c++ */
/* Clone of src/eboot/vec_append_fast_000d8c98.cpp (hstclone.py tag c26): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Container append of n copies of x: if n exceeds the capacity or the free room, grow (0xd9064) and take the
   slow append path (0xd8e34); otherwise fill in place and bump the size. The greater<> functor temporary
   gives the 32-byte frame; `n > cap` (not `cap < n`) keeps the first test a plain `sltu at; bnez at`.
   Names provisional. */
extern "C" {
void FUN_00059b60(void *v, unsigned need);
void FUN_00059930(void *v, unsigned n, const int &x);
}
struct Greater_00059544 { bool operator()(const unsigned &a, const unsigned &b) const { return a > b; } };
struct Vec_00059544 { int *data; unsigned size; unsigned capacity; };
extern "C" void FUN_00059544(Vec_00059544 *v, unsigned n, const int &x)
{
    unsigned cap = v->capacity;
    if (Greater_00059544()(n, cap) || cap - n < v->size) {
        FUN_00059b60(v, v->size + n - cap);
    } else {
        int *p = v->data + v->size;
        for (unsigned i = n; i != 0; --i)
            *p++ = x;
        v->size += n;
        return;
    }
    FUN_00059930(v, n, x);
}
