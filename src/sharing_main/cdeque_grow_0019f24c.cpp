/* HSTMATCH module=hstp_trans_main.prx start=0x0019f24c end=0x0019f344 symbol=FUN_0019f24c lang=c++ */
/* Clone of src/eboot/cdeque_grow_00192a3c.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) growth helper: new capacity for n elements (same shape as
   cdeque_grow_0011f440). Here max_size() is min(alloc.max_size(), 0x7fffffff) - 1 in a guarded local static;
   the allocator is an empty base (a0 = this passes straight to the out-of-line 0x192b34) and the 0x7fffffff
   bound comes from an inline function returning by value (a literal operand of the const& min() becomes a
   .data constant instead of retail's stack temporary). Names provisional. */
extern "C" {
struct Reent_0019f24c { int pad[3]; void *err; };
Reent_0019f24c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
extern char DAT_00388ab0[]; /* "cdeque max_size error" */
extern char DAT_003ea919;     /* max_size() static guard */
extern unsigned DAT_002d2c84; /* max_size() static value */
}
inline void Error_0019f24c(const char *msg)
{
    FUN_0000f3e8(FUN_0000fe3c()->err, msg);
    FUN_0000d530();
}
template <class T> inline const T &Min_0019f24c(const T &a, const T &b) { return b < a ? b : a; }
inline unsigned Lim_0019f24c() { return 0x7fffffff; }
struct Alloc_0019f24c {
    unsigned max_size() const;
};
extern "C" unsigned FUN_0019f344(const Alloc_0019f24c *);
inline unsigned Alloc_0019f24c::max_size() const { return FUN_0019f344(this); }
struct Cdeque_0019f24c : Alloc_0019f24c {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    int *data_;
    unsigned max_size() const
    {
        if (!DAT_003ea919) {
            DAT_002d2c84 = Min_0019f24c(Alloc_0019f24c::max_size(), Lim_0019f24c()) - 1;
            DAT_003ea919 = 1;
        }
        return DAT_002d2c84;
    }
};
extern "C" unsigned FUN_0019f24c(const Cdeque_0019f24c *self, unsigned n)
{
    unsigned m = self->max_size();
    if (n > m)
        Error_0019f24c(DAT_00388ab0);
    unsigned c = self->cap_ ? self->cap_ - 1 : 1;
    while (n > c)
        c = c < m / 2 ? 2 * c : m;
    return c;
}
