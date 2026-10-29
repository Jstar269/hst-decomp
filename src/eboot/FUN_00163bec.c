/* HSTMATCH module=EBOOT.BIN start=0x00163bec end=0x00163d68 symbol=FUN_00163bec lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified (95/95 words).
   Large sibling of 0x00163e60/0x00163d68: same table lookup (record table, 0x22c stride)
   but the base value is at +0x4c, the per-entry term at +0xf4 and FUN_000d8334's second
   argument is 1; the float parameter is the FOURTH formal, ahead of the last int, which is
   what puts mov.s before the a3 move; clamping uses the +4 fields; names await human review. */
#include "hst/stat_calc.h"

extern StatRecTable *DAT_0034150c;
extern LimitTable *DAT_00341510;
extern char *DAT_0034b5d4;
extern float FUN_000d8334(StatMod *, int);

/* Stat 1 of a record plus the modifier's terms, scaled by two percentages, clamped to the limit table's range. */
float FUN_00163bec(StatRec *rec, StatMod *mod, int skip_scale, float percent, int use_alt_scale)
{
    float v = rec->stat1;
    float lo;
    float hi;

    if (mod != 0) {
        if (mod->id >= 0)
            v += STAT_REC_AT(DAT_0034150c, mod->id)->stat1;
        v += FUN_000d8334(mod, 1);
        {
            int off = mod->rank * RANK_ROW_SIZE;
            v += *(float *)(off + (int)DAT_0034b5d4 + RANK_BONUS_BASE + 4);
        }
    }
    if (skip_scale == 0) {
        if (use_alt_scale != 0)
            v *= rec->scale94 * 0.01f;
        else
            v *= rec->scale88 * 0.01f;
    }
    v *= percent * 0.01f;
    lo = LIMIT_ROW_AT(DAT_00341510, 0)->v[1];
    hi = LIMIT_ROW_AT(DAT_00341510, DAT_00341510->count - 1)->v[1];
    if (v < lo)
        return lo;
    if (v > hi)
        return hi;
    return v;
}
