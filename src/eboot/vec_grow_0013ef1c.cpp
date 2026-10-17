/* HSTMATCH module=EBOOT.BIN start=0x0013ef1c end=0x0013f000 symbol=FUN_0013ef1c lang=c++ */
/* Clone of src/eboot/vec_grow_00116688.cpp (hstclone.py tag c15): addresses substituted; exact match verified; names and types await human review. */
/* Container growth policy for a 12-byte element type: max_size = 0xffffffff / sizeof(T); grow by 3/5 of
   the capacity below max/3, by 1/2 below 2*max/3, otherwise to max_size; never less than n.
   max() returns a const reference, so n and the computed sizes live on the stack. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_0013ef1c(const T &a, const T &b) { return a < b ? b : a; }
struct Elem_0013ef1c { int w[3]; };
struct Vec_0013ef1c { Elem_0013ef1c *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_0013ef1c(Vec_0013ef1c *v, unsigned n)
{
    const unsigned max_size = 0xffffffffu / sizeof(Elem_0013ef1c);
    unsigned cap = v->capacity;
    if (max_size - cap < n)
        FUN_000043b4();
    if (cap < max_size / 3)
        return cap + Max_0013ef1c((cap + 1) * 3 / 5, n);
    if (cap < max_size / 3 * 2)
        return cap + Max_0013ef1c((cap + 1) / 2, n);
    return max_size;
}
