/* HSTMATCH module=EBOOT.BIN start=0x00164ac4 end=0x00164c60 symbol=FUN_00164ac4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idioms: the ratio is an in-place divide (`r = c - lo; r = r / (hi - lo);`); the clamp reads the table through a typed Row while the division uses raw offsets so the loads are not shared; `last = count - 1` kept as a local; the final clamp takes its bounds by pointer (double global load). */
struct Row { int a; int b; int c; int d; float key; };
struct Tbl {
    int base;
    int count;
    int pad;
    int idx;
};
extern struct Tbl *DAT_0034150c;
extern struct Tbl *DAT_00341510;
extern float DAT_002e03a8;
extern float DAT_002e03ac;
extern float FUN_000d8334(int, int);

static inline float Clamp(float v, float lo, float hi)
{
    return v < lo ? lo : (!(v > hi) ? v : hi);
}
static inline float ClampR(float v, const float *lo, const float *hi)
{
    return v < *lo ? *lo : (!(v > *hi) ? v : *hi);
}

float FUN_00164ac4(int param_1, int param_2)
{
    float v;
    float c;
    float r;
    int count;
    int base;
    int last;

    if (param_2 != 0 && *(short *)(param_2 + 10) / 10 == 50) {
        count = DAT_00341510->count;
        base = DAT_00341510->base;
        last = count - 1;
        c = *(float *)((char *)base + last * 0x14 + 0x10);
    } else {
        v = *(float *)(param_1 + 0x58);
        if (param_2 != 0) {
            if (*(short *)(param_2 + 10) >= 0)
                v += *(float *)(DAT_0034150c->base +
                                *(short *)(DAT_0034150c->idx + *(short *)(param_2 + 10) * 2) * 0x22c +
                                0x58);
            v += FUN_000d8334(param_2, 4);
        }
        count = DAT_00341510->count;
        base = DAT_00341510->base;
        last = count - 1;
        c = Clamp(v, ((struct Row *)base)[0].key, *(float *)((char *)base + last * 0x14 + 0x10));
    }
    r = c - *(float *)(base + 0x10);
    r = r / (*(float *)(base + (count - 1) * 0x14 + 0x10) - *(float *)(base + 0x10));
    return ClampR(r, &DAT_002e03a8, &DAT_002e03ac);
}
