/* HSTMATCH module=EBOOT.BIN start=0x0028ac5c end=0x0028ad5c symbol=FUN_0028ac5c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_001c6bec(void *ctx, int a, int b, int c, int d, int e);
extern void FUN_0028adc4(void);
extern void FUN_00055240(void *buf, void *src, int mode);
extern void FUN_0028c204(int ctx, int obj, void *vec, float value);
extern void FUN_0022ca9c(int a, int b, int c, int d);
extern int FUN_00014a40(char *text);
extern void FUN_001b28f0(void *ctx, char *text);
extern char DAT_0034a114[];
extern char DAT_0034179c[];
struct Vec4_0028ac5c { float x, y, z, w; };
struct Buf_0028ac5c { int pad[12]; struct Vec4_0028ac5c v; };
void FUN_0028ac5c(char *self)
{
    if (*(unsigned char *)(self + 0xec) != 0) {
        FUN_001c6bec(*(void **)DAT_0034a114, -1, -1, *(int *)(self + 0xa8), 0, 0);
    } else {
        FUN_0028adc4();
        int *p = *(int **)(self + 0x74);
        int *r = *(int **)((char *)p + 0xf4);
        float value;
        if (r != 0)
            value = *(float *)(*r + 8);
        else
            value = 0.0f;
        struct Vec4_0028ac5c v;
        struct Buf_0028ac5c buf;
        FUN_00055240(&buf, p, *(int *)(self + 0xf0));
        v = buf.v;
        FUN_0028c204(*(int *)((char *)*(void **)DAT_0034a114 + 0x17c), (int)(self + 0x80), &v, value);
        *(char *)(self + 0xec) = 1;
        FUN_0022ca9c(*(int *)((char *)*(void **)DAT_0034a114 + 0xcc), *(int *)((char *)*(void **)DAT_0034a114 + 0xd0),
                     *(int *)(self + 0x88), 1);
        if (FUN_00014a40(self + 0xae) != 0)
            FUN_001b28f0(DAT_0034179c, self + 0xae);
    }
}
