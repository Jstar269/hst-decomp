/* HSTMATCH module=EBOOT.BIN start=0x00042a90 end=0x00042bec symbol=FUN_00042a90 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern void FUN_00044d40(void *self);
extern void FUN_00044e54(void);
extern void FUN_00044eac(void);
extern int FUN_002b7ab8(void *desc, int *out);
extern void FUN_00042bec(void *self);
extern void FUN_0004315c(void *self, int a, float f1, float f2, float f3, float f4);
extern void FUN_00042e04(void *self);

extern int DAT_0030ff7c;

typedef struct Desc {
    int a;
    int b;
    int c;
    void *on1;
    void *on2;
    int z[6];
} Desc;

typedef struct Self {
    char pad0[0x104];
    int f104;
    char pad1[0x19074 - 0x108];
    int f19074;
    char pad2[0x19084 - 0x19078];
    int f19084;
    int f19088;
    int f1908c;
    int f19090;
    int f19094;
    int f19098;
    int f1909c;
    int f190a0;
    int f190a4;
    int f190a8;
    int f190ac;
    int f190b0;
    int f190b4;
    int f190b8;
} Self;

void FUN_00042a90(Self *self)
{
    int out;
    Desc d;
    char col[4];

    FUN_00044d40(self);
    DAT_0030ff7c = 0;
    d.b = 3;
    d.a = 0;
    d.c = 0;
    d.on1 = (void *)&FUN_00044e54;
    d.on2 = (void *)&FUN_00044eac;
    d.z[0] = 0;
    d.z[1] = 0;
    d.z[2] = 0;
    d.z[3] = 0;
    d.z[4] = 0;
    d.z[5] = 0;
    self->f19088 = FUN_002b7ab8(&d, &out);
    FUN_00042bec(self);
    self->f19074 = 0;
    self->f19084 = 0;
    self->f190a0 = (self->f190b4 / self->f19098) * (0 / self->f1909c);
    self->f190b4 = 0;
    self->f190b8 = 0;
    self->f190a4 = 0;
    col[0] = 0x80;
    col[1] = 0x80;
    col[2] = 0x80;
    col[3] = 0x80;
    self->f104 = *(int *)col;
    FUN_0004315c(self, 0xffff, 0.0f, 0.0f, 1.0f, 1.0f);
    FUN_00042e04(self);
}
// PARKED 2026-10-28 (3 compiles): 70/87 words. Shape recovered: init function; DAT_0030ff7c=0
// in the FUN_00044d40 jal delay slot, a 44-byte Desc at sp+32 (0,3,0, &FUN_00044e54,
// &FUN_00044eac, six zero words) passed by pointer with an int* out-param to FUN_002b7ab8
// (result -> self+0x19088), FUN_00042bec(self), then self+0x19074/0x19084/0x190b4/0x190b8 = 0,
// self+0x190a0 = (f190b4/f19098) * (0/f1909c), f190a4 = 0, f104 = 0x80808080 (built from a
// 4-byte char array), FUN_0004315c(self, 0xffff, 0.0f, 0.0f, 1.0f, 1.0f), FUN_00042e04(self).
// BLOCKER: retail's `lw a1,0x190b4` is NOT forwarded from the `sw zero,0x190b4` just before it,
// so the divisions survive; every spelling here forwards the 0 and MWCC then folds the whole
// `(a/b)*(0/c)` product to `sw zero`. Retail's store/load pair must differ in type or base
// expression (type-keyed CSE). Field offsets: self+0x104, 0x19074, 0x19084, 0x19088, 0x19098,
// 0x1909c, 0x190a0, 0x190a4, 0x190b4, 0x190b8 (frame 80, out@76, Desc@32, char[4]@28).
// near miss from lane dsn2 (unreviewed)
