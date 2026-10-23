/* NEAR 87/86 words, 53 differ (first +0x48). Float-argument twin of 0x001b1d10:
   same body, parameters (int*, int, int, int, float x4); the tail passes the four
   floats and two extra zero ints to FUN_001b2240. Everything matches except the same
   shared-store/fold issue as 0x001b1d10 (the else path keeps its own `sw res`), plus
   MWCC colouring the range test `slti at` where retail has `slti v0`. */
/* HSTMATCH module=EBOOT.BIN start=0x001b1e24 end=0x001b1f7c symbol=FUN_001b1e24 lang=c++ */
struct Entry {
    int id;
    int name;
};
extern "C" struct Entry DAT_002e5fe8[];
extern "C" int FUN_00014a40(int);
extern "C" void FUN_000628b4(int, int, int);
extern "C" int FUN_00062b64(int, int, int);
extern "C" void FUN_001b2240(int *, int *, int, int, int, int,
                             float, float, float, float);

extern "C" int FUN_001b1e24(int *param_1, int param_2, int param_3, int param_4,
                            float f1, float f2, float f3, float f4)
{
    int *base = (int *)*param_1;
    struct Entry *e = &DAT_002e5fe8[param_2];
    int idx = e->id;
    int res;

    if (param_2 > 0x1c && param_2 < 0x75)
        idx += base[0x79c / 4];
    bool ok = idx < 0x1da && base[idx];
    if (!ok)
        res = -1;
    else {
        if (!FUN_00014a40(e->name))
            FUN_000628b4(base[idx], 0, 0);
        res = FUN_00062b64(base[idx], e->name, 0);
        if (res >= 0)
            FUN_001b2240(param_1, &res, param_3, param_4, 0, 0,
                         f1, f2, f3, f4);
    }
    return res;

    return res;
}
// near miss from lane fm6 (unreviewed)
