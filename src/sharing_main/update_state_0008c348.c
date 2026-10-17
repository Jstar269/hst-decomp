/* HSTMATCH module=hstp_trans_main.prx start=0x0008c348 end=0x0008c400 symbol=FUN_0008c348 lang=c99 */
/* Clone of src/eboot/update_state_0008ac88.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: fixed inverted condition to logical OR; exact match verified; names and types await human review. */

extern char *DAT_003e1e84;
extern char DAT_003784c0;
extern void FUN_0001f4a0(void *, int, int, int);
extern void FUN_00089ab4(const void *, ...);
extern void FUN_0008c400(void *);
extern int FUN_0008c498(void *);
extern int FUN_000e31ec(void *);

struct S {
    char pad0[0x3c];
    int state;
    int state_64;
};

void FUN_0008c348(struct S *self)
{
    if (self->state == 7) {
        if (FUN_000e31ec(DAT_003e1e84) != 0 || *(unsigned char *)(DAT_003e1e84 + 0x5d) != 0) {
            FUN_0008c400(self);
            if (FUN_0008c498(self) != 0) {
                self->state_64 = 4;
            }
        } else {
            self->state_64 = 6;
        }
    } else {
        FUN_00089ab4(&DAT_003784c0, *(int *)(DAT_003e1e84 + 0x9c));
        FUN_0001f4a0(self, 20, 0, 0);
        self->state_64 = 5;
    }
}
