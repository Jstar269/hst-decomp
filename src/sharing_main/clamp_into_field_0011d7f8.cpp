/* HSTMATCH module=hstp_trans_main.prx start=0x0011d7f8 end=0x0011d838 symbol=FUN_0011d7f8 lang=c++ */
/* Clone of src/eboot/clamp_into_field_00113580.cpp (hstclone.py tag x1237s): addresses substituted; exact match verified; names and types await human review. */
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

extern "C" void FUN_0011d7f8(float v, Obj *o)
{
    o->value = Clamp(v, o->lo, o->hi);
}
