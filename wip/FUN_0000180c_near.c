/* HSTMATCH module=EBOOT.BIN start=0x0000180c end=0x00001960 symbol=FUN_0000180c lang=c99 rodata=0x002b914c */
/* Hand-written reconstruction from the disassembly (DeepSeek V4.1 Flash (Freebuff), lane dsn2); names and types
   await human review. Decoded from the retail words: a 24-byte struct and a 312-byte struct are copied into the
   frame, then a 16-way jump table at 0x2b914c dispatches on `*p & 0x1f` (entries 1 and 14 and the >=16 default go
   to the 0xec0 block, entry 13 falls through, every other value calls 0x2110 and re-dispatches). */
typedef unsigned char u8;

typedef struct {                 /* 24 bytes, copied first into sp+32 */
    int f[5];                    /* 0..19 (f[2] is the char * cursor) */
    float f14;                   /* 20 */
} Small;

typedef struct {                 /* 8 bytes */
    int a;
    int b;
} Pair;

typedef struct {                 /* 32-byte header member */
    int w[8];                    /* w[6] is the table base */
} Hdr8;

typedef struct {                 /* 280-byte pair-array member */
    Pair e[35];
} Pairs;

typedef struct {                 /* 312 bytes, copied into sp+56 */
    Hdr8 hdr;                    /* 0..31 */
    Pairs pairs;                 /* 32..311 */
} Big;

extern void FUN_00000ec0(void);
extern int FUN_00002110(Small *s);
extern void FUN_000010dc(char *p, int *out);

int FUN_0000180c(Big *obj, Small *valp)
{
    Big tmp;
    Small val;
    int idx;
    u8 c;
    unsigned int *q;

    val.f[0] = valp->f[0];
    val.f[1] = valp->f[1];
    val.f[2] = valp->f[2];
    val.f[3] = valp->f[3];
    val.f[4] = valp->f[4];
    val.f14 = valp->f14;
    tmp.hdr.w[0] = obj->hdr.w[0];
    tmp.hdr.w[1] = obj->hdr.w[1];
    tmp.hdr.w[2] = obj->hdr.w[2];
    tmp.hdr.w[3] = obj->hdr.w[3];
    tmp.hdr.w[4] = obj->hdr.w[4];
    tmp.hdr.w[5] = obj->hdr.w[5];
    tmp.hdr.w[6] = obj->hdr.w[6];
    tmp.hdr.w[7] = obj->hdr.w[7];
    tmp.pairs = obj->pairs;

    c = val.f[2] != 0 ? (u8)(*(u8 *)val.f[2] & 0x1f) : 0;
    for (;;) {
        switch (c) {
        default:
            FUN_00000ec0();
            goto done;
        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 15:
            c = (u8)FUN_00002110(&val);
            break;
        case 13:
            goto done;
        }
    }

done:
    FUN_000010dc((char *)val.f[2] + 1, &idx);
    q = (unsigned int *)(tmp.hdr.w[6] + idx);
    obj->hdr.w[0] = q[1];
    obj->hdr.w[1] = q[0];
    obj->hdr.w[2] = 0;
    obj->hdr.w[3] = (int)q;
    return (int)q;
}
// NEAR 85/85 words, 15 differ (all inside 0x1858-0x1894) - lane dsn2, 2026-10-28 pass 12.
// Frame, both struct homes, the 35-element pair loop, the 16-way jump table, the ternary null cursor, the tail and
// the epilogue are all word-exact.  The ONLY difference is the issue order of the 8-word header copy: retail emits
// eight strict `lw v0,off(a0); sw v0,off+56(sp)` pairs using ONE temp; this MWCC software-pipelines them three deep
// (`lw v1,4(a0); lw v0,8(a0); lw a1,0(a0); sw v1,60(sp); ...`).  The 16 instructions are the same set.
// Shapes tried for that block, all 85/85 with the same 15-word permutation: eight member assignments; a 4-word
// member assignment split; `for` loop (indexed and pointer-walk, unrolled); `Hdr8` struct copy (FP-copies instead:
// lwc1/swc1); eight-scalar-member struct copy (FP again); by-value `Big` parameter home (704-byte frame, 39x8
// loop); volatile destination, volatile source, both volatile (still hoisted); a single reused `int t` per word;
// memcpy (not inlined - adds a jal).  Register allocator insists on 3 temps, retail used 1.
// Next lever: something that makes MWCC emit this block unscheduled (a loop it unrolls AFTER scheduling, or a
// pragma that turns the scheduler off for the function); the rest of the function needs no further work.
// Pass 13 (bounded attempt, concluded TIE): pipeline-depth mechanisms tried on the 8-word copy, all 85/85:
// reverse word order 7..0 (16 differ - worse), destination and source through two distinct named Hdr8 pointers
// (15 differ), an always-inline `#pragma inline_depth(8)` CopyHdr helper (15 differ).  With the earlier ten shapes
// this is a register-allocator tie: retail uses one temp and no pipelining, this MWCC insists on three temps.
// near miss from lane dsn2 (unreviewed)
