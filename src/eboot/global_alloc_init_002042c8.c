/* HSTMATCH module=EBOOT.BIN start=0x002042c8 end=0x0020437c symbol=FUN_002042c8 lang=c99 */
/* LoadChrSelParamChara: data/menu/chrselect/chrsel_param_chara.csv; see docs/DATA-TABLES.md */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void *DAT_0034a148;
extern void *DAT_0034a14c;
extern char DAT_0020437c[];
extern char DAT_002ef5b0[];
extern char DAT_003070bc[];

extern void *FUN_00000a90(int size);
extern void *FUN_000008d8(void *blk, char *name, int zero, int a, int b);
extern void *FUN_00000bcc(int size);
extern void FUN_000649c0(void *obj);
extern void FUN_0008c230(void *p);
extern void FUN_0017b030(void *a, void *b, char *c, int d, int e);

void FUN_002042c8(void)
{
    void *blk;
    void *obj;

    if (DAT_0034a148 != 0)
        return;

    blk = FUN_00000a90(256);
    DAT_0034a148 = FUN_000008d8(blk, DAT_0020437c, 0, 16, 15);

    if ((obj = FUN_00000bcc(48)) != 0) {
        FUN_000649c0(obj);
        *(void **)obj = DAT_003070bc;
        FUN_0008c230((char *)obj + 16);
        FUN_0008c230((char *)obj + 32);
    }
    DAT_0034a14c = obj;
    FUN_0017b030(DAT_0034a148, obj, DAT_002ef5b0, 16, 15);
}
