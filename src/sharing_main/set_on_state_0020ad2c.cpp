/* HSTMATCH module=hstp_trans_main.prx start=0x0020ad2c end=0x0020ae30 symbol=FUN_0020ad2c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idiom: the negated flag passed to FUN_0020a4d0 is written `(on != 0) ^ 1`, which keeps retail's sltu/xori/andi; `!on` drops the andi and permutes every saved register); names and types await human review. */
/* Without part C only the mode is set (FUN_0020ae30(self, HOLDER_MODE_NONE)); otherwise the flag is stored in the
   object, in part C and in part A (after FUN_00108f54), and part C's two last widgets are switched on or off
   with the matching mode (ON plus the call FUN_001bfc3c(&DAT_003eaad8, 14) when on, OFF when off). */
#include "hst/part_holder.h"

extern "C" {
void FUN_0020ae30(PartHolder *, int);
void FUN_0020a4d0(PartC *, unsigned char);
void FUN_00108f54(PartA *, int);
void FUN_00105470(void *, int);
int FUN_001bfc3c(char *, int);
extern char DAT_003eaad8;
}

extern "C" void FUN_0020ad2c(PartHolder *self, int on)
{
    if (self->partC == 0) {
        FUN_0020ae30(self, HOLDER_MODE_NONE);
    } else {
        self->enabled = on;
        self->partC->unk7c = on;
        FUN_0020a4d0(self->partC, (on != 0) ^ 1);
        PartA *a = self->partA;
        FUN_00108f54(a, on);
        a->enabled = on;
        if (self->enabled != 0) {
            PartC *c = self->partC;
            c->unk7d = 1;
            c->unk7c = 0;
            FUN_00105470(c->widget[4], 1);
            FUN_00105470(c->widget[5], 1);
            FUN_0020ae30(self, HOLDER_MODE_ON);
            FUN_001bfc3c(&DAT_003eaad8, 14);
        } else {
            PartC *c = self->partC;
            c->unk7d = 0;
            c->unk7c = 1;
            FUN_00105470(c->widget[4], 0);
            FUN_00105470(c->widget[5], 0);
            FUN_0020ae30(self, HOLDER_MODE_OFF);
        }
    }
}
