/* HSTMATCH module=EBOOT.BIN start=0x001d1e6c end=0x001d1ec4 symbol=FUN_001d1e6c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: declaration order and loop pointer; exact match verified; names and types await human review. */

struct Obj {
    char pad_00[0x6c];
    void *items[2];
};

extern void FUN_000ffb3c(void *, int);

void FUN_001d1e6c(struct Obj *param_1, unsigned int param_2)
{
    unsigned int i;
    char *p = (char *)param_1;
    for (i = 0; i < 2; i++, p += 4) {
        FUN_000ffb3c(*(void **)(p + 0x6c), i != param_2);
    }
}
