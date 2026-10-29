/* HSTMATCH module=EBOOT.BIN start=0x00163f58 end=0x00164080 symbol=FUN_00163f58 lang=c99 */
/* Hand-written reconstruction from the disassembly (same chained-conditional clamp tail as 0x163aac, which is what lets MWCC duplicate the frame restore into the early return's branch delay); exact match verified; names and types await human review. */
#include "hst/stat_calc.h"

#define MOD_ID_NO_LIMIT 0x32 /* id / 10 value that returns the limit table's maximum directly */

extern StatRecTable *DAT_0034150c;
extern LimitTable *DAT_00341510;
extern float FUN_000d8334(StatMod *, int);

/* Stat 4 of a record plus the modifier's record and call result, clamped to the limit table's range. */
float FUN_00163f58(StatRec *rec, StatMod *mod)
{
    float v;
    float lo;
    float hi;

    if (mod != 0 && mod->id / 10 == MOD_ID_NO_LIMIT)
        return LIMIT_ROW_AT(DAT_00341510, DAT_00341510->count - 1)->v[4];
    v = rec->stat4;
    if (mod != 0) {
        if (mod->id >= 0)
            v += STAT_REC_AT(DAT_0034150c, mod->id)->stat4;
        v += FUN_000d8334(mod, 4);
    }
    lo = LIMIT_ROW_AT(DAT_00341510, 0)->v[4];
    hi = LIMIT_ROW_AT(DAT_00341510, DAT_00341510->count - 1)->v[4];
    return v < lo ? lo : v > hi ? hi : v;
}
