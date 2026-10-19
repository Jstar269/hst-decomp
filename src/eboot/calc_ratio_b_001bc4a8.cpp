/* HSTMATCH module=EBOOT.BIN start=0x001bc4a8 end=0x001bc56c symbol=FUN_001bc4a8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern const float DAT_002e9d98;
extern const float DAT_002e9d9c;

static inline float Clamp(const float &v, const float &lo, const float &hi) {
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" float FUN_001bc4a8(unsigned int a0, unsigned int a1, unsigned int a2) {
    unsigned int total = a0 + a1 + a2;
    return total ? Clamp(((float)a1 * 100.0f) / (float)total, DAT_002e9d98, DAT_002e9d9c) : 0.0f;
}
