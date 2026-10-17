/* HSTMATCH module=hstp_trans_main.prx start=0x001498dc end=0x00149ba0 symbol=FUN_001498dc lang=c++ */
/* Clone of src/eboot/vec_append_n_001087e0.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
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
struct Flag_001498dc { char v; Flag_001498dc(char x) : v(x) {} };
struct False_001498dc {};
template <class T> inline const T &Max_001498dc(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_001498dc(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_001498dc { float f[9]; };
struct Alloc_001498dc {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_001498dc); }
    void construct(Elem_001498dc *p, const Elem_001498dc &x) { new (p) Elem_001498dc(x); }
};
struct Vec_001498dc { Elem_001498dc *data; unsigned size; unsigned capacity; };
class Buf_001498dc;
extern "C" {
void FUN_0014ad0c(Buf_001498dc *buf, unsigned n, char f);
void FUN_0014a790(Buf_001498dc *buf, int flag);
}
class Buf_001498dc {
public:
    Elem_001498dc *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_001498dc(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_001498dc f) { FUN_0014ad0c(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_001498dc(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
    void construct_at_end(unsigned n, const Elem_001498dc &x, False_001498dc) {
        Elem_001498dc *p = data + start + size;
        for (; n != 0; --n) {
            Alloc_001498dc().construct(p, x);
            ++p;
            ++size;
        }
    }
    void move_in_front(Elem_001498dc *first, Elem_001498dc *last, False_001498dc) {
        Elem_001498dc *d = data + start;
        while (first < last) {
            --last;
            Alloc_001498dc().construct(--d, *last);
            --start;
            ++size;
        }
    }
};
inline unsigned MaxSize_001498dc() { return Alloc_001498dc().max_size(); }
static inline unsigned Grow_001498dc(Vec_001498dc *v, unsigned need)
{
    const unsigned ms = MaxSize_001498dc();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_001498dc((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_001498dc((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_001498dc(Vec_001498dc *v, unsigned n, const Elem_001498dc &x)
{
    Buf_001498dc buf(&v->capacity);
    buf.reserve(Grow_001498dc(v, v->size + n - v->capacity));
    buf.start = v->size;
    buf.construct_at_end(n, x, False_001498dc());
    buf.move_in_front(v->data, v->data + v->size, False_001498dc());
    Swap_001498dc(v->capacity, buf.capacity);
    Swap_001498dc(v->data, buf.data);
    Swap_001498dc(v->size, buf.size);
    FUN_0014a790(&buf, -1);
}
