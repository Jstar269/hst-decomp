/* HSTMATCH module=EBOOT.BIN start=0x001b6b6c end=0x001b6db0 symbol=FUN_001b6b6c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag gen-a7/v21) corrected by hand: rewrote the inverted if/else chain into the natural if/else-if order and used unsigned temps so the pointer parameter colours into s1; readability pass; exact match verified; names and types await human review. */
#include "hst/state_obj.h"

struct Obj144_001b6b6c {
    char pad00[0x144];
    int f144;
};
extern "C" {
extern StateCtx *DAT_00338b44;
extern void *DAT_003386b0;
extern char DAT_0034179c[];
int FUN_0008882c(void *);
int FUN_000dbc04(StateCtx *);
int FUN_000de208(StateCtx *, int);
int FUN_000de238(StateCtx *, int);
int FUN_000de268(StateCtx *, int);
int FUN_000de298(StateCtx *, int);
void FUN_001b8b48(StateObj *, int, int);
void FUN_001b89ec(float, StateObj *);
void FUN_001b8890(float, StateObj *);
void FUN_001b1c44(int, int);
void FUN_001b8260(StateObj *);
}
/* Per-frame state update: picks an event from the context flags, then checks the context's queries for
   the current side and the other side (side ^ 1), and finishes with the common tail. */
extern "C" void FUN_001b6b6c(StateObj *self)
{
    if (DAT_00338b44->unk84 != 0) {
        if (self->unk7b == 0)
            FUN_001b8b48(self, 0x91, 0);
        FUN_001b89ec(0.5f, self);
    }
    else if (DAT_00338b44->unk5f != 0) {
        FUN_001b8b48(self, 0x93, 0);
        FUN_001b89ec(0.5f, self);
    }
    else if (DAT_00338b44->unk5e != 0) {
        FUN_001b8b48(self, 0x92, 0);
    }
    else if (DAT_00338b44->unk5d != 0) {
        FUN_001b8b48(self, 0x94, 0);
    }
    else if (FUN_000dbc04(DAT_00338b44) != 0) {
        FUN_001b8b48(self, 0x95, 0);
        FUN_001b89ec(0.5f, self);
    }
    else {
        if (FUN_000de208(DAT_00338b44, -1) != 0 || FUN_000de238(DAT_00338b44, -1) != 0 ||
            FUN_000de298(DAT_00338b44, -1) != 0)
            FUN_001b8890(0.5f, self);
    }
    unsigned int side = ((Obj144_001b6b6c *)FUN_0008882c(DAT_003386b0))->f144;
    unsigned int other = side ^ 1;
    if (FUN_000de208(DAT_00338b44, side) != 0 || FUN_000de238(DAT_00338b44, side) != 0 ||
        FUN_000de268(DAT_00338b44, side) != 0) {
        FUN_001b1c44((int)DAT_0034179c, 0x43);
    }
    else {
        if (FUN_000de208(DAT_00338b44, other) != 0 || FUN_000de238(DAT_00338b44, other) != 0 ||
            FUN_000de268(DAT_00338b44, other) != 0) {
            if (self->unk90 != 0)
                FUN_001b1c44((int)DAT_0034179c, 0x4b);
        }
    }
    FUN_001b8260(self);
}
