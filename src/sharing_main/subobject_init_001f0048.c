/* HSTMATCH module=hstp_trans_main.prx start=0x001f0048 end=0x001f00fc symbol=FUN_001f0048 lang=c99 data=0x00393d24 */
/* Clone of src/eboot/subobject_init_001e1e24.c (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00393d24-0x00393d52) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00109a44(void *a0, void *a1, int a2);
extern void FUN_00108e6c(void *a0, float f12);
extern void FUN_001090f4(void *a0, int a1);
extern void FUN_00225e94(void *a0, void *a1, void *a2, int a3);
extern void FUN_00225f18(void *a0, void *a1, void *a2, int a3);
extern void FUN_002260f0(void *a0, void *a1, void *a2, int a3);
extern void FUN_00226820(void *a0, void *a1);
extern void FUN_002266bc(void *a0, void *a1);

extern char DAT_00393aec[];
extern char DAT_002d8068[];
extern char DAT_002d8194[];

void FUN_001f0048(char *self)
{
    FUN_00109a44(*(void **)(self + 0x175c), "data/menu/result/result_rank/ranklayouter.lay", 0);
    FUN_00108e6c(*(void **)(self + 0x175c), 2900.0f);
    FUN_001090f4(*(void **)(self + 0x175c), -256);
    FUN_00225e94(self + 0x1760, *(void **)(self + 0x175c), DAT_00393aec, 1);
    FUN_00225f18(self + 0x1764, self + 0x1760, DAT_002d8068, 9);
    FUN_002260f0(self + 0x1818, self + 0x1760, DAT_002d8194, 3);
    FUN_00226820(self + 0x183c, *(void **)(self + 0x175c));
    FUN_002266bc(self + 0x18c8, *(void **)(self + 0x178c));
}
