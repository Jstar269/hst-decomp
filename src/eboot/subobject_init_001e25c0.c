/* HSTMATCH module=EBOOT.BIN start=0x001e25c0 end=0x001e2668 symbol=FUN_001e25c0 lang=c99 data=0x002ec04c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002ec04c-0x002ec07c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern void FUN_00104118(void *a0, void *a1, int a2);
extern void FUN_00103540(void *a0, float f12);
extern void FUN_001037c8(void *a0, int a1);
extern void FUN_00216e90(void *a0, void *a1, void *a2, int a3);
extern void FUN_00216f14(void *a0, void *a1, void *a2, int a3);
extern void FUN_00103628(void *a0, int a1);
extern void FUN_00217778(void *a0, void *a1);
extern void FUN_00217614(void *a0, void *a1);

extern char DAT_002ebcb0[];
extern char DAT_002c87e0[];

void FUN_001e25c0(char *self)
{
    FUN_00104118(*(void **)(self + 0x25b8), "data/menu/result/result_main/result_overlay.lay", 0);
    FUN_00103540(*(void **)(self + 0x25b8), 3100.0f);
    FUN_001037c8(*(void **)(self + 0x25b8), -1);
    FUN_00216e90(self + 0x25bc, *(void **)(self + 0x25b8), DAT_002ebcb0, 5);
    FUN_00216f14(self + 0x25d0, self + 0x25bc, DAT_002c87e0, 0x17);
    FUN_00103628(*(void **)(self + 0x25b8), 1);
    FUN_00217778(self + 0x279c, *(void **)(self + 0x25b8));
    FUN_00217614(self + 0x2828, *(void **)(self + 0x25f8));
}
