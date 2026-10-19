/* HSTMATCH module=EBOOT.BIN start=0x001e1d70 end=0x001e1e24 symbol=FUN_001e1d70 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00104118(void *a0, void *a1, int a2);
extern void FUN_00103540(void *a0, float f12);
extern void FUN_001037c8(void *a0, int a1);
extern void FUN_00216e90(void *a0, void *a1, void *a2, int a3);
extern void FUN_00216f14(void *a0, void *a1, void *a2, int a3);
extern void FUN_00216fb0(void *a0, void *a1, void *a2, int a3);
extern void FUN_00217778(void *a0, void *a1);
extern void FUN_00217614(void *a0, void *a1);

extern char DAT_002ebde8[];
extern char DAT_002ebbd4[];
extern char DAT_002c7b3c[];
extern char DAT_002c7c04[];

void FUN_001e1d70(char *self)
{
    FUN_00104118(*(void **)(self + 0x810), DAT_002ebde8, 0);
    FUN_00103540(*(void **)(self + 0x810), 2900.0f);
    FUN_001037c8(*(void **)(self + 0x810), -256);
    FUN_00216e90(self + 0x814, *(void **)(self + 0x810), DAT_002ebbd4, 1);
    FUN_00216f14(self + 0x818, self + 0x814, DAT_002c7b3c, 6);
    FUN_00216fb0(self + 0x890, self + 0x814, DAT_002c7c04, 1);
    FUN_00217778(self + 0x89c, *(void **)(self + 0x810));
    FUN_00217614(self + 0x928, *(void **)(self + 0x818));
}
