/* HSTMATCH module=EBOOT.BIN start=0x000d8c98 end=0x000d8d4c symbol=FUN_000d8c98 lang=c++ */
extern "C" {
void FUN_000d9064(void *v, unsigned need);
void FUN_000d8e34(void *v, unsigned n, const int &x);
}
struct Less_000d8c98 { bool operator()(const unsigned &a, const unsigned &b) const { return a < b; } };
struct Vec_000d8c98 { int *data; unsigned size; unsigned capacity; };
extern "C" void FUN_000d8c98(Vec_000d8c98 *v, unsigned n, const int &x)
{
    unsigned cap = v->capacity;
    if (Less_000d8c98()(cap, n) || cap - n < v->size) {
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
// WIP (2026-10-15): 2 words from exact. Retail compares `cap < n` with `sltu at; bnez at`; this version uses
// `sltu v1; bnez v1` (the same with or without the Less functor, so it comes from the || lowering). The
// Less functor temporary gives the 32-byte frame. Tried by-value and int-returning functors, a named
// functor, goto forms and a bool flag. 6 clones wait on this.
// MATCHED (2026-10-15): EXACT as src/eboot/vec_append_fast_000d8c98.cpp; the first test is a greater<> functor, Greater()(n, cap). MWCC lowers `x < y` as the first || operand by materialising it (sltu v0/v1; bnez), but `y > x` / `y <= x` as sltu at; bnez at.
