/* HSTMATCH module=EBOOT.BIN start=0x001b1c44 end=0x001b1d10 symbol=FUN_001b1c44 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/slot_lookup.h"

extern "C" SlotDef DAT_002e5fe8[];
extern "C" int FUN_00014a40(int);
extern "C" void FUN_000628b4(void *, int, int);
extern "C" int FUN_00062b64(void *, int, int);

/* Load definition `def_no` into its slot (court definitions are offset by the court sound index); -1 when the slot is out of range or empty. */
extern "C" int FUN_001b1c44(SlotTable **ctx, int def_no)
{
    SlotTable *table = *ctx;
    SlotDef *def = &DAT_002e5fe8[def_no];
    int id = def->id;

    if (def_no >= DEF_COURT_FIRST && def_no <= DEF_COURT_LAST)
        id += table->court_sound;
    bool ok = id < SLOT_COUNT;
    if (ok)
        ok = table->slot[id] != 0;
    if (!ok)
        return -1;
    {
        int r = FUN_00014a40(def->name);
        if (r == 0)
            FUN_000628b4(table->slot[id], 0, 0);
        return FUN_00062b64(table->slot[id], def->name, 0);
    }
}
