/* HSTMATCH module=hstp_trans_main.prx start=0x0022c6d8 end=0x0022c8b4 symbol=FUN_0022c6d8 lang=c++ */
/* Clone of src/eboot/set_mode_and_layout_0021d164.cpp (hstclone.py tag s10170158a2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Ent { signed char lo : 4; signed char hi : 4; char pad[7]; };
struct Item { char pad[0x24]; int f24; int f28; };
struct Sub { char pad[0x60]; float f60; float f64; char pad68[0x78 - 0x68]; float f78; };
struct Self {
    char pad[0x5c];
    int f5c;
    int f60;
    int f64;
    int f68;
    int f6c;
    Sub *subs[3];
    char pad7c[4];
    Item *p80;
    char pad84[0x8c - 0x84];
    Item *p8c;
    char pad90[0x98 - 0x90];
    Item *p98;
    char pad9c[0xa0 - 0x9c];
    unsigned char fa0;
};
extern "C" {
extern int DAT_0039835c;
extern int DAT_0039895c;
extern int DAT_00398980;
extern int DAT_003989a4;
extern float DAT_003989b8[];
extern float DAT_003989e4;
extern float DAT_003989e8;
extern float DAT_003f34d0;
extern float DAT_003f34d4;
extern float DAT_003f34e0;
extern Ent *DAT_003f4914;
extern char DAT_003eaad8;
void FUN_00108dac(Self *);
int FUN_001c0bb0(char *, int);
void FUN_0022c96c(Self *);
}
static inline float Clamp(const float &v, const float &lo, const float &hi) { return v < lo ? lo : (!(v > hi) ? v : hi); }
extern "C" void FUN_0022c6d8(Self *self, int mode)
{
    self->f5c = mode;
    self->f60 = 0;
    int k = self->f5c;
    Ent *tab = DAT_003f4914;
    int v;
    if (k >= 0 && k < 0x1e) {
        v = tab[k].lo;
    } else {
        v = 5;
    }
    switch (v) {
    case 0:
        self->f60 = 0;
        break;
    case 1:
        self->f60 = 1;
        break;
    case 2:
        self->f60 = 2;
        break;
    case 3:
        self->f60 = 3;
        break;
    case 4:
        self->f60 = 0;
        break;
    }
    self->f64 = DAT_0039835c;
    self->fa0 = 1;
    FUN_0022c96c(self);
    int a = DAT_0039895c + self->f60;
    Item *it = self->p80;
    it->f24 = a;
    it->f28 = a;
    int b = DAT_00398980 + self->f60;
    Item *it2 = self->p8c;
    it2->f24 = b;
    it2->f28 = b;
    int c = DAT_003989a4 + self->f60;
    Item *it3 = self->p98;
    it3->f24 = c;
    it3->f28 = c;
    int i = 0;
    do {
        self->subs[i]->f60 = DAT_003f34d0;
        self->subs[i]->f64 = DAT_003f34d4 + DAT_003989b8[self->f68];
        self->subs[i]->f78 = Clamp(DAT_003f34e0, DAT_003989e4, DAT_003989e8);
        i++;
    } while (i < 3);
    FUN_00108dac(self);
    self->f6c = FUN_001c0bb0(&DAT_003eaad8, 0xd);
}
