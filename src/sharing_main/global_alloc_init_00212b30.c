/* HSTMATCH module=hstp_trans_main.prx start=0x00212b30 end=0x00212be4 symbol=FUN_00212b30 lang=c99 data=0x003976a4 */
/* Clone of src/eboot/global_alloc_init_002042c8.c (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x003976a4-0x003976cf) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void *DAT_003f3480;
extern void *DAT_003f3484;
extern char DAT_00212be4[];
extern char DAT_003b0388[];

extern void *FUN_00000a90(int size);
extern void *FUN_000008d8(void *blk, char *name, int zero, int a, int b);
extern void *FUN_00000bcc(int size);
extern void FUN_00065884(void *obj);
extern void FUN_0008d97c(void *p);
extern void FUN_00187724(void *a, void *b, char *c, int d, int e);

void FUN_00212b30(void)
{
    void *blk;
    void *obj;

    if (DAT_003f3480 != 0)
        return;

    blk = FUN_00000a90(256);
    DAT_003f3480 = FUN_000008d8(blk, DAT_00212be4, 0, 16, 15);

    if ((obj = FUN_00000bcc(48)) != 0) {
        FUN_00065884(obj);
        *(void **)obj = DAT_003b0388;
        FUN_0008d97c((char *)obj + 16);
        FUN_0008d97c((char *)obj + 32);
    }
    DAT_003f3484 = obj;
    FUN_00187724(DAT_003f3480, obj, "data/menu/chrselect/chrsel_param_chara.csv", 16, 15);
}
