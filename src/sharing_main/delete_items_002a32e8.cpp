/* HSTMATCH module=hstp_trans_main.prx start=0x002a32e8 end=0x002a334c symbol=FUN_002a32e8 lang=c++ */
/* Clone of src/eboot/delete_items_00291cdc.cpp (hstclone.py tag u5fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: declaration order and loop pointer; exact match verified; names and types await human review. */

struct VC_0 { virtual ~VC_0(); };

struct Obj {
    char pad_00[0x18];
    VC_0 *items[7];
};

extern "C" void FUN_002a32e8(struct Obj *param_1)
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
