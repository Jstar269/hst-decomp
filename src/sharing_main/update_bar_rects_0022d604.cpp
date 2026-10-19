/* HSTMATCH module=hstp_trans_main.prx start=0x0022d604 end=0x0022d6c0 symbol=FUN_0022d604 lang=c++ */
/* Clone of src/eboot/update_bar_rects_0021e090.cpp (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: typed float first parameter, inline Clamp(const float &, const float &, const float &) for the double global loads, and 24-byte slot array; exact match verified; names and types await human review. */
struct Rect_0022d604 {
    char pad[4];
    short x0;
    short y0;
    short x1;
    short y1;
};

struct Slot_0022d604 {
    Rect_0022d604 *rect;
    int pad[5];
};

struct Obj_0022d604 {
    char pad0[0x68];
    Slot_0022d604 slots[3];
    char pad1[0x1cc - 0x68 - 3 * 0x18];
    int state;
    float value;
    float width;
};

extern float DAT_00398c38;
extern float DAT_00398c3c;

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
    return value < lo ? lo : (!(value > hi) ? value : hi);
}

extern "C" void FUN_0022d604(float v, Obj_0022d604 *self)
{
    if (self->state == 30) {
        self->value = 100.0f;
    } else {
        self->value = v;
    }
    for (int i = 0; i < 3; i++) {
        float t = Clamp(self->value / 100.0f, DAT_00398c38, DAT_00398c3c);
        Rect_0022d604 *r = self->slots[i].rect;
        r->x1 = (short)((float)r->x0 + self->width * t);
    }
}
