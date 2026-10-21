/* HSTMATCH module=hstp_trans_main.prx start=0x00096780 end=0x00096924 symbol=FUN_00096780 lang=c++ */
/* Clone of src/eboot/matrix_from_euler_000947d4.cpp (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Builds a 4x4 rotation matrix from three angles: identity copied in, then rotateZ(-a[2]), rotateY(-a[1]), rotateX(a[0]) each applied in place, then the 16 floats copied out one by one. The callees are the SDK rotation stubs. */
struct Mat {
    float m[16];
};
extern Mat DAT_002cc260;
extern "C" void FUN_0004d698(float a, Mat *d, Mat *s);
extern "C" void FUN_0004d5f0(float a, Mat *d, Mat *s);
extern "C" void FUN_0004d644(float a, Mat *d, Mat *s);

extern "C" void FUN_00096780(Mat *out, int unused, float *a) {
    Mat m;
    m.m[0] = DAT_002cc260.m[0];
    m.m[1] = DAT_002cc260.m[1];
    m.m[2] = DAT_002cc260.m[2];
    m.m[3] = DAT_002cc260.m[3];
    m.m[4] = DAT_002cc260.m[4];
    m.m[5] = DAT_002cc260.m[5];
    m.m[6] = DAT_002cc260.m[6];
    m.m[7] = DAT_002cc260.m[7];
    m.m[8] = DAT_002cc260.m[8];
    m.m[9] = DAT_002cc260.m[9];
    m.m[10] = DAT_002cc260.m[10];
    m.m[11] = DAT_002cc260.m[11];
    m.m[12] = DAT_002cc260.m[12];
    m.m[13] = DAT_002cc260.m[13];
    m.m[14] = DAT_002cc260.m[14];
    m.m[15] = DAT_002cc260.m[15];
    FUN_0004d698(-a[2], &m, &m);
    FUN_0004d5f0(-a[1], &m, &m);
    FUN_0004d644(a[0], &m, &m);
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
