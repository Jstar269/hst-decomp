/* HSTMATCH module=EBOOT.BIN start=0x001bc3e4 end=0x001bc4a8 symbol=FUN_001bc3e4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern const float DAT_002e9d90;
extern const float DAT_002e9d94;

static inline float Clamp(const float &v, const float &lo, const float &hi) {
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" float FUN_001bc3e4(unsigned int a0, unsigned int a1, unsigned int a2) {
    unsigned int total = a0 + a1 + a2;
    return total ? Clamp(((float)a0 * 100.0f) / (float)total, DAT_002e9d90, DAT_002e9d94) : 0.0f;
}
