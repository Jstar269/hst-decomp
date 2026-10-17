/* HSTMATCH module=EBOOT.BIN start=0x000b49ec end=0x000b4c1c symbol=FUN_000b49ec lang=c++ */
#pragma inline_depth(8)
/* Container append of n copies of *value through a local split buffer: grow, reserve, fill, move the old
   elements in front, clear the old storage, swap buffers; the buffer's destructor (0xb6320) frees the old
   block. Names provisional. */
extern "C" {
void FUN_000043b4(void);
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Flag_000b49ec { char v; Flag_000b49ec(char x) : v(x) {} };
template <class T> inline const T &Max_000b49ec(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_000b49ec(T &a, T &b) { T t = a; a = b; b = t; }
struct It_000b49ec { int *p; It_000b49ec(int *q) : p(q) {} };
inline int Distance_000b49ec(int *const &a, int *const &b) { return b - a; }
inline void FillN_000b49ec(int *p, int n, const int &x) { for (; n != 0; --n) *p++ = x; }
struct Vec_000b49ec { int *data; int size; unsigned capacity; };
class D_000b6320 {
public:
    int *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_000b6320(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    ~D_000b6320();
};
extern "C" void FUN_000b64e0(D_000b6320 *buf, unsigned n, char f);
inline void Reserve2_000b49ec(D_000b6320 *b, unsigned n, Flag_000b49ec f) { FUN_000b64e0(b, n, f.v); }
inline void Reserve_000b49ec(D_000b6320 *b, unsigned n) { Reserve2_000b49ec(b, n, Flag_000b49ec(0)); }
static inline unsigned Grow_000b49ec(Vec_000b49ec *v, const unsigned &need)
{
    unsigned cap = v->capacity;
    if (0x3fffffff - cap < need)
        FUN_000043b4();
    if (cap < 0x15555555)
        return cap + Max_000b49ec((cap + 1) * 3 / 5, need);
    if (cap < 0x2aaaaaaa)
        return cap + Max_000b49ec((cap + 1) / 2, need);
    return 0x3fffffff;
}
extern "C" void FUN_000b49ec(Vec_000b49ec *v, int n, const int *value)
{
    D_000b6320 buf(&v->capacity);
    unsigned need = v->size + n - v->capacity;
    Reserve_000b49ec(&buf, Grow_000b49ec(v, need));
    buf.start = v->size;
    FillN_000b49ec(buf.data + buf.start + buf.size, n, *value);
    buf.size += n;
    int *old = v->data;
    int count = Distance_000b49ec(old, old + v->size);
    buf.start -= count;
    FUN_00011090(buf.data + buf.start, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_000b49ec(v->capacity, buf.capacity);
    Swap_000b49ec(v->data, buf.data);
    Swap_000b49ec(v->size, buf.size);
}
// WIP (2026-10-15, try/exp-dtor/ap23): every instruction matches except stack offsets.
// - Retail frame 96: buf at 76, an unknown 16-byte object at 60..75, need at 56, max temporaries at 52/48.
// - This version, frame 80: buf at 60, need at 56, a 4-byte slot at 52, max temporaries at 48/44.
// - So retail creates a 16-byte object between the buffer and `need` (perhaps an allocator or iterator
//   temporary from the real split-buffer constructor) and lacks our 4-byte slot.
// - Needs `#pragma inline_depth(8)`; Distance takes pointers by const reference. 35 clones (19.6 KB)
//   plus their Sharing twins wait on this.
// 2026-10-15 later: a less<> functor temporary in the function itself also reserves a 16-byte slot (push_back 0x9c864 matched that way); adding Less() inside the inline grow() did not change this frame.
// More findings (2026-10-15 ~08:10Z):
// - Ghidra types `need` as `uint local_28[5]`: a 20-byte object at 56..75 whose first word is need. So the
//   unknown 16 bytes are probably part of one object with need, or a temporary right after it.
// - The same append exists for 18-byte elements (family 0xb4d00, 8 x 660 B). Crack this once, then add it to
//   tools/hsttmpl.py.
// - Ruled out: functor temporaries (inline or outer, incl. a discarded call), tag dispatch,
//   begin()/end() returning iterator structs, implicit iterator construction, allocator by value to the
//   buffer constructor.
// - Also ruled out: allocator/flag temporaries bound by const& to the buffer constructor; an iterator with a non-trivial destructor (by value).
// - Also ruled out: by-value iterators from begin()/end() (right 96-byte frame but FPU copies, as ap18), end()-begin() via operator-(const It&), tag objects created in the outer function.
// SOLVED (2026-10-15, try/agent-b49ec/z5 -> src/eboot/vec_append_000b49ec.cpp, EXACT):
// - The 16 bytes are four phantom 4-byte slots, one per by-value EMPTY tag temporary: reserve (E() inside
//   the inline Reserve, forwarded by value through Reserve2 to b64e0), fill, move-front and clear (v->size = 0
//   moved into an inline Clear(v, E())). Each inline helper takes the tag by value and ignores it.
// - Grow must take `need` BY VALUE (not const&): MWCC lays out named locals first, then class temporaries,
//   then inline by-value parameter copies (need), then const&-bound temporaries (max), then the forwarded
//   tag parameter copy in Reserve2 (a hidden 4-byte slot below the max temporaries, which is why the frame
//   reaches 96). Diagnostic trick: a named `int pad[k]` local reveals hidden slots via the frame size.
// Update (2026-10-15, agent-b49ec): src now uses the unified form (try/agent-b49ec/fb49ec): the 4th tag is a
//   by-value E() passed to the buffer CONSTRUCTOR instead of a Clear tag (plain `v->size = 0`); also EXACT.
// - Phase rule seen: phantom slots for tags created in the outer function or in a depth-1 inline body sit
//   above `need`; tags created/copied in depth-2 inline bodies (Reserve2's forwarded copy) sit below the max
//   temporaries.
// - 18-byte family 0xb4d00: EXACT with the same 4 tags (try/agent-b49ec/k4.cpp; generic placement-new loops,
//   move loop `--p; --last; new (p) T(*last);`, no clear). Needs symbol __dt__10D_000b54ecFv = 0x000b54ec.
// - 80-byte 0xb5088: EXACT (try/agent-b49ec/m12.cpp): ctor + reserve tags, but the fill/move tags are created
//   one inline level deeper (Wrapper -> Wrapper2 { FUN_000b52f4(..., E()) }), which moves them below the max
//   temporaries (8-byte gap). Needs symbol __dt__10D_000b5480Fv = 0x000b5480.
