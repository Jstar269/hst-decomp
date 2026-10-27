/* HSTMATCH module=hstp_trans_main.prx start=0x002422f0 end=0x002424e0 symbol=FUN_002422f0 lang=c++ rodata=0x002da228 */
/* Clone of src/eboot/widget_refresh_002321f0.cpp (hstclone.py tag c072907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. matching idiom: the tests read `int m = self->mode;` back after the store (the parameter itself then stays in a1 for the store). */
struct Ctl {
    virtual void v0();
    virtual void SetEnabled(bool on);
};

struct Item {
    char pad[0x24];
    int a;
    int b;
};

struct Shared {
    char pad0[0x138];
    int f138;
    unsigned char f13c;
};

struct Obj {
    char pad0[0x5c];
    Ctl *ctl5c;
    Ctl *ctl60;
    Item *items[94];
    int mode;
    int sub;
    char pad1[0x200 - 0x1e4];
    int sel[10];
};

extern "C" {
Shared *FUN_0023ce60(void);
void FUN_00105470(Item *, bool);
void FUN_00242658(Obj *, int);
extern int DAT_0039c3b8;
extern int DAT_0039c2b4[];
}

extern "C" void FUN_002422f0(Obj *self, int param_2)
{
    self->mode = param_2;
    int m = self->mode;
    bool notOne = !(m == 1);
    Shared *sh = FUN_0023ce60();
    bool u = sh->f138 == 0;
    unsigned char c13c = sh->f13c;
    self->ctl5c->SetEnabled(!(m == 0));
    self->ctl60->SetEnabled(notOne);
    for (int i = 25; i <= 34; i++) {
        FUN_00105470(self->items[i], 1);
    }
    FUN_00105470(self->items[22], notOne);
    FUN_00105470(self->items[23], notOne);
    FUN_00105470(self->items[19], !u);
    bool b = !c13c;
    FUN_00105470(self->items[20], b);
    FUN_00105470(self->items[21], b);
    int v = DAT_0039c3b8 + u;
    Item *it = self->items[21];
    it->a = v;
    it->b = v;
    switch (self->mode) {
    case 0:
        for (int i = 0; i < 10; i++) {
            int m = self->sel[i];
            switch (m) {
            case 0:
            case 1:
                FUN_00105470(self->items[45 + i], 1);
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                m = (m == 4) ? 2 : m;
                FUN_00105470(self->items[45 + i], 0);
                int val = m - 2 + DAT_0039c2b4[i * 3 + 0x89];
                Item *p = self->items[45 + i];
                p->a = val;
                p->b = val;
            }
        }
        break;
    case 1:
        FUN_00242658(self, self->sub);
        break;
    }
}
