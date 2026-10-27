/* HSTMATCH module=hstp_trans_main.prx start=0x0021a14c end=0x0021a2c0 symbol=FUN_0021a14c lang=c++ */
/* Hand-written reconstruction (port of src/eboot/clamped_slot_value_0020b62c.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
struct Cfg {
    char pad[0x45];
    unsigned char flag;
    char pad2[0x90 - 0x46];
    int value90;
};
struct Self {
    char pad[0x144];
    int f144;
    int idx;
};
extern Cfg *DAT_003e1e84;
extern int DAT_003f39a8;
extern int DAT_003ea844;
extern int DAT_00397a4c;
extern int DAT_00397a50;
extern int DAT_00397a54;
extern unsigned char DAT_003eab6c[];
extern unsigned char DAT_003eabd0[];

static inline int Min(const int &a, const int &b)
{
    return (b < a) ? b : a;
}
static inline int Max(const int &a, const int &b)
{
    return (a < b) ? b : a;
}

extern "C" int FUN_0021a14c(Self *self)
{
    int v = DAT_003eab6c[self->idx * 0x120];
    if (DAT_003eabd0[self->idx * 0x120] != 0) {
        bool is31 = DAT_003f39a8 == 0x31;
        Cfg *cfg = DAT_003e1e84;
        unsigned char flag = cfg->flag;
        if ((flag != 0) ^ 1) {
            if (DAT_003eabd0[((self->idx + 2) % 4) * 0x120] == 0) {
                v = Min(v + DAT_003ea844, DAT_00397a4c);
            }
        }
        if (is31 && v == 15 && self->f144 == 1) {
            v = 16;
        }
        if (flag != 0 && v < 16) {
            int d = cfg->value90 / 10;
            v -= Min(d, DAT_00397a50);
            v = Max(v, DAT_00397a54);
        }
    }
    return v;
}
