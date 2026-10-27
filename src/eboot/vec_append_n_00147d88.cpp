/* HSTMATCH module=EBOOT.BIN start=0x00147d88 end=0x00147fec symbol=FUN_00147d88 lang=c++ */
/* Clone of src/sharing_main/vec_append_n_00153670.cpp (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (adapted from the EBOOT instance src/eboot/vec_append_n_001167fc.cpp: 32-byte element of five floats with a user memberwise copy constructor, Sharing reserve 0x156f70 and buffer destructor 0x1564f4); exact match verified; names and types await human review. */
/* Container append of n copies of x through a local split buffer (template instance, twin of EBOOT
   0x147d88): grow the capacity (1.6x below max/3, 1.5x below 2*max/3, else max_size; never less than
   needed), reserve through an inline chain that builds the char flag one level below reserve(),
   copy-construct n elements at the end, copy the old elements in front, swap buffers, destroy the buffer
   (its destructor called explicitly). The element's user copy constructor gives the per-field lwc1/swc1
   pairs (an implicit copy of the 16-aligned record is a 32-byte block copy). Names provisional. */
#pragma inline_depth(8)
extern "C" void FUN_000043b4(void);
inline void *operator new(unsigned, void *p) { return p; }
struct Flag_00147d88 { char v; Flag_00147d88(char x) : v(x) {} };
struct False_00147d88 {};
template <class T> inline const T &Max_00147d88(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_00147d88(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_00147d88 {
    float a, b, c, d, e;
    Elem_00147d88(const Elem_00147d88 &o) : a(o.a), b(o.b), c(o.c), d(o.d), e(o.e) {}
} __attribute__((aligned(16)));
struct Alloc_00147d88 {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_00147d88); }
    void construct(Elem_00147d88 *p, const Elem_00147d88 &x) { new (p) Elem_00147d88(x); }
};
struct Vec_00147d88 { Elem_00147d88 *data; unsigned size; unsigned capacity; };
class Buf_00147d88;
extern "C" {
void FUN_0014b688(Buf_00147d88 *buf, unsigned n, char f);
void FUN_0014ac0c(Buf_00147d88 *buf, int flag);
}
class Buf_00147d88 {
public:
    Elem_00147d88 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_00147d88(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_00147d88 f) { FUN_0014b688(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_00147d88(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
    void construct_at_end(unsigned n, const Elem_00147d88 &x, False_00147d88) {
        Elem_00147d88 *p = data + start + size;
        for (; n != 0; --n) {
            Alloc_00147d88().construct(p, x);
            ++p;
            ++size;
        }
    }
    void move_in_front(Elem_00147d88 *first, Elem_00147d88 *last, False_00147d88) {
        Elem_00147d88 *d = data + start;
        while (first < last) {
            --last;
            Alloc_00147d88().construct(--d, *last);
            --start;
            ++size;
        }
    }
};
inline unsigned MaxSize_00147d88() { return Alloc_00147d88().max_size(); }
static inline unsigned Grow_00147d88(Vec_00147d88 *v, unsigned need)
{
    const unsigned ms = MaxSize_00147d88();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_00147d88((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_00147d88((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_00147d88(Vec_00147d88 *v, unsigned n, const Elem_00147d88 &x)
{
    Buf_00147d88 buf(&v->capacity);
    buf.reserve(Grow_00147d88(v, v->size + n - v->capacity));
    buf.start = v->size;
    buf.construct_at_end(n, x, False_00147d88());
    buf.move_in_front(v->data, v->data + v->size, False_00147d88());
    Swap_00147d88(v->capacity, buf.capacity);
    Swap_00147d88(v->data, buf.data);
    Swap_00147d88(v->size, buf.size);
    FUN_0014ac0c(&buf, -1);
}
