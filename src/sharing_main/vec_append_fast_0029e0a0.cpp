/* HSTMATCH module=hstp_trans_main.prx start=0x0029e0a0 end=0x0029e154 symbol=FUN_0029e0a0 lang=c++ */
/* Clone of src/eboot/vec_append_fast_00059544.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Container append of n copies of x: if n exceeds the capacity or the free room, grow (0xd9064) and take the
   slow append path (0xd8e34); otherwise fill in place and bump the size. The greater<> functor temporary
   gives the 32-byte frame; `n > cap` (not `cap < n`) keeps the first test a plain `sltu at; bnez at`.
   Names provisional. */
extern "C" {
void FUN_0029ee04(void *v, unsigned need);
void FUN_0029ebd4(void *v, unsigned n, const int &x);
}
struct Greater_0029e0a0 { bool operator()(const unsigned &a, const unsigned &b) const { return a > b; } };
struct Vec_0029e0a0 { int *data; unsigned size; unsigned capacity; };
extern "C" void FUN_0029e0a0(Vec_0029e0a0 *v, unsigned n, const int &x)
{
    unsigned cap = v->capacity;
    if (Greater_0029e0a0()(n, cap) || cap - n < v->size) {
        FUN_0029ee04(v, v->size + n - cap);
    } else {
        int *p = v->data + v->size;
        for (unsigned i = n; i != 0; --i)
            *p++ = x;
        v->size += n;
        return;
    }
    FUN_0029ebd4(v, n, x);
}
