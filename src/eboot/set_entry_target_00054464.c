/* HSTMATCH module=EBOOT.BIN start=0x00054464 end=0x00054510 symbol=FUN_00054464 lang=c99 */
/* Clone of src/sharing_main/set_entry_target_00054fb0.c (hstclone.py tag u6fr2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_0032b250[];

struct SubNode {
    void *f0;
};

struct Obj {
    char pad8[8];
    void *f8;
    int padc;
    struct SubNode *f10;
};

extern void FUN_0002b7a8(void *, unsigned short, unsigned char);
extern void *FUN_0002e790(void *, int);
extern void *FUN_0002e504(void *);

void FUN_00054464(struct Obj *self, int param_2, int param_3, int param_4, void *param_5)
{
    if (param_2 >= 0) {
        if (self->f10 != 0 && self->f10->f0 != 0) {
            FUN_0002b7a8(self->f10->f0, param_2, param_4);
        }
    }
    if (param_3 < 0) {
        return;
    }
    if (self->f8 != 0) {
        void *uVar1 = FUN_0002e790((char *)self->f8 + 16, param_3);
        void **puVar2 = (void **)FUN_0002e504(uVar1);
        if (param_4 != 0) {
            *puVar2 = param_5;
        } else {
            *puVar2 = &DAT_0032b250;
        }
    }
}
