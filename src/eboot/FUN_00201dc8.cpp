/* HSTMATCH module=EBOOT.BIN start=0x00201dc8 end=0x0020212c symbol=FUN_00201dc8 lang=c++ */
/* Hand-written reconstruction from the disassembly and the Ghidra pseudocode; the identity matrix is copied one float at a time from DAT_002bc410 into each of the three local matrices (fresh lui per element), rotated in place and then given its translation row; the e != 0 block is written first so MWCC places it first; exact match verified; names and types await human review. */
struct Mat {
    float m[16];
};

extern Mat DAT_002bc410;

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
void FUN_0004d2cc(float, Mat *, Mat *);
Pos *FUN_001fd170(void);
void FUN_00093434(void *, Mat *);
void FUN_00093cc8(void *);
}

extern "C" void FUN_00201dc8(Obj *self)
{
    if (self->f0 != 0) {
        if (self->f1 == 0) {
            void *e = self->f8;
            if (e != 0) {
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
                FUN_0004d2cc(self->angle, &m, &m);
                m.m[15] = 1.0f;
                m.m[12] = 0.0f;
                m.m[13] = 0.0f;
                m.m[14] = 0.0f;
                FUN_00093434(e, &m);
                FUN_00093cc8(e);
            }
        } else {
            void *e = self->f8;
            if (e != 0) {
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
                FUN_0004d2cc(self->angle, &m, &m);
                m.m[12] = FUN_001fd170()->x;
                m.m[15] = 1.0f;
                m.m[13] = 0.0f;
                m.m[14] = 0.0f;
                FUN_00093434(e, &m);
                FUN_00093cc8(e);
                e = self->fc;
            } else {
                e = self->fc;
            }
            if (e != 0) {
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
                FUN_0004d2cc(self->angle, &m, &m);
                m.m[12] = FUN_001fd170()->y;
                m.m[15] = 1.0f;
                m.m[13] = 0.0f;
                m.m[14] = 0.0f;
                FUN_00093434(e, &m);
                FUN_00093cc8(e);
            }
        }
    }
}
