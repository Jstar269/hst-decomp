/* HSTMATCH module=hstp_trans_main.prx start=0x000aaba8 end=0x000aacac symbol=FUN_000aaba8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v0) corrected by hand: Vec4 struct copies and const-ref min/max templates; exact match verified; names and types await human review. */
extern "C" {
extern const float DAT_0037acac;
extern const float DAT_0037acb0;
extern void FUN_0002245c(void *dst, int, int);
}

template <typename T>
static inline const T &max(const T &a, const T &b) {
    return (a < b) ? b : a;
}

template <typename T>
static inline const T &min(const T &a, const T &b) {
    return (b < a) ? b : a;
}

struct Vec4 {
    float x, y, z, w;
};

struct Obj {
    char pad[0x150];
    int f150;
};

extern "C" void FUN_000aaba8(Vec4 *param_1, Obj *param_2, int param_3, int param_4, unsigned char param_5)
{
    Vec4 local_10;
    Vec4 local_20;

    FUN_0002245c(&local_20, param_3, param_4);
    local_10 = local_20;

    if (param_5 == (param_2->f150 == 0)) {
        local_10.x = max(DAT_0037acac, local_10.x);
    } else {
        local_10.x = min(DAT_0037acb0, local_10.x);
    }
    *param_1 = local_10;
}
