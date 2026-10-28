/* HSTMATCH module=EBOOT.BIN start=0x0004c66c end=0x0004c8d8 symbol=FUN_0004c66c lang=c99 */
/* Hand-written reconstruction from the disassembly (DeepSeek V4.1 Flash (Freebuff), lane dsn2); names and types
   await human review. Frame 336: 44 bytes of saves (ra, s0-s8), a 64-byte float scratch at sp+64, a 160-byte
   zeroed record at sp+128, 12 unused bytes, and a 36-byte parameter block at sp+300.
   Ten parameters: a0 = source object (words at +0/+4/+8, +4 being a u16 table), a1 = target (floats at +16..+28,
   +32..+44 and one at +48), a2/a3 = two selectors, t0 = a data base, t1..t3 and two stack words (an int and a
   flag byte) fill the parameter block. The block is handed to FUN_00026a94, which fills the record through the
   pointer in its sixth slot; the record is then read back (a -1 sentinel in slot 112 means the call wrote
   nothing) and unpacked into the target through two matrix multiplies and a final transform. */
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Obj {
    int f0;                      /* 0 */
    u16 *f4;                     /* 4: u16 table */
    int f8;                      /* 8 */
} Obj;

typedef struct Target {
    u8 pad0[16];                 /* 0..15 */
    float f10;                   /* 16 */
    float f14;                   /* 20 */
    float f18;                   /* 24 */
    float f1c;                   /* 28 */
    float f20;                   /* 32 */
    float f24;                   /* 36 */
    float f28;                   /* 40 */
    float f2c;                   /* 44 */
    float f30;                   /* 48 */
} Target;

typedef struct Params {          /* sp+300: nine words */
    int f0;                      /* 0: obj->f0 */
    int f1;                      /* 4: t0 */
    int f2;                      /* 8: obj->f4 */
    int f3;                      /* 12: DAT_002d0914 */
    int f4;                      /* 16: DAT_002d0918 */
    int f5;                      /* 20: DAT_002d091c */
    int f6;                      /* 24: &rec */
    int f7;                      /* 28: DAT_002d0924 */
    int f8;                      /* 32: DAT_002d0928 */
} Params;

typedef struct Rec {             /* sp+128: 160 bytes, memset 0 */
    int f0;                      /* 0: -1 sentinel */
    u8 pad4[76];                 /* 4..79 */
    float f80;                   /* 80 */
    float f84;                   /* 84 */
    float f88;                   /* 88 */
    float f92;                   /* 92 */
    float f96;                   /* 96 */
    float f100;                  /* 100 */
    float f104;                  /* 104 */
    float f108;                  /* 108 */
    int f112;                    /* 112: -1 sentinel, re-read after the call */
    int f116;                    /* 116 */
    u8 pad120[8];                /* 120..127 */
    int f128;                    /* 128: target */
    int f132;                    /* 132: result pointer */
    u8 f136;                     /* 136: flag byte */
    u8 pad137[3];                /* 137..139 */
    int f140;                    /* 140: t1 */
    int f144;                    /* 144: obj->f8 */
    int f148;                    /* 148: t2 */
    int f152;                    /* 152: t3 */
    u8 pad156[4];                /* 156..159 */
} Rec;

extern int DAT_002d0908;
extern int DAT_002d090c;
extern int DAT_002d0910;
extern int DAT_002d0914;
extern int DAT_002d0918;
extern int DAT_002d091c;
extern int DAT_002d0920;
extern int DAT_002d0924;
extern int DAT_002d0928;

void FUN_000114c0(void *dst, int val, int n);
int FUN_00026a94(Params *p, int a2, int a3);
void FUN_00022570(float *dst, int a1, int a2);
void FUN_00022548(float *dst, float *src, float *arg);
void FUN_00022518(float *dst, float *arg);

