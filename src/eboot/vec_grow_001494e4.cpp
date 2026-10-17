/* HSTMATCH module=EBOOT.BIN start=0x001494e4 end=0x001495c8 symbol=FUN_001494e4 lang=c++ */
/* Container growth policy for a 40-byte element type (template instance, hsttmpl.py tag t1):
   max_size = 0xffffffff / sizeof(T); grow by 3/5 below max/3, by 1/2 below 2*max/3, else to max_size;
   never less than n. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_001494e4(const T &a, const T &b) { return a < b ? b : a; }
struct Elem_001494e4 { int w[10]; };
struct Vec_001494e4 { Elem_001494e4 *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_001494e4(Vec_001494e4 *v, unsigned n)
{
    const unsigned max_size = 0xffffffffu / sizeof(Elem_001494e4);
    unsigned cap = v->capacity;
    if (max_size - cap < n)
        FUN_000043b4();
    if (cap < max_size / 3)
        return cap + Max_001494e4((cap + 1) * 3 / 5, n);
    if (cap < max_size / 3 * 2)
        return cap + Max_001494e4((cap + 1) / 2, n);
    return max_size;
}
