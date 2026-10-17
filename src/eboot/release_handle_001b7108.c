/* HSTMATCH module=EBOOT.BIN start=0x001b7108 end=0x001b7150 symbol=FUN_001b7108 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: changed -1<handle to handle>=0 and used &DAT_0034179c; exact match verified; names and types await human review. */

extern char DAT_0034179c;
extern void FUN_001b1f84(void *, int *);

struct S {
    char pad0[0x54];
    int handle;
    char pad1[0x80 - 0x58];
    int state;
};

void FUN_001b7108(struct S *self)
{
    if (self->handle >= 0) {
        FUN_001b1f84(&DAT_0034179c, &self->handle);
        self->handle = -1;
    }
    self->state = 3;
}
