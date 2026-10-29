/* HSTMATCH module=EBOOT.BIN start=0x0021d478 end=0x0021d79c symbol=FUN_0021d478 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/parts_pane.h"

/* Packed 2-bit settings at 0x8b; only field b is read. */
struct Settings {
    char pad[0x8b];
    signed char a : 2;
    signed char b : 2;
    signed char c : 2;
    signed char d : 2;
};

#define PARTS_TIMER_EXIT 100    /* timer value where the layer eases toward its exit position */
#define EASE_EPS 0.01f

extern int DAT_0034179c;
extern float DAT_0034a1a0;
extern float DAT_0034a1a4;
extern float DAT_0034a1b0;
extern float DAT_002f05e8;
extern float DAT_002f05ec[];
extern int DAT_002eff90;
extern int DAT_002eff94;
extern Settings *DAT_002cfc8c;

extern "C" {
int FUN_001b1f7c(int *, int);
float FUN_000ede98(float, float, float, float);
float FUN_0000bd2c(float);
void FUN_00103480(PartsPane *);
void FUN_000ffb3c(PaneItem *, int);
void FUN_001b1c44(int *, int);
void FUN_00103628(PartsPane *, int);
void FUN_00103128(PartsPane *);

/* Per-frame update: eases the selected layer's three floats toward their targets, shows the item of the selected
   layer once the timer is past the intro, and hides the pane when the timer reaches its end. */
void FUN_0021d478(PartsPane *self)
{
    if (self->sound >= 0) {
        if (FUN_001b1f7c(&DAT_0034179c, self->sound) == 0) {
            self->sound = PARTS_NO_SOUND;
        }
    }
    int t = self->timer;
    if (t >= 0) {
        PartsLayer *layer = self->layer[self->selected];
        float cur0 = layer->unk60;
        float cur1 = layer->unk64;
        float cur2 = layer->unk78;
        float a, b, c;
        if (t < PARTS_TIMER_EXIT) {
            a = FUN_000ede98(cur0, 0.0f, DAT_002f05e8, EASE_EPS);
            b = FUN_000ede98(cur1, DAT_002f05ec[self->selected], DAT_002f05e8, EASE_EPS);
            c = FUN_000ede98(cur2, 1.0f, DAT_002f05e8, EASE_EPS);
        } else {
            a = FUN_000ede98(cur0, -DAT_0034a1a0, DAT_002f05e8, EASE_EPS);
            b = FUN_000ede98(cur1, -DAT_0034a1a4 + DAT_002f05ec[self->selected], DAT_002f05e8, EASE_EPS);
            c = FUN_000ede98(cur2, DAT_0034a1b0, DAT_002f05e8, EASE_EPS);
        }
        self->layer[self->selected]->unk60 = FUN_0000bd2c(a);
        self->layer[self->selected]->unk64 = FUN_0000bd2c(b);
        self->layer[self->selected]->unk78 = c;
        FUN_00103480(self);
        if (self->timer >= DAT_002eff90 + 20 && self->active != 0) {
            switch (self->selected) {
            case 0:
                FUN_000ffb3c(self->item[0], 0);
                break;
            case 1:
                FUN_000ffb3c(self->item[3], 0);
                break;
            case 2:
                FUN_000ffb3c(self->item[6], 0);
                break;
            }
            if (DAT_002cfc8c->b == 0) {
                FUN_001b1c44(&DAT_0034179c, 3);
                self->active = 0;
                self->timer = PARTS_TIMER_EXIT;
            }
        } else {
            FUN_000ffb3c(self->item[0], 1);
            FUN_000ffb3c(self->item[3], 1);
            FUN_000ffb3c(self->item[6], 1);
            self->timer = self->timer + 1;
        }
        if (self->timer >= DAT_002eff94) {
            FUN_00103628(self, 1);
            self->base.shown = 1;
            self->timer = PARTS_TIMER_OFF;
        }
    }
    FUN_00103128(self);
}
}
