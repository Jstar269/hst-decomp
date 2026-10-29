/* HSTMATCH module=EBOOT.BIN start=0x00122888 end=0x00122a80 symbol=FUN_00122888 lang=c99 */
/* Hand-written reconstruction from the disassembly (near miss wip/state_ctor_00122888.c, completed: third argument of FUN_00124bf8 is the state pointer; matching idioms: #pragma opt_strength_reduction off, explicit byte-offset loop variable `off` next to the index `i`, and a char * cast on the first slot store so its address is not CSE'd with the later ones); exact match verified; names and types await human review. */
#include "hst/actor_state.h"

extern void FUN_0001f06c(void);
extern int FUN_00000bcc(int);
extern int FUN_00125d38(int);
extern int FUN_00216174(int);
extern void FUN_00124bf8(ActorState *, int, StateRow *);
extern void FUN_00132124(int, void *);
extern int FUN_001252fc(ActorState *, int);
extern void FUN_00124b98(float, ActorState *, StateRow *, StateRow *);
extern int DAT_00308028;
extern StateRow DAT_0033b584[];

#pragma opt_strength_reduction off
/* Constructor: creates the three child objects and the helper object, then enters the first state. */
ActorState *FUN_00122888(ActorState *param_1)
{
    ActorState *self;
    int i;
    int off;
    int v;
    ActorChild *child;
    int other;
    float f;
    int iv;
    int tmp;
    StateRow *cur;

    self = param_1;
    FUN_0001f06c();
    self->vtable = (const void *)&DAT_00308028;
    self->unk54 = 0;
    i = 0;
    off = 0;
    do {
        *(int *)((char *)self + off + 0x3c) = 0;
        v = FUN_00000bcc(0xa0);
        if (v != 0)
            v = FUN_00125d38(v);
        *(int *)((int)self + off + 0x3c) = v;
        *(int *)((int)self + off + 0x48) = 0;
        child = *(ActorChild **)((int)self + off + 0x3c);
        child->slot = (StateRow **)((int)self + off + 0x48);
        child = *(ActorChild **)((int)self + off + 0x3c);
        child->index = i;
        i = i + 1;
        off = off + 4;
    } while (i < ACTOR_CHILD_COUNT);
    v = FUN_00000bcc(0x50);
    if (v != 0)
        v = FUN_00216174(v);
    self->unk54 = v;
    self->active = 0;
    self->unk79 = 0;
    self->unk7a = 1;
    self->unk7b = 0;
    self->unk7c = 0;
    self->unk80 = -1;
    self->unk84 = -1.0f;
    self->unk88 = 0.0f;
    self->unk8c = 0;
    self->unk90 = 0;
    self->unk94 = 0;
    self->unk95 = 0;
    self->unk98 = 0;
    self->unk9c = 0;
    self->stateIdx = 0;
    self->unk5c = 0;
    self->unk60 = 0.0f;
    self->unk64 = 0.0f;
    self->unk68 = 0.0f;
    self->unk6c = -1.0f;
    self->unk70 = 0.0f;
    self->unk74 = 0;
    if (DAT_0033b584[self->stateIdx].unk4e == 0) {
        cur = &DAT_0033b584[self->stateIdx];
        self->slotA = cur;
        FUN_00124bf8(self, 0, cur);
    } else {
        f = DAT_0033b584[self->stateIdx].unk1c;
        iv = (int)f;
        FUN_00132124(DAT_0033b584[self->stateIdx].unk46, &tmp);
        other = FUN_001252fc(self, tmp);
        FUN_00124b98((float)iv, self, &DAT_0033b584[self->stateIdx], &DAT_0033b584[other]);
    }
    return self;
}
