/* HSTMATCH module=EBOOT.BIN start=0x0022be84 end=0x0022bf24 symbol=FUN_0022be84 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_0022b6a0(int, int);
extern void FUN_0022b02c(int, int, int);

int FUN_0022be84(int param_1, int param_2, int param_3, int param_4)
{
    int cur;
    int next;

    cur = FUN_0022b6a0(param_1, param_2);
    if (cur >= param_3) {
        cur = 0;
    }
    next = (cur + 1) % param_3;
    if (param_4 != 0 && next == 0 && 1 < param_3) {
        next = next + 1;
    }
    FUN_0022b02c(param_1, param_2, next);
    return cur;
}
