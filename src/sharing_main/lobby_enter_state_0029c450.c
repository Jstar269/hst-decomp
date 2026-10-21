/* HSTMATCH module=hstp_trans_main.prx start=0x0029c450 end=0x0029c550 symbol=FUN_0029c450 lang=c99 */
/* Clone of src/eboot/lobby_enter_state_0028ac5c.c (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_001d5014(void *ctx, int a, int b, int c, int d, int e);
extern void FUN_0029c5b8(void);
extern void FUN_00055d60(void *buf, void *src, int mode);
extern void FUN_0029d9cc(int ctx, int obj, void *vec, float value);
extern void FUN_0023c838(int a, int b, int c, int d);
extern int FUN_00014a40(char *text);
extern void FUN_001c0984(void *ctx, char *text);
extern char DAT_003f344c[];
extern char DAT_003eaad8[];
struct Vec4_0029c450 { float x, y, z, w; };
struct Buf_0029c450 { int pad[12]; struct Vec4_0029c450 v; };
void FUN_0029c450(char *self)
{
    if (*(unsigned char *)(self + 0xec) != 0) {
        FUN_001d5014(*(void **)DAT_003f344c, -1, -1, *(int *)(self + 0xa8), 0, 0);
    } else {
        FUN_0029c5b8();
        int *p = *(int **)(self + 0x74);
        int *r = *(int **)((char *)p + 0xf4);
        float value;
        if (r != 0)
            value = *(float *)(*r + 8);
        else
            value = 0.0f;
        struct Vec4_0029c450 v;
        struct Buf_0029c450 buf;
        FUN_00055d60(&buf, p, *(int *)(self + 0xf0));
        v = buf.v;
        FUN_0029d9cc(*(int *)((char *)*(void **)DAT_003f344c + 0x17c), (int)(self + 0x80), &v, value);
        *(char *)(self + 0xec) = 1;
        FUN_0023c838(*(int *)((char *)*(void **)DAT_003f344c + 0xcc), *(int *)((char *)*(void **)DAT_003f344c + 0xd0),
                     *(int *)(self + 0x88), 1);
        if (FUN_00014a40(self + 0xae) != 0)
            FUN_001c0984(DAT_003eaad8, self + 0xae);
    }
}
