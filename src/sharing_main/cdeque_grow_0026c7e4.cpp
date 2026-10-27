/* HSTMATCH module=hstp_trans_main.prx start=0x0026c7e4 end=0x0026c8dc symbol=FUN_0026c7e4 lang=c++ data=0x003a642c */
/* Clone of src/eboot/cdeque_grow_00192a3c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x003a642c-0x003a6442) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) growth helper: new capacity for n elements (same shape as
   cdeque_grow_0011f440). Here max_size() is min(alloc.max_size(), 0x7fffffff) - 1 in a guarded local static;
   the allocator is an empty base (a0 = this passes straight to the out-of-line 0x192b34) and the 0x7fffffff
   bound comes from an inline function returning by value (a literal operand of the const& min() becomes a
   .data constant instead of retail's stack temporary). Names provisional. */
extern "C" {
struct Reent_0026c7e4 { int pad[3]; void *err; };
Reent_0026c7e4 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
extern char DAT_003f3af1;     /* max_size() static guard */
extern unsigned DAT_002dad74; /* max_size() static value */
}
inline void Error_0026c7e4(const char *msg)
{
    FUN_0000f3e8(FUN_0000fe3c()->err, msg);
    FUN_0000d530();
}
template <class T> inline const T &Min_0026c7e4(const T &a, const T &b) { return b < a ? b : a; }
inline unsigned Lim_0026c7e4() { return 0x7fffffff; }
struct Alloc_0026c7e4 {
    unsigned max_size() const;
};
extern "C" unsigned FUN_0026c8dc(const Alloc_0026c7e4 *);
inline unsigned Alloc_0026c7e4::max_size() const { return FUN_0026c8dc(this); }
struct Cdeque_0026c7e4 : Alloc_0026c7e4 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    int *data_;
    unsigned max_size() const
    {
        if (!DAT_003f3af1) {
            DAT_002dad74 = Min_0026c7e4(Alloc_0026c7e4::max_size(), Lim_0026c7e4()) - 1;
            DAT_003f3af1 = 1;
        }
        return DAT_002dad74;
    }
};
extern "C" unsigned FUN_0026c7e4(const Cdeque_0026c7e4 *self, unsigned n)
{
    unsigned m = self->max_size();
    if (n > m)
        Error_0026c7e4("cdeque max_size error");
    unsigned c = self->cap_ ? self->cap_ - 1 : 1;
    while (n > c)
        c = c < m / 2 ? 2 * c : m;
    return c;
}
