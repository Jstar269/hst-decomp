/* HSTMATCH module=EBOOT.BIN start=0x00231ba0 end=0x00231c5c symbol=FUN_00231ba0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: restored self argument to FUN_00231c5c, inline SetIndex helper with != first and two-case switch on field_1dc, and &DAT_0034179c; readability pass; exact match verified; names and types await human review. */
#include "hst/challenge_menu.h"

extern "C" {
extern char DAT_0034179c;
int FUN_001b1c44(void *, int);
void FUN_00231c5c(ChallengeMenu *);
void FUN_00231f84(ChallengeMenu *, int *, float *);
void FUN_00232558(ChallengeMenu *, int);
}

/* Select point `val`; a change plays a sound, and mode 1 notifies the selection handler. */
static inline void SetIndex(ChallengeMenu *self, int val)
{
    if (self->selected != val) {
        FUN_001b1c44(&DAT_0034179c, 1);
        self->selected = val;
    } else {
        self->selected = val;
    }
    switch (self->mode) {
    case 0:
        break;
    case 1:
        FUN_00232558(self, self->selected);
        break;
    }
}

/* Per-frame: in mode 0 pick a point by direction, or, when a request is pending, jump to the nearest point. */
extern "C" void FUN_00231ba0(ChallengeMenu *self)
{
    if (self->pending == 0 && self->mode == 0) {
        FUN_00231c5c(self);
    }
    if (self->mode == 0 && self->pending != 0) {
        self->pending = 0;
        int idx;
        float dist;
        FUN_00231f84(self, &idx, &dist);
        SetIndex(self, idx);
    }
}
