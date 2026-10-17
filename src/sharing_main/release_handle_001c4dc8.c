/* HSTMATCH module=hstp_trans_main.prx start=0x001c4dc8 end=0x001c4e10 symbol=FUN_001c4dc8 lang=c99 */
/* Clone of src/eboot/release_handle_001b7108.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: changed -1<handle to handle>=0 and used &DAT_003eaad8; exact match verified; names and types await human review. */

extern char DAT_003eaad8;
extern void FUN_001c0018(void *, int *);

struct S {
    char pad0[0x54];
    int handle;
    char pad1[0x80 - 0x58];
    int state;
};

void FUN_001c4dc8(struct S *self)
{
    if (self->handle >= 0) {
        FUN_001c0018(&DAT_003eaad8, &self->handle);
        self->handle = -1;
    }
    self->state = 3;
}
