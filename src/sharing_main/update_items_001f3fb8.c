/* HSTMATCH module=hstp_trans_main.prx start=0x001f3fb8 end=0x001f4008 symbol=FUN_001f3fb8 lang=c99 */
/* Clone of src/eboot/update_items_001e5da0.c (hstclone.py tag u5fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: declaration order and loop pointer; exact match verified; names and types await human review. */

struct SubObj {
    char pad_00[0x60];
    float f60;
};

struct Obj {
    char pad_00[0x1d6c];
    struct SubObj *items[5];
};

extern void FUN_00108558(struct SubObj *);

void FUN_001f3fb8(struct Obj *param_1)
{
    int i;
    char *p = (char *)param_1;
    for (i = 0; i < 5; i++, p += 4) {
        struct SubObj *sub = *(struct SubObj **)(p + 0x1d6c);
        sub->f60 = 350.0f;
        FUN_00108558(*(struct SubObj **)(p + 0x1d6c));
    }
}
