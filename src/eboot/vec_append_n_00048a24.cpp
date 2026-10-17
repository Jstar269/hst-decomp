/* HSTMATCH module=EBOOT.BIN start=0x00048a24 end=0x00048c78 symbol=FUN_00048a24 lang=c++ */
/* Clone of src/eboot/vec_append_n_001167fc.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
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
struct Flag_00048a24 { char v; Flag_00048a24(char x) : v(x) {} };
struct False_00048a24 {};
template <class T> inline const T &Max_00048a24(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_00048a24(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_00048a24 { float x, y, z, w; };
struct Alloc_00048a24 {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_00048a24); }
    void construct(Elem_00048a24 *p, const Elem_00048a24 &x) { new (p) Elem_00048a24(x); }
};
struct Vec_00048a24 { Elem_00048a24 *data; unsigned size; unsigned capacity; };
class Buf_00048a24;
extern "C" {
void FUN_00048dd0(Buf_00048a24 *buf, unsigned n, char f);
void FUN_00048d5c(Buf_00048a24 *buf, int flag);
}
class Buf_00048a24 {
public:
    Elem_00048a24 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_00048a24(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_00048a24 f) { FUN_00048dd0(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_00048a24(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
    void construct_at_end(unsigned n, const Elem_00048a24 &x, False_00048a24) {
        Elem_00048a24 *p = data + start + size;
        for (; n != 0; --n) {
            Alloc_00048a24().construct(p, x);
            ++p;
            ++size;
        }
    }
    void move_in_front(Elem_00048a24 *first, Elem_00048a24 *last, False_00048a24) {
        Elem_00048a24 *d = data + start;
        while (first < last) {
            --last;
            Alloc_00048a24().construct(--d, *last);
            --start;
            ++size;
        }
    }
};
inline unsigned MaxSize_00048a24() { return Alloc_00048a24().max_size(); }
static inline unsigned Grow_00048a24(Vec_00048a24 *v, unsigned need)
{
    const unsigned ms = MaxSize_00048a24();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_00048a24((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_00048a24((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_00048a24(Vec_00048a24 *v, unsigned n, const Elem_00048a24 &x)
{
    Buf_00048a24 buf(&v->capacity);
    buf.reserve(Grow_00048a24(v, v->size + n - v->capacity));
    buf.start = v->size;
    buf.construct_at_end(n, x, False_00048a24());
    buf.move_in_front(v->data, v->data + v->size, False_00048a24());
    Swap_00048a24(v->capacity, buf.capacity);
    Swap_00048a24(v->data, buf.data);
    Swap_00048a24(v->size, buf.size);
    FUN_00048d5c(&buf, -1);
}
