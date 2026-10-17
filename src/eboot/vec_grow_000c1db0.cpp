/* HSTMATCH module=EBOOT.BIN start=0x000c1db0 end=0x000c1e94 symbol=FUN_000c1db0 lang=c++ */
/* Container growth policy for a 80-byte element type (template instance, hsttmpl.py tag t1):
   max_size = 0xffffffff / sizeof(T); grow by 3/5 below max/3, by 1/2 below 2*max/3, else to max_size;
   never less than n. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_000c1db0(const T &a, const T &b) { return a < b ? b : a; }
struct Elem_000c1db0 { int w[20]; };
struct Vec_000c1db0 { Elem_000c1db0 *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_000c1db0(Vec_000c1db0 *v, unsigned n)
{
    const unsigned max_size = 0xffffffffu / sizeof(Elem_000c1db0);
    unsigned cap = v->capacity;
    if (max_size - cap < n)
        FUN_000043b4();
    if (cap < max_size / 3)
        return cap + Max_000c1db0((cap + 1) * 3 / 5, n);
    if (cap < max_size / 3 * 2)
        return cap + Max_000c1db0((cap + 1) / 2, n);
    return max_size;
}
