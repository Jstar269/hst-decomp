/* HSTMATCH module=EBOOT.BIN start=0x000da7bc end=0x000da9dc symbol=FUN_000da7bc lang=c++ */
/* Hand-written reconstruction from the disassembly (adapted from the sibling split-buffer append recipe vec_append_000d8e34.cpp); exact match verified; names and types await human review. */
#pragma inline_depth(8)
extern "C" {
void FUN_000043b4(void);
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
struct ZeroTag;
void FUN_0005e9fc(void *buf, unsigned n, ZeroTag tag);
void FUN_0005e7d8(void *buf, int flag);
}
/* Empty tag type passed through the helpers. */
struct ZeroTag {};
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance(int *const &a, int *const &b) { return b - a; }
inline void Move(int *dst, int *src, unsigned bytes, ZeroTag) { FUN_00011090(dst, src, bytes); FUN_000114c0(src, 0, bytes); }
inline void Fill(int *p, unsigned n, ZeroTag) { FUN_000114c0(p, 0, n << 2); }
struct IntVec { int *data; int size; unsigned capacity; };
class SplitBuf {
public:
    int *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    SplitBuf(unsigned *a, ZeroTag) : data(0), size(0), capacity(0), alloc(a), start(0) {}
};
inline void Reserve2(SplitBuf *b, unsigned n, ZeroTag f) { FUN_0005e9fc(b, n, f); }
inline void Reserve(SplitBuf *b, unsigned n) { Reserve2(b, n, ZeroTag()); }
/* New capacity when `need` more elements do not fit: grows by 60% (or 50% for large vectors), capped at the maximum. */
static inline unsigned GrowCapacity(IntVec *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x3fffffff - cap < need)
        FUN_000043b4();
    if (cap < 0x15555555)
        return cap + Max((cap + 1) * 3 / 5, need);
    if (cap < 0x2aaaaaaa)
        return cap + Max((cap + 1) / 2, need);
    return 0x3fffffff;
}
/* Append n zeroed words to the vector, reallocating through a split buffer that takes over the old contents. */
extern "C" void FUN_000da7bc(IntVec *v, unsigned n)
{
    SplitBuf buf(&v->capacity, ZeroTag());
    unsigned need = v->size + n - v->capacity;
    Reserve(&buf, GrowCapacity(v, need));
    buf.start = v->size;
    Fill(buf.data + buf.start + buf.size, n, ZeroTag());
    buf.size += n;
    int *old = v->data;
    int count = Distance(old, old + v->size);
    buf.start -= count;
    Move(buf.data + buf.start, old, count * 4, ZeroTag());
    buf.size += count;
    v->size = 0;
    Swap(v->capacity, buf.capacity);
    Swap(v->data, buf.data);
    Swap(v->size, buf.size);
    FUN_0005e7d8(&buf, -1);
}
