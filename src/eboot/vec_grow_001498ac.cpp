/* HSTMATCH module=EBOOT.BIN start=0x001498ac end=0x00149990 symbol=FUN_001498ac lang=c++ */
/* Container growth policy for a 48-byte element type (template instance, hsttmpl.py tag t1):
   max_size = 0xffffffff / sizeof(T); grow by 3/5 below max/3, by 1/2 below 2*max/3, else to max_size;
   never less than n. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_001498ac(const T &a, const T &b) { return a < b ? b : a; }
struct Elem_001498ac { int w[12]; };
struct Vec_001498ac { Elem_001498ac *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_001498ac(Vec_001498ac *v, unsigned n)
{
    const unsigned max_size = 0xffffffffu / sizeof(Elem_001498ac);
    unsigned cap = v->capacity;
    if (max_size - cap < n)
        FUN_000043b4();
    if (cap < max_size / 3)
        return cap + Max_001498ac((cap + 1) * 3 / 5, n);
    if (cap < max_size / 3 * 2)
        return cap + Max_001498ac((cap + 1) / 2, n);
    return max_size;
}
