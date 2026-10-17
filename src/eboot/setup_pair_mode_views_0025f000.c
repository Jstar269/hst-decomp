/* HSTMATCH module=EBOOT.BIN start=0x0025f000 end=0x0025f0c4 symbol=FUN_0025f000 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a7/v21/FUN_0025f000.c (tag: a7) */
extern unsigned char DAT_003417be;
extern void FUN_000ffb3c(int, int);

void FUN_0025f000(int param_1, int param_2)
{
    if (*(unsigned char *)(param_1 + 0x64) != 0 && (*(unsigned char *)(param_1 + 0x65) == 0 || DAT_003417be != 0)) {
        FUN_000ffb3c(*(int *)(param_1 + 0x7c), 1);
        FUN_000ffb3c(*(int *)(param_1 + 0x80), 1);
        FUN_000ffb3c(*(int *)(param_1 + 0x88), 1);
        FUN_000ffb3c(*(int *)(param_1 + 0x8c), 1);
    } else {
        if (*(unsigned char *)(param_1 + 0x65) != 0) {
            FUN_000ffb3c(*(int *)(param_1 + 0x7c), 0);
            FUN_000ffb3c(*(int *)(param_1 + 0x80), 0);
        }
        FUN_000ffb3c(*(int *)(param_1 + 0x88), param_2);
        FUN_000ffb3c(*(int *)(param_1 + 0x8c), param_2);
    }
}
