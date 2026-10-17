/* HSTMATCH module=hstp_trans_main.prx start=0x0012a6e4 end=0x0012a7b4 symbol=FUN_0012a6e4 lang=c++ */
/* Clone of src/eboot/cdeque_grow_0011f440.cpp (hstclone.py tag c37): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) growth helper: new capacity for n elements (called by push_back at
   0x11df6c). max_size() is the guarded function-local static of cdeque_reserve_0011dad8 (guard byte 0x3e47d3,
   value 0x2d1714; store-then-decrement keeps 0x3fffffff - 1 unfolded); start from capacity (1 when empty)
   and double until n fits, clamping at max_size(). `cap ? cap - 1 : 1` (not `cap == 0 ? 1 : cap - 1`) puts
   the 1 in retail's beqzl delay slot; `n > c` gives the sltu at loop test. Names provisional. */
extern "C" {
struct Reent_0012a6e4 { int pad[3]; void *err; };
Reent_0012a6e4 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
extern char DAT_00381168[]; /* "cdeque max_size error" */
extern char DAT_003e47d3;     /* max_size() static guard */
extern unsigned DAT_002d1714; /* max_size() static value */
}
inline void Error_0012a6e4(const char *msg)
{
    FUN_0000f3e8(FUN_0000fe3c()->err, msg);
    FUN_0000d530();
}
struct Alloc_0012a6e4 {
    unsigned max_size() const { return 0x3fffffff; }
};
struct Cdeque_0012a6e4 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    int *data_;
    unsigned capacity() const { return cap_ == 0 ? 0 : cap_ - 1; }
    unsigned max_size() const
    {
        if (!DAT_003e47d3) {
            DAT_002d1714 = Alloc_0012a6e4().max_size();
            --DAT_002d1714;
            DAT_003e47d3 = 1;
        }
        return DAT_002d1714;
    }
};
extern "C" unsigned FUN_0012a6e4(const Cdeque_0012a6e4 *self, unsigned n)
{
    unsigned m = self->max_size();
    if (n > m)
        Error_0012a6e4(DAT_00381168);
    unsigned c = self->cap_ ? self->cap_ - 1 : 1;
    while (n > c)
        c = c < m / 2 ? 2 * c : m;
    return c;
}
