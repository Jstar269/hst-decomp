/* HSTMATCH module=EBOOT.BIN start=0x00164d00 end=0x00164e24 symbol=FUN_00164d00 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/stat_curve.h"

extern StatTable *DAT_00341510; /* curve rows */
extern float DAT_002e0390;
extern float DAT_002e0394;
extern int DAT_002e03b4;

extern "C" float FUN_00163bec(float, int, int, int, int);

static inline float ClampF(const float &v, const float &lo, const float &hi)
{
    return v < lo ? lo : (v > hi ? hi : v);
}

static inline unsigned ClampU(const int &v, const int &lo, const unsigned &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}

/* Row index for the position along the curve: the clamped ratio runs from the last row (0) back to the first. */
extern "C" unsigned FUN_00164d00(int a, int b)
{
    float t = FUN_00163bec(100.0f, a, b, 1, 0);
    StatTable *tab = DAT_00341510;
    StatCurveRow *rows = (StatCurveRow *)tab->base;
    unsigned size = tab->count;
    float first = rows[0].col04;
    int last = size - 1;
    float lastKey = ((StatCurveRow *)((char *)rows + last * STAT_CURVE_ROW_SIZE))->col04;
    float f = t - first;
    f /= lastKey - first;
    f = ClampF(f, DAT_002e0390, DAT_002e0394);
    int idx = (int)((1.0f - f) * (float)(size - 1));
    return ClampU(idx, DAT_002e03b4, size - 2);
}
