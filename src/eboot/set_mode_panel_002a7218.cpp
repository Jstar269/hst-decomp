/* HSTMATCH module=EBOOT.BIN start=0x002a7218 end=0x002a734c symbol=FUN_002a7218 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/mode_panel_obj.h"

struct Gfx {
    virtual void v0();
    virtual void v1(int);
};
extern int DAT_0034b354;
extern int DAT_0034b358;
extern "C" {
void FUN_002a79fc(ModePanel *, int);
void FUN_002a761c(ModePanel *);
void FUN_002a734c(ModePanel *);
int FUN_001fea10(int, int, int);
void FUN_000143b0(int *, int, char *);
void FUN_00110a78(int, int *, int);
void FUN_00103480(ModePanel *);
}

#define MODE1_UNK1674 0x12 /* value stored in unk1674 and passed on in mode 1 */

extern "C" void FUN_002a7218(ModePanel *self, int mode)
{
    self->mode = mode;
    switch (mode) {
    case MODE_PANEL_MODE0: {
        self->slot54->value = 1.0f;
        self->slot58->value = 0.0f;
        self->slot5c->value = 0.0f;
        int v = self->unk1668;
        self->unk1674 = v;
        FUN_002a79fc(self, v);
        FUN_002a734c(self);
        self->gfx->v1(0);
        int s = FUN_001fea10(0x12, 0x31, 0xe);
        FUN_00110a78(DAT_0034b354, (int *)s, 0);
        break;
    }
    case MODE_PANEL_MODE1: {
        self->slot54->value = 0.0f;
        self->slot58->value = 1.0f;
        self->slot5c->value = 1.0f;
        self->unk1674 = MODE1_UNK1674;
        FUN_002a79fc(self, MODE1_UNK1674);
        FUN_002a761c(self);
        self->gfx->v1(1);
        int s = FUN_001fea10(0x12, 0x31, 0xf);
        FUN_000143b0(&DAT_0034b358, s, self->name1361);
        FUN_00110a78(DAT_0034b354, &DAT_0034b358, 0);
        break;
    }
    }
    FUN_00103480(self);
}
