/* HSTMATCH module=hstp_trans_main.prx start=0x0017268c end=0x00172770 symbol=FUN_0017268c lang=c++ */
/* Clone of src/eboot/vec_grow_001664c8.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Container growth policy for a 20-byte element type (template instance, hsttmpl.py tag t1):
   max_size = 0xffffffff / sizeof(T); grow by 3/5 below max/3, by 1/2 below 2*max/3, else to max_size;
   never less than n. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_0017268c(const T &a, const T &b) { return a < b ? b : a; }
struct Elem_0017268c { int w[5]; };
struct Vec_0017268c { Elem_0017268c *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_0017268c(Vec_0017268c *v, unsigned n)
{
    const unsigned max_size = 0xffffffffu / sizeof(Elem_0017268c);
    unsigned cap = v->capacity;
    if (max_size - cap < n)
        FUN_000043b4();
    if (cap < max_size / 3)
        return cap + Max_0017268c((cap + 1) * 3 / 5, n);
    if (cap < max_size / 3 * 2)
        return cap + Max_0017268c((cap + 1) / 2, n);
    return max_size;
}
