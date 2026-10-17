/* HSTMATCH module=hstp_trans_main.prx start=0x0015552c end=0x00155610 symbol=FUN_0015552c lang=c++ */
/* Container growth policy for a 48-byte element type (template instance, hsttmpl.py tag t1s):
   max_size = 0xffffffff / sizeof(T); grow by 3/5 below max/3, by 1/2 below 2*max/3, else to max_size;
   never less than n. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_0015552c(const T &a, const T &b) { return a < b ? b : a; }
struct Elem_0015552c { int w[12]; };
struct Vec_0015552c { Elem_0015552c *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_0015552c(Vec_0015552c *v, unsigned n)
{
    const unsigned max_size = 0xffffffffu / sizeof(Elem_0015552c);
    unsigned cap = v->capacity;
    if (max_size - cap < n)
        FUN_000043b4();
    if (cap < max_size / 3)
        return cap + Max_0015552c((cap + 1) * 3 / 5, n);
    if (cap < max_size / 3 * 2)
        return cap + Max_0015552c((cap + 1) / 2, n);
    return max_size;
}
