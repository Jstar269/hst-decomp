/* HSTMATCH module=hstp_trans_main.prx start=0x0004fbfc end=0x0004fdb4 symbol=FUN_0004fbfc lang=c99 */
/* Clone of src/eboot/tex_load_0004f374.c (hstclone.py tag c072907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (structured like the matched siblings 0x0004f52c/0x0004f5f0; the `return;` closing the success arm reproduces retail's dead delay-slot originals); exact match verified; names and types await human review. */
extern char DAT_003767fc[];
extern char DAT_00376800[]; /* "I3rRoot__Get_nTex failed.\n" */
extern char DAT_0037681c[]; /* "I3rRoot__GetTexName failed.\n" */
extern char DAT_0037683c[]; /* "I3dRender__SetTexInfo failed.\n" */
extern char DAT_0037685c[]; /* "I3rRoot__AssignTex failed.\n" */
extern char DAT_003763c8[]; /* "i3d.cpp" */
extern char DAT_003ba4b0[];

struct Obj {
    char pad[516];
    char buf[576];
};

extern void FUN_00048fb8(void);
extern void FUN_00049020(void);
extern int FUN_0002fef4(void *);
extern void *FUN_0002ff00(void *, int);
extern int FUN_0004ff3c(void *, void *, int, int, int, int, int, int);
extern int FUN_0003993c(void *, void *, int);
extern int FUN_000350bc(void *, void *, int);
extern void FUN_0004efe0(void *);
extern void FUN_0004f864(void *, int, void *, int, void *);

void FUN_0004fbfc(struct Obj *self, void *root, int param_3, int param_4, int param_5)
{
    int err = 0;
    int n;
    int i;
    void *name;

    FUN_00048fb8();
    n = FUN_0002fef4(root);
    FUN_00049020();
    if (n < 0) {
        FUN_0004efe0(&DAT_00376800);
    } else {
        for (i = 0; i < n; i++) {
            FUN_00048fb8();
            name = FUN_0002ff00(root, i);
            FUN_00049020();
            if (name == 0) {
                FUN_0004efe0(&DAT_0037681c);
                goto fail;
            }
            if (FUN_0004ff3c(self, name, param_3, param_4, 0, param_5, 0x40, 1) < 0)
                goto fail;
        }
        FUN_00048fb8();
        err = FUN_0003993c(self, &self->buf, 576);
        FUN_00049020();
        if (err != 0) {
            FUN_0004efe0(&DAT_0037683c);
        } else {
            FUN_00048fb8();
            err = FUN_000350bc(root, &self->buf, 576);
            FUN_00049020();
            if (err != 0) {
                FUN_0004efe0(&DAT_0037685c);
            } else {
                return;
            }
        }
    }
fail:
    FUN_0004f864(&DAT_003ba4b0, err, &DAT_003763c8, 1199, &DAT_003767fc);
}
