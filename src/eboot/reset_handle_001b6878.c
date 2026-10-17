/* HSTMATCH module=EBOOT.BIN start=0x001b6878 end=0x001b68c4 symbol=FUN_001b6878 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: changed -1<handle to handle>=0 and used &DAT_0034179c; exact match verified; names and types await human review. */

extern char DAT_0034179c;
extern void FUN_001b1f84(void *, int *);
extern int FUN_001b2af0(void *, int);

struct S {
    char pad0[0x4c];
    int handle;
    int next_handle;
};

void FUN_001b6878(struct S *self)
{
    if (self->handle >= 0) {
        FUN_001b1f84(&DAT_0034179c, &self->handle);
    }
    self->next_handle = FUN_001b2af0(&DAT_0034179c, 0);
}
