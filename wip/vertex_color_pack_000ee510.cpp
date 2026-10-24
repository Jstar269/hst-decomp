/* HSTMATCH module=EBOOT.BIN start=0x000ee510 end=0x000ee6d4 symbol=FUN_000ee510 lang=c++ */

struct Vtx {
    unsigned int color;     /* 0x00 */
    short x;                /* 0x04 */
    short y;                /* 0x06 */
    short z;                /* 0x08 */
    short w;                /* 0x0a */
};

extern "C" {
extern short DAT_002c0880[];
extern int DAT_002d6cec;
extern unsigned int DAT_002d6cf0;
extern float DAT_002d6cbc[];
extern float DAT_002d6cc0[];
extern int DAT_00338b58[];
}

static inline int Clamp(const int &v, const int &lo, const unsigned &hi)
{
    return v < lo ? lo : (hi < v ? v : (int)hi);
}

extern "C" void FUN_000ee510(struct Vtx *v, int idx, int row, int sel, int flag)
{
    short *ps;
    unsigned u = Clamp(sel, DAT_002d6cec, DAT_002d6cf0);

    ps = DAT_002c0880 + u * 15 + row * 5;
    if (flag != 0 || row != 2) {
        short s1 = ps[4];
        short s2 = ps[1];
        short s3 = ps[2];
        short s4 = ps[3];

        v->x = (short)(int)((float)DAT_00338b58[idx * 4] +
                            (float)ps[0] * DAT_002d6cbc[idx * 2]);
        v->y = (short)(int)((float)DAT_00338b58[idx * 4 + 1] +
                            (float)s2 * DAT_002d6cc0[idx * 2]);
        v->z = (short)(int)((float)DAT_00338b58[idx * 4 + 2] +
                            (float)s3 * DAT_002d6cbc[idx * 2]);
        v->w = (short)(int)((float)DAT_00338b58[idx * 4 + 3] +
                            (float)s4 * DAT_002d6cc0[idx * 2]);
        v->color = (v->color & 0xffffff) |
                   ((unsigned)(((int)s1 << 7) / 100) << 24);
    }
}
// NEAR 109/113 words, 100 differ. Clamp head matches retail exactly for the
// first two compares (double global load of lo, slt/bnezl layout) once the
// clamp is written as Clamp(const int&v,const int&lo,const unsigned&hi)
// { return v < lo ? lo : (hi < v ? v : (int)hi); } in a .cpp (references force
// the double load; hi must be unsigned for the sltu).
// Still differs: the hi-arm emits an extra `move a3,t1` in the delay slot plus
// a following `move t1,a3` (4 words short overall); tail body offsets shift.
// Ruled out: statement form with plain globals (CSEs to one lo load), unsigned
// return type, (int)hi cast - all give 109/113.
// near miss from lane fm7 (unreviewed)
