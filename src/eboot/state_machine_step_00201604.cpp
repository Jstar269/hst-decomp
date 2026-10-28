/* HSTMATCH module=EBOOT.BIN start=0x00201604 end=0x00201724 symbol=FUN_00201604 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/menu_obj.h"
#include "hst/game.h"

extern "C" {
extern Game *DAT_0034a13c;
void FUN_000ffb3c(Cell *, int);
void FUN_00102c54(MenuSub60 *);
void FUN_00201880(MenuObj *);
void FUN_00200bcc(MenuObj *, char *, char *);
}

/* Menu state machine: after each timed state it advances and resets the timer. */
extern "C" void FUN_00201604(MenuObj *self)
{
    switch (self->state) {
    case MENU_STATE_SLIDE_IN:
        self->timer++;
        if (self->timer >= MENU_STATE_TIMEOUT) {
            FUN_000ffb3c(self->cell558, 0);
            self->sub20->unk60 = 0;
            FUN_00102c54(self->sub20);
            FUN_00201880(self);
            self->state++;
            self->timer = 0;
        }
        break;
    case MENU_STATE_SETTLE:
        self->timer++;
        if (self->timer >= MENU_STATE_TIMEOUT) {
            FUN_000ffb3c(self->cell56c, 0);
            self->w708->v1(0);
            if (DAT_0034a13c->unkc4 != 0) {
                self->w0c->v1(0);
            }
            self->state++;
            self->timer = 0;
        }
        FUN_00200bcc(self, DAT_0034a13c->unkcd0, DAT_0034a13c->unkf90);
        break;
    case MENU_STATE_DONE:
        break;
    }
}
