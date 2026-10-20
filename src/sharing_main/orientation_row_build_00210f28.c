/* HSTMATCH module=hstp_trans_main.prx start=0x00210f28 end=0x00211020 symbol=FUN_00210f28 lang=c99 */
/* Clone of src/eboot/orientation_row_build_00202758.c (hstclone.py tag c055807): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
extern float FUN_0000bc4c(float);
extern float FUN_0000bf4c(float);
extern double FUN_00020f84(float);
extern double FUN_000216fc(double, double);
extern double FUN_0000b184(double);
extern float FUN_000223c8(double);
extern void FUN_002110a8(float *);

void FUN_00210f28(float phase, float angle, float *out)
{
    float a = -angle - 1.5707964f;
    double q;

    out[0] = -FUN_0000bc4c(phase) * FUN_0000bc4c(a);
    out[1] = -FUN_0000bf4c(phase);
    out[2] = -FUN_0000bc4c(phase) * FUN_0000bf4c(a);
    q = FUN_00020f84(phase);
    q = FUN_000216fc(q, 1.5707963267948966);
    q = FUN_0000b184(q);
    q = FUN_000216fc(1.5707963267948966, q);
    out[4] = FUN_000223c8(q);
    FUN_002110a8(out);
}
