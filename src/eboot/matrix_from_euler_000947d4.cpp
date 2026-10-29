/* HSTMATCH module=EBOOT.BIN start=0x000947d4 end=0x00094978 symbol=FUN_000947d4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Builds a 4x4 rotation matrix from three angles: identity copied in, then rotateZ(-angles[2]), rotateY(-angles[1]), rotateX(angles[0]) each applied in place, then the 16 floats copied out one by one. The callees are the SDK rotation stubs. */
struct Mat {
    float m[16];
};
extern Mat DAT_002bc410;
extern "C" void FUN_0004d320(float a, Mat *d, Mat *s);
extern "C" void FUN_0004d278(float a, Mat *d, Mat *s);
extern "C" void FUN_0004d2cc(float a, Mat *d, Mat *s);

extern "C" void FUN_000947d4(Mat *out, int unused, float *angles) {
    Mat m;
    m.m[0] = DAT_002bc410.m[0];
    m.m[1] = DAT_002bc410.m[1];
    m.m[2] = DAT_002bc410.m[2];
    m.m[3] = DAT_002bc410.m[3];
    m.m[4] = DAT_002bc410.m[4];
    m.m[5] = DAT_002bc410.m[5];
    m.m[6] = DAT_002bc410.m[6];
    m.m[7] = DAT_002bc410.m[7];
    m.m[8] = DAT_002bc410.m[8];
    m.m[9] = DAT_002bc410.m[9];
    m.m[10] = DAT_002bc410.m[10];
    m.m[11] = DAT_002bc410.m[11];
    m.m[12] = DAT_002bc410.m[12];
    m.m[13] = DAT_002bc410.m[13];
    m.m[14] = DAT_002bc410.m[14];
    m.m[15] = DAT_002bc410.m[15];
    FUN_0004d320(-angles[2], &m, &m);
    FUN_0004d278(-angles[1], &m, &m);
    FUN_0004d2cc(angles[0], &m, &m);
    out->m[0] = m.m[0];
    out->m[1] = m.m[1];
    out->m[2] = m.m[2];
    out->m[3] = m.m[3];
    out->m[4] = m.m[4];
    out->m[5] = m.m[5];
    out->m[6] = m.m[6];
    out->m[7] = m.m[7];
    out->m[8] = m.m[8];
    out->m[9] = m.m[9];
    out->m[10] = m.m[10];
    out->m[11] = m.m[11];
    out->m[12] = m.m[12];
    out->m[13] = m.m[13];
    out->m[14] = m.m[14];
    out->m[15] = m.m[15];
}
