/* HSTMATCH module=hstp_trans_main.prx start=0x001eff94 end=0x001f0048 symbol=FUN_001eff94 lang=c99 data=0x00393cf4 */
/* Hand-written reconstruction from the disassembly (same source as the EBOOT twin src/eboot/subobject_init_001e1d70.c, addresses substituted); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00393cf4-0x00393d24) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern void FUN_00109a44(void *a0, void *a1, int a2);
extern void FUN_00108e6c(void *a0, float f12);
extern void FUN_001090f4(void *a0, int a1);
extern void FUN_00225e94(void *a0, void *a1, void *a2, int a3);
extern void FUN_00225f18(void *a0, void *a1, void *a2, int a3);
extern void FUN_00225fb4(void *a0, void *a1, void *a2, int a3);
extern void FUN_00226820(void *a0, void *a1);
extern void FUN_002266bc(void *a0, void *a1);

extern char DAT_00393ae0[];
extern char DAT_002d7f7c[];
extern char DAT_002d8044[];

void FUN_001eff94(char *self)
{
    FUN_00109a44(*(void **)(self + 0x810), "data/menu/result/result_phase/phaselayouter.lay", 0);
    FUN_00108e6c(*(void **)(self + 0x810), 2900.0f);
    FUN_001090f4(*(void **)(self + 0x810), -256);
    FUN_00225e94(self + 0x814, *(void **)(self + 0x810), DAT_00393ae0, 1);
    FUN_00225f18(self + 0x818, self + 0x814, DAT_002d7f7c, 6);
    FUN_00225fb4(self + 0x890, self + 0x814, DAT_002d8044, 1);
    FUN_00226820(self + 0x89c, *(void **)(self + 0x810));
    FUN_002266bc(self + 0x928, *(void **)(self + 0x818));
}
