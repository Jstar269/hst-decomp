/* HSTMATCH module=EBOOT.BIN start=0x001e5f00 end=0x001e5f50 symbol=FUN_001e5f00 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: declaration order and loop pointer; exact match verified; names and types await human review. */

struct Obj {
    char pad_00[0x1adc];
    void *items[21];
};

extern void FUN_00103628(void *, int);

void FUN_001e5f00(struct Obj *param_1)
{
    int i;
    char *p = (char *)param_1;
    for (i = 0; i < 21; i++, p += 4) {
        void *item = *(void **)(p + 0x1adc);
        if (item != 0) {
            FUN_00103628(item, 1);
        }
    }
}
