/* HSTMATCH module=EBOOT.BIN start=0x001b1d10 end=0x001b1e24 symbol=FUN_001b1d10 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag fm6 near miss, wip/select_target_001b1d10.cpp) corrected by hand: result computed in a local r and copied to the address-taken res before the r >= 0 test (matching idiom: the r/res split gives the single store in the bltz delay slot); range test written >= 0x1d && <= 0x74 (slti v0); readability pass; exact match verified; names and types await human review. */
#include "hst/slot_lookup.h"

extern "C" SlotDef DAT_002e5fe8[];
extern "C" int FUN_00014a40(int);
extern "C" void FUN_000628b4(void *, int, int);
extern "C" int FUN_00062b64(void *, int, int);
extern "C" void FUN_001b2218(SlotTable **, int *, int, int, int);

/* Load definition `def_no` into its slot (court definitions are offset by the court sound index); on success pass the result on. */
extern "C" int FUN_001b1d10(SlotTable **ctx, int def_no, int param_3, int param_4)
{
    SlotTable *table = *ctx;
    SlotDef *def = &DAT_002e5fe8[def_no];
    int idx = def->id;
    int res;

    if (def_no >= DEF_COURT_FIRST && def_no <= DEF_COURT_LAST)
        idx += table->court_sound;
    bool ok = idx < SLOT_COUNT && table->slot[idx];
    int r;
    if (!ok)
        r = -1;
    else {
        if (!FUN_00014a40(def->name))
            FUN_000628b4(table->slot[idx], 0, 0);
        r = FUN_00062b64(table->slot[idx], def->name, 0);
    }
    res = r;
    if (r >= 0)
        FUN_001b2218(ctx, &res, param_3, param_4, 0);
    return res;
}
