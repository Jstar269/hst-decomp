/* HSTMATCH module=hstp_trans_main.prx start=0x001c4538 end=0x001c4584 symbol=FUN_001c4538 lang=c99 */
/* Clone of src/eboot/reset_handle_001b6878.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: changed -1<handle to handle>=0 and used &DAT_003eaad8; exact match verified; names and types await human review. */

extern char DAT_003eaad8;
extern void FUN_001c0018(void *, int *);
extern int FUN_001c0bb0(void *, int);

struct S {
    char pad0[0x4c];
    int handle;
    int next_handle;
};

void FUN_001c4538(struct S *self)
{
    if (self->handle >= 0) {
        FUN_001c0018(&DAT_003eaad8, &self->handle);
    }
    self->next_handle = FUN_001c0bb0(&DAT_003eaad8, 0);
}
