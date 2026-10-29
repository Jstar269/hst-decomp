/* HSTMATCH module=EBOOT.BIN start=0x00093838 end=0x00093898 symbol=FUN_00093838 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/model_set.h"

extern char DAT_00338710; /* set once the fallback vector has been initialised */
extern int DAT_002beb40, DAT_002beb44, DAT_002beb48, DAT_002beb4c; /* fallback vector x, y, z, w */

#define FLOAT_ONE_BITS 0x3F800000 /* 1.0f */

/* Vector of the main model, or a shared fallback (0, 0, 0, 1) when there is no main model. */
void *FUN_00093838(ModelSet *self)
{
    if (self->model[MODEL_SLOT_MAIN] != 0)
        return self->model[MODEL_SLOT_MAIN]->unk60;
    if (DAT_00338710 == 0) {
        DAT_002beb40 = 0;
        DAT_002beb44 = 0;
        DAT_002beb48 = 0;
        DAT_002beb4c = FLOAT_ONE_BITS;
        DAT_00338710 = 1;
    }
    return &DAT_002beb40;
}
