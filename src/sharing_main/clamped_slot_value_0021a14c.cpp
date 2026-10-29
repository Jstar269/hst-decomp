/* HSTMATCH module=hstp_trans_main.prx start=0x0021a14c end=0x0021a2c0 symbol=FUN_0021a14c lang=c++ */
/* Hand-written reconstruction (port of src/eboot/clamped_slot_value_0020b62c.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
#include "hst/chara_player.h"
#include "hst/match_cfg.h"

extern MatchCfg *DAT_003e1e84;
extern int DAT_003f39a8;
extern int DAT_003ea844;
extern int DAT_00397a4c;
extern int DAT_00397a50;
extern int DAT_00397a54;
extern unsigned char DAT_003eab6c[];
extern unsigned char DAT_003eabd0[];

enum { SLOT_ROW_SIZE = 0x120 };   /* stride of the per-slot rows behind DAT_003eab6c / DAT_003eabd0 */

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
extern "C" int FUN_0021a14c(CharaPlayer *self)
{
    int value = DAT_003eab6c[self->slot * SLOT_ROW_SIZE];
    if (DAT_003eabd0[self->slot * SLOT_ROW_SIZE] != 0) {
        bool is_mode31 = DAT_003f39a8 == 0x31;
        MatchCfg *cfg = DAT_003e1e84;
        unsigned char flag = cfg->flag45;
        if ((flag != 0) ^ 1) {
            if (DAT_003eabd0[((self->slot + 2) % 4) * SLOT_ROW_SIZE] == 0) {
                value = Min(value + DAT_003ea844, DAT_00397a4c);
            }
        }
        if (is_mode31 && value == 15 && self->unk144 == 1) {
            value = 16;
        }
        if (flag != 0 && value < 16) {
            int reduction = cfg->value90 / 10;
            value -= Min(reduction, DAT_00397a50);
            value = Max(value, DAT_00397a54);
        }
    }
    return value;
}
