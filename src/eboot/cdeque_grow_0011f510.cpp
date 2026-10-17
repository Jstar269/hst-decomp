/* HSTMATCH module=EBOOT.BIN start=0x0011f510 end=0x0011f5e0 symbol=FUN_0011f510 lang=c++ */
/* Clone of src/eboot/cdeque_grow_0011f440.cpp (hstclone.py tag c36): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) growth helper: new capacity for n elements (called by push_back at
   0x11df6c). max_size() is the guarded function-local static of cdeque_reserve_0011dad8 (guard byte 0x33b493,
   value 0x2c1334; store-then-decrement keeps 0x3fffffff - 1 unfolded); start from capacity (1 when empty)
   and double until n fits, clamping at max_size(). `cap ? cap - 1 : 1` (not `cap == 0 ? 1 : cap - 1`) puts
   the 1 in retail's beqzl delay slot; `n > c` gives the sltu at loop test. Names provisional. */
extern "C" {
struct Reent_0011f510 { int pad[3]; void *err; };
Reent_0011f510 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
extern char DAT_002da188[]; /* "cdeque max_size error" */
extern char DAT_0033b493;     /* max_size() static guard */
extern unsigned DAT_002c1334; /* max_size() static value */
}
inline void Error_0011f510(const char *msg)
{
    FUN_0000f3e8(FUN_0000fe3c()->err, msg);
    FUN_0000d518();
}
struct Alloc_0011f510 {
    unsigned max_size() const { return 0x3fffffff; }
};
struct Cdeque_0011f510 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    int *data_;
    unsigned capacity() const { return cap_ == 0 ? 0 : cap_ - 1; }
    unsigned max_size() const
    {
        if (!DAT_0033b493) {
            DAT_002c1334 = Alloc_0011f510().max_size();
            --DAT_002c1334;
            DAT_0033b493 = 1;
        }
        return DAT_002c1334;
    }
};
extern "C" unsigned FUN_0011f510(const Cdeque_0011f510 *self, unsigned n)
{
    unsigned m = self->max_size();
    if (n > m)
        Error_0011f510(DAT_002da188);
    unsigned c = self->cap_ ? self->cap_ - 1 : 1;
    while (n > c)
        c = c < m / 2 ? 2 * c : m;
    return c;
}
