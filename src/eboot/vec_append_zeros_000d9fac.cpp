/* HSTMATCH module=EBOOT.BIN start=0x000d9fac end=0x000da040 symbol=FUN_000d9fac lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
void *FUN_000114c0(void *p, int c, unsigned n);
void FUN_0005df68(void *v, unsigned need);
void FUN_000da7bc(void *v, unsigned n);
}
struct Greater_000d9fac { bool operator()(const unsigned &a, const unsigned &b) const { return a > b; } };
struct Vec_000d9fac { int *data; unsigned size; unsigned capacity; };
extern "C" void FUN_000d9fac(Vec_000d9fac *v, unsigned n)
{
    unsigned cap = v->capacity;
    if (Greater_000d9fac()(n, cap) || cap - n < v->size) {
        FUN_0005df68(v, v->size + n - cap);
    } else {
        FUN_000114c0(v->data + v->size, 0, n << 2);
        v->size += n;
        return;
    }
    FUN_000da7bc(v, n);
}
