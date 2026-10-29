/* HSTMATCH module=EBOOT.BIN start=0x0021f1fc end=0x0021f2d4 symbol=FUN_0021f1fc lang=c++ */
/* Hand-written reconstruction from the disassembly (twin of src/sharing_main/init_clamped_entry_0022e770.cpp with the addresses substituted; same shape as the matched sibling src/eboot/init_clamped_entries_002216cc.cpp: the clamp is an inline helper taking value and bounds by const reference, which gives retail's double loads); exact match verified; names and types await human review. */
#include "hst/status_overlay.h"

extern "C" {
extern int DAT_002eff90;
extern float DAT_002f0950;
extern float DAT_002f0954;
extern float DAT_0034a1c0;
extern float DAT_0034a1c4;
extern float DAT_0034a1d0;
extern char DAT_0034179c;
void FUN_0021f30c(void *);
void FUN_00103480(void *);
int FUN_001b2af0(void *, int);
}

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
    return value < lo ? lo : (!(value > hi) ? value : hi);
}

/* Start the overlay: load the timer from DAT_002eff90 and set the hold flag, call FUN_0021f30c(self), set the entity's
   two floats from globals and its +0x78 float from DAT_0034a1d0 clamped to [DAT_002f0950, DAT_002f0954], call
   FUN_00103480(self) and keep the result of FUN_001b2af0(&DAT_0034179c, 12) as the sound handle. */
extern "C" void FUN_0021f1fc(StatusOverlay *self)
{
    self->timer = DAT_002eff90;
    self->hold = 1;
    FUN_0021f30c(self);
    self->ent->unk60 = DAT_0034a1c0;
    self->ent->unk64 = DAT_0034a1c4;
    self->ent->unk78 = Clamp(DAT_0034a1d0, DAT_002f0950, DAT_002f0954);
    FUN_00103480(self);
    self->sound = FUN_001b2af0(&DAT_0034179c, 0xc);
}
