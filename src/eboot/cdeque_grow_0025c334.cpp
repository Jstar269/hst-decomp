/* HSTMATCH module=EBOOT.BIN start=0x0025c334 end=0x0025c42c symbol=FUN_0025c334 lang=c++ */
/* Clone of src/eboot/cdeque_grow_00192a3c.cpp (hstclone.py tag c38): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) growth helper: new capacity for n elements (same shape as
   cdeque_grow_0011f440). Here max_size() is min(alloc.max_size(), 0x7fffffff) - 1 in a guarded local static;
   the allocator is an empty base (a0 = this passes straight to the out-of-line 0x192b34) and the 0x7fffffff
   bound comes from an inline function returning by value (a literal operand of the const& min() becomes a
   .data constant instead of retail's stack temporary). Names provisional. */
extern "C" {
struct Reent_0025c334 { int pad[3]; void *err; };
Reent_0025c334 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
extern char DAT_002fd884[]; /* "cdeque max_size error" */
extern char DAT_0034a7c1;     /* max_size() static guard */
extern unsigned DAT_002ca7b4; /* max_size() static value */
}
inline void Error_0025c334(const char *msg)
{
    FUN_0000f3e8(FUN_0000fe3c()->err, msg);
    FUN_0000d518();
}
template <class T> inline const T &Min_0025c334(const T &a, const T &b) { return b < a ? b : a; }
inline unsigned Lim_0025c334() { return 0x7fffffff; }
struct Alloc_0025c334 {
    unsigned max_size() const;
};
extern "C" unsigned FUN_0025c42c(const Alloc_0025c334 *);
inline unsigned Alloc_0025c334::max_size() const { return FUN_0025c42c(this); }
struct Cdeque_0025c334 : Alloc_0025c334 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    int *data_;
    unsigned max_size() const
    {
        if (!DAT_0034a7c1) {
            DAT_002ca7b4 = Min_0025c334(Alloc_0025c334::max_size(), Lim_0025c334()) - 1;
            DAT_0034a7c1 = 1;
        }
        return DAT_002ca7b4;
    }
};
extern "C" unsigned FUN_0025c334(const Cdeque_0025c334 *self, unsigned n)
{
    unsigned m = self->max_size();
    if (n > m)
        Error_0025c334(DAT_002fd884);
    unsigned c = self->cap_ ? self->cap_ - 1 : 1;
    while (n > c)
        c = c < m / 2 ? 2 * c : m;
    return c;
}
