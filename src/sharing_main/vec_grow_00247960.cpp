/* HSTMATCH module=hstp_trans_main.prx start=0x00247960 end=0x00247a44 symbol=FUN_00247960 lang=c++ */
/* Clone of src/eboot/vec_grow_00237828.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Container growth policy for a 560-byte element type (template instance, hsttmpl.py tag t1):
   max_size = 0xffffffff / sizeof(T); grow by 3/5 below max/3, by 1/2 below 2*max/3, else to max_size;
   never less than n. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_00247960(const T &a, const T &b) { return a < b ? b : a; }
struct Elem_00247960 { int w[140]; };
struct Vec_00247960 { Elem_00247960 *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_00247960(Vec_00247960 *v, unsigned n)
{
    const unsigned max_size = 0xffffffffu / sizeof(Elem_00247960);
    unsigned cap = v->capacity;
    if (max_size - cap < n)
        FUN_000043b4();
    if (cap < max_size / 3)
        return cap + Max_00247960((cap + 1) * 3 / 5, n);
    if (cap < max_size / 3 * 2)
        return cap + Max_00247960((cap + 1) / 2, n);
    return max_size;
}
