/* HSTMATCH module=hstp_trans_main.prx start=0x000ab68c end=0x000ab7d4 symbol=FUN_000ab68c lang=c++ */
/* Clone of src/eboot/clamped_band_check_000a8c98.cpp (hstclone.py tag bp1018ar1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
extern const float DAT_0037acac;
extern const float DAT_0037acb0;
extern float DAT_003ea53c;
extern void FUN_0002245c(void *dst, int, int);
struct Ctx;
struct Obj;
extern Ctx *FUN_000b6e80(void *obj);
}

template <typename T>
static inline const T &max(const T &a, const T &b) { return (a < b) ? b : a; }
template <typename T>
static inline const T &min(const T &a, const T &b) { return (b < a) ? b : a; }

struct Vec4 { float x, y, z, w; };
struct Ctx { char pad[0x24]; float f24; };
struct Obj { char pad[0x150]; int f150; };

extern "C" unsigned char FUN_000ab68c(Obj *param_1, int param_2, int param_3, unsigned char param_4)
{
    Vec4 local_10;
    Vec4 local_20;

    FUN_0002245c(&local_20, param_2, param_3);
    local_10 = local_20;

    if (param_4 == (param_1->f150 == 0)) {
        local_10.x = max(DAT_0037acac, local_10.x);
    } else {
        local_10.x = min(DAT_0037acb0, local_10.x);
    }

    bool ok;
    if (local_10.y > DAT_003ea53c * 0.01f * -(FUN_000b6e80(param_1)->f24 * 0.01f) &&
        local_10.y < 0.0f) {
        ok = true;
    } else {
        ok = false;
    }
    if (ok) {
        return 1;
    }
    return 0;
}
