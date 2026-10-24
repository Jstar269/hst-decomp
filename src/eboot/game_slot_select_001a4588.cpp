/* HSTMATCH module=EBOOT.BIN start=0x001a4588 end=0x001a4760 symbol=FUN_001a4588 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
// matching idioms: empty `False` by-value tag parameter (48-byte frame); pointer-wrapper `Iter` with `!(cur == o.cur)` operator!=; the slot count is read twice (inline End() and a local `n` before the loop, int vs. inline getter) so MWCC keeps two loads; `int c = **it; if (c == param_2)` for the bnel operand order; the range test spelled `param_2 <= 0 || param_2 >= 0x15` (gives `slti v1`, the `0x14 < param_2` spelling gives `slti at`).
struct False {};

struct SlotTable {
    char pad0[0x378];
    int **slots;
    int count;
    int **Begin() { return slots; }
    int **End() { return slots + count; }
    int Count() const { return count; }
};

struct Iter {
    int **cur;
    Iter(int **p) { cur = p; }
    bool operator!=(const Iter &o) const { return !(cur == o.cur); }
    Iter &operator++() { cur++; return *this; }
    int *operator*() const { return *cur; }
};
extern "C" int FUN_0027edb4(int);
extern "C" int FUN_0027edbc(int, int);
extern "C" int DAT_00310fc8;
extern "C" int DAT_0034a7ec;

extern "C" void FUN_001a4588(int param_1, int param_2, False)
{
    int count;
    int index;
    int found;
    int i;
    int t;
    int **base;
    int **end;
    int **p;

    if (param_2 <= 0 || param_2 >= 0x15) {
        if (param_2 == 0) {
            if (*(unsigned char *)(param_1 + 0x4f) != 0) {
                found = 0;
                for (i = 0; i < FUN_0027edb4(DAT_0034a7ec); i++) {
                    int entry = FUN_0027edbc(DAT_0034a7ec, i);
                    if (entry != 0
                        && *(signed char *)(entry + *(int *)(param_1 + 0x54) + 0x12) == 2) {
                        found = 1;
                        param_2 = i;
                        break;
                    }
                }
                if (!found)
                    param_2 = 1;
            } else {
                DAT_00310fc8 = DAT_00310fc8 * 0x343fd + 0x269ec3;
                param_2 = **(int **)(*(int *)(param_1 + 0x378)
                    + (((DAT_00310fc8 >> 0x10) & 0x7fff) % *(unsigned int *)(param_1 + 0x37c)) * 4);
            }
        } else {
            param_2 = 1;
        }
    }
    SlotTable *tbl = (SlotTable *)param_1;
    int n = tbl->Count();
    index = 0;
    for (Iter it(tbl->Begin()), last(tbl->End()); it != last; ++it, index++) {
        int c = **it;
        if (c == param_2) {
            if (n < 7) {
                *(int *)(param_1 + 0x2c0) = index;
                *(int *)(param_1 + 0x2c8) = 0;
            } else if (index + 2 >= n) {
                t = n - 6;
                *(int *)(param_1 + 0x2c8) = t;
                *(int *)(param_1 + 0x2c0) = index - t;
            } else if (index - 3 < 1) {
                *(int *)(param_1 + 0x2c0) = index;
                *(int *)(param_1 + 0x2c8) = 0;
            } else {
                *(int *)(param_1 + 0x2c0) = 3;
                *(int *)(param_1 + 0x2c8) = index - 3;
            }
            *(int *)(param_1 + 0x2c4) = index;
            return;
        }
    }
}
