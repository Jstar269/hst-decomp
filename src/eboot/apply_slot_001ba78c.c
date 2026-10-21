/* HSTMATCH module=EBOOT.BIN start=0x001ba78c end=0x001ba8a8 symbol=FUN_001ba78c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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
    void **slot = (void **)(*(char **)(self + 4) + 4);
    int v = FUN_00204570(rect[0]);
    FUN_00205df4(*slot, mode, rect, *(unsigned char *)(cfg + 8) != 0,
                 *(unsigned char *)(cfg + 9) != 0, *(unsigned char *)(cfg + 10) != 0, v);
    self[0x11] = 1;
    self[0x15] = 1;
}
