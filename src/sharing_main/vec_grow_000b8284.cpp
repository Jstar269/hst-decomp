/* HSTMATCH module=hstp_trans_main.prx start=0x000b8284 end=0x000b8368 symbol=FUN_000b8284 lang=c++ */
/* Container growth policy for a 18-byte element type (template instance, hsttmpl.py tag t1s):
   max_size = 0xffffffff / sizeof(T); grow by 3/5 below max/3, by 1/2 below 2*max/3, else to max_size;
   never less than n. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_000b8284(const T &a, const T &b) { return a < b ? b : a; }
struct Elem_000b8284 { char b[18]; };
struct Vec_000b8284 { Elem_000b8284 *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_000b8284(Vec_000b8284 *v, unsigned n)
{
    const unsigned max_size = 0xffffffffu / sizeof(Elem_000b8284);
    unsigned cap = v->capacity;
    if (max_size - cap < n)
        FUN_000043b4();
    if (cap < max_size / 3)
        return cap + Max_000b8284((cap + 1) * 3 / 5, n);
    if (cap < max_size / 3 * 2)
        return cap + Max_000b8284((cap + 1) / 2, n);
    return max_size;
}
