/* HSTMATCH module=EBOOT.BIN start=0x002a7a08 end=0x002a7b3c symbol=FUN_002a7a08 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/mode_panel_obj.h"

extern int DAT_0034179c;
extern "C" {
void FUN_002a6e34(ModePanel *);
void FUN_001b1c44(int *, int);
void FUN_0010b8cc(struct Gfx *, int, int);
float FUN_0000bf34(float);
float fabsf(float);
void FUN_00103128(ModePanel *);

/* Move a range's start to v and shift its end by the same delta. */
static inline void Shift(ModeRange *r, float v)
{
    short nv = (short)v;
    short old = r->start;
    r->start = nv;
    r->end += (short)(nv - old);
}

void FUN_002a7a08(ModePanel *self)
{
    int a = self->unk1674;
    int b = self->unk166c;
    FUN_002a6e34(self);
    if (a != self->unk1674 || b != self->unk166c) {
        FUN_001b1c44(&DAT_0034179c, 1);
        FUN_0010b8cc(self->gfx, self->unk1674, 0);
    }
    self->target->unke0 = (float)self->unk166c;
    /* pulse amplitude: |wave(0.2 * frame)| * 6 */
    float amp = 6.0f * fabsf(FUN_0000bf34(0.2f * (float)self->unk1688));
    Shift(self->range1d0, (float)self->unk168c - amp);
    Shift(self->range1d4, (float)self->unk1690 + amp);
    self->unk1688 = self->unk1688 + 1;
    FUN_00103128(self);
}
}
