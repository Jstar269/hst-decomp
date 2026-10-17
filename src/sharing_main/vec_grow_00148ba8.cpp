/* HSTMATCH module=hstp_trans_main.prx start=0x00148ba8 end=0x00148c8c symbol=FUN_00148ba8 lang=c++ */
/* Clone of src/eboot/vec_grow_00048c78.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Container growth policy: new capacity for n more elements (length error past max_size 0x3fffffff).
   max() returns a const reference, so n and the computed sizes live on the stack. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_00148ba8(const T &a, const T &b) { return a < b ? b : a; }
struct Vec_00148ba8 { void *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_00148ba8(Vec_00148ba8 *v, unsigned n)
{
    unsigned cap = v->capacity;
    if (0x3fffffff - cap < n)
        FUN_000043b4();
    if (cap < 0x15555555)
        return cap + Max_00148ba8((cap + 1) * 3 / 5, n);
    if (cap < 0x2aaaaaaa)
        return cap + Max_00148ba8((cap + 1) / 2, n);
    return 0x3fffffff;
}
