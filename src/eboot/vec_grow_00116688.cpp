/* HSTMATCH module=EBOOT.BIN start=0x00116688 end=0x0011676c symbol=FUN_00116688 lang=c++ */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Container growth policy for a 12-byte element type: max_size = 0xffffffff / sizeof(T); grow by 3/5 of
   the capacity below max/3, by 1/2 below 2*max/3, otherwise to max_size; never less than n.
   max() returns a const reference, so n and the computed sizes live on the stack. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_00116688(const T &a, const T &b) { return a < b ? b : a; }
struct Elem_00116688 { int w[3]; };
struct Vec_00116688 { Elem_00116688 *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_00116688(Vec_00116688 *v, unsigned n)
{
    const unsigned max_size = 0xffffffffu / sizeof(Elem_00116688);
    unsigned cap = v->capacity;
    if (max_size - cap < n)
        FUN_000043b4();
    if (cap < max_size / 3)
        return cap + Max_00116688((cap + 1) * 3 / 5, n);
    if (cap < max_size / 3 * 2)
        return cap + Max_00116688((cap + 1) / 2, n);
    return max_size;
}
