/* HSTMATCH module=EBOOT.BIN start=0x001b1d10 end=0x001b1e24 symbol=FUN_001b1d10 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag fm6 near miss, wip/select_target_001b1d10.cpp) corrected by hand: result computed in a local r and copied to the address-taken res before the r >= 0 test (matching idiom: the r/res split gives the single store in the bltz delay slot); range test written >= 0x1d && <= 0x74 (slti v0); exact match verified; names and types await human review. */
struct Entry {
    int id;
    int name;
};
extern "C" struct Entry DAT_002e5fe8[];
extern "C" int FUN_00014a40(int);
extern "C" void FUN_000628b4(int, int, int);
extern "C" int FUN_00062b64(int, int, int);
extern "C" void FUN_001b2218(int *, int *, int, int, int);

extern "C" int FUN_001b1d10(int *param_1, int param_2, int param_3, int param_4)
{
    int *base = (int *)*param_1;
    struct Entry *e = &DAT_002e5fe8[param_2];
    int idx = e->id;
    int res;

    if (param_2 >= 0x1d && param_2 <= 0x74)
        idx += base[0x79c / 4];
    bool ok = idx < 0x1da && base[idx];
    int r;
    if (!ok)
        r = -1;
    else {
        if (!FUN_00014a40(e->name))
            FUN_000628b4(base[idx], 0, 0);
        r = FUN_00062b64(base[idx], e->name, 0);
    }
    res = r;
    if (r >= 0)
        FUN_001b2218(param_1, &res, param_3, param_4, 0);
    return res;
}
