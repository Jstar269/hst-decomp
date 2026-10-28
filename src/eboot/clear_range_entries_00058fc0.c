/* HSTMATCH module=EBOOT.BIN start=0x00058fc0 end=0x00059084 symbol=FUN_00058fc0 lang=c99 */
/* Clone of src/sharing_main/clear_range_entries_00059ca4.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct {
    char pad[0xec];
    u8 flag_ec;
    char pad_158[0x158 - 0xed];
    int start_idx;
    int end_idx;
} Obj;

extern void FUN_00058748(Obj *self, int idx, int one, float zero_f);

void FUN_00058fc0(Obj *self, int param_2)
{
    if (param_2 < 0) {
        int i = self->start_idx;
        if (i <= self->end_idx) {
            char *p = (char *)self + i * 52;
            do {
                FUN_00058748(self, i, 1, 0.0f);
                *(int *)(p + 0x10c) = 0;
                i++;
                p += 52;
            } while (i <= self->end_idx);
        }
        self->flag_ec = 0;
    } else {
        FUN_00058748(self, param_2, 1, 0.0f);
        int off = param_2 * 52;
        *(int *)(off + (int)self + 0x10c) = 0;
    }
}
