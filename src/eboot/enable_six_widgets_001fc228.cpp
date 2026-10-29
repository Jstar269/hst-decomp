/* HSTMATCH module=EBOOT.BIN start=0x001fc228 end=0x001fc2a8 symbol=FUN_001fc228 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/part_holder.h"

extern "C" int FUN_000487f4(PartC *part);
extern "C" void FUN_000ffb3c(void *p, int v);
extern "C" void FUN_00103128(PartC *part);

/* If the part passes the check, switch on all six of its widgets. */
extern "C" void FUN_001fc228(PartC *part)
{
    if (FUN_000487f4(part) != 0) {
        FUN_000ffb3c(part->widget[0], 1);
        FUN_000ffb3c(part->widget[1], 1);
        FUN_000ffb3c(part->widget[2], 1);
        FUN_000ffb3c(part->widget[3], 1);
        FUN_000ffb3c(part->widget[4], 1);
        FUN_000ffb3c(part->widget[5], 1);
    }
    FUN_00103128(part);
}
