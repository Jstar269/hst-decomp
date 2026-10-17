/* HSTMATCH module=hstp_trans_main.prx start=0x001dfc70 end=0x001dfcc8 symbol=FUN_001dfc70 lang=c99 */
/* Clone of src/eboot/update_pair_001d1e6c.c (hstclone.py tag u5fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: declaration order and loop pointer; exact match verified; names and types await human review. */

struct Obj {
    char pad_00[0x6c];
    void *items[2];
};

extern void FUN_00105470(void *, int);

void FUN_001dfc70(struct Obj *param_1, unsigned int param_2)
{
    unsigned int i;
    char *p = (char *)param_1;
    for (i = 0; i < 2; i++, p += 4) {
        FUN_00105470(*(void **)(p + 0x6c), i != param_2);
    }
}
