/* NEAR 70/69 words, 39 differ (first +0x38). Best source for 0x001b1d10.
   Matches the whole prologue/body: the bool `ok` must be C++ (idx < 0x1da && base[idx]
   gives sltu v0,zero,v0 + bnezl into the body) and the else must be written first
   (`if (!ok) res = -1; else {...}`) so retail's `bnezl ok,body` / `b epilogue` order appears.
   What still differs: retail stores `res` exactly once, in the delay of the final
   `bltz` (shared by both paths); MWCC here stores it in the else block's `b` delay
   AND again at the join (one extra word), and folds `res >= 0` for the -1 path.
   Ruled out: bool ok = false; if(idx<474) ok=... (adds move v1,zero), plain
   if/else (64 words), int res = -1 initialiser (62 words, init store), && without
   the bool variable (no sltu), `if (res > -1)` and `if (0 <= res)` at the tail
   (both keep the per-arm store; 71/69 and 70/69 words). */
/* HSTMATCH module=EBOOT.BIN start=0x001b1d10 end=0x001b1e24 symbol=FUN_001b1d10 lang=c++ */
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
            FUN_001b2218(param_1, &res, param_3, param_4, 0);
    }

    return res;
}
// near miss from lane fm6 (unreviewed)
