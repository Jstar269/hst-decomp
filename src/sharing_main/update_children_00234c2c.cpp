/* HSTMATCH module=hstp_trans_main.prx start=0x00234c2c end=0x00234e10 symbol=FUN_00234c2c lang=c++ */
/* Clone of src/eboot/update_children_002256b8.cpp (hstclone.py tag c072907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* While the global mode is 0x20 or 2: let FUN_0022a3fc handle the holder at +0x28 unless its state is 11, then (flag DAT_00398358) run virtual slot 3 of the child objects, with state 11 / state 0 specific work first, and finally FUN_000fc33c on +0x30 when DAT_00398359 is set. The calls through `lw t9,0(a0); lw t9,20(t9)` are C++ virtual calls (slot 3; slot 2 for the main object). */
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
extern int DAT_003f39a8;
extern unsigned char DAT_00398358;
extern unsigned char DAT_00398359;
extern Game *DAT_003f344c;
extern int DAT_003ba2c4;
void FUN_0022a3fc(Holder *h);
int FUN_001db984(Game *g);
void FUN_0022a5fc(VObj *o, int a, int b, int c);
void FUN_00108aec(VObj *o);
void FUN_000430d8(float f, int x);
void FUN_000fc33c(void *p);
}

extern "C" void FUN_00234c2c(Self *self)
{
    if (DAT_003f39a8 == 0x20 || DAT_003f39a8 == 2) {
        if (self->f28->state != 11) {
            FUN_0022a3fc(self->f28);
        }
        if (DAT_00398358 != 0) {
            if (self->f28->state == 11) {
                self->f0->v3();
                self->f20->v3();
                if (DAT_003f344c != 0 && FUN_001db984(DAT_003f344c) == 0) {
                    self->f4->v3();
                }
            } else if (self->f28->state == 0) {
                Main *m;
                FUN_0022a5fc(self->f0, DAT_003f344c->fcc + 1, DAT_003f344c->fd0 + 1, 1);
                m = self->f0;
                m->f5c = 1;
                m->v2();
                FUN_00108aec(m);
                FUN_000430d8(100000.0f, DAT_003ba2c4);
            }
            self->f8->v3();
            self->fc->v3();
            self->f10->v3();
            self->f18->v3();
            self->f1c->v3();
            self->f24->v3();
        }
        if (DAT_00398359 != 0) {
            FUN_000fc33c(self->f30);
        }
    }
}
