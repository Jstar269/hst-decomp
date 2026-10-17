/* HSTMATCH module=hstp_trans_main.prx start=0x0029e450 end=0x0029e534 symbol=FUN_0029e450 lang=c++ */
/* Clone of src/eboot/vec_grow_0028cc88.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Container growth policy for a 96-byte element type (template instance, hsttmpl.py tag t1):
   max_size = 0xffffffff / sizeof(T); grow by 3/5 below max/3, by 1/2 below 2*max/3, else to max_size;
   never less than n. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_0029e450(const T &a, const T &b) { return a < b ? b : a; }
struct Elem_0029e450 { int w[24]; };
struct Vec_0029e450 { Elem_0029e450 *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_0029e450(Vec_0029e450 *v, unsigned n)
{
    const unsigned max_size = 0xffffffffu / sizeof(Elem_0029e450);
    unsigned cap = v->capacity;
    if (max_size - cap < n)
        FUN_000043b4();
    if (cap < max_size / 3)
        return cap + Max_0029e450((cap + 1) * 3 / 5, n);
    if (cap < max_size / 3 * 2)
        return cap + Max_0029e450((cap + 1) / 2, n);
    return max_size;
}
