/* HSTMATCH module=hstp_trans_main.prx start=0x0008c5d4 end=0x0008c66c symbol=FUN_0008c5d4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

typedef struct {
    char pad[0x90];
    void *f90;
    char pad2[0xc];
    void *fa0;
} Obj_0008c5d4;

extern void *DAT_003e1a54;
extern void *DAT_003e1a0c;
extern void *DAT_003da704;
extern char *DAT_003e95e0;

extern void FUN_0005c700(void *, void *);
extern void FUN_0014c118(char *);
extern void FUN_000cb374(void *);
extern void FUN_002031cc(void *);

void FUN_0008c5d4(Obj_0008c5d4 *self)
{
    if (DAT_003e1a54 != 0) {
        FUN_0005c700(DAT_003e1a54, DAT_003da704);
    }
    if (DAT_003e1a0c != 0) {
        FUN_0005c700(DAT_003e1a0c, DAT_003da704);
    }
    if (DAT_003e95e0 != 0) {
        FUN_0014c118(DAT_003e95e0 + 0x40);
    }
    if (self->f90 != 0) {
        FUN_000cb374(self->f90);
    }
    if (self->fa0 != 0) {
        FUN_002031cc(self->fa0);
    }
}
