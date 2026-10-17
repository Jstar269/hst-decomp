/* HSTMATCH module=EBOOT.BIN start=0x000a81b4 end=0x000a82b8 symbol=FUN_000a81b4 lang=c++ */
/* Clone of src/sharing_main/clamp_vec4_x_000aaba8.cpp (hstclone.py tag s10170158a1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v0) corrected by hand: Vec4 struct copies and const-ref min/max templates; exact match verified; names and types await human review. */
extern "C" {
extern const float DAT_002d46a4;
extern const float DAT_002d46a8;
extern void FUN_00022434(void *dst, int, int);
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

extern "C" void FUN_000a81b4(Vec4 *param_1, Obj *param_2, int param_3, int param_4, unsigned char param_5)
{
    Vec4 local_10;
    Vec4 local_20;

    FUN_00022434(&local_20, param_3, param_4);
    local_10 = local_20;

    if (param_5 == (param_2->f150 == 0)) {
        local_10.x = max(DAT_002d46a4, local_10.x);
    } else {
        local_10.x = min(DAT_002d46a8, local_10.x);
    }
    *param_1 = local_10;
}
