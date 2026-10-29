/* HSTMATCH module=EBOOT.BIN start=0x00130d60 end=0x0013110c symbol=FUN_00130d60 lang=c++ rodata=0x002c151c */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: every missing case label 0..25 is listed (empty group) so MWCC emits the 26-entry jump table (rodata=0x2c151c), cases in retail body order (0x14 before 0xc/0x17, 0x16 before 0xe), the flag stays a bool passed to a bool parameter, FUN_000df000 takes the global pointer Ghidra dropped; names and types await human review. */
#include "hst/timed_obj.h"

extern "C" {
extern int DAT_0034a678;
struct Game { char pad[0x5d]; unsigned char f5d; };
extern Game *DAT_00338b44;
int FUN_0022c860(void);
void FUN_0001f1fc(void *o, int n);
void FUN_001b9b0c(void *o, bool n);
void FUN_001b9d10(void *o);
void FUN_00124238(TimedSub *o);
void FUN_00124268(TimedSub *o);
int FUN_00125218(TimedSub *o);
int FUN_000df000(Game *g);
void FUN_00123c94(TimedSub *o, int n);
void FUN_001240f4(TimedSub *o);
void FUN_0013096c(TimedObj *o, int n);
void FUN_001237e0(TimedSub *o);
void FUN_000b9edc(void *o);
void FUN_00131e00(void);
}

/* Per-state entry action: sets the sub-object, helpers and mode word that go with the new state.
   State 8 resets all the working fields. Always returns 0. */
extern "C" int FUN_00130d60(TimedObj *self, int state)
{
    switch (state) {
    case 4: {
        bool b = DAT_0034a678 == 0x2a && FUN_0022c860() != 0;
        self->mode = 4;
        FUN_0001f1fc(self->unk7c, 0);
        FUN_0001f1fc(self->unk84, 1);
        FUN_001b9b0c(self->unk84, b);
        if (b) {
            FUN_0001f1fc(self->sub, 1);
            FUN_00124238(self->sub);
            self->unk88 = FUN_00125218(self->sub);
        }
        break;
    }
    case 5: {
        bool b = DAT_0034a678 == 0x2a && FUN_0022c860() != 0;
        FUN_0001f1fc(self->unk7c, 1);
        FUN_0001f1fc(self->unk84, 0);
        FUN_001b9d10(self->unk84);
        if (b) {
            FUN_0001f1fc(self->sub, 0);
            self->sub->unk78 = 0;
        }
        self->mode = 0;
        break;
    }
    case 6:
        FUN_0001f1fc(self->sub, 1);
        FUN_00124268(self->sub);
        self->unk88 = FUN_00125218(self->sub);
        self->mode = 3;
        break;
    case 7:
        FUN_0001f1fc(self->sub, 0);
        self->sub->unk78 = 0;
        self->unk88 = 0;
        self->mode = 0;
        break;
    case 8:
        FUN_0001f1fc(self->sub, 0);
        self->sub->unk78 = 0;
        self->unk88 = 0;
        self->mode = 0;
        self->unkf0 = 1;
        self->unkb0 = 0;
        self->unkb4 = 0;
        self->unkc0 = 0;
        self->unkc4 = 0;
        self->unkc8 = 0;
        self->unkcc = 0x3f800000;
        self->unk90 = 0;
        self->unka0 = 0;
        self->unka4 = 0;
        self->unka8 = 0;
        self->unkac = 0x3f800000;
        self->unkd0 = 0;
        self->unk44 = 0;
        self->unke0 = 0;
        self->unke4 = 0;
        self->unke8 = 0;
        self->unkec = 0x3f800000;
        self->unk128 = 0;
        self->unk12c = 1;
        self->unk130 = 0;
        self->unkf1 = 0;
        self->unkf2 = 0;
        self->unkf3 = 0;
        self->unkf4 = 0;
        self->unkf8 = 0;
        self->unkfc = 0;
        self->unk100 = 0;
        self->unk110 = 0;
        self->unk114 = 0;
        self->unk118 = 0;
        self->unk11c = 0x3f800000;
        break;
    case 0x14:
        if (self->unkf0 != 0) {
            self->unkf0 = 0;
            FUN_00131e00();
        }
        break;
    case 0x17:
    case 0xc:
        self->elapsed = 0;
        self->limit = TIMED_NO_LIMIT;
        if (DAT_00338b44->f5d == 0 && FUN_000df000(DAT_00338b44) == 0) {
            FUN_0001f1fc(self->sub, 1);
            if (state >= 0x10) {
                FUN_001240f4(self->sub);
            } else {
                FUN_00123c94(self->sub, 0);
            }
            self->unk88 = FUN_00125218(self->sub);
            self->mode = 2;
        }
        break;
    case 0xd:
        FUN_0001f1fc(self->sub, 0);
        self->sub->unk78 = 0;
        self->unk88 = 0;
        self->mode = 0;
        break;
    case 0x16:
        self->elapsed = 0;
        self->limit = TIMED_NO_LIMIT;
        break;
    case 0xe:
        self->elapsed = 0;
        self->limit = TIMED_NO_LIMIT;
        FUN_0013096c(self, 0);
        FUN_0001f1fc(self->sub, 1);
        FUN_001237e0(self->sub);
        if (self->sub->unk78 == 0) {
            if (self->sub->unk7a != 0) FUN_000b9edc(self->unk7c);
        }
        self->unk88 = FUN_00125218(self->sub);
        self->mode = 1;
        self->unk134 = 0;
        self->unkf3 = 0;
        break;
    case 0xf:
        FUN_0013096c(self, 0);
        FUN_0001f1fc(self->sub, 0);
        self->sub->unk78 = 0;
        self->unk88 = 0;
        self->mode = 0;
        break;
    case 0x19:
        self->elapsed = 0;
        self->limit = TIMED_NO_LIMIT;
        FUN_0013096c(self, 0);
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 9:
    case 10:
    case 11:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x15:
    case 0x18:
        break;
    }
    return 0;
}
