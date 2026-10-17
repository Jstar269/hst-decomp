/* HSTMATCH module=EBOOT.BIN start=0x00113580 end=0x001135c0 symbol=FUN_00113580 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
    char pad[0x18];
    float value;
    float lo;
    float hi;
};

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
    return value < lo ? lo : (!(value > hi) ? value : hi);
}

extern "C" void FUN_00113580(float v, Obj *o)
{
    o->value = Clamp(v, o->lo, o->hi);
}
