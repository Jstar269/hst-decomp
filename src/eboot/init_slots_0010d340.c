/* HSTMATCH module=EBOOT.BIN start=0x0010d340 end=0x0010d3e4 symbol=FUN_0010d340 lang=c99 */
/* Hand-written reconstruction from the disassembly (the two field stores go through a block-scoped pointer so it dies at the second call and is reloaded for the last store; `opt_strength_reduction off` keeps the per-iteration `i * 4`); exact match verified; names and types await human review. */
extern void FUN_000ffb3c(int, int);
extern void FUN_000ffca4(int);
#pragma opt_strength_reduction off

void FUN_0010d340(int param_1)
{
    int i;

    for (i = 0; i < *(int *)(param_1 + 0x14); i++) {
        int off = i * 4;
        int v;

        FUN_000ffb3c(*(int *)(*(int *)(param_1 + 0x10) + off), 0);
        v = *(int *)(param_1 + 0xd0);
        {
            int *p = *(int **)(*(int *)(param_1 + 0x10) + off);
            p[9] = v;
            p[10] = v;
        }
        FUN_000ffca4(*(int *)(*(int *)(param_1 + 0x10) + off));
        **(int **)(*(int *)(param_1 + 0x10) + off) = *(int *)(param_1 + 0xd4);
    }
}
