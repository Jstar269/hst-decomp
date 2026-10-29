/* HSTMATCH module=EBOOT.BIN start=0x001b1e24 end=0x001b1f7c symbol=FUN_001b1e24 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/slot_lookup.h"

extern "C" SlotDef DAT_002e5fe8[];
extern "C" int FUN_00014a40(int);
extern "C" void FUN_000628b4(void *, int, int);
extern "C" int FUN_00062b64(void *, int, int);
extern "C" void FUN_001b2240(SlotTable **, int *, int, float, float, float, float,
                             int, int, int);

/* Load the definition's name into slot `idx`; -1 when the slot is out of range or empty. */
static inline int Load(SlotTable *table, int idx, SlotDef *def)
{
    bool ok = idx < SLOT_COUNT && table->slot[idx];
    if (!ok)
        return -1;
    if (!FUN_00014a40(def->name))
        FUN_000628b4(table->slot[idx], 0, 0);
    return FUN_00062b64(table->slot[idx], def->name, 0);
}

/* Like the plain selector, with four float arguments passed on to FUN_001b2240. */
extern "C" int FUN_001b1e24(SlotTable **ctx, int def_no, int param_3,
                            float f1, float f2, float f3, float f4, int param_4)
{
    SlotTable *table = *ctx;
    SlotDef *def = &DAT_002e5fe8[def_no];
    int idx = def->id;
    int res;

    if (def_no >= DEF_COURT_FIRST && def_no <= DEF_COURT_LAST)
        idx += table->court_sound;
    res = Load(table, idx, def);
    if (res >= 0)
        FUN_001b2240(ctx, &res, param_3, f1, f2, f3, f4, param_4, 0, 0);
    return res;
}
