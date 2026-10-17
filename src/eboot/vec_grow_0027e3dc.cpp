/* HSTMATCH module=EBOOT.BIN start=0x0027e3dc end=0x0027e4c0 symbol=FUN_0027e3dc lang=c++ */
/* Container growth policy for a 104-byte element type (template instance, hsttmpl.py tag t1):
   max_size = 0xffffffff / sizeof(T); grow by 3/5 below max/3, by 1/2 below 2*max/3, else to max_size;
   never less than n. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_0027e3dc(const T &a, const T &b) { return a < b ? b : a; }
struct Elem_0027e3dc { int w[26]; };
struct Vec_0027e3dc { Elem_0027e3dc *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_0027e3dc(Vec_0027e3dc *v, unsigned n)
{
    const unsigned max_size = 0xffffffffu / sizeof(Elem_0027e3dc);
    unsigned cap = v->capacity;
    if (max_size - cap < n)
        FUN_000043b4();
    if (cap < max_size / 3)
        return cap + Max_0027e3dc((cap + 1) * 3 / 5, n);
    if (cap < max_size / 3 * 2)
        return cap + Max_0027e3dc((cap + 1) / 2, n);
    return max_size;
}
