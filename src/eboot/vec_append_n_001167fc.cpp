/* HSTMATCH module=EBOOT.BIN start=0x001167fc end=0x00116a50 symbol=FUN_001167fc lang=c++ */
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
struct Flag_001167fc { char v; Flag_001167fc(char x) : v(x) {} };
struct False_001167fc {};
template <class T> inline const T &Max_001167fc(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_001167fc(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_001167fc { float x, y, z, w; };
struct Alloc_001167fc {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_001167fc); }
    void construct(Elem_001167fc *p, const Elem_001167fc &x) { new (p) Elem_001167fc(x); }
};
struct Vec_001167fc { Elem_001167fc *data; unsigned size; unsigned capacity; };
class Buf_001167fc;
extern "C" {
void FUN_00116cd8(Buf_001167fc *buf, unsigned n, char f);
void FUN_00116bb8(Buf_001167fc *buf, int flag);
}
class Buf_001167fc {
public:
    Elem_001167fc *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_001167fc(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_001167fc f) { FUN_00116cd8(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_001167fc(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
    void construct_at_end(unsigned n, const Elem_001167fc &x, False_001167fc) {
        Elem_001167fc *p = data + start + size;
        for (; n != 0; --n) {
            Alloc_001167fc().construct(p, x);
            ++p;
            ++size;
        }
    }
    void move_in_front(Elem_001167fc *first, Elem_001167fc *last, False_001167fc) {
        Elem_001167fc *d = data + start;
        while (first < last) {
            --last;
            Alloc_001167fc().construct(--d, *last);
            --start;
            ++size;
        }
    }
};
inline unsigned MaxSize_001167fc() { return Alloc_001167fc().max_size(); }
static inline unsigned Grow_001167fc(Vec_001167fc *v, unsigned need)
{
    const unsigned ms = MaxSize_001167fc();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_001167fc((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_001167fc((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_001167fc(Vec_001167fc *v, unsigned n, const Elem_001167fc &x)
{
    Buf_001167fc buf(&v->capacity);
    buf.reserve(Grow_001167fc(v, v->size + n - v->capacity));
    buf.start = v->size;
    buf.construct_at_end(n, x, False_001167fc());
    buf.move_in_front(v->data, v->data + v->size, False_001167fc());
    Swap_001167fc(v->capacity, buf.capacity);
    Swap_001167fc(v->data, buf.data);
    Swap_001167fc(v->size, buf.size);
    FUN_00116bb8(&buf, -1);
}
