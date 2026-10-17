/* HSTMATCH module=hstp_trans_main.prx start=0x00248244 end=0x00248328 symbol=FUN_00248244 lang=c++ */
/* Clone of src/eboot/vec_grow_0023810c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Container growth policy for a 72-byte element type (template instance, hsttmpl.py tag t1):
   max_size = 0xffffffff / sizeof(T); grow by 3/5 below max/3, by 1/2 below 2*max/3, else to max_size;
   never less than n. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_00248244(const T &a, const T &b) { return a < b ? b : a; }
struct Elem_00248244 { int w[18]; };
struct Vec_00248244 { Elem_00248244 *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_00248244(Vec_00248244 *v, unsigned n)
{
    const unsigned max_size = 0xffffffffu / sizeof(Elem_00248244);
    unsigned cap = v->capacity;
    if (max_size - cap < n)
        FUN_000043b4();
    if (cap < max_size / 3)
        return cap + Max_00248244((cap + 1) * 3 / 5, n);
    if (cap < max_size / 3 * 2)
        return cap + Max_00248244((cap + 1) / 2, n);
    return max_size;
}
