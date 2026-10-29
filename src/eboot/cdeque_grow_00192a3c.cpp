/* HSTMATCH module=EBOOT.BIN start=0x00192a3c end=0x00192b34 symbol=FUN_00192a3c lang=c++ data=0x002e13d4 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002e13d4-0x002e13ea) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* MSL-style circular deque (cdeque) growth helper: new capacity for n elements (same shape as
   cdeque_grow_0011f440). Here max_size() is min(alloc.max_size(), 0x7fffffff) - 1 in a guarded local static;
   the allocator is an empty base (a0 = this passes straight to the out-of-line 0x192b34) and the 0x7fffffff
   bound comes from an inline function returning by value (a literal operand of the const& min() becomes a
   .data constant instead of retail's stack temporary). Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0000f3e8(void *stream, const char *format, ...);
extern char DAT_003415d9;     /* max_size() static guard */
extern unsigned DAT_002c2784; /* max_size() static value */
}
inline void Error(const char *msg)
{
    FUN_0000f3e8(FUN_0000fe3c()->err, msg);
    FUN_0000d518();
}
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
inline unsigned Lim() { return 0x7fffffff; }
struct Alloc {
    unsigned max_size() const;
};
extern "C" unsigned FUN_00192b34(const Alloc *);
inline unsigned Alloc::max_size() const { return FUN_00192b34(this); }
struct Cdeque : Alloc {
    unsigned cap_;    /* 0x00 */
    unsigned size_;   /* 0x04 */
    unsigned start_;  /* 0x08 */
    int *data_;       /* 0x0c */
    unsigned max_size() const
    {
        if (!DAT_003415d9) {
            DAT_002c2784 = Min(Alloc::max_size(), Lim()) - 1;
            DAT_003415d9 = 1;
        }
        return DAT_002c2784;
    }
};
/* Smallest capacity (starting from the current one, doubling up to max_size) that holds want elements. */
extern "C" unsigned FUN_00192a3c(const Cdeque *self, unsigned want)
{
    unsigned limit = self->max_size();
    if (want > limit)
        Error("cdeque max_size error");
    unsigned cap = self->cap_ ? self->cap_ - 1 : 1;
    while (want > cap)
        cap = cap < limit / 2 ? 2 * cap : limit;
    return cap;
}
