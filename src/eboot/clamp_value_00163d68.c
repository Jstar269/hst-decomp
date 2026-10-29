/* HSTMATCH module=EBOOT.BIN start=0x00163d68 end=0x00163e60 symbol=FUN_00163d68 lang=c99 */
/* Hand-written reconstruction from the disassembly (the offset of the last term is a block-scoped local, which flips MWCC's add operand order); exact match verified; names and types await human review. */
#include "hst/stat_calc.h"

extern StatRecTable *DAT_0034150c;
extern LimitTable *DAT_00341510;
extern char *DAT_0034b5d4;
extern float FUN_000d8334(StatMod *, int);

/* Stat 2 of a record plus the modifier's record, call result and rank bonus, clamped to the limit table's range. */
float FUN_00163d68(StatRec *rec, StatMod *mod)
{
    float v = rec->stat2;
    float lo;
    float hi;

    if (mod != 0) {
        if (mod->id >= 0)
            v += STAT_REC_AT(DAT_0034150c, mod->id)->stat2;
        v += FUN_000d8334(mod, 2);
        {
            int off = mod->rank * RANK_ROW_SIZE;
            v += *(float *)(off + (int)DAT_0034b5d4 + RANK_BONUS_BASE + 8);
        }
    }
    lo = LIMIT_ROW_AT(DAT_00341510, 0)->v[2];
    hi = LIMIT_ROW_AT(DAT_00341510, DAT_00341510->count - 1)->v[2];
    if (v < lo)
        return lo;
    if (v > hi)
        return hi;
    return v;
}
