/* HSTMATCH module=hstp_trans_main.prx start=0x0020fdd4 end=0x0020fef4 symbol=FUN_0020fdd4 lang=c++ */
/* Clone of src/eboot/state_machine_step_00201604.cpp (hstclone.py tag c17b07b): addresses substituted; exact match verified; names and types await human review. */
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
extern Game *DAT_003f3474;
void FUN_00105470(void *, int);
void FUN_00108558(Sub *);
void FUN_00210050(Obj *);
void FUN_0020f39c(Obj *, void *, void *);
}

extern "C" void FUN_0020fdd4(Obj *o)
{
    switch (o->state) {
    case 1:
        o->cnt++;
        if (o->cnt >= 11) {
            FUN_00105470(o->p558, 0);
            o->p20->f60 = 0;
            FUN_00108558(o->p20);
            FUN_00210050(o);
            o->state++;
            o->cnt = 0;
        }
        break;
    case 2:
        o->cnt++;
        if (o->cnt >= 11) {
            FUN_00105470(o->p56c, 0);
            o->p708->s1(0);
            if (DAT_003f3474->fc4 != 0) {
                o->pc->s1(0);
            }
            o->state++;
            o->cnt = 0;
        }
        FUN_0020f39c(o, (char *)DAT_003f3474 + 0xcd0, (char *)DAT_003f3474 + 0xf90);
        break;
    case 3:
        break;
    }
}
