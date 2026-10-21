/* HSTMATCH module=EBOOT.BIN start=0x001ba78c end=0x001ba8a8 symbol=FUN_001ba78c lang=c99 */
extern int FUN_0016b1dc(int id);
extern char *FUN_0016b3d8(int id, int prev);
extern int FUN_0016b19c(int id);
extern unsigned char FUN_001baf80(void *model);
extern int FUN_00204570(int id);
extern void FUN_00205df4(void *slot, unsigned char mode, int *rect, int a, int b, int c, int d);

void FUN_001ba78c(char *self, int *handle)
{
    char *p = *(char **)handle + 0x30;
    if (*(unsigned char *)p == 0)
        return;
    int id = *(short *)(*(int *)(p + 4));
    char *cfg = FUN_0016b3d8(id, FUN_0016b1dc(id));
    int rect[6] = {0};
    rect[0] = id;
    int *src = *(int **)(*(char **)handle + 0x34);
    rect[1] = *(short *)((char *)src + 2);
    rect[2] = *(short *)((char *)src + 4);
    rect[3] = *(short *)((char *)src + 6);
    rect[4] = *(short *)((char *)src + 8);
    rect[5] = FUN_0016b19c(id);
    unsigned char mode = FUN_001baf80(*(void **)(*(int *)(*(int *)(self + 4) + 4) + 4));
    int v = FUN_00204570(rect[0]);
    FUN_00205df4(*(void **)(v + 4), mode, rect, *(unsigned char *)(cfg + 8) != 0,
                 *(unsigned char *)(cfg + 9) != 0, *(unsigned char *)(cfg + 10) != 0, v);
    self[0x11] = 1;
    self[0x15] = 1;
}
// NEAR MISS first pass: 69/71 words. Structure is right (substructure pointer `p = *handle + 0x30`,
// `cfg = FUN_0016b3d8(id, FUN_0016b1dc(id))` where the first call's result is the second argument --
// that nested-argument form is what puts `move a1,v0` in the jal delay slot). Remaining: the mode
// value lands in s1 instead of s2, retail re-loads `*(int*)(self+4)` (dead) before the FUN_00204570
// call, and the three boolean arguments materialise in a3/t0/t1 where ours use a0/a2/t0.
// near miss from lane ds11 (unreviewed)
