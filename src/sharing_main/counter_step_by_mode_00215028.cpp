/* HSTMATCH module=hstp_trans_main.prx start=0x00215028 end=0x00215150 symbol=FUN_00215028 lang=c++ */
/* Clone of src/eboot/counter_step_by_mode_002067c0.cpp (hstclone.py tag c17b07b): addresses substituted; exact match verified; names and types await human review. */
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
extern "C" Game *DAT_003e19f0;
extern "C" Ctx *DAT_003e1e84;
extern "C" int DAT_00397850;
extern "C" int DAT_00397854;
extern "C" int DAT_00397858;

static inline int Min(const int &a, const int &b)
{
    return (b < a) ? b : a;
}
static inline int Max(const int &a, const int &b)
{
    return (a < b) ? b : a;
}

extern "C" void FUN_00215028(Self *self)
{
    if (self->f408 != 0 && DAT_003e19f0->f3c != 7) {
        Ctx *c = DAT_003e1e84;
        switch (c->f90) {
        case 0:
            break;
        case 1:
            if ((self->f144 ^ 1) == c->f9c) {
                self->f820 = Max(self->f820 - 1, DAT_00397850);
                self->f824 = 0;
            }
            break;
        case 2:
            if (self->f144 == c->f9c && c->f61 == 0) {
                self->f820 = Min(self->f820 + 1, DAT_00397854);
                self->f824 = 0;
            }
            break;
        default: {
            int n = self->f824 + 1;
            self->f824 = n;
            if (n >= 3) {
                self->f824 = 0;
                self->f820 = Min(self->f820 + 1, DAT_00397858);
            }
            break;
        }
        }
    }
}
