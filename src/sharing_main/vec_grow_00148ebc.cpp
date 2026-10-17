/* HSTMATCH module=hstp_trans_main.prx start=0x00148ebc end=0x00148fa0 symbol=FUN_00148ebc lang=c++ */
/* Clone of src/eboot/vec_grow_00048c78.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Container growth policy: new capacity for n more elements (length error past max_size 0x3fffffff).
   max() returns a const reference, so n and the computed sizes live on the stack. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_00148ebc(const T &a, const T &b) { return a < b ? b : a; }
struct Vec_00148ebc { void *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_00148ebc(Vec_00148ebc *v, unsigned n)
{
    unsigned cap = v->capacity;
    if (0x3fffffff - cap < n)
        FUN_000043b4();
    if (cap < 0x15555555)
        return cap + Max_00148ebc((cap + 1) * 3 / 5, n);
    if (cap < 0x2aaaaaaa)
        return cap + Max_00148ebc((cap + 1) / 2, n);
    return 0x3fffffff;
}
