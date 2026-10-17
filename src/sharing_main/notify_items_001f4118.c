/* HSTMATCH module=hstp_trans_main.prx start=0x001f4118 end=0x001f4168 symbol=FUN_001f4118 lang=c99 */
/* Clone of src/eboot/notify_items_001e5f00.c (hstclone.py tag u5fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: declaration order and loop pointer; exact match verified; names and types await human review. */

struct Obj {
    char pad_00[0x1adc];
    void *items[21];
};

extern void FUN_00108f54(void *, int);

void FUN_001f4118(struct Obj *param_1)
{
    int i;
    char *p = (char *)param_1;
    for (i = 0; i < 21; i++, p += 4) {
        void *item = *(void **)(p + 0x1adc);
        if (item != 0) {
            FUN_00108f54(item, 1);
        }
    }
}
