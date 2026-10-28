/* HSTMATCH module=EBOOT.BIN start=0x0004f130 end=0x0004f374 symbol=FUN_0004f130 lang=c99 */
/* Hand-written reconstruction from the disassembly (DeepSeek V4.1 Flash (Freebuff), lane dsn2); names and types
   await human review. Variant B: fixed parameters, the word at sp+44 is read through a pointer to the address-taken
   float local (retail: swc1 f0,44(sp); addiu s4,sp,44; lw s0,0(s4); ... addiu s4,s4,4 in the loop-back delay). */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Obj {
    u8 pad0[512];
    void *f200;                 /* 512 */
    u8 pad1[0x1a0a8 - 516];
    u8 f1a0a8[8];               /* 0x1a0a8 */
    u32 f1a0b0;                 /* 0x1a0b0 */
} Obj;

typedef struct Node {
    void *f0;                   /* 0 */
    void *f4;                   /* 4 */
    u8 f8;                      /* 8 */
    u8 pad9[3];
    u32 fc;                     /* 12 */
    u32 f10;                    /* 16 */
} Node;

extern float DAT_002d0a68;
extern char DAT_002d0c50[];
extern char DAT_002d0d28[];
extern char DAT_002d0a6c[];
extern char DAT_002d0d40[];
extern char DAT_00311170[];
extern char DAT_0004ecbc[];
extern u32 DAT_0032b234;
extern u32 DAT_0032b238;
extern u32 DAT_0032b23c;
extern u32 DAT_0032b240;

int FUN_00039818(int i);
void FUN_00025c94(char *msg);
int FUN_00039838(void);
void FUN_0004f010(char *tag, u32 code, char *file, int line, char *extra);
char *FUN_0004ea98(char *msg);
void *FUN_00010184(int size, int n);
void FUN_000104e0(void *p);
int FUN_00039dec(Obj *o, void *p, int n, int m);
void FUN_00050dd8(void *p, int n);
int FUN_0002b7a50(void);
int FUN_0002b7a28(void);
void FUN_00022fa0(int a, char *b);
void *FUN_00000bcc(int size);

void FUN_0004f130(Obj *o, int n, int m)
{
    int i;
    u32 *arg;
    float f;
    int want;
    void *p;
    Node *q;
    u32 tc;
    u32 ts;

    f = DAT_002d0a68;
    arg = (u32 *)&f;

    i = 0;
    while (i == 0) {
        want = (int)*arg;
        if (FUN_00039818(i) != want) {
            FUN_00025c94(DAT_002d0c50);
            for (;;)
                ;
        }
        i++;
        arg++;
    }

    if (FUN_00039838() != 0)
        FUN_0004f010(DAT_00311170, (u32)FUN_0004ea98(DAT_002d0d28), DAT_002d0a6c, 1091, DAT_002d0d40);

    o->f200 = FUN_00010184(16, n);
    p = o->f200;
    if (((u32)p & 0xff000000) != (((u32)p + n) & 0xff000000)) {
        o->f200 = FUN_00010184(16, n);
        FUN_000104e0(p);
    }
    if (FUN_00039dec(o, o->f200, n, 2) != 0)
        FUN_0004f010(DAT_00311170, 0x20000, DAT_002d0a6c, 1110, DAT_002d0d40);

    if (o->f1a0b0 < 256)
        FUN_00050dd8(o->f1a0a8, 256);

    DAT_0032b234 = 0;
    DAT_0032b238 = FUN_0002b7a50() + m;
    DAT_0032b23c = DAT_0032b238 + (FUN_0002b7a28() - m);
    DAT_0032b240 = 64;

    FUN_00022fa0(0, DAT_0004ecbc);

    q = (Node *)FUN_00000bcc(20);
    if (q == 0)
        return;
    tc = DAT_0032b23c;
    ts = DAT_0032b238;
    q->f0 = 0;
    q->f4 = 0;
    if (q->f0 != 0) {
        ((u32 *)q->f0)[1] = (u32)q;
        ((u32 *)q->f0)[4] = ts;
    } else {
        DAT_0032b234 = (u32)q;
    }
    if (q->f4 != 0) {
        ((u32 *)q->f4)[0] = (u32)q;
        ((u32 *)q->f4)[3] = tc;
    }
    q->f8 = 1;
    q->fc = ts;
    q->f10 = tc;
}
// NEAR 145/145 words, 2 differ (0x4f24c-0x4f250) - lane dsn2, 2026-10-28 pass 11.
// Rebuilt from the disassembly. NOT variadic: the sp+44 word is a float local `f = DAT_002d0a68` whose ADDRESS is
// taken (`u32 *arg = (u32 *)&f;`) and walked; `arg++` lands in the loop-back delay slot. Variadic spellings
// (va_start/va_arg) were tried first and do not produce this frame - see the checkpoint.
// Shape that reproduced retail word for word: `if (FUN_00039818(i) != want) { FUN_00025c94(DAT_002d0c50);
// for (;;) ; } i++; arg++;` (ASSERT-then-increment, NOT if/else) - an if/else spelling puts the print block first
// and costs 5 words.
// Mask is 0xff000000 (lui a0,0xff00), not 0xff00 - it compares 16MB segments.
// `o->f200 = FUN_00010184(16, n); p = o->f200;` (store the call result into the field, then read it back into the
// local) is what makes MWCC emit `sw v0,512(s3); move s0,v0; and v1,v0,a0; addu v0,v0,s2; ... beql` with the join's
// `lw a1,512(s3)` in the branch delay. `p = FUN_00010184(...); o->f200 = p;` orders the masks the other way (4 words
// wrong at 0x4f1ec).
// `u32 tc = DAT_0032b23c; u32 ts = DAT_0032b238;` as REAL locals (tc declared first) gives retail's a1/a0 colours
// and the two hoisted loads before the zero stores.  The tail globals are at 0x32b234..0x32b240 (hi=0x33, lo=-19916),
// not 0x33b234.
// REMAINING 2 WORDS: retail loads the second assert's 0x20000 argument into v0 (in the beqzl delay slot) and then
// `move a1,v0`; ours emits `lui a1,0x2` after `addiu a0,a0,4464`. Every spelling tried (0x20000, 0x20000u,
// (void*)0x20000, a u32 local, an o->f200-based expression, char* sum) folds to the same `lui a1`. The value is the
// same 0x20000 that is the hi half of `o->f1a0b0`, so retail is a constant-CSE/scheduling tie, not a source shape.
// Pass 12: the two words are a scheduler tie, concluded after the four remaining mechanisms, all byte-identical to
// the `lui a1,0x2` form: (a) the hi half shared with the address - `(u32)((char *)o + 0x20000) - (u32)o` does NOT
// fold to a constant, it emits `lui at,0x2; addu` (147 words); (b) address arithmetic on the field itself
// `(u32)&o->f1a0b0 - (u32)o - 0x1a0b0 + 0x20000` emits `lui at,0x1; ori at,0xa0b0; addu` (149 words); (c) a
// pointer-typed constant `(u32)(char *)0x20000` and a `u32` local assigned earlier both fold back to `lui a1,0x2`;
// (d) a variadic prototype for FUN_0004f010 changes nothing.  Retail's `move a1,v0` reuses the 0x20000 already in
// v0 for the later `addu v0,s3,v0`; this MWCC keeps that temp live across the jal and loads a1 separately.
// near miss from lane dsn2 (unreviewed)
