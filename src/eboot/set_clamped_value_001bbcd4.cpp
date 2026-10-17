/* HSTMATCH module=EBOOT.BIN start=0x001bbcd4 end=0x001bbd30 symbol=FUN_001bbcd4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Store value clamped to [(float)DAT_002e9d48, DAT_002e9d4c] into the float at +4, then tail-call FUN_001bbab8(o).
   Matching idioms: the lo bound is an INT global taken by const reference (retail's lw v1 + lwc1/cvt.s.w
   double load) and `#pragma exceptions off` (without it C++ never emits the tail-call `j`). */
#pragma exceptions off
extern int DAT_002e9d48;
extern float DAT_002e9d4c;
extern "C" void FUN_001bbab8(void *);

static inline float Clamp(float value, const int &lo, const float &hi)
{
    return value < lo ? lo : (!(value > hi) ? value : hi);
}

extern "C" void FUN_001bbcd4(float v, char *o)
{
    *(float *)(o + 4) = Clamp(v, DAT_002e9d48, DAT_002e9d4c);
    FUN_001bbab8(o);
}
