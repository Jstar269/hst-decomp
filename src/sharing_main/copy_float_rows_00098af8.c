/* HSTMATCH module=hstp_trans_main.prx start=0x00098af8 end=0x00098bc8 symbol=FUN_00098af8 lang=c99 */
/* Clone of src/eboot/copy_float_rows_000969c0.c (hstclone.py tag c21sn1s): addresses substituted; exact match verified; names and types await human review. */
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
extern Vec4 DAT_003e1a60;
extern Vec4 DAT_003e1a70;
extern float DAT_003e1a80;
extern float DAT_003e1a84;
extern float DAT_003e1a88;
extern float DAT_003e1a8c;
extern int DAT_003e1a90;
extern short DAT_003e1a94;
extern signed char DAT_003e1a96;
extern signed char DAT_003e1a97;
extern int DAT_003e1a98;

void FUN_00098af8(Src *self)
{
    DAT_003e1a60 = self->a;
    DAT_003e1a70 = self->b;
    DAT_003e1a80 = self->c0;
    DAT_003e1a84 = self->c1;
    DAT_003e1a88 = self->c2;
    DAT_003e1a8c = self->c3;
    DAT_003e1a90 = self->d0;
    DAT_003e1a94 = self->d1;
    DAT_003e1a96 = self->d2;
    DAT_003e1a97 = self->d3;
    DAT_003e1a98 = self->d4;
}
