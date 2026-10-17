/* HSTMATCH module=hstp_trans_main.prx start=0x001b5724 end=0x001b5808 symbol=FUN_001b5724 lang=c++ */
/* Clone of src/eboot/vec_grow_0005e2c0.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Container growth policy for a 12-byte element type: max_size = 0xffffffff / sizeof(T); grow by 3/5 of
   the capacity below max/3, by 1/2 below 2*max/3, otherwise to max_size; never less than n.
   max() returns a const reference, so n and the computed sizes live on the stack. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_001b5724(const T &a, const T &b) { return a < b ? b : a; }
struct Elem_001b5724 { int w[3]; };
struct Vec_001b5724 { Elem_001b5724 *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_001b5724(Vec_001b5724 *v, unsigned n)
{
    const unsigned max_size = 0xffffffffu / sizeof(Elem_001b5724);
    unsigned cap = v->capacity;
    if (max_size - cap < n)
        FUN_000043b4();
    if (cap < max_size / 3)
        return cap + Max_001b5724((cap + 1) * 3 / 5, n);
    if (cap < max_size / 3 * 2)
        return cap + Max_001b5724((cap + 1) / 2, n);
    return max_size;
}
