/* HSTMATCH module=EBOOT.BIN start=0x000d6094 end=0x000d6178 symbol=FUN_000d6094 lang=c++ */
/* Clone of src/eboot/vec_grow_000b4c1c.cpp (hstclone.py tag c6): addresses substituted; exact match verified; names and types await human review. */
/* Container growth policy: new capacity for n more elements (length error past max_size 0x3fffffff).
   max() returns a const reference, so n and the computed sizes live on the stack. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_000d6094(const T &a, const T &b) { return a < b ? b : a; }
struct Vec_000d6094 { void *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_000d6094(Vec_000d6094 *v, unsigned n)
{
    unsigned cap = v->capacity;
    if (0x3fffffff - cap < n)
        FUN_000043b4();
    if (cap < 0x15555555)
        return cap + Max_000d6094((cap + 1) * 3 / 5, n);
    if (cap < 0x2aaaaaaa)
        return cap + Max_000d6094((cap + 1) / 2, n);
    return 0x3fffffff;
}
