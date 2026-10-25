/* HSTMATCH module=EBOOT.BIN start=0x00224738 end=0x00224830 symbol=FUN_00224738 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

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
    int target = param_2;
    int i = 0;

    if (param_1->count > 0) {
        char *p = (char *)param_1;
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
        } while (i < param_1->count);
    }

    if (param_1->field_88 != 0) {
        void *res = FUN_001fea10(18, 32, param_1->field_90);
        FUN_00110a78(param_1->field_88, res, 0);
    }
}
