/* HSTMATCH module=EBOOT.BIN start=0x00291cdc end=0x00291d40 symbol=FUN_00291cdc lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: declaration order and loop pointer; exact match verified; names and types await human review. */

struct VC_0 { virtual ~VC_0(); };

struct Obj {
    char pad_00[0x18];
    VC_0 *items[7];
};

extern "C" void FUN_00291cdc(struct Obj *param_1)
{
    int i;
    char *p = (char *)param_1;
    for (i = 0; i < 7; i++, p += 4) {
        VC_0 *item = *(VC_0 **)(p + 0x18);
        if (item != 0) {
            delete item;
            *(void **)(p + 0x18) = 0;
        }
    }
}
