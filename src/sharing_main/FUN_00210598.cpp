/* HSTMATCH module=hstp_trans_main.prx start=0x00210598 end=0x002108fc symbol=FUN_00210598 lang=c++ */
/* Clone of src/eboot/FUN_00201dc8.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly and the Ghidra pseudocode; the identity matrix is copied one float at a time from DAT_002cc260 into each of the three local matrices (fresh lui per element), rotated in place and then given its translation row; the e != 0 block is written first so MWCC places it first; exact match verified; names and types await human review. */
struct Mat {
    float m[16];
};

extern Mat DAT_002cc260;

struct Obj {
    unsigned char f0;
    unsigned char f1;
    char pad2[6];
    void *f8;
    void *fc;
    int pad10;
    float angle;
};

struct Pos {
    int pad0;
    int pad4;
    float x;
    float y;
};

extern "C" {
void FUN_0004d644(float, Mat *, Mat *);
Pos *FUN_0020b940(void);
void FUN_00095358(void *, Mat *);
void FUN_00095bec(void *);
}

extern "C" void FUN_00210598(Obj *self)
{
    if (self->f0 != 0) {
        if (self->f1 == 0) {
            void *e = self->f8;
            if (e != 0) {
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
                FUN_0004d644(self->angle, &m, &m);
                m.m[15] = 1.0f;
                m.m[12] = 0.0f;
                m.m[13] = 0.0f;
                m.m[14] = 0.0f;
                FUN_00095358(e, &m);
                FUN_00095bec(e);
            }
        } else {
            void *e = self->f8;
            if (e != 0) {
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
                FUN_0004d644(self->angle, &m, &m);
                m.m[12] = FUN_0020b940()->x;
                m.m[15] = 1.0f;
                m.m[13] = 0.0f;
                m.m[14] = 0.0f;
                FUN_00095358(e, &m);
                FUN_00095bec(e);
                e = self->fc;
            } else {
                e = self->fc;
            }
            if (e != 0) {
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
                FUN_0004d644(self->angle, &m, &m);
                m.m[12] = FUN_0020b940()->y;
                m.m[15] = 1.0f;
                m.m[13] = 0.0f;
                m.m[14] = 0.0f;
                FUN_00095358(e, &m);
                FUN_00095bec(e);
            }
        }
    }
}
