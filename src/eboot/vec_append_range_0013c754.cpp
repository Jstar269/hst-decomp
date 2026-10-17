/* HSTMATCH module=EBOOT.BIN start=0x0013c754 end=0x0013c80c symbol=FUN_0013c754 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: reserve(n, Tag()) call (empty tag temporary) followed by a placement-new copy loop over 16-byte elements with a memberwise copy ctor (`beqzl p` per element, size re-read after each copy); exact match verified; names and types await human review. */
inline void *operator new(unsigned, void *p) { return p; }
struct Tag {};
struct Vec4 {
    float x, y, z, w;
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
};
struct Vec { Vec4 *data; int size; unsigned cap; };
extern "C" void FUN_0012cb38(Vec *, int, Tag);

extern "C" void FUN_0013c754(Vec *self, Vec4 *first, Vec4 *last)
{
    int n = ((char *)last - (char *)first) / 16;
    if (n != 0) {
        FUN_0012cb38(self, n, Tag());
        Vec4 *p = self->data + self->size;
        for (; first != last; ++first) {
            new (p) Vec4(*first);
            ++p;
            ++self->size;
        }
    }
}
