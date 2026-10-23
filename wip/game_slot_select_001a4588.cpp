/* HSTMATCH module=EBOOT.BIN start=0x001a4588 end=0x001a4760 symbol=FUN_001a4588 lang=c++ */
// NEAR MISS 117/118 words.  Open delta: retail loads the slot count THREE times
// (0x1a45b4 v1 hoisted at entry, 0x1a469c v1 for `end`, 0x1a46a4 a2 for the
// <7 / index+2 / count-6 comparisons); this source lets MWCC CSE the 3rd read
// into the 2nd, so every word shifts by one and the a1/a2/v1 names differ.
// Ruled out: reading the body limit inline (hoisted and CSE'd), through a
// struct member (same), through a byte-offset cast, and two locals for the
// same load -- all still CSE.  Everything else matches: the frame (-48) needs
// the empty `False` by-value tag, and the `xor/sltiu/xori` loop test is the
// pointer-wrapper `Iter` class with `bool operator!=(const Iter &) const
// { return !(cur == o.cur); }` (MWCC-NOTES 0x102370); the RNG shift is
// `(DAT >> 0x10) & 0x7fff` (ext), and the slot is dereferenced twice.
struct False {};

struct SlotTable {
    char pad0[0x378];
    int **slots;
    int count;
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

    if (param_2 < 1 || 0x14 < param_2) {
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
    count = tbl->count;
    base = tbl->slots;
    end = base + count;
    index = 0;
    for (Iter it(base), last(end); it != last; ++it, index++) {
        if (**it == param_2) {
            if (tbl->count < 7) {
                *(int *)(param_1 + 0x2c0) = index;
                *(int *)(param_1 + 0x2c8) = 0;
            } else if (index + 2 < tbl->count) {
                if (index - 3 < 1) {
                    *(int *)(param_1 + 0x2c0) = index;
                    *(int *)(param_1 + 0x2c8) = 0;
                } else {
                    *(int *)(param_1 + 0x2c0) = 3;
                    *(int *)(param_1 + 0x2c8) = index - 3;
                }
            } else {
                t = tbl->count - 6;
                *(int *)(param_1 + 0x2c8) = t;
                *(int *)(param_1 + 0x2c0) = index - t;
            }
            *(int *)(param_1 + 0x2c4) = index;
            return;
        }
    }
}
// near miss from lane fm8 (unreviewed)
