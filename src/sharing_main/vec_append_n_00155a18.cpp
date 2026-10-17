/* HSTMATCH module=hstp_trans_main.prx start=0x00155a18 end=0x00155cac symbol=FUN_00155a18 lang=c++ */
/* Clone of src/eboot/vec_append_n_000e894c.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
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
struct Flag_00155a18 { char v; Flag_00155a18(char x) : v(x) {} };
struct False_00155a18 {};
template <class T> inline const T &Max_00155a18(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_00155a18(T &a, T &b) { T t = a; a = b; b = t; }
struct V4 { float x, y, z, w; V4(const V4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {} };
struct Elem_00155a18 { V4 a, b; };
struct Alloc_00155a18 {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_00155a18); }
    void construct(Elem_00155a18 *p, const Elem_00155a18 &x) { new (p) Elem_00155a18(x); }
};
struct Vec_00155a18 { Elem_00155a18 *data; unsigned size; unsigned capacity; };
class Buf_00155a18;
extern "C" {
void FUN_00156a54(Buf_00155a18 *buf, unsigned n, char f);
void FUN_001561d8(Buf_00155a18 *buf, int flag);
}
class Buf_00155a18 {
public:
    Elem_00155a18 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_00155a18(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_00155a18 f) { FUN_00156a54(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_00155a18(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
    void construct_at_end(unsigned n, const Elem_00155a18 &x, False_00155a18) {
        Elem_00155a18 *p = data + start + size;
        for (; n != 0; --n) {
            Alloc_00155a18().construct(p, x);
            ++p;
            ++size;
        }
    }
    void move_in_front(Elem_00155a18 *first, Elem_00155a18 *last, False_00155a18) {
        Elem_00155a18 *d = data + start;
        while (first < last) {
            --last;
            Alloc_00155a18().construct(--d, *last);
            --start;
            ++size;
        }
    }
};
inline unsigned MaxSize_00155a18() { return Alloc_00155a18().max_size(); }
static inline unsigned Grow_00155a18(Vec_00155a18 *v, unsigned need)
{
    const unsigned ms = MaxSize_00155a18();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_00155a18((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_00155a18((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_00155a18(Vec_00155a18 *v, unsigned n, const Elem_00155a18 &x)
{
    Buf_00155a18 buf(&v->capacity);
    buf.reserve(Grow_00155a18(v, v->size + n - v->capacity));
    buf.start = v->size;
    buf.construct_at_end(n, x, False_00155a18());
    buf.move_in_front(v->data, v->data + v->size, False_00155a18());
    Swap_00155a18(v->capacity, buf.capacity);
    Swap_00155a18(v->data, buf.data);
    Swap_00155a18(v->size, buf.size);
    FUN_001561d8(&buf, -1);
}