int FUN_0004c66c(Obj *obj, Target *t, int a2, int a3, int base, int t1, int t2, int t3, int *res,
                 u8 flag)
{
    Params p;
    Rec rec;
    int pad[3];
    float buf[16];
    int rc;
    int idx;
    int id;
    int key;
    u16 sel;

    FUN_000114c0(&rec, 0, 160);
    rec.f0 = -1;

    p.f0 = DAT_002d0908;
    p.f1 = DAT_002d090c;
    p.f2 = DAT_002d0910;
    p.f3 = DAT_002d0914;
    p.f4 = DAT_002d0918;
    p.f5 = DAT_002d091c;
    p.f6 = DAT_002d0920;
    p.f7 = DAT_002d0924;
    p.f8 = DAT_002d0928;

    rec.f92 = t->f30;
    rec.f128 = (int)t;
    rec.f132 = (int)res;
    rec.f136 = flag;
    rec.f140 = t1;
    rec.f144 = obj->f8;
    rec.f148 = t2;
    rec.f152 = t3;

    p.f0 = obj->f0;
    p.f1 = base;
    p.f2 = (int)obj->f4;
    p.f6 = (int)&rec;

    rec.f112 = -1;
    rc = FUN_00026a94(&p, a2, a3);

    idx = -1;
    id = -1;
    if (rc >= 0) {
        id = rec.f116;
        idx = rc;
    }
    if (idx < 0)
        return 0;
    if (flag == 0)
        return 1;

    t->f30 = rec.f92;
    key = idx >> 16;
    sel = obj->f4[key];
    FUN_00022570(buf, a3, base + (sel << 6));

    t->f10 = rec.f80;
    t->f14 = rec.f84;
    t->f18 = rec.f88;
    t->f1c = rec.f92;
    t->f1c = 1.0f;
    FUN_00022548(&t->f10, buf, &t->f10);

    t->f20 = -rec.f96;
    t->f24 = -rec.f100;
    t->f28 = -rec.f104;
    t->f2c = -rec.f108;
    t->f2c = 0.0f;
    FUN_00022548(&t->f20, buf, &t->f20);

    t->f2c = 0.0f;
    FUN_00022518(&t->f20, &t->f20);

    if (res != 0) {
        res[31] = key;
        res[32] = sel;
        res[33] = id;
    }
    return 1;
}
// PHASE-3 HEAVY HEAD (2026-10-28, pass 18): first write-first pass from the disassembly -> 153/155 words, 139 differ.
// DECODE: ten parameters (a0 obj, a1 target, a2/a3 selectors, t0 data base, t1..t3 + an int stack word + a flag byte).
// Frame 336: 44 saves, a 64-byte float scratch at sp+64 (the dst of mat4_mul_0022570), a 160-byte zeroed record at
// sp+128, 12 unused bytes at 288, and a 36-byte parameter block at sp+300. memset(rec,0,160) is FUN_000114c0; the
// record's slot 0 is set to -1, slot 112 is a second -1 that is written before the FUN_00026a94 call and read back
// after it (a sentinel: the callee fills the record through block.f6 = &rec). If the result is >= 0, idx = result and
// id = rec.f116, otherwise both stay -1; idx < 0 returns 0, a zero flag returns 1 early. The unpack: key = idx >> 16,
// sel = obj->f4[key] (a u16 table), mat4_mul(scratch, a3, base + sel*64), the record's four floats at 80..92 copied
// to target+16..28 and 1.0f forced into target+28, a mat4 multiply in place at target+16, the record's four floats at
// 96..108 negated into target+32..44 with 0.0f forced at +44, a second in-place multiply at target+32, a final
// FUN_00022518 at target+32, then res[31..33] = key/sel/id when res is non-null.
// FRAME GAP (the blocker): ours -320 with the local area 16 bytes lower (scratch at sp+48, record at 124, block at
// 284). Retail starts the local area at 64, which needs 16-byte alignment of the float scratch. Dead ends measured:
// `__attribute__((aligned(16)))` is accepted and ignored; `__declspec(align(16))` does not compile; unused 16-byte
// locals are eliminated and never move the frame (4 declaration orders tried). A 172-byte Rec (record + its trailing
// 12 bytes) would put the block at 300 with no separate local, still 16 short.
// ALSO LEFT: the parameter-to-s-register permutation (retail copies a2 to s7, a3 to s0, t0 to s3, t1 to s8 and loads
// the stack word into s2, in that order; ours uses s0/s3/s2/s6/s1), which follows from the first-use order in the
// source, not from the frame.
// near miss from lane dsn2 (unreviewed)
