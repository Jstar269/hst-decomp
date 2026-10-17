/* HSTMATCH module=EBOOT.BIN start=0x0009156c end=0x00091650 symbol=FUN_0009156c lang=c++ */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Container growth policy for a 32-byte element type: max_size = 0xffffffff / sizeof(T); grow by 3/5 of
   the capacity below max/3, by 1/2 below 2*max/3, otherwise to max_size; never less than n.
   max() returns a const reference, so n and the computed sizes live on the stack. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_0009156c(const T &a, const T &b) { return a < b ? b : a; }
struct Elem_0009156c { int w[8]; };
struct Vec_0009156c { Elem_0009156c *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_0009156c(Vec_0009156c *v, unsigned n)
{
    const unsigned max_size = 0xffffffffu / sizeof(Elem_0009156c);
    unsigned cap = v->capacity;
    if (max_size - cap < n)
        FUN_000043b4();
    if (cap < max_size / 3)
        return cap + Max_0009156c((cap + 1) * 3 / 5, n);
    if (cap < max_size / 3 * 2)
        return cap + Max_0009156c((cap + 1) / 2, n);
    return max_size;
}
