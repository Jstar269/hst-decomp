/* HSTMATCH module=hstp_trans_main.prx start=0x00154dcc end=0x00154eb0 symbol=FUN_00154dcc lang=c++ */
/* Container growth policy for a 40-byte element type (template instance, hsttmpl.py tag t1s):
   max_size = 0xffffffff / sizeof(T); grow by 3/5 below max/3, by 1/2 below 2*max/3, else to max_size;
   never less than n. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_00154dcc(const T &a, const T &b) { return a < b ? b : a; }
struct Elem_00154dcc { int w[10]; };
struct Vec_00154dcc { Elem_00154dcc *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_00154dcc(Vec_00154dcc *v, unsigned n)
{
    const unsigned max_size = 0xffffffffu / sizeof(Elem_00154dcc);
    unsigned cap = v->capacity;
    if (max_size - cap < n)
        FUN_000043b4();
    if (cap < max_size / 3)
        return cap + Max_00154dcc((cap + 1) * 3 / 5, n);
    if (cap < max_size / 3 * 2)
        return cap + Max_00154dcc((cap + 1) / 2, n);
    return max_size;
}
