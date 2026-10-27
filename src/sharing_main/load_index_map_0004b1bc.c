/* HSTMATCH module=hstp_trans_main.prx start=0x0004b1bc end=0x0004b2d4 symbol=FUN_0004b1bc lang=c99 data=0x00376150 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00376150-0x00376178) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */

typedef struct {
    void *f0;
    unsigned short *arr;
} Obj_0004b1bc;

typedef struct {
    char pad[8];
    void *f8;
} Ctx_0004b1bc;

extern void *FUN_000104b0(int);
extern void FUN_000104e0(void *);
extern int FUN_0002b628(void *);
extern void *FUN_0002b630(void *, unsigned short);
extern int FUN_0002fea8(void *, void *);
extern void FUN_00048fb8(void);
extern void FUN_00049020(void);
extern void FUN_0004ae24(const char *, void *);

void FUN_0004b1bc(Obj_0004b1bc *self, Ctx_0004b1bc *ctx)
{
    if (self->arr != 0) {
        FUN_000104e0(self->arr);
        self->arr = 0;
    }
    if (ctx == 0)
        return;
    if (self->f0 == 0)
        return;

    FUN_00048fb8();
    int count = FUN_0002b628(self->f0);
    self->arr = (unsigned short *)FUN_000104b0(count * 2);
    for (int i = 0; i < count; i++) {
        void *item = FUN_0002b630(self->f0, i);
        int idx = (ctx->f8 != 0) ? FUN_0002fea8(ctx->f8, item) : -1;
        if (idx < 0) {
            FUN_0004ae24("CollisionData::AssignNode not found %s\n", item);
            self->arr[i] = 0xffff;
        } else {
            self->arr[i] = idx;
        }
    }
    FUN_00049020();
}
