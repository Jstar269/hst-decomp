/* HSTMATCH module=EBOOT.BIN start=0x001e1e24 end=0x001e1ed8 symbol=FUN_001e1e24 lang=c99 data=0x002ebe18 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002ebe18-0x002ebe46) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern void FUN_00104118(void *a0, void *a1, int a2);
extern void FUN_00103540(void *a0, float f12);
extern void FUN_001037c8(void *a0, int a1);
extern void FUN_00216e90(void *a0, void *a1, void *a2, int a3);
extern void FUN_00216f14(void *a0, void *a1, void *a2, int a3);
extern void FUN_002170ec(void *a0, void *a1, void *a2, int a3);
extern void FUN_00217778(void *a0, void *a1);
extern void FUN_00217614(void *a0, void *a1);

extern char DAT_002ebbe0[];
extern char DAT_002c7c28[];
extern char DAT_002c7d54[];

void FUN_001e1e24(char *self)
{
    FUN_00104118(*(void **)(self + 0x175c), "data/menu/result/result_rank/ranklayouter.lay", 0);
    FUN_00103540(*(void **)(self + 0x175c), 2900.0f);
    FUN_001037c8(*(void **)(self + 0x175c), -256);
    FUN_00216e90(self + 0x1760, *(void **)(self + 0x175c), DAT_002ebbe0, 1);
    FUN_00216f14(self + 0x1764, self + 0x1760, DAT_002c7c28, 9);
    FUN_002170ec(self + 0x1818, self + 0x1760, DAT_002c7d54, 3);
    FUN_00217778(self + 0x183c, *(void **)(self + 0x175c));
    FUN_00217614(self + 0x18c8, *(void **)(self + 0x178c));
}
