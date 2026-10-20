/* HSTMATCH module=EBOOT.BIN start=0x00096214 end=0x0009642c symbol=FUN_00096214 lang=c99 */
// NEAR MISS (138/134 words, 82 differ, first at +0x50): the guard chain now matches retail exactly
// (`lbu` DAT; `sltu v1,zero,v1`; `beqz` with `move s5,a0` in the delay slot; `lbu 0x1b4`; `sltu`+`xori`
// from `!(*(unsigned char*)...)`; `beqzl` to the epilogue), as do the 96-byte frame, all eleven saves and
// the whole destination layout (floats 0x20-0x3c, short 0x40, signed-char bitfields 3+5 in 0x42 and
// 2+1+1+1+3 in 0x43, float 0x44, ints 0x48/0x4c). What remains is register assignment among the ten
// values loaded before the FUN_0001d3ac call (retail keeps 0x4da/0x4d9/0x4d8/0x4cf/0x4e8/0x4e4 in
// s2/s1/s0/s6/s7/s8 and the global+100 value in v0) and the resulting 4-word length difference, which
// shifts every branch target by 0x10.
typedef unsigned char u8;
typedef unsigned int u32;

extern u8 DAT_003386b8;
extern u8 *DAT_003386b0;
extern u8 *DAT_00338af0;
extern void FUN_0001d3ac(float *dst, float *src);
extern u8 *FUN_000c4ba0(u8 *a, int b);

typedef struct {
    u8 pad0[0x20];
    float f20;
    float f24;
    float f28;
    float f2c;
    float f30;
    float f34;
    float f38;
    float f3c;
    short f40;
    signed char b42_lo : 3;
    signed char b42_hi : 5;
    signed char b43_a : 2;
    signed char b43_b : 1;
    signed char b43_c : 1;
    signed char b43_d : 1;
    signed char b43_e : 3;
    float f44;
    int f48;
    int f4c;
} Dst;

void FUN_00096214(char *p)
{
    Dst *d;
    float tmp[4];
    int go = 0;
    float fa;
    int v4dc;
    int vg;
    int v4da;
    int v4d9;
    int v41c;
    int v4d8;
    int v4cf;
    int v4e8;
    int v4e4;

    go = DAT_003386b8 != 0;
    if (go != 0) go = !*(unsigned char *)(p + 0x1b4);
    if (go == 0) return;
    if (DAT_00338af0 == 0) return;

    d = (Dst *)FUN_000c4ba0(DAT_00338af0, *(int *)(p + 0x148));
    d->f4c = *(int *)(DAT_00338af0 + 0x780);

    fa = *(float *)(p + 0x43c);
    v4dc = *(int *)(p + 0x4dc);
    vg = *(int *)(DAT_003386b0 + 100);
    v4da = *(u8 *)(p + 0x4da);
    v4d9 = *(u8 *)(p + 0x4d9);
    v41c = *(int *)(p + 0x41c);
    v4d8 = *(u8 *)(p + 0x4d8);
    v4cf = *(u8 *)(p + 0x4cf);
    v4e8 = *(int *)(p + 0x4e8);
    v4e4 = *(int *)(p + 0x4e4);

    FUN_0001d3ac(tmp, (float *)(p + 0x550));

    d->f20 = tmp[0];
    d->f24 = tmp[1];
    d->f28 = tmp[2];
    d->f2c = tmp[3];

    d->f30 = *(float *)(p + 0x580);
    d->f34 = *(float *)(p + 0x584);
    d->f38 = *(float *)(p + 0x588);
    d->f3c = *(float *)(p + 0x58c);

    d->f40 = (short)v41c;

    d->b43_a = v4cf;
    d->b42_lo = v4e4;
    d->b42_hi = v4e8;

    d->b43_b = v4d8;
    d->b43_c = v4d9;
    d->b43_d = v4da;
    d->b43_e = v4dc;

    d->f44 = fa;
    d->f48 = vg;
}
// near miss from lane ds1 (unreviewed)
