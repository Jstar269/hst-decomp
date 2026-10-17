/* HSTMATCH module=hstp_trans_main.prx start=0x001c9abc end=0x001c9b18 symbol=FUN_001c9abc lang=c++ */
/* Clone of src/eboot/set_clamped_value_001bbcd4.cpp (hstclone.py tag s10170158a1r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Store value clamped to [(float)DAT_00391980, DAT_00391984] into the float at +4, then tail-call FUN_001c98a0(o).
   Matching idioms: the lo bound is an INT global taken by const reference (retail's lw v1 + lwc1/cvt.s.w
   double load) and `#pragma exceptions off` (without it C++ never emits the tail-call `j`). */
#pragma exceptions off
extern int DAT_00391980;
extern float DAT_00391984;
extern "C" void FUN_001c98a0(void *);

static inline float Clamp(float value, const int &lo, const float &hi)
{
    return value < lo ? lo : (!(value > hi) ? value : hi);
}

extern "C" void FUN_001c9abc(float v, char *o)
{
    *(float *)(o + 4) = Clamp(v, DAT_00391980, DAT_00391984);
    FUN_001c98a0(o);
}
