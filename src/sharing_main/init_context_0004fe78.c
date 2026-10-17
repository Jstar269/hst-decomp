/* HSTMATCH module=hstp_trans_main.prx start=0x0004fe78 end=0x0004ff3c symbol=FUN_0004fe78 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_003767fc[];
extern char DAT_0037683c[];
extern char DAT_003763c8[];
extern char DAT_003ba4b0[];

struct Obj {
    char pad[516];
    char buf[576];
};

extern int FUN_0004ff3c(void *, int, void *, int, int, int, int, int);
extern void FUN_00048fb8(void);
extern int FUN_0003993c(void *, void *, int);
extern void FUN_00049020(void);
extern void FUN_0004efe0(void *);
extern void FUN_0004f864(void *, int, void *, int, int);

int FUN_0004fe78(struct Obj *param_1, int param_2, int param_3, int param_4, int param_5, int param_6)
{
    int err = 0;
    int res = FUN_0004ff3c(param_1, param_2, &DAT_003767fc, param_4, param_3, param_5, param_6, 0);
    if (res >= 0) {
        FUN_00048fb8();
        err = FUN_0003993c(param_1, &param_1->buf, 576);
        FUN_00049020();
        if (err != 0) {
            FUN_0004efe0(&DAT_0037683c);
        } else {
            return res;
        }
    }
    FUN_0004f864(&DAT_003ba4b0, err, &DAT_003763c8, 1255, param_2);
    return -1;
}
