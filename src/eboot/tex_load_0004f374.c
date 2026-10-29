/* HSTMATCH module=EBOOT.BIN start=0x0004f374 end=0x0004f52c symbol=FUN_0004f374 lang=c99 */
/* Hand-written reconstruction from the disassembly (structured like the matched siblings 0x0004f52c/0x0004f5f0; the `return;` closing the success arm reproduces retail's dead delay-slot originals); exact match verified; names and types await human review. */
extern char DAT_002d0d40[];
extern char DAT_002d0d44[]; /* "I3rRoot__Get_nTex failed.\n" */
extern char DAT_002d0d60[]; /* "I3rRoot__GetTexName failed.\n" */
extern char DAT_002d0d80[]; /* "I3dRender__SetTexInfo failed.\n" */
extern char DAT_002d0da0[]; /* "I3rRoot__AssignTex failed.\n" */
extern char DAT_002d0a6c[]; /* "i3d.cpp" */
extern char DAT_00311170[];

#define TEXINFO_SIZE 576  /* bytes of texture info handed to SetTexInfo/AssignTex */
#define TEX_LOAD_FLAGS 0x40
#define I3D_LINE_TEX_LOAD 1199  /* line number reported with the failure */

struct TexBank {
    char pad[516];
    char texinfo[TEXINFO_SIZE];
};

extern void FUN_00049194(void);
extern void FUN_000491cc(void);
extern int FUN_0002fecc(void *);
extern void *FUN_0002fed8(void *, int);
extern int FUN_0004f6b4(void *, void *, int, int, int, int, int, int);
extern int FUN_00039914(void *, void *, int);
extern int FUN_00035094(void *, void *, int);
extern void FUN_0004ea98(void *);
extern void FUN_0004f010(void *, int, void *, int, void *);

void FUN_0004f374(struct TexBank *self, void *root, int arg3, int arg4, int arg5)
{
    int err = 0;
    int n; /* texture count */
    int i;
    void *name;

    FUN_00049194();
    n = FUN_0002fecc(root);
    FUN_000491cc();
    if (n < 0) {
        FUN_0004ea98(&DAT_002d0d44);
    } else {
        for (i = 0; i < n; i++) {
            FUN_00049194();
            name = FUN_0002fed8(root, i);
            FUN_000491cc();
            if (name == 0) {
                FUN_0004ea98(&DAT_002d0d60);
                goto fail;
            }
            if (FUN_0004f6b4(self, name, arg3, arg4, 0, arg5, TEX_LOAD_FLAGS, 1) < 0)
                goto fail;
        }
        FUN_00049194();
        err = FUN_00039914(self, &self->texinfo, TEXINFO_SIZE);
        FUN_000491cc();
        if (err != 0) {
            FUN_0004ea98(&DAT_002d0d80);
        } else {
            FUN_00049194();
            err = FUN_00035094(root, &self->texinfo, TEXINFO_SIZE);
            FUN_000491cc();
            if (err != 0) {
                FUN_0004ea98(&DAT_002d0da0);
            } else {
                return;
            }
        }
    }
fail:
    FUN_0004f010(&DAT_00311170, err, &DAT_002d0a6c, I3D_LINE_TEX_LOAD, &DAT_002d0d40);
}
