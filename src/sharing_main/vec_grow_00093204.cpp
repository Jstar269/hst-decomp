/* HSTMATCH module=hstp_trans_main.prx start=0x00093204 end=0x000932e8 symbol=FUN_00093204 lang=c++ */
/* Clone of src/eboot/vec_grow_0009156c.cpp (hstclone.py tag x5): addresses substituted; exact match verified; names and types await human review. */
/* Container growth policy for a 32-byte element type: max_size = 0xffffffff / sizeof(T); grow by 3/5 of
   the capacity below max/3, by 1/2 below 2*max/3, otherwise to max_size; never less than n.
   max() returns a const reference, so n and the computed sizes live on the stack. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_00093204(const T &a, const T &b) { return a < b ? b : a; }
struct Elem_00093204 { int w[8]; };
struct Vec_00093204 { Elem_00093204 *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_00093204(Vec_00093204 *v, unsigned n)
{
    const unsigned max_size = 0xffffffffu / sizeof(Elem_00093204);
    unsigned cap = v->capacity;
    if (max_size - cap < n)
        FUN_000043b4();
    if (cap < max_size / 3)
        return cap + Max_00093204((cap + 1) * 3 / 5, n);
    if (cap < max_size / 3 * 2)
        return cap + Max_00093204((cap + 1) / 2, n);
    return max_size;
}
