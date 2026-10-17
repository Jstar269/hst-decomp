/* HSTMATCH module=hstp_trans_main.prx start=0x002c7258 end=0x002c733c symbol=FUN_002c7258 lang=c++ */
/* Clone of src/eboot/vec_grow_0009156c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Container growth policy for a 32-byte element type: max_size = 0xffffffff / sizeof(T); grow by 3/5 of
   the capacity below max/3, by 1/2 below 2*max/3, otherwise to max_size; never less than n.
   max() returns a const reference, so n and the computed sizes live on the stack. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_002c7258(const T &a, const T &b) { return a < b ? b : a; }
struct Elem_002c7258 { int w[2]; };
struct Vec_002c7258 { Elem_002c7258 *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_002c7258(Vec_002c7258 *v, unsigned n)
{
    const unsigned max_size = 0xffffffffu / sizeof(Elem_002c7258);
    unsigned cap = v->capacity;
    if (max_size - cap < n)
        FUN_000043b4();
    if (cap < max_size / 3)
        return cap + Max_002c7258((cap + 1) * 3 / 5, n);
    if (cap < max_size / 3 * 2)
        return cap + Max_002c7258((cap + 1) / 2, n);
    return max_size;
}
