/* HSTMATCH module=hstp_trans_main.prx start=0x0022e770 end=0x0022e848 symbol=FUN_0022e770 lang=c++ */
/* Hand-written reconstruction from the disassembly (same shape as the matched siblings src/sharing_main/init_clamped_entries_00230c40.cpp and apply_float_range_0022f7ac.cpp: the clamp is an inline helper taking value and bounds by const reference, which gives retail's double loads of each bound and of the value); exact match verified; names and types await human review. */
#include "hst/status_overlay.h"

extern "C" {
extern int DAT_0039835c;
extern float DAT_00398d1c;
extern float DAT_00398d20;
extern float DAT_003f34f0;
extern float DAT_003f34f4;
extern float DAT_003f3500;
extern char DAT_003eaad8;
void FUN_0022e880(void *);
void FUN_00108dac(void *);
int FUN_001c0bb0(void *, int);
}

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
    return value < lo ? lo : (!(value > hi) ? value : hi);
}

/* Start the overlay: load the timer from DAT_0039835c and set the hold flag, call FUN_0022e880(self), set the entity's
   two floats from globals and its +0x78 float from DAT_003f3500 clamped to [DAT_00398d1c, DAT_00398d20], call
   FUN_00108dac(self) and keep the result of FUN_001c0bb0(&DAT_003eaad8, 12) as the sound handle. */
extern "C" void FUN_0022e770(StatusOverlay *self)
{
    self->timer = DAT_0039835c;
    self->hold = 1;
    FUN_0022e880(self);
    self->ent->unk60 = DAT_003f34f0;
    self->ent->unk64 = DAT_003f34f4;
    self->ent->unk78 = Clamp(DAT_003f3500, DAT_00398d1c, DAT_00398d20);
    FUN_00108dac(self);
    self->sound = FUN_001c0bb0(&DAT_003eaad8, 0xc);
}
