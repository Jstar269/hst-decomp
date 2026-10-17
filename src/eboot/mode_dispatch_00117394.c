/* HSTMATCH module=EBOOT.BIN start=0x00117394 end=0x001173f8 symbol=FUN_00117394 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: reconstructed switch with cases 0 (break), 1, 2, 3; exact match verified; names and types await human review. */

extern void FUN_001173f8(void *);
extern void FUN_00117a54(void *);

struct S {
    char pad[0x3c];
    int mode;
};

void FUN_00117394(struct S *self)
{
    switch (self->mode) {
    case 0:
        break;
    case 1:
    case 2:
        FUN_001173f8(self);
        break;
    case 3:
        FUN_00117a54(self);
        break;
    }
}
