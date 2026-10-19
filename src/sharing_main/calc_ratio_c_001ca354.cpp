/* HSTMATCH module=hstp_trans_main.prx start=0x001ca354 end=0x001ca418 symbol=FUN_001ca354 lang=c++ */
/* Clone of src/eboot/calc_ratio_c_001bc56c.cpp (hstclone.py tag s10172123g8r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern const float DAT_003919d8;
extern const float DAT_003919dc;

static inline float Clamp(const float &v, const float &lo, const float &hi) {
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" float FUN_001ca354(unsigned int a0, unsigned int a1, unsigned int a2) {
    unsigned int total = a0 + a1 + a2;
    return total ? Clamp(((float)a2 * 100.0f) / (float)total, DAT_003919d8, DAT_003919dc) : 0.0f;
}
