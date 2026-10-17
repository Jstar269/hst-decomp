/* HSTMATCH module=hstp_trans_main.prx start=0x001b45f4 end=0x001b46d8 symbol=FUN_001b45f4 lang=c++ */
/* Clone of src/eboot/vec_grow_001498ac.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Container growth policy for a 48-byte element type (template instance, hsttmpl.py tag t1):
   max_size = 0xffffffff / sizeof(T); grow by 3/5 below max/3, by 1/2 below 2*max/3, else to max_size;
   never less than n. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_001b45f4(const T &a, const T &b) { return a < b ? b : a; }
struct Elem_001b45f4 { int w[12]; };
struct Vec_001b45f4 { Elem_001b45f4 *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_001b45f4(Vec_001b45f4 *v, unsigned n)
{
    const unsigned max_size = 0xffffffffu / sizeof(Elem_001b45f4);
    unsigned cap = v->capacity;
    if (max_size - cap < n)
        FUN_000043b4();
    if (cap < max_size / 3)
        return cap + Max_001b45f4((cap + 1) * 3 / 5, n);
    if (cap < max_size / 3 * 2)
        return cap + Max_001b45f4((cap + 1) / 2, n);
    return max_size;
}
