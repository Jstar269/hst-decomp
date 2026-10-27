/* HSTMATCH module=hstp_trans_main.prx start=0x001efe64 end=0x001eff94 symbol=FUN_001efe64 lang=c99 data=0x00393c84 */
/* Clone of src/eboot/init_result_status_001e1c40.c (hstclone.py tag c21sn2s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x00393c84-0x00393cf1) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_002262f8(void *dst, char *name, int n);
extern void FUN_00109a44(void *obj, char *name, int flag);
extern void FUN_00108e6c(void *obj, float value);
extern void FUN_001090f4(void *obj, int value);
extern void FUN_00225e94(void *dst, void *parent, char **names, int n);
extern void FUN_00225f18(void *dst, void *parent, void *src, int n);
extern void FUN_00225fb4(void *dst, void *parent, void *src, int n);
extern void FUN_002260f0(void *dst, void *parent, void *src, int n);
extern void *DAT_003f3468;
extern char *DAT_00393ac4[];
extern char DAT_002d773c[];
extern char DAT_002d77c0[];

void FUN_001efe64(char *self)
{
    FUN_002262f8(&DAT_003f3468, "data/menu/result/result_status/result_status_unitlist.txt", 123);
    FUN_00109a44(*(void **)(self + 0x9b4), "data/menu/result/result_status/result_status.lay", 0);
    FUN_00108e6c(*(void **)(self + 0x9b4), 2900.0f);
    FUN_001090f4(*(void **)(self + 0x9b4), -256);
    FUN_00225e94(self + 0x9b8, *(void **)(self + 0x9b4), DAT_00393ac4, 5);
    FUN_00225f18(self + 0x9cc, self + 0x9b8, DAT_003f3468, 123);
    FUN_00225fb4(self + 0x1368, self + 0x9b8, DAT_002d773c, 4);
    FUN_002260f0(self + 0x1398, self + 0x9b8, DAT_002d77c0, 60);
    for (int i = 0; i < 5; i++)
        *(int *)(self + 0x1748 + i * 4) = (int)*(float *)(*(int *)(self + 0x9b8 + i * 4) + 0x60);
}
