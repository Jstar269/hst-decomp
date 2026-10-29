/* HSTMATCH module=EBOOT.BIN start=0x00154288 end=0x001542dc symbol=FUN_00154288 data=0x002dc88c */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc88c-0x002dc89d) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
typedef struct LoadKomonoCmd {
    char pad00[8];
    void *obj;  /* 0x08 */
    void *name; /* 0x0c name shown in the trace line */
} LoadKomonoCmd;

extern unsigned char DAT_003402f0; /* script trace flag */
extern void FUN_0014d044(void *ctx);
extern void FUN_0014fd94(const char *fmt, void *name);
extern void FUN_002889cc(void *obj, void *name);

/* Script command "LoadKomono": trace it and load the named komono onto the object. */
int FUN_00154288(LoadKomonoCmd *cmd, void *ctx)
{
    if (DAT_003402f0) {
        FUN_0014d044(ctx);
        FUN_0014fd94("LoadKomono [%s]\n", cmd->name);
    }
    FUN_002889cc(cmd->obj, cmd->name);
    return 0;
}
