/* HSTMATCH module=EBOOT.BIN start=0x001e29e0 end=0x001e2a54 symbol=FUN_001e29e0 lang=c99 */
/* Hand-written reconstruction (external matching lane): the two arms must read DAT_002eb9a0 at their
   top (address materialised first, value loaded after the 0x3c/0x60 chain) - hoisting `iVar1 =
   DAT_002eb9a0;` above the if, or reading it after the pointer in the else arm, changes which
   instruction mwcc copies into the bnel delay slot and costs 2-7 words. Exact match verified;
   names and types await human review. */
#include "hst/result_screen.h"

extern int DAT_002eb9a0;
extern unsigned char DAT_003417b8;
extern void FUN_000ffb3c(void *);

/* Set both values of the score box to the base number (plus one when the flag is 1). */
void FUN_001e29e0(ResultScreen *self)
{
    int value;
    ScoreBox *box;

    FUN_000ffb3c(self->ui->unk60);
    if (DAT_003417b8 == 1) {
        value = DAT_002eb9a0 + 1;
        box = self->ui->unk60;
        box->unk24 = value;
        box->unk28 = value;
    } else {
        value = DAT_002eb9a0;
        box = self->ui->unk60;
        box->unk24 = value;
        box->unk28 = value;
    }
}
