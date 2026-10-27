/* HSTMATCH module=hstp_trans_main.prx start=0x0022a228 end=0x0022a3fc symbol=FUN_0022a228 lang=c++ rodata=0x002d9f14 */
/* Hand-written reconstruction (port of src/eboot/state_switch_0021acb4.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
class Owner {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
};

struct OwnerData {
    char pad0[0x54];
    unsigned char f54;
    char pad1[0xe8 - 0x55];
    int f0e8;
    int tab[1];
};

struct Flags {
    char pad[0x8b];
    signed char a : 2;
    signed char x : 2;
    signed char b : 2;
};

struct Self {
    OwnerData *owner;
    unsigned kind;
};

extern Flags *DAT_003751d4;
extern int DAT_003eaad8;
extern int DAT_003ea8ec;

extern "C" {
void FUN_0022a154(Self *, int);
int FUN_001204dc(int);
void FUN_00108f54(int, int);
int FUN_001205f0(int);
void FUN_001bfc3c(int *, int);

void FUN_0022a228(Self *self)
{
    switch (self->kind) {
    case 1: case 2: case 3: case 4: case 5:
    case 8: case 9: case 10:
    case 14: case 15: case 16: case 17:
        FUN_0022a154(self, 11);
        break;
    case 6: case 7: case 13: case 18:
        if (FUN_001204dc(DAT_003ea8ec) != 0) {
            FUN_00108f54(DAT_003ea8ec, 1);
            if (FUN_001205f0(DAT_003ea8ec) == 0) {
                switch (self->kind) {
                case 13:
                    FUN_0022a154(self, 14);
                    break;
                case 18:
                    FUN_0022a154(self, 8);
                    break;
                case 6:
                    FUN_0022a154(self, 9);
                    break;
                case 7:
                    FUN_0022a154(self, 10);
                    break;
                }
            } else {
                FUN_0022a154(self, 0);
            }
        }
        return;
    default: {
        OwnerData *o = self->owner;
        if (o->f54 != 0 && self->kind == 0) {
            FUN_0022a154(self, o->tab[o->f0e8] + 1);
            self->owner->f54 = 0;
        }
        if (DAT_003751d4->a == 0 || DAT_003751d4->b == 0) {
            if (self->kind == 0) {
                FUN_001bfc3c(&DAT_003eaad8, 12);
                FUN_0022a154(self, 11);
            }
        }
        ((Owner *)self->owner)->m2();
        break;
    }
    }
}
}
