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
    unsigned char flag5c; /* 0x5c */
};
struct Holder { /* object plus its state id */
    VObj *obj;
    int state;
};
struct Game {
    char pad[0xcc];
    int unkcc;
    int unkd0;
};
/* Same layout as ModeParts (the part set reached through +0x3c), typed for the virtual calls. */
struct PartSet {
    Main *part00;
    VObj *part04;
    VObj *part08;
    VObj *part0c;
    VObj *part10;
    VObj *part14;
    VObj *part18;
    VObj *part1c;
    VObj *part20;
    VObj *part24;
    Holder *part28;
    int part2c;
    void *part30;
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

extern "C" void FUN_002256b8(PartSet *parts)
{
    if (DAT_0034a678 == 0x20 || DAT_0034a678 == 2) {
        if (parts->part28->state != 11) {
            FUN_0021ae88(parts->part28);
        }
        if (DAT_002eff8c != 0) {
            if (parts->part28->state == 11) {
                parts->part00->v3();
                parts->part20->v3();
                if (DAT_0034a114 != 0 && FUN_001cd2a8(DAT_0034a114) == 0) {
                    parts->part04->v3();
                }
            } else if (parts->part28->state == 0) {
                Main *m;
                FUN_0021b088(parts->part00, DAT_0034a114->unkcc + 1, DAT_0034a114->unkd0 + 1, 1);
                m = parts->part00;
                m->flag5c = 1;
                m->v2();
                FUN_001031e8(m);
                FUN_00042ff4(100000.0f, DAT_00310fc4);
            }
            parts->part08->v3();
            parts->part0c->v3();
            parts->part10->v3();
            parts->part18->v3();
            parts->part1c->v3();
            parts->part24->v3();
        }
        if (DAT_002eff8d != 0) {
            FUN_000f6c48(parts->part30);
        }
    }
}
