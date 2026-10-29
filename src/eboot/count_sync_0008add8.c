/* HSTMATCH module=EBOOT.BIN start=0x0008add8 end=0x0008aee4 symbol=FUN_0008add8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag from inputs/generated/FUN_0008add8.c) corrected by hand: counter and fields as struct members (a struct pointer stores s-relative, an int-address expression did not); readability pass; exact match verified; names and types await human review. */
// matching idioms: lbu globals as unsigned char; `if (x != 0) {..} else { return 1; }` keeps retail's beqzl+li; `if (c != 0) n = 2; else n = 4;` for the arm order.
#include "hst/play_flow.h"

extern unsigned char DAT_003386b8;
extern int DAT_00338af0;
extern unsigned char *DAT_00338b44;
extern void FUN_000c50cc(int);
extern int FUN_000c4ba0(int, int);
extern void FUN_0008822c(char *, int, int);
extern char DAT_002d2428[];

/* Count the countdown down and call the helper when it reaches zero; otherwise compare each row entry with the target value. */
int FUN_0008add8(PlayFlowObj *self)
{
    int n;
    int i;
    int row;

    if (DAT_003386b8 != 0) {
        if (DAT_00338af0 != 0) {
            n = self->countdown;
            if (n < 1) {
                return 0;
            }
            if (0 < n) {
                if (--self->countdown == 0) {
                    FUN_000c50cc(DAT_00338af0);
                    return 0;
                }
            }
            if (*(unsigned char *)(DAT_00338b44 + 0x45) != 0) {
                n = 2;
            } else {
                n = 4;
            }
            for (i = 0; i < n; i++) {
                row = FUN_000c4ba0(DAT_00338af0, i);
                if (self->unk64 != *(int *)(row + self->unk5c * 4 + 4)) {
                    return 0;
                }
            }
            FUN_0008822c(DAT_002d2428, self->unk64, self->unk5c);
            self->unk60 = self->unk64 + 1;
        } else {
            return 1;
        }
    }
    return 1;
}
