/* HSTMATCH module=EBOOT.BIN start=0x002b4ac8 end=0x002b4bac symbol=FUN_002b4ac8 lang=c++ */
/* Container growth policy for a 100-byte element type (template instance, hsttmpl.py tag t1):
   max_size = 0xffffffff / sizeof(T); grow by 3/5 below max/3, by 1/2 below 2*max/3, else to max_size;
   never less than n. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_002b4ac8(const T &a, const T &b) { return a < b ? b : a; }
struct Elem_002b4ac8 { int w[25]; };
struct Vec_002b4ac8 { Elem_002b4ac8 *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_002b4ac8(Vec_002b4ac8 *v, unsigned n)
{
    const unsigned max_size = 0xffffffffu / sizeof(Elem_002b4ac8);
    unsigned cap = v->capacity;
    if (max_size - cap < n)
        FUN_000043b4();
    if (cap < max_size / 3)
        return cap + Max_002b4ac8((cap + 1) * 3 / 5, n);
    if (cap < max_size / 3 * 2)
        return cap + Max_002b4ac8((cap + 1) / 2, n);
    return max_size;
}
