/* HSTMATCH module=hstp_trans_main.prx start=0x000ddf6c end=0x000de000 symbol=FUN_000ddf6c lang=c++ */
/* Clone of src/eboot/vec_append_zeros_000d9fac.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
void *FUN_000114c0(void *p, int c, unsigned n);
void FUN_0005ed58(void *v, unsigned need);
void FUN_000de77c(void *v, unsigned n);
}
struct Greater_000ddf6c { bool operator()(const unsigned &a, const unsigned &b) const { return a > b; } };
struct Vec_000ddf6c { int *data; unsigned size; unsigned capacity; };
extern "C" void FUN_000ddf6c(Vec_000ddf6c *v, unsigned n)
{
    unsigned cap = v->capacity;
    if (Greater_000ddf6c()(n, cap) || cap - n < v->size) {
        FUN_0005ed58(v, v->size + n - cap);
    } else {
        FUN_000114c0(v->data + v->size, 0, n << 2);
        v->size += n;
        return;
    }
    FUN_000de77c(v, n);
}
