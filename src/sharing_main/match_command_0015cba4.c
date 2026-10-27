/* HSTMATCH module=hstp_trans_main.prx start=0x0015cba4 end=0x0015cc54 symbol=FUN_0015cba4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Same code shape as the EBOOT script command src/eboot/FUN_00150b6c.c (only addresses differ): logs "Match (CharaBind)". */
typedef struct Owner { char pad[0x5a]; unsigned char f5a; } Owner;
typedef struct Cmd { int key; int f4; int f8; Owner *owner; } Cmd;

extern unsigned char DAT_003e9630;   /* debug-log enable flag */
extern void *DAT_003f344c;
extern char DAT_0038390c[];   /* "Match%s\n" */
extern char DAT_00383918[];   /* " (CharaBind)" */
extern char DAT_00383928[];   /* "" */
extern int *FUN_00157e10(int key, int id);
extern void FUN_00158b2c(Cmd *cmd);
extern void FUN_0015bb68(const char *fmt, ...);
extern void FUN_001db0bc(void *p, int flag);

int FUN_0015cba4(void *self, Cmd *cmd)
{
    int key = cmd->key;
    int bound = *FUN_00157e10(key, 11) != 0;
    if (DAT_003e9630 != 0) {
        char *msg;
        FUN_00158b2c(cmd);
        if (bound)
            msg = DAT_00383918;
        else
            msg = DAT_00383928;
        FUN_0015bb68(DAT_0038390c, msg);
    }
    FUN_001db0bc(DAT_003f344c, bound);
    cmd->owner->f5a = 1;
    *FUN_00157e10(key, 11) = 0;
    return 0;
}
