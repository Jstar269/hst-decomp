/* HSTMATCH module=EBOOT.BIN start=0x000969c0 end=0x00096a90 symbol=FUN_000969c0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Vec4 { float x, y, z, w; } Vec4;
typedef struct Src {
    char pad0[0xf0];
    Vec4 a;
    Vec4 b;
    float c0, c1, c2, c3;
    int d0;
    short d1;
    signed char d2;
    signed char d3;
    int d4;
} Src;
extern Vec4 DAT_00338720;
extern Vec4 DAT_00338730;
extern float DAT_00338740;
extern float DAT_00338744;
extern float DAT_00338748;
extern float DAT_0033874c;
extern int DAT_00338750;
extern short DAT_00338754;
extern signed char DAT_00338756;
extern signed char DAT_00338757;
extern int DAT_00338758;

void FUN_000969c0(Src *self)
{
    DAT_00338720 = self->a;
    DAT_00338730 = self->b;
    DAT_00338740 = self->c0;
    DAT_00338744 = self->c1;
    DAT_00338748 = self->c2;
    DAT_0033874c = self->c3;
    DAT_00338750 = self->d0;
    DAT_00338754 = self->d1;
    DAT_00338756 = self->d2;
    DAT_00338757 = self->d3;
    DAT_00338758 = self->d4;
}
