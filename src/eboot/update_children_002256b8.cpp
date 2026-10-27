/* HSTMATCH module=EBOOT.BIN start=0x002256b8 end=0x0022589c symbol=FUN_002256b8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* While the global mode is 0x20 or 2: let FUN_0021ae88 handle the holder at +0x28 unless its state is 11, then (flag DAT_002eff8c) run virtual slot 3 of the child objects, with state 11 / state 0 specific work first, and finally FUN_000f6c48 on +0x30 when DAT_002eff8d is set. The calls through `lw t9,0(a0); lw t9,20(t9)` are C++ virtual calls (slot 3; slot 2 for the main object). */
struct VObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};
struct Main : VObj {
    char pad[0x5c - 4];
    unsigned char f5c;
};
struct Holder {
    VObj *obj;
    int state;
};
struct Game {
    char pad[0xcc];
    int fcc;
    int fd0;
};
struct Self {
    Main *f0;
    VObj *f4;
    VObj *f8;
    VObj *fc;
    VObj *f10;
    VObj *f14;
    VObj *f18;
    VObj *f1c;
    VObj *f20;
    VObj *f24;
    Holder *f28;
    int f2c;
    void *f30;
};
extern "C" {
extern int DAT_0034a678;
extern unsigned char DAT_002eff8c;
extern unsigned char DAT_002eff8d;
extern Game *DAT_0034a114;
extern int DAT_00310fc4;
void FUN_0021ae88(Holder *h);
int FUN_001cd2a8(Game *g);
void FUN_0021b088(VObj *o, int a, int b, int c);
void FUN_001031e8(VObj *o);
void FUN_00042ff4(float f, int x);
void FUN_000f6c48(void *p);
}

extern "C" void FUN_002256b8(Self *self)
{
    if (DAT_0034a678 == 0x20 || DAT_0034a678 == 2) {
        if (self->f28->state != 11) {
            FUN_0021ae88(self->f28);
        }
        if (DAT_002eff8c != 0) {
            if (self->f28->state == 11) {
                self->f0->v3();
                self->f20->v3();
                if (DAT_0034a114 != 0 && FUN_001cd2a8(DAT_0034a114) == 0) {
                    self->f4->v3();
                }
            } else if (self->f28->state == 0) {
                Main *m;
                FUN_0021b088(self->f0, DAT_0034a114->fcc + 1, DAT_0034a114->fd0 + 1, 1);
                m = self->f0;
                m->f5c = 1;
                m->v2();
                FUN_001031e8(m);
                FUN_00042ff4(100000.0f, DAT_00310fc4);
            }
            self->f8->v3();
            self->fc->v3();
            self->f10->v3();
            self->f18->v3();
            self->f1c->v3();
            self->f24->v3();
        }
        if (DAT_002eff8d != 0) {
            FUN_000f6c48(self->f30);
        }
    }
}
