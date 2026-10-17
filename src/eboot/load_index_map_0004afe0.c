/* HSTMATCH module=EBOOT.BIN start=0x0004afe0 end=0x0004b0f8 symbol=FUN_0004afe0 lang=c99 */
/* Clone of src/sharing_main/load_index_map_0004b1bc.c (hstclone.py tag u1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

typedef struct {
    void *f0;
    unsigned short *arr;
} Obj_0004afe0;

typedef struct {
    char pad[8];
    void *f8;
} Ctx_0004afe0;

extern char DAT_002d08cc[];
extern void *FUN_000104b0(int);
extern void FUN_000104e0(void *);
extern int FUN_0002b600(void *);
extern void *FUN_0002b608(void *, unsigned short);
extern int FUN_0002fe80(void *, void *);
extern void FUN_00049194(void);
extern void FUN_000491cc(void);
extern void FUN_0004ad6c(const char *, void *);

void FUN_0004afe0(Obj_0004afe0 *self, Ctx_0004afe0 *ctx)
{
    if (self->arr != 0) {
        FUN_000104e0(self->arr);
        self->arr = 0;
    }
    if (ctx == 0)
        return;
    if (self->f0 == 0)
        return;

    FUN_00049194();
    int count = FUN_0002b600(self->f0);
    self->arr = (unsigned short *)FUN_000104b0(count * 2);
    for (int i = 0; i < count; i++) {
        void *item = FUN_0002b608(self->f0, i);
        int idx = (ctx->f8 != 0) ? FUN_0002fe80(ctx->f8, item) : -1;
        if (idx < 0) {
            FUN_0004ad6c(DAT_002d08cc, item);
            self->arr[i] = 0xffff;
        } else {
            self->arr[i] = idx;
        }
    }
    FUN_000491cc();
}
