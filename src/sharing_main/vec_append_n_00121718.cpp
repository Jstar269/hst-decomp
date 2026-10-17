/* HSTMATCH module=hstp_trans_main.prx start=0x00121718 end=0x0012196c symbol=FUN_00121718 lang=c++ */
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
struct Flag_00121718 { char v; Flag_00121718(char x) : v(x) {} };
struct False_00121718 {};
template <class T> inline const T &Max_00121718(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_00121718(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_00121718 { float x, y, z, w; };
struct Alloc_00121718 {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_00121718); }
    void construct(Elem_00121718 *p, const Elem_00121718 &x) { new (p) Elem_00121718(x); }
};
struct Vec_00121718 { Elem_00121718 *data; unsigned size; unsigned capacity; };
class Buf_00121718;
extern "C" {
void FUN_00121bf4(Buf_00121718 *buf, unsigned n, char f);
void FUN_00121ad4(Buf_00121718 *buf, int flag);
}
class Buf_00121718 {
public:
    Elem_00121718 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_00121718(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_00121718 f) { FUN_00121bf4(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_00121718(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
    void construct_at_end(unsigned n, const Elem_00121718 &x, False_00121718) {
        Elem_00121718 *p = data + start + size;
        for (; n != 0; --n) {
            Alloc_00121718().construct(p, x);
            ++p;
            ++size;
        }
    }
    void move_in_front(Elem_00121718 *first, Elem_00121718 *last, False_00121718) {
        Elem_00121718 *d = data + start;
        while (first < last) {
            --last;
            Alloc_00121718().construct(--d, *last);
            --start;
            ++size;
        }
    }
};
inline unsigned MaxSize_00121718() { return Alloc_00121718().max_size(); }
static inline unsigned Grow_00121718(Vec_00121718 *v, unsigned need)
{
    const unsigned ms = MaxSize_00121718();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_00121718((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_00121718((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_00121718(Vec_00121718 *v, unsigned n, const Elem_00121718 &x)
{
    Buf_00121718 buf(&v->capacity);
    buf.reserve(Grow_00121718(v, v->size + n - v->capacity));
    buf.start = v->size;
    buf.construct_at_end(n, x, False_00121718());
    buf.move_in_front(v->data, v->data + v->size, False_00121718());
    Swap_00121718(v->capacity, buf.capacity);
    Swap_00121718(v->data, buf.data);
    Swap_00121718(v->size, buf.size);
    FUN_00121ad4(&buf, -1);
}
