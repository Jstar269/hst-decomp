/* HSTMATCH module=EBOOT.BIN start=0x0029f818 end=0x0029f92c symbol=FUN_0029f818 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char u8;

extern void *FUN_00011090(void *dest, const void *src, int n);
extern void FUN_000c067c(void *, void *, void *);
extern int FUN_000ff5b0(int, const void *, int);

void FUN_0029f818(char *param_1)
{
    int consumed;

    if (*(int *)(param_1 + 0x201c0) > 0) {
        consumed = FUN_000ff5b0(*(int *)(param_1 + 0x1b4), *(void **)(param_1 + 0x201bc), *(int *)(param_1 + 0x201c0));
        *(int *)(param_1 + 0x201c0) -= consumed;
        *(char **)(param_1 + 0x201bc) += consumed;
    } else {
        *(int *)(param_1 + 0x101b8) = 0x10000;
        FUN_000c067c(*(void **)(param_1 + 4), param_1 + 0x1b8, param_1 + 0x101b8);
        consumed = FUN_000ff5b0(*(int *)(param_1 + 0x1b4), param_1 + 0x1b8, *(int *)(param_1 + 0x101b8));
        if (consumed < *(int *)(param_1 + 0x101b8)) {
            *(int *)(param_1 + 0x201c0) = *(int *)(param_1 + 0x101b8) - consumed;
            *(char **)(param_1 + 0x201bc) = param_1 + 0x101bc;
            FUN_00011090(param_1 + 0x101bc, param_1 + 0x1b8 + consumed, *(int *)(param_1 + 0x201c0));
        }
    }
}
