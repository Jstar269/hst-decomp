/* HSTMATCH module=EBOOT.BIN start=0x0020b62c end=0x0020b7a0 symbol=FUN_0020b62c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idioms: bool/flag locals loaded before the first test, `(flag != 0) ^ 1`, Min/Max inlines taking const int& and returning by value); names and types await human review. */
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
extern Cfg *DAT_00338b44;
extern int DAT_0034a678;
extern int DAT_00341504;
extern int DAT_002ef86c;
extern int DAT_002ef870;
extern int DAT_002ef874;
extern unsigned char DAT_00341834[];
extern unsigned char DAT_00341898[];

static inline int Min(const int &a, const int &b)
{
    return (b < a) ? b : a;
}
static inline int Max(const int &a, const int &b)
{
    return (a < b) ? b : a;
}

extern "C" int FUN_0020b62c(Self *self)
{
    int v = DAT_00341834[self->idx * 0x120];
    if (DAT_00341898[self->idx * 0x120] != 0) {
        bool is31 = DAT_0034a678 == 0x31;
        Cfg *cfg = DAT_00338b44;
        unsigned char flag = cfg->flag;
        if ((flag != 0) ^ 1) {
            if (DAT_00341898[((self->idx + 2) % 4) * 0x120] == 0) {
                v = Min(v + DAT_00341504, DAT_002ef86c);
            }
        }
        if (is31 && v == 15 && self->f144 == 1) {
            v = 16;
        }
        if (flag != 0 && v < 16) {
            int d = cfg->value90 / 10;
            v -= Min(d, DAT_002ef870);
            v = Max(v, DAT_002ef874);
        }
    }
    return v;
}
