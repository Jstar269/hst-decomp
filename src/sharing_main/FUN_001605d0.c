/* HSTMATCH module=hstp_trans_main.prx start=0x001605d0 end=0x00160624 symbol=FUN_001605d0 data=0x00383d74 */
/* Clone of src/eboot/FUN_00154288.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00383d74-0x00383d85) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
typedef struct LoadKomonoCmd {
    char pad00[8];
    void *obj;  /* 0x08 */
    void *name; /* 0x0c name shown in the trace line */
} LoadKomonoCmd;

extern unsigned char DAT_003e9630; /* script trace flag */
extern void FUN_00158b2c(void *ctx);
extern void FUN_0015bb68(const char *fmt, void *name);
extern void FUN_0029a168(void *obj, void *name);

/* Script command "LoadKomono": trace it and load the named komono onto the object. */
int FUN_001605d0(LoadKomonoCmd *cmd, void *ctx)
{
    if (DAT_003e9630) {
        FUN_00158b2c(ctx);
        FUN_0015bb68("LoadKomono [%s]\n", cmd->name);
    }
    FUN_0029a168(cmd->obj, cmd->name);
    return 0;
}
