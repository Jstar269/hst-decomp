/* HSTMATCH module=EBOOT.BIN start=0x002067c0 end=0x002068e8 symbol=FUN_002067c0 lang=c++ */
/* Hand-written reconstruction from the disassembly (matching idioms: Min/Max inlines taking const int& and returning by value for the double global load; `n >= 3` on a local copy of the incremented counter); exact match verified; names and types await human review. */
struct Game {
    char pad[0x3c];
    int f3c;
};
struct Ctx {
    char pad[0x61];
    unsigned char f61;
    char pad2[0x90 - 0x62];
    int f90;
    char pad3[0x9c - 0x94];
    unsigned f9c;
};
struct Self {
    char pad[0x144];
    unsigned f144;
    char pad2[0x408 - 0x148];
    unsigned char f408;
    char pad3[0x820 - 0x409];
    int f820;
    int f824;
};
extern "C" Game *DAT_003386b0;
extern "C" Ctx *DAT_00338b44;
extern "C" int DAT_002ef75c;
extern "C" int DAT_002ef760;
extern "C" int DAT_002ef764;

static inline int Min(const int &a, const int &b)
{
    return (b < a) ? b : a;
}
static inline int Max(const int &a, const int &b)
{
    return (a < b) ? b : a;
}

extern "C" void FUN_002067c0(Self *self)
{
    if (self->f408 != 0 && DAT_003386b0->f3c != 7) {
        Ctx *c = DAT_00338b44;
        switch (c->f90) {
        case 0:
            break;
        case 1:
            if ((self->f144 ^ 1) == c->f9c) {
                self->f820 = Max(self->f820 - 1, DAT_002ef75c);
                self->f824 = 0;
            }
            break;
        case 2:
            if (self->f144 == c->f9c && c->f61 == 0) {
                self->f820 = Min(self->f820 + 1, DAT_002ef760);
                self->f824 = 0;
            }
            break;
        default: {
            int n = self->f824 + 1;
            self->f824 = n;
            if (n >= 3) {
                self->f824 = 0;
                self->f820 = Min(self->f820 + 1, DAT_002ef764);
            }
            break;
        }
        }
    }
}
