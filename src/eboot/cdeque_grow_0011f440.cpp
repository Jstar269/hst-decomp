/* HSTMATCH module=EBOOT.BIN start=0x0011f440 end=0x0011f510 symbol=FUN_0011f440 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) growth helper: new capacity for n elements (called by push_back at
   0x11df6c). max_size() is the guarded function-local static of cdeque_reserve_0011dad8 (guard byte 0x33b492,
   value 0x2c1330; store-then-decrement keeps 0x3fffffff - 1 unfolded); start from capacity (1 when empty)
   and double until n fits, clamping at max_size(). `cap ? cap - 1 : 1` (not `cap == 0 ? 1 : cap - 1`) puts
   the 1 in retail's beqzl delay slot; `n > c` gives the sltu at loop test. Names provisional. */
extern "C" {
struct Reent_0011f440 { int pad[3]; void *err; };
Reent_0011f440 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
extern char DAT_002da188[]; /* "cdeque max_size error" */
extern char DAT_0033b492;     /* max_size() static guard */
extern unsigned DAT_002c1330; /* max_size() static value */
}
inline void Error_0011f440(const char *msg)
{
    FUN_0000f3e8(FUN_0000fe3c()->err, msg);
    FUN_0000d518();
}
struct Alloc_0011f440 {
    unsigned max_size() const { return 0x3fffffff; }
};
struct Cdeque_0011f440 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    int *data_;
    unsigned capacity() const { return cap_ == 0 ? 0 : cap_ - 1; }
    unsigned max_size() const
    {
        if (!DAT_0033b492) {
            DAT_002c1330 = Alloc_0011f440().max_size();
            --DAT_002c1330;
            DAT_0033b492 = 1;
        }
        return DAT_002c1330;
    }
};
extern "C" unsigned FUN_0011f440(const Cdeque_0011f440 *self, unsigned n)
{
    unsigned m = self->max_size();
    if (n > m)
        Error_0011f440(DAT_002da188);
    unsigned c = self->cap_ ? self->cap_ - 1 : 1;
    while (n > c)
        c = c < m / 2 ? 2 * c : m;
    return c;
}
