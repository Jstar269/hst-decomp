/* HSTMATCH module=EBOOT.BIN start=0x0005708c end=0x00057344 symbol=FUN_0005708c lang=c99 */
/* Hand-written reconstruction from the disassembly (DeepSeek V4.1 Flash (Freebuff), lane dsn2); names and types
   await human review. Frame 80 (ra, s0-s7, f20/f21). a0 = the object. Two early outs (the pointer at +0x8c and the
   handle at +0x168), then the old array at +0x16c is released, the handle is re-registered through 0x562d8, and two
   arrays are built with operator new[] + __construct_new_array (16-byte elements from ctor 0x57344, 64-byte elements
   from ctor 0x56098) with count n = 0x2fe08(self->f8c->f8). 0x351c8 and 0x5691c bind the second array to the handle,
   then for each of the n entries a signed 16-bit index selects a 64-byte block of that array, three edge lengths are
   taken (dot then sqrt: 0x224d8 / 0x22e44) and stored in a four-float vector that 0x22450 applies three times, before
   the three lengths of the transformed block are written to the 16-byte output record at +0x16c with 1.0f in slot 3.
   The array is released, 0x491cc runs, and 0x57d6c(self) closes. */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct V4 {
    float x;
    float y;
    float z;
    float w;
} V4;

typedef struct Inner {
    char pad0[8];
    int *f8;                     /* 8 */
} Inner;

typedef struct Self {
    char pad0[0x8c];
    Inner *f8c;                  /* 0x8c */
    char pad90[0x168 - 0x90];
    int f168;                    /* 0x168: handle */
    u32 *f16c;                   /* 0x16c: output records */
} Self;

void FUN_000562d8(int handle, int a1, int a2);
void FUN_000009e4(void *p);
void FUN_00049194(void);
void FUN_000491cc(void);
int FUN_0002fe08(int a0);
void *FUN_00000a90(int size);
void *FUN_000008d8(void *p, void (*ctor)(), int dtor, int elem, int count);
void FUN_00057344(void);
void FUN_00056098(void);
void FUN_000351c8(int a0, void *a1);
void FUN_0005691c(int handle, void *a1, int a2, int a3, float f12, float f13, float f14);
void *FUN_0002e7a4(int a0);
float FUN_000224d8(void *a0, void *a1);
float FUN_00022e44(float f12);
void FUN_00022450(void *a0, void *a1, V4 *a2);
void FUN_00057d6c(Self *self);

void FUN_0005708c(Self *self)
{
    int n;
    int i;
    void *a;
    void *b;
    int *src;
    V4 v;
    float f20;
    float f21;

    if (self->f8c == 0)
        return;
    if (self->f168 == 0)
        return;

    FUN_000562d8(self->f168, 0, 0);
    if (self->f16c != 0) {
        self->f16c = 0;
        FUN_000009e4((char *)self->f16c - 16);
    }
    self->f16c = 0;
    FUN_00049194();

    if (self->f8c->f8 != 0)
        n = FUN_0002fe08((int)self->f8c->f8);
    else
        n = 0;

    a = FUN_00000a90(n * 16 + 16);
    a = FUN_000008d8(a, FUN_00057344, 0, 16, n);
    self->f16c = (u32 *)a;

    b = FUN_00000a90(n * 64 + 16);
    b = FUN_000008d8(b, FUN_00056098, 0, 64, n);

    FUN_000351c8((int)self->f8c->f8, b);
    FUN_0005691c(self->f168, b, 546, 0, 0.0f, 0.0f, 0.0f);

    src = (int *)FUN_0002e7a4((int)self->f8c->f8 + 16);
    v.x = 1.0f;
    v.y = 1.0f;
    v.z = 1.0f;
    v.w = 1.0f;

    for (i = 0; i < n; i++) {
        int idx = *(short *)*src;
        char *e;
        char *d;
        u32 *out;

        if (idx < 0) {
            e = (char *)b;
            d = (char *)a + 32;
        } else {
            e = (char *)b + (idx << 6);
            d = (char *)a;
        }
        v.x = FUN_00022e44(FUN_000224d8(e, e));
        v.y = FUN_00022e44(FUN_000224d8(e + 16, e + 16));
        v.z = FUN_00022e44(FUN_000224d8(e + 32, e + 32));
        FUN_00022450(d, d, &v);
        FUN_00022450(d + 16, d + 16, &v);
        FUN_00022450(d + 32, d + 32, &v);
        f21 = FUN_00022e44(FUN_000224d8(d + 32, d + 32));
        f20 = FUN_00022e44(FUN_000224d8(d + 16, d + 16));
        out = self->f16c + i * 4;
        out[0] = *(u32 *)&f20;
        out[1] = *(u32 *)&f21;
        out[3] = 0x3f800000u;

        src += 4;
        a = (char *)a + 64;
    }

    if (b != 0)
        FUN_000009e4((char *)b - 16);
    FUN_000491cc();
    FUN_00057d6c(self);
}
// PHASE-3 HEAVY HEAD (2026-10-28, pass 19): first write-first pass from the disassembly -> 170/174 words, 155 differ.
// DECODE: frame 80 (ra, s0-s7, f20/f21), one parameter. Two early outs: the pointer at +0x8c and the handle at +0x168.
// Then the old array at +0x16c is released (delete[] with the -16 cookie), the handle is re-registered through
// 0x562d8(handle,0,0), and two arrays are built with new[] + 0x8d8 __construct_new_array: 16-byte elements with ctor
// FUN_00057344 (the address right after this function) and 64-byte elements with ctor FUN_00056098, both counted by
// n = 0x2fe08(self->f8c->f8). 0x351c8 and 0x5691c(handle, b, 546, 0, 0,0,0) bind the 64-byte array to the handle, then
// 0x2e7a4(self->f8c->f8 + 16) gives the source cursor. Per entry: idx = *(short *)*src; if idx < 0 the block is the
// array base and the write cursor is +32, else the block is base + (idx << 6) and the cursor is the base; three edge
// lengths (0x224d8 = dot, 0x22e44 = its float transform) fill a four-float vector initialised to 1.0f, 0x22450 applies
// it three times in place, and the lengths of the transformed block's three sub-blocks are written to the record with
// 1.0f in slot 3. Tail: delete[] of the 64-byte array, 0x491cc(), 0x57d6c(self). 0x49194 at entry answers 0x491cc.
// LEFT: the loop body's register allocation and the bltzl arm (index < 0), which the first pass approximated; the
// 4-word extent gap is the missing arm.
// near miss from lane dsn2 (unreviewed)
