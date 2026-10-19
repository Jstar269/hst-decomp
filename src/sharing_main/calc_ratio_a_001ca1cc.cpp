/* HSTMATCH module=hstp_trans_main.prx start=0x001ca1cc end=0x001ca290 symbol=FUN_001ca1cc lang=c++ */
/* Clone of src/eboot/calc_ratio_a_001bc3e4.cpp (hstclone.py tag s10172123g8r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern const float DAT_003919c8;
extern const float DAT_003919cc;

static inline float Clamp(const float &v, const float &lo, const float &hi) {
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" float FUN_001ca1cc(unsigned int a0, unsigned int a1, unsigned int a2) {
    unsigned int total = a0 + a1 + a2;
    return total ? Clamp(((float)a0 * 100.0f) / (float)total, DAT_003919c8, DAT_003919cc) : 0.0f;
}
