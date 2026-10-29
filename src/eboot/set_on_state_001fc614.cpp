/* HSTMATCH module=EBOOT.BIN start=0x001fc614 end=0x001fc718 symbol=FUN_001fc614 lang=c++ */
/* Hand-written reconstruction from the disassembly (EBOOT twin of src/sharing_main/set_on_state_0020ad2c.cpp, identical masked code: addresses substituted); exact match verified (matching idiom: the negated flag passed to FUN_001fbdb8 is written `(on != 0) ^ 1`, which keeps retail's sltu/xori/andi; `!on` drops the andi and permutes every saved register); names and types await human review. */
/* Without part C only the mode is set (FUN_001fc718(self, HOLDER_MODE_NONE)); otherwise the flag is stored in the
   object, in part C and in part A (after FUN_00103628), and part C's two last widgets are switched on or off
   with the matching mode (ON plus the call FUN_001b1c44(&DAT_0034179c, 14) when on, OFF when off). */
#include "hst/part_holder.h"

extern "C" {
void FUN_001fc718(PartHolder *, int);
void FUN_001fbdb8(PartC *, unsigned char);
void FUN_00103628(PartA *, int);
void FUN_000ffb3c(void *, int);
int FUN_001b1c44(char *, int);
extern char DAT_0034179c;
}

extern "C" void FUN_001fc614(PartHolder *self, int on)
{
    if (self->partC == 0) {
        FUN_001fc718(self, HOLDER_MODE_NONE);
    } else {
        self->enabled = on;
        self->partC->unk7c = on;
        FUN_001fbdb8(self->partC, (on != 0) ^ 1);
        PartA *a = self->partA;
        FUN_00103628(a, on);
        a->enabled = on;
        if (self->enabled != 0) {
            PartC *c = self->partC;
            c->unk7d = 1;
            c->unk7c = 0;
            FUN_000ffb3c(c->widget[4], 1);
            FUN_000ffb3c(c->widget[5], 1);
            FUN_001fc718(self, HOLDER_MODE_ON);
            FUN_001b1c44(&DAT_0034179c, 14);
        } else {
            PartC *c = self->partC;
            c->unk7d = 0;
            c->unk7c = 1;
            FUN_000ffb3c(c->widget[4], 0);
            FUN_000ffb3c(c->widget[5], 0);
            FUN_001fc718(self, HOLDER_MODE_OFF);
        }
    }
}
