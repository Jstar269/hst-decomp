/* HSTMATCH module=EBOOT.BIN start=0x000fa884 end=0x000fa98c symbol=FUN_000fa884 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/hud_scene.h"

#define HUD_REC_COUNT 16

struct HudWidget { virtual void s0(); virtual void s1(); };
struct HudRec {
    unsigned char unk0;
    int unk4, unk8, unkc, unk10, unk14;
    char pad18[8];
    int unk20, unk24, unk28;
    float unk2c;
    int unk30;
    char pad34[0xc];
};
struct HudPanel {
    char pad0[0xa0];
    HudRec recs[HUD_REC_COUNT];
};
extern "C" {
extern void FUN_000f3640(void *);
extern void FUN_000f6b0c(void *, int);
extern void FUN_001ec518(void *, int);
}

/* Reset the scene's state: restart the widgets, set the flag and block, clear the 16 panel records
   to their defaults and refresh the remaining parts. */
#pragma opt_unroll_loops off
extern "C" void FUN_000fa884(HudScene *self)
{
    FUN_000f3640(self->top);
    self->unk70->s1();
    self->unk6c->s1();
    self->unk74->s1();
    self->unk78->s1();
    *self->unk7c = 1;
    HudBlock *b = self->unk80;
    b->flag = 1;
    b->unk8 = -1.0f;
    unsigned i = 0;
    char *p = (char *)self->unk88;
    do {
        HudRec *r = (HudRec *)(p + 0xa0);
        r->unk0 = 0;
        r->unk4 = 0x10;
        r->unk8 = 0;
        r->unkc = -1;
        r->unk10 = 0;
        r->unk14 = 0;
        r->unk20 = 0;
        r->unk24 = 0;
        r->unk28 = 0;
        r->unk2c = 1.0f;
        r->unk30 = 0;
        i++;
        p += 0x40;
    } while (i < HUD_REC_COUNT);
    FUN_000f6b0c(self->unk8c, 0);
    FUN_000f6b0c(self->unk90, 0);
    FUN_001ec518(self->unk94, 1);
}
