/* HSTMATCH module=EBOOT.BIN start=0x0016a93c end=0x0016aafc symbol=FUN_0016a93c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand, starting from the fm9 near miss (four-way && chain): the dz == 0 guard is the ternary dz = (dz != zero) ? dz : 0.001f; matching idioms: a named float local zero compared against (the literal swaps the c.eq.s operands) and dz declared before dx (float register numbering); exact match verified; names and types await human review. */
extern float FUN_0000b8a8(float);
extern float fabsf(float);

float FUN_0016a93c(float *param_1, float *param_2)
{
    float zero = 0.0f;
    float dz = param_2[2] - param_1[2];
    float dx = param_2[0] - param_1[0];

    if (dx >= 0.0f && dz >= 0.0f) {
        dz = (dz != zero) ? dz : 0.001f;
        return 360.0f - 57.29578f * FUN_0000b8a8(dx / fabsf(dz));
    } else if (dx >= 0.0f && dz < 0.0f) {
        dz = (dz != zero) ? dz : 0.001f;
        return 180.0f + 57.29578f * FUN_0000b8a8(dx / fabsf(dz));
    } else if (dx < 0.0f && dz >= 0.0f) {
        dz = (dz != zero) ? dz : 0.001f;
        return 57.29578f * FUN_0000b8a8(-dx / fabsf(dz));
    } else {
        dz = (dz != zero) ? dz : 0.001f;
        return 180.0f - 57.29578f * FUN_0000b8a8(-dx / fabsf(dz));
    }
}
