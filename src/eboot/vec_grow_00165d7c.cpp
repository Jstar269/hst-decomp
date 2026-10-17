/* HSTMATCH module=EBOOT.BIN start=0x00165d7c end=0x00165e60 symbol=FUN_00165d7c lang=c++ */
/* Container growth policy for a 556-byte element type (template instance, hsttmpl.py tag t1):
   max_size = 0xffffffff / sizeof(T); grow by 3/5 below max/3, by 1/2 below 2*max/3, else to max_size;
   never less than n. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_00165d7c(const T &a, const T &b) { return a < b ? b : a; }
struct Elem_00165d7c { int w[139]; };
struct Vec_00165d7c { Elem_00165d7c *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_00165d7c(Vec_00165d7c *v, unsigned n)
{
    const unsigned max_size = 0xffffffffu / sizeof(Elem_00165d7c);
    unsigned cap = v->capacity;
    if (max_size - cap < n)
        FUN_000043b4();
    if (cap < max_size / 3)
        return cap + Max_00165d7c((cap + 1) * 3 / 5, n);
    if (cap < max_size / 3 * 2)
        return cap + Max_00165d7c((cap + 1) / 2, n);
    return max_size;
}
