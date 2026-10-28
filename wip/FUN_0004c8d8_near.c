/* HSTMATCH module=EBOOT.BIN start=0x0004c8d8 end=0x0004caa4 symbol=FUN_0004c8d8 lang=c99 */
/* Hand-written reconstruction from the disassembly (DeepSeek V4.1 Flash (Freebuff), lane dsn2); names and types
   await human review. Frame 272: ra 44, s8 40, s7 36, s6 32, s5 28, s4 24, s3 20, s2 16, s1 12, s0 8, t3 56,
   t2 60, a 160-byte query record at 64 (field 0 = -1, float at +92, -1 at +112, then arg slots at +120..+152)
   and a 36-byte descriptor at 236. Ten parameters: a0 = table object (f0/f4/f8), a1 = float source (f30),
   a2/a3 = lookup keys, t0/t1/t2/t3 = records, arg9 = the output record (f7c/f80/f84), arg10 = a byte switch.
   Returns (result >= 0). */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct Obj {             /* a0 */
    u32 f0;                      /* 0 */
    u32 f4;                      /* 4: u16 table base */
    u32 f8;                      /* 8 */
} Obj;

typedef struct Src {             /* a1 */
    u8 pad0[48];
    float f30;                   /* 48 */
} Src;

typedef struct Out {             /* arg9 */
    u8 pad0[124];
    int f7c;                     /* 124 */
    int f80;                     /* 128 */
    int f84;                     /* 132 */
} Out;

typedef struct T {               /* the 160-byte record at sp+64 */
    int f0;                      /* 0 */
    u8 pad4[88];                 /* 4..91 */
    float f5c;                   /* 92 */
    u8 pad60[16];                /* 96..111 */
    int f70;                     /* 112: result */
    int f74;                     /* 116: second result */
    int f78;                     /* 120 */
    int f7c;                     /* 124 */
    int f80;                     /* 128 */
    int f84;                     /* 132 */
    int f88;                     /* 136 */
    int f8c;                     /* 140 */
    int f90;                     /* 144 */
    int f94;                     /* 148 */
    int f98;                     /* 152 */
    u8 pad9c[4];                 /* 156..159 */
    u8 tail[12];                 /* 160..171 */
} T;

typedef struct Q {               /* the 36-byte descriptor at sp+236 */
    u32 q00, q04, q08, q0c, q10, q14, q18, q1c, q20;
} Q;

extern u32 DAT_002d092c[9];

void FUN_000114c0(void *d, int c, int n);
void FUN_00026a4c(Q *q, int a, int b, int c);

int FUN_0004c8d8(Obj *a0, Src *a1, int a2, int a3, int t0, int t1, int t2, int t3,
                 Out *out, u8 flag)
{
    Q q;
    T t;
    int rc;
    int extra;
    int r;
    u16 *p;

    FUN_000114c0(&t, 0, 160);
    t.f0 = -1;

    q.q00 = DAT_002d092c[0];
    q.q04 = DAT_002d092c[1];
    q.q08 = DAT_002d092c[2];
    q.q0c = DAT_002d092c[3];
    q.q10 = DAT_002d092c[4];
    q.q14 = DAT_002d092c[5];
    q.q18 = DAT_002d092c[6];
    q.q1c = DAT_002d092c[7];
    q.q20 = DAT_002d092c[8];

    q.q00 = a0->f0;
    q.q04 = (u32)t0;
    q.q08 = a0->f4;
    q.q18 = (u32)&t;

    t.f98 = t3;
    t.f5c = a1->f30;
    t.f78 = a3;
    t.f7c = a2;
    t.f80 = (int)a1;
    t.f8c = t1;
    t.f90 = (int)a0->f8;
    t.f94 = t2;
    t.f88 = flag;
    t.f84 = (int)out;

    rc = -1;
    extra = -1;
    t.f70 = -1;
    FUN_00026a4c(&q, a2, a3, flag);
    r = t.f70;
    if (r >= 0) {
        extra = t.f74;
        rc = r;
    }

    if (rc >= 0) {
        if (flag != 0) {
            int idx = rc >> 16;
            p = (u16 *)(a0->f4 + ((u32)idx << 1));
            if (out != 0) {
                out->f7c = idx;
                out->f80 = *p;
                out->f84 = extra;
            }
        }
    }

    return rc >= 0;
}
// near miss from lane dsn2 (unreviewed)
