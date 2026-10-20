/* HSTMATCH module=EBOOT.BIN start=0x00202758 end=0x00202850 symbol=FUN_00202758 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
extern float FUN_0000bc34(float);
extern float FUN_0000bf34(float);
extern double FUN_00020f5c(float);
extern double FUN_000216d4(double, double);
extern double FUN_0000b16c(double);
extern float FUN_000223a0(double);
extern void FUN_002028d8(float *);

void FUN_00202758(float phase, float angle, float *out)
{
    float a = -angle - 1.5707964f;
    double q;

    out[0] = -FUN_0000bc34(phase) * FUN_0000bc34(a);
    out[1] = -FUN_0000bf34(phase);
    out[2] = -FUN_0000bc34(phase) * FUN_0000bf34(a);
    q = FUN_00020f5c(phase);
    q = FUN_000216d4(q, 1.5707963267948966);
    q = FUN_0000b16c(q);
    q = FUN_000216d4(1.5707963267948966, q);
    out[4] = FUN_000223a0(q);
    FUN_002028d8(out);
}
