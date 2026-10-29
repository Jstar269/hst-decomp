/* HSTMATCH module=hstp_trans_main.prx start=0x001c4584 end=0x001c473c symbol=FUN_001c4584 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/enter_state_001b68c4.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */

#include "hst/state_obj.h"

extern "C" {
extern void *DAT_00391590;
extern void *DAT_003e1e84;
extern void *DAT_003e47a0;
extern void *DAT_003eaad8;

extern int FUN_000e2c0c(void *, int);
extern int FUN_000e2708(void *, int);
extern int FUN_000e30f8(void *);
extern int FUN_001259ac(void *);
extern void FUN_001c21a8(void *);
extern void FUN_001c2280(void *, float, float);
extern void FUN_001c23fc(void *, int);
extern void FUN_001c63e4(void *);
extern void FUN_001c6408(void *);
extern void FUN_001c6440(void *, int);
extern void FUN_001c64d4(void *, int, int);
extern void FUN_001c6834(void *, int, int);
extern void FUN_001c71e4(void *, void *, void *, void *);
}

/* Enters the state: reacts to the queries on the global context, resets the flags and counters and
   calls the list helper on the second list block. */
extern "C" void FUN_001c4584(StateObj *self)
{
    if (FUN_000e2c0c(DAT_003e1e84, -1)) {
        FUN_001c23fc(&DAT_003eaad8, 0x23);
        FUN_001c6440(self, 1);
    } else if (FUN_000e2708(DAT_003e1e84, -1)) {
        FUN_001c23fc(&DAT_003eaad8, 0x22);
        FUN_001c6440(self, 1);
    } else if (self->handle50 < 0) {
        FUN_001c21a8(&DAT_003eaad8);
        FUN_001c64d4(self, 0, 1);
    } else if (FUN_000e30f8(DAT_003e1e84) && self->unk78 == 0) {
        FUN_001c21a8(&DAT_003eaad8);
        FUN_001c64d4(self, 0, 1);
        FUN_001c2280(&DAT_003eaad8, 0.0f, 0.0f);
    }

    if (FUN_000e30f8(DAT_003e1e84) && self->unk7a != 0) {
        FUN_001c6834(self, 150, 0);
        self->unk7a = 0;
    }

    if (DAT_003e47a0 != 0 && FUN_001259ac(DAT_003e47a0)) {
        self->unk8c = DAT_00391590;
    }

    int scratch;
    int tail;
    void *head;
    head = self->list_f0.head;
    tail = self->list_f0.tail;
    FUN_001c71e4(&scratch, self->list_f0.tag, &tail, &head);

    self->unk7b = 0;
    FUN_001c6408(self);
    self->unk84 = 0;
    self->unk88 = 0;
    self->unke8 = 0xd0;
    self->unkec = 0xd0;
    FUN_001c63e4(self);
}
