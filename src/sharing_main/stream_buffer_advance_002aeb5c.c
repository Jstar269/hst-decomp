/* HSTMATCH module=hstp_trans_main.prx start=0x002aeb5c end=0x002aec70 symbol=FUN_002aeb5c lang=c99 */
/* Clone of src/eboot/stream_buffer_advance_0029f818.c (hstclone.py tag s10171846g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char u8;

extern void *FUN_00011090(void *dest, const void *src, int n);
extern void FUN_000c3d1c(void *, void *, void *);
extern int FUN_00104e48(int, const void *, int);

void FUN_002aeb5c(char *param_1)
{
    int consumed;

    if (*(int *)(param_1 + 0x201c0) > 0) {
        consumed = FUN_00104e48(*(int *)(param_1 + 0x1b4), *(void **)(param_1 + 0x201bc), *(int *)(param_1 + 0x201c0));
        *(int *)(param_1 + 0x201c0) -= consumed;
        *(char **)(param_1 + 0x201bc) += consumed;
    } else {
        *(int *)(param_1 + 0x101b8) = 0x10000;
        FUN_000c3d1c(*(void **)(param_1 + 4), param_1 + 0x1b8, param_1 + 0x101b8);
        consumed = FUN_00104e48(*(int *)(param_1 + 0x1b4), param_1 + 0x1b8, *(int *)(param_1 + 0x101b8));
        if (consumed < *(int *)(param_1 + 0x101b8)) {
            *(int *)(param_1 + 0x201c0) = *(int *)(param_1 + 0x101b8) - consumed;
            *(char **)(param_1 + 0x201bc) = param_1 + 0x101bc;
            FUN_00011090(param_1 + 0x101bc, param_1 + 0x1b8 + consumed, *(int *)(param_1 + 0x201c0));
        }
    }
}
