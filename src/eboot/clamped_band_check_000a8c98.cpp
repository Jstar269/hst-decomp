/* HSTMATCH module=EBOOT.BIN start=0x000a8c98 end=0x000a8de0 symbol=FUN_000a8c98 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
extern const float DAT_002d46a4;
extern const float DAT_002d46a8;
extern float DAT_003411fc;
extern void FUN_00022434(void *dst, int, int);
struct Ctx;
struct Obj;
extern Ctx *FUN_000b3c68(void *obj);
}

template <typename T>
static inline const T &max(const T &a, const T &b) { return (a < b) ? b : a; }
template <typename T>
static inline const T &min(const T &a, const T &b) { return (b < a) ? b : a; }

struct Vec4 { float x, y, z, w; };
struct Ctx { char pad[0x24]; float unk24; /* 0x24 */ };
struct Obj { char pad[0x150]; int unk150; /* 0x150 */ };

/* Takes the difference of the two arguments, clamps its x from below or above depending on flag, and returns 1
   when its y lies strictly between a limit derived from the context and zero. */
extern "C" unsigned char FUN_000a8c98(Obj *obj, int a, int b, unsigned char flag)
{
    Vec4 clamped;
    Vec4 delta;

    FUN_00022434(&delta, a, b);
    clamped = delta;

    if (flag == (obj->unk150 == 0)) {
        clamped.x = max(DAT_002d46a4, clamped.x);
    } else {
        clamped.x = min(DAT_002d46a8, clamped.x);
    }

    bool ok;
    if (clamped.y > DAT_003411fc * 0.01f * -(FUN_000b3c68(obj)->unk24 * 0.01f) &&
        clamped.y < 0.0f) {
        ok = true;
    } else {
        ok = false;
    }
    if (ok) {
        return 1;
    }
    return 0;
}
