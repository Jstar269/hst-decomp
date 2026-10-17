/* HSTMATCH module=EBOOT.BIN start=0x0008ac88 end=0x0008ad40 symbol=FUN_0008ac88 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: fixed inverted condition to logical OR; exact match verified; names and types await human review. */

extern char *DAT_00338b44;
extern char DAT_002d241c;
extern void FUN_0001f558(void *, int, int, int);
extern void FUN_0008822c(const void *, ...);
extern void FUN_0008ad40(void *);
extern int FUN_0008add8(void *);
extern int FUN_000df000(void *);

struct S {
    char pad0[0x3c];
    int state;
    int state_64;
};

void FUN_0008ac88(struct S *self)
{
    if (self->state == 7) {
        if (FUN_000df000(DAT_00338b44) != 0 || *(unsigned char *)(DAT_00338b44 + 0x5d) != 0) {
            FUN_0008ad40(self);
            if (FUN_0008add8(self) != 0) {
                self->state_64 = 4;
            }
        } else {
            self->state_64 = 6;
        }
    } else {
        FUN_0008822c(&DAT_002d241c, *(int *)(DAT_00338b44 + 0x9c));
        FUN_0001f558(self, 20, 0, 0);
        self->state_64 = 5;
    }
}
