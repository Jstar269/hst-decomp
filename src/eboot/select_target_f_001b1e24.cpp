/* HSTMATCH module=EBOOT.BIN start=0x001b1e24 end=0x001b1f7c symbol=FUN_001b1e24 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Entry {
    int id;
    int name;
};
extern "C" struct Entry DAT_002e5fe8[];
extern "C" int FUN_00014a40(int);
extern "C" void FUN_000628b4(int, int, int);
extern "C" int FUN_00062b64(int, int, int);
extern "C" void FUN_001b2240(int *, int *, int, float, float, float, float,
                             int, int, int);

static inline int Load(int *base, int idx, Entry *e)
{
    bool ok = idx < 0x1da && base[idx];
    if (!ok)
        return -1;
    if (!FUN_00014a40(e->name))
        FUN_000628b4(base[idx], 0, 0);
    return FUN_00062b64(base[idx], e->name, 0);
}

extern "C" int FUN_001b1e24(int *param_1, int param_2, int param_3,
                            float f1, float f2, float f3, float f4, int param_4)
{
    int *base = (int *)*param_1;
    struct Entry *e = &DAT_002e5fe8[param_2];
    int idx = e->id;
    int res;

    if (param_2 >= 0x1d && param_2 < 0x75)
        idx += base[0x79c / 4];
    res = Load(base, idx, e);
    if (res >= 0)
        FUN_001b2240(param_1, &res, param_3, f1, f2, f3, f4, param_4, 0, 0);
    return res;
}
