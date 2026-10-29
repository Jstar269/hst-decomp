/* HSTMATCH module=EBOOT.BIN start=0x00163aac end=0x00163bec symbol=FUN_00163aac lang=c99 */
/* Hand-written reconstruction from the disassembly (the clamp at the end is a chained conditional expression: with an early return before it MWCC only duplicates the frame restore into the branch delay for that form); exact match verified; names and types await human review. */
#include "hst/stat_calc.h"

#define MOD_ID_NO_LIMIT 0x32 /* id / 10 value that returns the limit table's minimum directly */

extern StatRecTable *DAT_0034150c;
extern LimitTable *DAT_00341510;
extern char *DAT_0034b5d4;
extern float FUN_000d8334(StatMod *, int);

/* Stat 0 of a record plus the modifier's record, bonus and rank row, clamped to the limit table's range. */
float FUN_00163aac(StatRec *rec, StatMod *mod)
{
    float v;
    float lo;
    float hi;

    if (mod != 0 && mod->id / 10 == MOD_ID_NO_LIMIT)
        return LIMIT_ROW_AT(DAT_00341510, 0)->v[0];
    v = rec->stat0;
    if (mod != 0) {
        if (mod->id >= 0)
            v += STAT_REC_AT(DAT_0034150c, mod->id)->stat0;
        v += FUN_000d8334(mod, 0);
        {
            int off = mod->rank * RANK_ROW_SIZE;
            v += *(float *)(off + (int)DAT_0034b5d4 + RANK_BONUS_BASE);
        }
    }
    lo = LIMIT_ROW_AT(DAT_00341510, 0)->v[0];
    hi = LIMIT_ROW_AT(DAT_00341510, DAT_00341510->count - 1)->v[0];
    return v < lo ? lo : v > hi ? hi : v;
}
