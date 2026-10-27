/* HSTMATCH module=EBOOT.BIN start=0x000912e8 end=0x0009156c symbol=FUN_000912e8 lang=c++ */
/* Clone of src/sharing_main/vec_append_n_00092f80.cpp (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Same template as src/sharing_main/vec_append_n_000eda20.cpp with this instance's 32-byte element
   {int, unsigned char, int, 16-aligned Vec4}. Container append of n copies of x through a local split buffer (template instance): grow the capacity
   (1.6x below max/3, 1.5x below 2*max/3, else max_size; never less than needed), reserve through an
   inline chain that builds the char flag one level below reserve() (so its slot follows the growth
   temporaries), copy-construct n elements at the end, copy the old elements in front, swap buffers,
   destroy the buffer (its destructor called explicitly). Empty tag and allocator temporaries only shape
   the frame: tags passed from this function sit right below the buffer, allocator temporaries in the
   inlined helpers next, then need, then the max() temporaries. Names provisional. */
#pragma inline_depth(8)
extern "C" void FUN_000043b4(void);
inline void *operator new(unsigned, void *p) { return p; }
struct Flag_000912e8 { char v; Flag_000912e8(char x) : v(x) {} };
struct False_000912e8 {};
template <class T> inline const T &Max_000912e8(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_000912e8(T &a, T &b) { T t = a; a = b; b = t; }
struct V4 { float x, y, z, w; V4(const V4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {} } __attribute__((aligned(16)));
struct Elem_000912e8 { int a; unsigned char b; int c; V4 v; };
struct Alloc_000912e8 {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_000912e8); }
    void construct(Elem_000912e8 *p, const Elem_000912e8 &x) { new (p) Elem_000912e8(x); }
};
struct Vec_000912e8 { Elem_000912e8 *data; unsigned size; unsigned capacity; };
class Buf_000912e8;
extern "C" {
void FUN_00091764(Buf_000912e8 *buf, unsigned n, char f);
void FUN_000916d4(Buf_000912e8 *buf, int flag);
}
class Buf_000912e8 {
public:
    Elem_000912e8 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_000912e8(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_000912e8 f) { FUN_00091764(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_000912e8(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
    void construct_at_end(unsigned n, const Elem_000912e8 &x, False_000912e8) {
        Elem_000912e8 *p = data + start + size;
        for (; n != 0; --n) {
            Alloc_000912e8().construct(p, x);
            ++p;
            ++size;
        }
    }
    void move_in_front(Elem_000912e8 *first, Elem_000912e8 *last, False_000912e8) {
        Elem_000912e8 *d = data + start;
        while (first < last) {
            --last;
            Alloc_000912e8().construct(--d, *last);
            --start;
            ++size;
        }
    }
};
inline unsigned MaxSize_000912e8() { return Alloc_000912e8().max_size(); }
static inline unsigned Grow_000912e8(Vec_000912e8 *v, unsigned need)
{
    const unsigned ms = MaxSize_000912e8();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_000912e8((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_000912e8((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_000912e8(Vec_000912e8 *v, unsigned n, const Elem_000912e8 &x)
{
    Buf_000912e8 buf(&v->capacity);
    buf.reserve(Grow_000912e8(v, v->size + n - v->capacity));
    buf.start = v->size;
    buf.construct_at_end(n, x, False_000912e8());
    buf.move_in_front(v->data, v->data + v->size, False_000912e8());
    Swap_000912e8(v->capacity, buf.capacity);
    Swap_000912e8(v->data, buf.data);
    Swap_000912e8(v->size, buf.size);
    FUN_000916d4(&buf, -1);
}
