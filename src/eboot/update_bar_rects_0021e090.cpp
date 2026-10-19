/* HSTMATCH module=EBOOT.BIN start=0x0021e090 end=0x0021e14c symbol=FUN_0021e090 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: typed float first parameter, inline Clamp(const float &, const float &, const float &) for the double global loads, and 24-byte slot array; exact match verified; names and types await human review. */
struct Rect_0021e090 {
    char pad[4];
    short x0;
    short y0;
    short x1;
    short y1;
};

struct Slot_0021e090 {
    Rect_0021e090 *rect;
    int pad[5];
};

struct Obj_0021e090 {
    char pad0[0x68];
    Slot_0021e090 slots[3];
    char pad1[0x1cc - 0x68 - 3 * 0x18];
    int state;
    float value;
    float width;
};

extern float DAT_002f086c;
extern float DAT_002f0870;

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
    return value < lo ? lo : (!(value > hi) ? value : hi);
}

extern "C" void FUN_0021e090(float v, Obj_0021e090 *self)
{
    if (self->state == 30) {
        self->value = 100.0f;
    } else {
        self->value = v;
    }
    for (int i = 0; i < 3; i++) {
        float t = Clamp(self->value / 100.0f, DAT_002f086c, DAT_002f0870);
        Rect_0021e090 *r = self->slots[i].rect;
        r->x1 = (short)((float)r->x0 + self->width * t);
    }
}
