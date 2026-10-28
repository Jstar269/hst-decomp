/* HSTMATCH module=hstp_trans_main.prx start=0x0020a63c end=0x0020a6c0 symbol=FUN_0020a63c lang=c99 */
/* Clone of src/eboot/prepare_float_callback_001fbf24.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed the callback argument order across the integer and floating register banks and corrected the byte and short accesses; exact match verified; names and types await human review. */
#include "hst/types.h"
extern void FUN_00105470(int, int);
extern void FUN_000f3588(float, float, float, void *, u32 *, int, int,
                         float, float);
extern void FUN_00108aec(void *);

void FUN_0020a63c(char *self)
{
    FUN_00105470(*(int *)(self + 0x74),
                 ((*(unsigned char *)(self + 0x7c) != 0) ^ 1));
    if (*(int *)(self + 0x78) != 0 &&
        ((*(unsigned short *)((char *)*(u32 **)(self + 0x70) + 0xe) & 3) == 0)) {
        FUN_000f3588(0.0f, 0.0f, 1.0f,
                     *(void **)(self + 0x78), *(u32 **)(self + 0x70), 0, 0,
                     1.0f, 1.0f);
    }
    FUN_00108aec(self);
}
