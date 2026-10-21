/* HSTMATCH module=hstp_trans_main.prx start=0x001efa80 end=0x001efb88 symbol=FUN_001efa80 lang=c99 */
/* Clone of src/eboot/setup_table_001e185c.c (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00109a44(void *obj, char *name, int flag);
extern void FUN_00108e6c(void *obj, float value);
extern void FUN_001090f4(void *obj, int mode);
extern void FUN_00225e94(void *dst, void *src, char *name, int flag);
extern void FUN_00225f18(void *dst, void *src, char *name, int count);
extern void FUN_00226820(void *dst, void *src);
extern char DAT_00393bd0[];
extern char DAT_00393a50[];
extern char DAT_002d7400[];
void FUN_001efa80(char *self)
{
    FUN_00109a44(*(void **)(self + 0xd4), DAT_00393bd0, 0);
    FUN_00108e6c(*(void **)(self + 0xd4), 2900.0f);
    FUN_001090f4(*(void **)(self + 0xd4), -256);
    FUN_00225e94(self + 0xd8, *(void **)(self + 0xd4), DAT_00393a50, 1);
    FUN_00225f18(self + 0xdc, self + 0xd8, DAT_002d7400, 5);
    for (int i = 0; i < 5; i++) {
        *(int *)(self + 0x140 + i * 4) = *(short *)(*(int *)(self + 0xdc + i * 0x14) + 4);
        *(int *)(self + 0x154 + i * 4) = *(short *)(*(int *)(self + 0xdc + i * 0x14) + 8);
    }
    FUN_00226820(self + 0x168, *(void **)(self + 0xd4));
}
