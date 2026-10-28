/* HSTMATCH module=EBOOT.BIN start=0x00201724 end=0x00201810 symbol=FUN_00201724 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: virtual slot-1 calls (`lw t9,12(t9)`) as a polymorphic member call s1(1) on all three objects (the first call's a1 = 1 is shared with the constant stored to +0x710, Ghidra drops that argument), float stores of -240.0f/240.0f into a typed Sub60 field, DAT_0034a13c as a byte-addressed table pointer; readability pass; exact match verified; names and types await human review. */
#include "hst/menu_obj.h"
#include "hst/game.h"

extern "C" {
extern Game *DAT_0034a13c;
void FUN_00102c54(MenuSub60 *);
void FUN_00200bcc(MenuObj *, char *, char *);
void FUN_00201810(MenuObj *);
}

/* Starts the menu: state 1, all three widgets on, the five sub-objects set to their start offsets (one -240, four +240). */
extern "C" void FUN_00201724(MenuObj *self)
{
    self->state = MENU_STATE_SLIDE_IN;
    self->timer = 0;
    self->w0c->v1(1);
    self->w24->v1(1);
    self->w708->v1(1);
    self->sub20->unk60 = -240.0f;
    FUN_00102c54(self->sub20);
    self->sub10->unk60 = 240.0f;
    FUN_00102c54(self->sub10);
    self->sub14->unk60 = 240.0f;
    FUN_00102c54(self->sub14);
    self->sub18->unk60 = 240.0f;
    FUN_00102c54(self->sub18);
    self->sub1c->unk60 = 240.0f;
    FUN_00102c54(self->sub1c);
    FUN_00200bcc(self, DAT_0034a13c->unkcd0, DAT_0034a13c->unkf90);
    FUN_00201810(self);
}
