/* HSTMATCH module=EBOOT.BIN start=0x001b68c4 end=0x001b6a7c symbol=FUN_001b68c4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#include "hst/state_obj.h"

extern "C" {
extern void *DAT_002e99d4;
extern void *DAT_00338b44;
extern void *DAT_0033b460;
extern void *DAT_0034179c;

extern int FUN_000dea20(void *, int);
extern int FUN_000de51c(void *, int);
extern int FUN_000def0c(void *);
extern int FUN_0011a7d8(void *);
extern void FUN_001b3f1c(void *);
extern void FUN_001b413c(void *, float, float);
extern void FUN_001b42b8(void *, int);
extern void FUN_001b86f8(void *);
extern void FUN_001b871c(void *);
extern void FUN_001b8754(void *, int);
extern void FUN_001b87e8(void *, int, int);
extern void FUN_001b8b48(void *, int, int);
extern void FUN_001b94f8(void *, void *, void *, void *);
}

/* Enters the state: reacts to the queries on the global context, resets the flags and counters and
   calls the list helper on the second list block. */
extern "C" void FUN_001b68c4(StateObj *self)
{
    if (FUN_000dea20(DAT_00338b44, -1)) {
        FUN_001b42b8(&DAT_0034179c, 0x23);
        FUN_001b8754(self, 1);
    } else if (FUN_000de51c(DAT_00338b44, -1)) {
        FUN_001b42b8(&DAT_0034179c, 0x22);
        FUN_001b8754(self, 1);
    } else if (self->handle50 < 0) {
        FUN_001b3f1c(&DAT_0034179c);
        FUN_001b87e8(self, 0, 1);
    } else if (FUN_000def0c(DAT_00338b44) && self->unk78 == 0) {
        FUN_001b3f1c(&DAT_0034179c);
        FUN_001b87e8(self, 0, 1);
        FUN_001b413c(&DAT_0034179c, 0.0f, 0.0f);
    }

    if (FUN_000def0c(DAT_00338b44) && self->unk7a != 0) {
        FUN_001b8b48(self, 150, 0);
        self->unk7a = 0;
    }

    if (DAT_0033b460 != 0 && FUN_0011a7d8(DAT_0033b460)) {
        self->unk8c = DAT_002e99d4;
    }

    int scratch;
    int tail;
    void *head;
    head = self->list_f0.head;
    tail = self->list_f0.tail;
    FUN_001b94f8(&scratch, self->list_f0.tag, &tail, &head);

    self->unk7b = 0;
    FUN_001b871c(self);
    self->unk84 = 0;
    self->unk88 = 0;
    self->unke8 = 0xd0;
    self->unkec = 0xd0;
    FUN_001b86f8(self);
}
