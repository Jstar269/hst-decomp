/* HSTMATCH module=EBOOT.BIN start=0x002216cc end=0x002217b8 symbol=FUN_002216cc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/lay_pane.h"

extern "C" {
extern unsigned DAT_002eff90;
extern float DAT_002f0d94;
extern float DAT_002f0dc8;
extern float DAT_002f0dcc;
extern float DAT_0034a250;
extern float DAT_0034a254;
extern char DAT_0034179c;
void FUN_002217f0(void *);
void FUN_00103480(void *);
int FUN_001b2af0(void *, int);
}

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
    return value < lo ? lo : (!(value > hi) ? value : hi);
}

/* Start the pane animation: preset the timer, set the hold flag and put every entry at its start values. */
extern "C" void FUN_002216cc(PaneB *pane)
{
    pane->timer = DAT_002eff90;
    pane->hold = 1;
    FUN_002217f0(pane);
    for (int i = 0; i < 2; i++) {
        pane->ent[i]->unk60 = DAT_0034a250;
        pane->ent[i]->unk64 = DAT_0034a254;
        pane->ent[i]->unk78 = Clamp(DAT_002f0d94, DAT_002f0dc8, DAT_002f0dcc);
    }
    FUN_00103480(pane);
    FUN_001b2af0(&DAT_0034179c, 0x21);
}
