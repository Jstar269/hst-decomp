/* HSTMATCH module=EBOOT.BIN start=0x0004f5f0 end=0x0004f6b4 symbol=FUN_0004f5f0 lang=c99 */
/* Clone of src/sharing_main/init_context_0004fe78.c (hstclone.py tag u6fr2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_002d0d40[];
extern char DAT_002d0d80[];
extern char DAT_002d0a6c[];
extern char DAT_00311170[];

struct Obj {
    char pad[516];
    char buf[576];
};

extern int FUN_0004f6b4(void *, int, void *, int, int, int, int, int);
extern void FUN_00049194(void);
extern int FUN_00039914(void *, void *, int);
extern void FUN_000491cc(void);
extern void FUN_0004ea98(void *);
extern void FUN_0004f010(void *, int, void *, int, int);

int FUN_0004f5f0(struct Obj *param_1, int param_2, int param_3, int param_4, int param_5, int param_6)
{
    int err = 0;
    int res = FUN_0004f6b4(param_1, param_2, &DAT_002d0d40, param_4, param_3, param_5, param_6, 0);
    if (res >= 0) {
        FUN_00049194();
        err = FUN_00039914(param_1, &param_1->buf, 576);
        FUN_000491cc();
        if (err != 0) {
            FUN_0004ea98(&DAT_002d0d80);
        } else {
            return res;
        }
    }
    FUN_0004f010(&DAT_00311170, err, &DAT_002d0a6c, 1255, param_2);
    return -1;
}
