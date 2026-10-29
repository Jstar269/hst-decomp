/* HSTMATCH module=EBOOT.BIN start=0x0020b62c end=0x0020b7a0 symbol=FUN_0020b62c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idioms: bool/flag locals loaded before the first test, `(flag != 0) ^ 1`, Min/Max inlines taking const int& and returning by value); names and types await human review. */
#include "hst/chara_player.h"
#include "hst/match_cfg.h"

extern MatchCfg *DAT_00338b44;
extern int DAT_0034a678;
extern int DAT_00341504;
extern int DAT_002ef86c;
extern int DAT_002ef870;
extern int DAT_002ef874;
extern unsigned char DAT_00341834[];
extern unsigned char DAT_00341898[];

enum { SLOT_ROW_SIZE = 0x120 };   /* stride of the per-slot rows behind DAT_00341834 / DAT_00341898 */

static inline int Min(const int &a, const int &b)
{
    return (b < a) ? b : a;
}
static inline int Max(const int &a, const int &b)
{
    return (a < b) ? b : a;
}

/* Per-slot value from the row table: raised by a global when the partner slot is empty, reduced by
   value90 / 10 when the config flag is set; 15 becomes 16 in mode 0x31 when unk144 is 1. */
extern "C" int FUN_0020b62c(CharaPlayer *self)
{
    int value = DAT_00341834[self->slot * SLOT_ROW_SIZE];
    if (DAT_00341898[self->slot * SLOT_ROW_SIZE] != 0) {
        bool is_mode31 = DAT_0034a678 == 0x31;
        MatchCfg *cfg = DAT_00338b44;
        unsigned char flag = cfg->flag45;
        if ((flag != 0) ^ 1) {
            if (DAT_00341898[((self->slot + 2) % 4) * SLOT_ROW_SIZE] == 0) {
                value = Min(value + DAT_00341504, DAT_002ef86c);
            }
        }
        if (is_mode31 && value == 15 && self->unk144 == 1) {
            value = 16;
        }
        if (flag != 0 && value < 16) {
            int reduction = cfg->value90 / 10;
            value -= Min(reduction, DAT_002ef870);
            value = Max(value, DAT_002ef874);
        }
    }
    return value;
}
