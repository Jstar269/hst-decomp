/* HSTMATCH module=EBOOT.BIN start=0x001e185c end=0x001e1964 symbol=FUN_001e185c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00104118(void *obj, char *name, int flag);
extern void FUN_00103540(void *obj, float value);
extern void FUN_001037c8(void *obj, int mode);
extern void FUN_00216e90(void *dst, void *src, char *name, int flag);
extern void FUN_00216f14(void *dst, void *src, char *name, int count);
extern void FUN_00217778(void *dst, void *src);
extern char DAT_002ebcc4[];
extern char DAT_002ebb44[];
extern char DAT_002c6fc0[];
void FUN_001e185c(char *self)
{
    FUN_00104118(*(void **)(self + 0xd4), DAT_002ebcc4, 0);
    FUN_00103540(*(void **)(self + 0xd4), 2900.0f);
    FUN_001037c8(*(void **)(self + 0xd4), -256);
    FUN_00216e90(self + 0xd8, *(void **)(self + 0xd4), DAT_002ebb44, 1);
    FUN_00216f14(self + 0xdc, self + 0xd8, DAT_002c6fc0, 5);
    for (int i = 0; i < 5; i++) {
        *(int *)(self + 0x140 + i * 4) = *(short *)(*(int *)(self + 0xdc + i * 0x14) + 4);
        *(int *)(self + 0x154 + i * 4) = *(short *)(*(int *)(self + 0xdc + i * 0x14) + 8);
    }
    FUN_00217778(self + 0x168, *(void **)(self + 0xd4));
}
