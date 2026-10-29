/* HSTMATCH module=EBOOT.BIN start=0x000c29bc end=0x000c2aa0 symbol=FUN_000c29bc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/body_obj.h"

extern "C" void FUN_00022548(void *, void *, const Float4 *);

/* Set the two scalars, the integer and the vectors; the counter counts the first BODY_COUNTER_LIMIT calls. */
extern "C" void FUN_000c29bc(float value1, float value2, BodyObj *self, const Float4 *firstArg,
                              const Float4 *secondArg, const int *valueArg)
{
    Float4 first = *firstArg;
    Float4 second = *secondArg;
    if (self->counter < BODY_COUNTER_LIMIT) {
        self->unk04 = 1;
        self->counter = self->counter + 1;
    }
    self->unk120 = value1;
    self->unk124 = value2;
    self->unk134 = *valueArg;
    self->vec30 = first;
    self->vec10 = self->vec30;
    FUN_00022548(&self->vec40, self->block90, &second);
    self->unk128 = 0;
}
