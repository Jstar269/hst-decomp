/* HSTMATCH module=hstp_trans_main.prx start=0x00059ca4 end=0x00059d68 symbol=FUN_00059ca4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct {
    char pad[0xec];
    u8 flag_ec;
    char pad_158[0x158 - 0xed];
    int start_idx;
    int end_idx;
} Obj;

extern void FUN_000593fc(Obj *self, int idx, int one, float zero_f);

void FUN_00059ca4(Obj *self, int param_2)
{
    if (param_2 < 0) {
        int i = self->start_idx;
        if (i <= self->end_idx) {
            char *p = (char *)self + i * 52;
            do {
                FUN_000593fc(self, i, 1, 0.0f);
                *(int *)(p + 0x10c) = 0;
                i++;
                p += 52;
            } while (i <= self->end_idx);
        }
        self->flag_ec = 0;
    } else {
        FUN_000593fc(self, param_2, 1, 0.0f);
        int off = param_2 * 52;
        *(int *)(off + (int)self + 0x10c) = 0;
    }
}
