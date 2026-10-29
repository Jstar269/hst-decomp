/* HSTMATCH module=EBOOT.BIN start=0x002067c0 end=0x002068e8 symbol=FUN_002067c0 lang=c++ */
/* Hand-written reconstruction from the disassembly (matching idioms: Min/Max inlines taking const int& and returning by value for the double global load; `n >= 3` on a local copy of the incremented counter); exact match verified; names and types await human review. */
#include "hst/root_state.h"
#include "hst/session_ctx.h"

#define LEVEL_STEP_TICKS 3  /* ticks of the default mode before the level is raised */

struct Self {
    char pad[0x144];
    unsigned unk144;
    char pad2[0x408 - 0x148];
    unsigned char active;   /* 0x408 */
    char pad3[0x820 - 0x409];
    int level;              /* 0x820 clamped between the three limits */
    int ticks;              /* 0x824 counts ticks of the default mode */
};
extern "C" RootState *DAT_003386b0;
extern "C" SessionCtx *DAT_00338b44;
extern "C" int DAT_002ef75c;
extern "C" int DAT_002ef760;
extern "C" int DAT_002ef764;

static inline int Min(const int &a, const int &b)
{
    return (b < a) ? b : a;
}
static inline int Max(const int &a, const int &b)
{
    return (a < b) ? b : a;
}

/* Steps the level by the mode of the session context: lowers it (mode 1), raises it (mode 2) or raises it every LEVEL_STEP_TICKS ticks (other modes). */
extern "C" void FUN_002067c0(Self *self)
{
    if (self->active != 0 && DAT_003386b0->mode != ROOT_MODE_SPECIAL) {
        SessionCtx *c = DAT_00338b44;
        switch (c->mode) {
        case 0:
            break;
        case 1:
            if ((self->unk144 ^ 1) == c->unk9c) {
                self->level = Max(self->level - 1, DAT_002ef75c);
                self->ticks = 0;
            }
            break;
        case 2:
            if (self->unk144 == c->unk9c && c->unk61 == 0) {
                self->level = Min(self->level + 1, DAT_002ef760);
                self->ticks = 0;
            }
            break;
        default: {
            int n = self->ticks + 1;
            self->ticks = n;
            if (n >= LEVEL_STEP_TICKS) {
                self->ticks = 0;
                self->level = Min(self->level + 1, DAT_002ef764);
            }
            break;
        }
        }
    }
}
