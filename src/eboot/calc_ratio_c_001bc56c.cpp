/* HSTMATCH module=EBOOT.BIN start=0x001bc56c end=0x001bc630 symbol=FUN_001bc56c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern const float DAT_002e9da0;
extern const float DAT_002e9da4;

static inline float Clamp(const float &v, const float &lo, const float &hi) {
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" float FUN_001bc56c(unsigned int a0, unsigned int a1, unsigned int a2) {
    unsigned int total = a0 + a1 + a2;
    return total ? Clamp(((float)a2 * 100.0f) / (float)total, DAT_002e9da0, DAT_002e9da4) : 0.0f;
}
