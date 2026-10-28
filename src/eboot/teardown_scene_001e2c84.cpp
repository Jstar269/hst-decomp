/* HSTMATCH module=EBOOT.BIN start=0x001e2c84 end=0x001e2da8 symbol=FUN_001e2c84 lang=c++ */
/* Hand-written reconstruction (external matching lane). Notes: a virtual call to retail's slot 0xc
   must be written as the SECOND declared virtual (mwcc puts declared virtual #0 at vtable offset 8
   and #1 at 0xc in this build), and the C++ TU needs every extern inside `extern "C" { }` or hstmatch
   reports MISSING_SYMBOLS with the mangled names. FUN_001e4b4c's second argument is a float 0.0f
   (mtc1 zero,$f12), not an int. The score pair repeats init_score_pair_001e29e0 with DAT read first
   in both arms. Exact match verified; names and types await human review. */
#include "hst/result_screen.h"

extern "C" {
extern int DAT_002eb9a0;
extern unsigned char DAT_003417b8;
extern void FUN_000ffb3c(void *, int);
extern void FUN_001e09dc(ResultScreen *, int);
extern void FUN_001e2694();
extern void FUN_001e30a8(ResultScreen *, int);
extern void FUN_001e4b4c(ResultScreen *, float);
}

/* Object whose virtual call at vtable slot 0xc is the second declared virtual. */
struct UiTarget {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

/* Switch object: w1 is the integer setter. */
struct ResultSwitch {
    virtual void w0();
    virtual void w1(int);
    virtual void w2();
    virtual void w3();
};

extern "C" void FUN_001e2c84(ResultScreen *self)
{
    int value;
    ScoreBox *box;
    ResultSwitch *sw;

    FUN_001e2694();
    FUN_001e09dc(self, 1);
    ((UiTarget *)self->ui)->v1();
    FUN_000ffb3c(self->ui->unk60, 0);
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
    sw = self->ui->unk58;
    sw->w1(1);
    sw = self->ui->unk5c;
    sw->w1(0);
    FUN_000ffb3c(self->ui->unk7c, 0);
    FUN_000ffb3c(self->ui->unk84, 0);
    FUN_000ffb3c(self->ui->unk80, 0);
    FUN_000ffb3c(self->ui->unk88, 0);
    FUN_001e30a8(self, 1);
    FUN_001e4b4c(self, 0.0f);
}
