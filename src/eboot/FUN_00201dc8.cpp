/* HSTMATCH module=EBOOT.BIN start=0x00201dc8 end=0x0020212c symbol=FUN_00201dc8 lang=c++ */
/* Hand-written reconstruction from the disassembly and the Ghidra pseudocode; the identity matrix is copied one float at a time from DAT_002bc410 into each of the three local matrices (fresh lui per element), rotated in place and then given its translation row; the e != 0 block is written first so MWCC places it first; exact match verified; names and types await human review. */
struct Mat {
    float m[16];
};

/* Translation row of a Mat (column-major 4x4: elements 12..15). */
enum { MAT_TX = 12, MAT_TY = 13, MAT_TZ = 14, MAT_W = 15 };

extern Mat DAT_002bc410; /* identity matrix */

/* Object with an enable flag, a "two parts" flag and two part handles rotated by one angle. */
struct Obj {
    unsigned char enabled;  /* 0x00 */
    unsigned char twoParts; /* 0x01, 0: only part1 is placed at the origin */
    char pad2[6];
    void *part1;            /* 0x08 */
    void *part2;            /* 0x0c */
    int pad10;
    float angle;            /* 0x14 */
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

/* Copies the identity matrix one float at a time (retail uses a fresh address load per element). */
#define LOAD_IDENTITY(mat) \
    do { \
        (mat).m[0] = DAT_002bc410.m[0]; \
        (mat).m[1] = DAT_002bc410.m[1]; \
        (mat).m[2] = DAT_002bc410.m[2]; \
        (mat).m[3] = DAT_002bc410.m[3]; \
        (mat).m[4] = DAT_002bc410.m[4]; \
        (mat).m[5] = DAT_002bc410.m[5]; \
        (mat).m[6] = DAT_002bc410.m[6]; \
        (mat).m[7] = DAT_002bc410.m[7]; \
        (mat).m[8] = DAT_002bc410.m[8]; \
        (mat).m[9] = DAT_002bc410.m[9]; \
        (mat).m[10] = DAT_002bc410.m[10]; \
        (mat).m[11] = DAT_002bc410.m[11]; \
        (mat).m[12] = DAT_002bc410.m[12]; \
        (mat).m[13] = DAT_002bc410.m[13]; \
        (mat).m[14] = DAT_002bc410.m[14]; \
        (mat).m[15] = DAT_002bc410.m[15]; \
    } while (0)

/* Rotates each present part by the object's angle and places it: part1 at the origin when single, else
   part1 gets the position x and part2 the position y in the first translation slot. */
extern "C" void FUN_00201dc8(Obj *self)
{
    if (self->enabled != 0) {
        if (self->twoParts == 0) {
            void *part = self->part1;
            if (part != 0) {
                Mat m;
                LOAD_IDENTITY(m);
                FUN_0004d2cc(self->angle, &m, &m);
                m.m[MAT_W] = 1.0f;
                m.m[MAT_TX] = 0.0f;
                m.m[MAT_TY] = 0.0f;
                m.m[MAT_TZ] = 0.0f;
                FUN_00093434(part, &m);
                FUN_00093cc8(part);
            }
        } else {
            void *part = self->part1;
            if (part != 0) {
                Mat m;
                LOAD_IDENTITY(m);
                FUN_0004d2cc(self->angle, &m, &m);
                m.m[MAT_TX] = FUN_001fd170()->x;
                m.m[MAT_W] = 1.0f;
                m.m[MAT_TY] = 0.0f;
                m.m[MAT_TZ] = 0.0f;
                FUN_00093434(part, &m);
                FUN_00093cc8(part);
                part = self->part2;
            } else {
                part = self->part2;
            }
            if (part != 0) {
                Mat m;
                LOAD_IDENTITY(m);
                FUN_0004d2cc(self->angle, &m, &m);
                m.m[MAT_TX] = FUN_001fd170()->y;
                m.m[MAT_W] = 1.0f;
                m.m[MAT_TY] = 0.0f;
                m.m[MAT_TZ] = 0.0f;
                FUN_00093434(part, &m);
                FUN_00093cc8(part);
            }
        }
    }
}
