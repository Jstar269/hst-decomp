/* HSTMATCH module=EBOOT.BIN start=0x002b74b8 end=0x002b759c symbol=FUN_002b74b8 lang=c++ */
/* Clone of src/eboot/vec_grow_0009156c.cpp (hstclone.py tag c15): addresses substituted; exact match verified; names and types await human review. */
/* Container growth policy for a 32-byte element type: max_size = 0xffffffff / sizeof(T); grow by 3/5 of
   the capacity below max/3, by 1/2 below 2*max/3, otherwise to max_size; never less than n.
   max() returns a const reference, so n and the computed sizes live on the stack. Names provisional. */
extern "C" void FUN_000043b4(void);
template <class T> inline const T &Max_002b74b8(const T &a, const T &b) { return a < b ? b : a; }
struct Elem_002b74b8 { int w[2]; };
struct Vec_002b74b8 { Elem_002b74b8 *data; unsigned size; unsigned capacity; };
extern "C" unsigned FUN_002b74b8(Vec_002b74b8 *v, unsigned n)
{
    const unsigned max_size = 0xffffffffu / sizeof(Elem_002b74b8);
    unsigned cap = v->capacity;
    if (max_size - cap < n)
        FUN_000043b4();
    if (cap < max_size / 3)
        return cap + Max_002b74b8((cap + 1) * 3 / 5, n);
    if (cap < max_size / 3 * 2)
        return cap + Max_002b74b8((cap + 1) / 2, n);
    return max_size;
}
