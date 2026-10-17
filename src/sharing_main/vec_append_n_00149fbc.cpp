/* HSTMATCH module=hstp_trans_main.prx start=0x00149fbc end=0x0014a210 symbol=FUN_00149fbc lang=c++ */
/* Clone of src/eboot/vec_append_n_00048a24.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Container append of n copies of x through a local split buffer (template instance): grow the capacity
   (1.6x below max/3, 1.5x below 2*max/3, else max_size; never less than needed), reserve through an
   inline chain that builds the char flag one level below reserve() (so its slot follows the growth
   temporaries), copy-construct n elements at the end, copy the old elements in front, swap buffers,
   destroy the buffer (its destructor called explicitly). Empty tag and allocator temporaries only shape
   the frame: tags passed from this function sit right below the buffer, allocator temporaries in the
   inlined helpers next, then need, then the max() temporaries. Names provisional. */
#pragma inline_depth(8)
extern "C" void FUN_000043b4(void);
inline void *operator new(unsigned, void *p) { return p; }
struct Flag_00149fbc { char v; Flag_00149fbc(char x) : v(x) {} };
struct False_00149fbc {};
template <class T> inline const T &Max_00149fbc(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_00149fbc(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_00149fbc { float x, y, z, w; };
struct Alloc_00149fbc {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_00149fbc); }
    void construct(Elem_00149fbc *p, const Elem_00149fbc &x) { new (p) Elem_00149fbc(x); }
};
struct Vec_00149fbc { Elem_00149fbc *data; unsigned size; unsigned capacity; };
class Buf_00149fbc;
extern "C" {
void FUN_0014abd4(Buf_00149fbc *buf, unsigned n, char f);
void FUN_0014a6b8(Buf_00149fbc *buf, int flag);
}
class Buf_00149fbc {
public:
    Elem_00149fbc *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_00149fbc(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_00149fbc f) { FUN_0014abd4(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_00149fbc(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
    void construct_at_end(unsigned n, const Elem_00149fbc &x, False_00149fbc) {
        Elem_00149fbc *p = data + start + size;
        for (; n != 0; --n) {
            Alloc_00149fbc().construct(p, x);
            ++p;
            ++size;
        }
    }
    void move_in_front(Elem_00149fbc *first, Elem_00149fbc *last, False_00149fbc) {
        Elem_00149fbc *d = data + start;
        while (first < last) {
            --last;
            Alloc_00149fbc().construct(--d, *last);
            --start;
            ++size;
        }
    }
};
inline unsigned MaxSize_00149fbc() { return Alloc_00149fbc().max_size(); }
static inline unsigned Grow_00149fbc(Vec_00149fbc *v, unsigned need)
{
    const unsigned ms = MaxSize_00149fbc();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_00149fbc((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_00149fbc((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_00149fbc(Vec_00149fbc *v, unsigned n, const Elem_00149fbc &x)
{
    Buf_00149fbc buf(&v->capacity);
    buf.reserve(Grow_00149fbc(v, v->size + n - v->capacity));
    buf.start = v->size;
    buf.construct_at_end(n, x, False_00149fbc());
    buf.move_in_front(v->data, v->data + v->size, False_00149fbc());
    Swap_00149fbc(v->capacity, buf.capacity);
    Swap_00149fbc(v->data, buf.data);
    Swap_00149fbc(v->size, buf.size);
    FUN_0014a6b8(&buf, -1);
}
