/* HSTMATCH module=EBOOT.BIN start=0x0028ad5c end=0x0028adc4 symbol=FUN_0028ad5c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/effect_source.h"

extern "C" {
void FUN_00058f38(ModelHolder *, float, int);
void FUN_0005f110(ModelHolder *, float);
void FUN_0028adc4(EffectSource *);
}

/* Marks the source started and applies the holder's node value (0 when it has none). */
extern "C" void FUN_0028ad5c(EffectSource *self)
{
    FUN_0028adc4(self);
    self->started = 1;
    ModelHolder *holder = self->modelA;
    float value = holder->node != 0 ? holder->node->item->value : 0.0f;
    FUN_00058f38(holder, value, -1);
    FUN_0005f110(holder, value);
}
