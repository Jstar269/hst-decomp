/* HSTMATCH module=hstp_trans_main.prx start=0x00171f6c end=0x00172050 symbol=FUN_00171f6c lang=c++ */
/* Clone of src/eboot/vec_grow_00165d7c.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Container growth policy for a 556-byte element type (template instance, hsttmpl.py tag t1):
   max_size = 0xffffffff / sizeof(T); grow by 3/5 below max/3, by 1/2 below 2*max/3, else to max_size;
   never less than n. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_00171f6c(const T &a, const T &b) { return a < b ? b : a; }
struct Elem_00171f6c { int w[139]; };
struct Vec_00171f6c { Elem_00171f6c *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_00171f6c(Vec_00171f6c *v, unsigned n)
{
    const unsigned max_size = 0xffffffffu / sizeof(Elem_00171f6c);
    unsigned cap = v->capacity;
    if (max_size - cap < n)
        FUN_000043b4();
    if (cap < max_size / 3)
        return cap + Max_00171f6c((cap + 1) * 3 / 5, n);
    if (cap < max_size / 3 * 2)
        return cap + Max_00171f6c((cap + 1) / 2, n);
    return max_size;
}
