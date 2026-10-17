/* HSTMATCH module=EBOOT.BIN start=0x000edc6c end=0x000edd50 symbol=FUN_000edc6c lang=c++ */
/* Container growth policy for a 24-byte element type (template instance, hsttmpl.py tag t1):
   max_size = 0xffffffff / sizeof(T); grow by 3/5 below max/3, by 1/2 below 2*max/3, else to max_size;
   never less than n. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_000edc6c(const T &a, const T &b) { return a < b ? b : a; }
struct Elem_000edc6c { int w[6]; };
struct Vec_000edc6c { Elem_000edc6c *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_000edc6c(Vec_000edc6c *v, unsigned n)
{
    const unsigned max_size = 0xffffffffu / sizeof(Elem_000edc6c);
    unsigned cap = v->capacity;
    if (max_size - cap < n)
        FUN_000043b4();
    if (cap < max_size / 3)
        return cap + Max_000edc6c((cap + 1) * 3 / 5, n);
    if (cap < max_size / 3 * 2)
        return cap + Max_000edc6c((cap + 1) / 2, n);
    return max_size;
}
