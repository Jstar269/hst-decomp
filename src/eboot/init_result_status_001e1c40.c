/* HSTMATCH module=EBOOT.BIN start=0x001e1c40 end=0x001e1d70 symbol=FUN_001e1c40 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_002172f4(void *dst, char *name, int n);
extern void FUN_00104118(void *obj, char *name, int flag);
extern void FUN_00103540(void *obj, float value);
extern void FUN_001037c8(void *obj, int value);
extern void FUN_00216e90(void *dst, void *parent, char **names, int n);
extern void FUN_00216f14(void *dst, void *parent, void *src, int n);
extern void FUN_00216fb0(void *dst, void *parent, void *src, int n);
extern void FUN_002170ec(void *dst, void *parent, void *src, int n);
extern void *DAT_0034a130;
extern char DAT_002ebd78[];
extern char DAT_002ebdb4[];
extern char *DAT_002ebbb8[];
extern char DAT_002c72fc[];
extern char DAT_002c7380[];

void FUN_001e1c40(char *self)
{
    FUN_002172f4(&DAT_0034a130, DAT_002ebd78, 123);
    FUN_00104118(*(void **)(self + 0x9b4), DAT_002ebdb4, 0);
    FUN_00103540(*(void **)(self + 0x9b4), 2900.0f);
    FUN_001037c8(*(void **)(self + 0x9b4), -256);
    FUN_00216e90(self + 0x9b8, *(void **)(self + 0x9b4), DAT_002ebbb8, 5);
    FUN_00216f14(self + 0x9cc, self + 0x9b8, DAT_0034a130, 123);
    FUN_00216fb0(self + 0x1368, self + 0x9b8, DAT_002c72fc, 4);
    FUN_002170ec(self + 0x1398, self + 0x9b8, DAT_002c7380, 60);
    for (int i = 0; i < 5; i++)
        *(int *)(self + 0x1748 + i * 4) = (int)*(float *)(*(int *)(self + 0x9b8 + i * 4) + 0x60);
}
