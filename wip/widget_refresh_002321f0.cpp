/* HSTMATCH module=EBOOT.BIN start=0x002321f0 end=0x002323e0 symbol=FUN_002321f0 lang=c++ rodata=0x002c9c68 */
struct Ctl {
    virtual void v0();
    virtual void SetEnabled(int on);
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
Shared *FUN_0022cd60(void);
void FUN_000ffb3c(Item *, int);
void FUN_00232558(Obj *, int);
extern int DAT_002f3af4;
extern int DAT_002f39f0[];
}

extern "C" void FUN_002321f0(Obj *self, int param_2)
{
    bool notOne = !(param_2 == 1);
    self->mode = param_2;
    Shared *sh = FUN_0022cd60();
    unsigned char c13c = sh->f13c;
    bool u = sh->f138 == 0;
    self->ctl5c->SetEnabled(!(param_2 == 0));
    self->ctl60->SetEnabled(notOne);
    for (int i = 25; i < 35; i++) {
        FUN_000ffb3c(self->items[i], 1);
    }
    FUN_000ffb3c(self->items[22], notOne);
    FUN_000ffb3c(self->items[23], notOne);
    FUN_000ffb3c(self->items[19], u == 0);
    bool b = c13c == 0;
    FUN_000ffb3c(self->items[20], b);
    FUN_000ffb3c(self->items[21], b);
    int v = DAT_002f3af4 + u;
    Item *it = self->items[21];
    it->a = v;
    it->b = v;
    if (self->mode == 1) {
        FUN_00232558(self, self->sub);
    } else if (self->mode == 0) {
        for (int i = 0; i < 10; i++) {
            int m = self->sel[i];
            switch (m) {
            case 0:
            case 1:
                FUN_000ffb3c(self->items[45 + i], 1);
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                if (m == 4) {
                    m = 2;
                }
                FUN_000ffb3c(self->items[45 + i], 0);
                int val = m - 2 + DAT_002f39f0[i * 3 + 0x89];
                Item *p = self->items[45 + i];
                p->a = val;
                p->b = val;
            }
        }
    }
}
// Parked (sn5, 126 vs 124 words, not close): structure and callee shapes are in place; the jump table needs rodata=0x002c9c68 (lui 0x2d + addiu -25496 =
// 0x2c9c68, not 0x2d9c68). Idioms found: `bool notOne = !(param_2 == 1)` (xori;sltiu;xori;andi in the jal slot), `SetEnabled(int)` called with `!(param_2 == 0)`
// (no andi), `unsigned`/`bool u = f138 == 0` kept raw with `andi a2,s0,0xff` only at the add, `Item *it = self->items[21]; it->a = v; it->b = v;` (one pointer load),
// the two loops index `items[i]` from a base at +0x64 (items[25..34], items[45+i]) and `sel[i]` at +0x200 with the compiler walking `self` itself in steps of 4.
// Open: saved-register numbering (retail notOne=s3, c13c=s5, self=s4, u=s0, loop counter s2/pointer s1; ours c13c=s0, notOne=s1) and the loop's table pointer / m registers;
// `sw a1,476(a0)` stores the incoming a1 (ours s0). Declaration/statement permutations of the head did not change the numbering.
// near miss from lane sn5 (unreviewed)
