/* HSTMATCH module=hstp_trans_main.prx start=0x001b8b60 end=0x001b8e10 symbol=FUN_001b8b60 lang=c++ */
/* Clone of src/eboot/update_sub_mode_001ab530.cpp (hstclone.py tag c162207): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct SubObj {
    virtual void func0();
    virtual void funcC(...);
};

struct G {
    char pad0[0x11c];
    unsigned char mode; /* 0x11c */
    char pad1[0x3a0 - 0x11d];
    unsigned char c;    /* 0x3a0 */
};

struct Obj {
    void *vtable;       /* 0x00 */
    SubObj *sub[2];     /* 0x04 */
    SubObj *alt_sub[4]; /* 0x0c */
    char pad_1c[0xaa4 - 0x1c];
    unsigned char f_aa4;/* 0xaa4 */
};

extern "C" {
G *FUN_001aa91c();
void FUN_001b807c(Obj *, int, int, int);
void FUN_001b7f74(Obj *, int, int);
}

extern "C" void FUN_001b8b60(Obj *self, int param_2)
{
    G *g = FUN_001aa91c();
    int c = FUN_001aa91c()->c;
    self->f_aa4 = c;
    unsigned char mode = g->mode;

    switch (mode) {
    case 0:
    case 4:
        if (c != 0) {
            switch (param_2) {
            case 0:
                self->sub[0]->funcC();
                break;
            case 1:
                self->sub[1]->funcC(1);
                break;
            }
        } else {
            int s4, s3;
            bool ok = true;
            if (param_2 == 0) {
                self->sub[0]->funcC(0);
                s4 = 0;
                s3 = 0;
            } else if (param_2 == 2) {
                self->sub[1]->funcC(0);
                s4 = 10;
                s3 = 5;
            } else {
                ok = false;
            }
            if (ok) {
                FUN_001b807c(self, param_2, s4, s3);
                FUN_001b7f74(self, param_2, s4);
            }
        }
        break;

    default:
        if (c != 0) {
            switch (param_2) {
            case 0:
                self->alt_sub[0]->funcC();
                break;
            case 1:
                self->alt_sub[1]->funcC(1);
                break;
            case 2:
                self->alt_sub[2]->funcC(1);
                break;
            case 3:
                self->alt_sub[3]->funcC(1);
                break;
            }
        } else {
            int s4, s3;
            bool ok = true;
            if (param_2 == 0) {
                self->alt_sub[0]->funcC(0);
                s4 = 20;
                s3 = 10;
            } else if (param_2 == 1) {
                self->alt_sub[1]->funcC(0);
                s4 = 30;
                s3 = 15;
            } else if (param_2 == 2) {
                self->alt_sub[2]->funcC(0);
                s4 = 40;
                s3 = 20;
            } else if (param_2 == 3) {
                self->alt_sub[3]->funcC(0);
                s4 = 50;
                s3 = 25;
            } else {
                ok = false;
            }
            if (ok) {
                FUN_001b807c(self, param_2, s4, s3);
                FUN_001b7f74(self, param_2, s4);
            }
        }
        break;
    }
}
