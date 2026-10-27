/* HSTMATCH module=hstp_trans_main.prx start=0x001f0814 end=0x001f08bc symbol=FUN_001f0814 lang=c99 data=0x00393f64 */
/* Clone of src/eboot/subobject_init_001e25c0.c (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00393f64-0x00393f94) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00109a44(void *a0, void *a1, int a2);
extern void FUN_00108e6c(void *a0, float f12);
extern void FUN_001090f4(void *a0, int a1);
extern void FUN_00225e94(void *a0, void *a1, void *a2, int a3);
extern void FUN_00225f18(void *a0, void *a1, void *a2, int a3);
extern void FUN_00108f54(void *a0, int a1);
extern void FUN_00226820(void *a0, void *a1);
extern void FUN_002266bc(void *a0, void *a1);

extern char DAT_00393bbc[];
extern char DAT_002d8c20[];

void FUN_001f0814(char *self)
{
    FUN_00109a44(*(void **)(self + 0x25b8), "data/menu/result/result_main/result_overlay.lay", 0);
    FUN_00108e6c(*(void **)(self + 0x25b8), 3100.0f);
    FUN_001090f4(*(void **)(self + 0x25b8), -1);
    FUN_00225e94(self + 0x25bc, *(void **)(self + 0x25b8), DAT_00393bbc, 5);
    FUN_00225f18(self + 0x25d0, self + 0x25bc, DAT_002d8c20, 0x17);
    FUN_00108f54(*(void **)(self + 0x25b8), 1);
    FUN_00226820(self + 0x279c, *(void **)(self + 0x25b8));
    FUN_002266bc(self + 0x2828, *(void **)(self + 0x25f8));
}
