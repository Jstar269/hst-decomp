/* HSTMATCH module=hstp_trans_main.prx start=0x00054fb0 end=0x0005505c symbol=FUN_00054fb0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_003d4590[];

struct SubNode {
    void *f0;
};

struct Obj {
    char pad8[8];
    void *f8;
    int padc;
    struct SubNode *f10;
};

extern void FUN_0002b7d0(void *, unsigned short, unsigned char);
extern void *FUN_0002e7b8(void *, int);
extern void *FUN_0002e52c(void *);

void FUN_00054fb0(struct Obj *self, int param_2, int param_3, int param_4, void *param_5)
{
    if (param_2 >= 0) {
        if (self->f10 != 0 && self->f10->f0 != 0) {
            FUN_0002b7d0(self->f10->f0, param_2, param_4);
        }
    }
    if (param_3 < 0) {
        return;
    }
    if (self->f8 != 0) {
        void *uVar1 = FUN_0002e7b8((char *)self->f8 + 16, param_3);
        void **puVar2 = (void **)FUN_0002e52c(uVar1);
        if (param_4 != 0) {
            *puVar2 = param_5;
        } else {
            *puVar2 = &DAT_003d4590;
        }
    }
}
