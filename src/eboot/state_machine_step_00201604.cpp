/* HSTMATCH module=EBOOT.BIN start=0x00201604 end=0x00201724 symbol=FUN_00201604 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct VC {
    virtual void s0();
    virtual void s1(int);
};

struct Sub {
    char pad[0x60];
    int f60;
};

struct Game {
    char pad[0xc4];
    unsigned char fc4;
};

struct Obj {
    char pad0[0xc];
    VC *pc;
    char pad1[0x20 - 0x10];
    Sub *p20;
    char pad2[0x558 - 0x24];
    void *p558;
    char pad3[0x56c - 0x55c];
    void *p56c;
    char pad4[0x708 - 0x570];
    VC *p708;
    int pad5;
    int state;
    int cnt;
};

extern "C" {
extern Game *DAT_0034a13c;
void FUN_000ffb3c(void *, int);
void FUN_00102c54(Sub *);
void FUN_00201880(Obj *);
void FUN_00200bcc(Obj *, void *, void *);
}

extern "C" void FUN_00201604(Obj *o)
{
    switch (o->state) {
    case 1:
        o->cnt++;
        if (o->cnt >= 11) {
            FUN_000ffb3c(o->p558, 0);
            o->p20->f60 = 0;
            FUN_00102c54(o->p20);
            FUN_00201880(o);
            o->state++;
            o->cnt = 0;
        }
        break;
    case 2:
        o->cnt++;
        if (o->cnt >= 11) {
            FUN_000ffb3c(o->p56c, 0);
            o->p708->s1(0);
            if (DAT_0034a13c->fc4 != 0) {
                o->pc->s1(0);
            }
            o->state++;
            o->cnt = 0;
        }
        FUN_00200bcc(o, (char *)DAT_0034a13c + 0xcd0, (char *)DAT_0034a13c + 0xf90);
        break;
    case 3:
        break;
    }
}
