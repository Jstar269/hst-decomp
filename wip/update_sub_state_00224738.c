/* HSTMATCH module=EBOOT.BIN start=0x00224738 end=0x00224830 symbol=FUN_00224738 lang=c99 */

struct Obj {
    char pad_00[0x68];
    void *sub[4];
    char pad_78[0x88 - 0x78];
    void *field_88;
    char pad_8c[4];
    int field_90;
    int count;
};

extern void FUN_000ffb3c(void *, int);
extern void FUN_00110a78(void *, void *, int);
extern void *FUN_001fea10(int, int, int);

void FUN_00224738(struct Obj *param_1, int param_2)
{
    char *p = (char *)param_1;
    struct Obj *self = param_1;
    int target = param_2;
    int i = 0;

    if (self->count > 0) {
        do {
            if (i == target) {
                FUN_000ffb3c(*(void **)(p + 0x68), 0);
                FUN_000ffb3c(*(void **)(p + 0x6c), 1);
                FUN_000ffb3c(*(void **)(p + 0x70), 0);
                FUN_000ffb3c(*(void **)(p + 0x74), 1);
            } else {
                FUN_000ffb3c(*(void **)(p + 0x68), 1);
                FUN_000ffb3c(*(void **)(p + 0x6c), 0);
                FUN_000ffb3c(*(void **)(p + 0x70), 1);
                FUN_000ffb3c(*(void **)(p + 0x74), 0);
            }
            i++;
            p += 16;
        } while (i < self->count);
    }

    if (self->field_88 != 0) {
        void *res = FUN_001fea10(18, 32, self->field_90);
        FUN_00110a78(self->field_88, res, 0);
    }
}
// Near miss: 20/62 words differ, purely a 4-way register permutation across s0..s3.
// Retail allocates: s0 = i (counter), s1 = param_2, s2 = param_1, s3 = p (pointer stride 16).
// Our best attempt gets s0 = i, s1 = p, s2 = param_2, s3 = param_1.
// Every opcode, branch displacement, struct offset, and jal target matches retail exactly.
// near miss from lane u5fr1-0 (unreviewed)
