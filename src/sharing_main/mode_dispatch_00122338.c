/* HSTMATCH module=hstp_trans_main.prx start=0x00122338 end=0x0012239c symbol=FUN_00122338 lang=c99 */
/* Clone of src/eboot/mode_dispatch_00117394.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: reconstructed switch with cases 0 (break), 1, 2, 3; exact match verified; names and types await human review. */

extern void FUN_0012239c(void *);
extern void FUN_00122a74(void *);

struct S {
    char pad[0x3c];
    int mode;
};

void FUN_00122338(struct S *self)
{
    switch (self->mode) {
    case 0:
        break;
    case 1:
    case 2:
        FUN_0012239c(self);
        break;
    case 3:
        FUN_00122a74(self);
        break;
    }
}
