/* HSTMATCH module=EBOOT.BIN start=0x0022be84 end=0x0022bf24 symbol=FUN_0022be84 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_0022b6a0(int, int);
extern void FUN_0022b02c(int, int, int);

/* Read entry `slot` of the object, wrap it into [0, count), store its successor (skipping 0 when skip_zero is set and count > 1) and return the wrapped value. */
int FUN_0022be84(int obj, int slot, int count, int skip_zero)
{
    int cur;
    int next;

    cur = FUN_0022b6a0(obj, slot);
    if (cur >= count) {
        cur = 0;
    }
    next = (cur + 1) % count;
    if (skip_zero != 0 && next == 0 && 1 < count) {
        next = next + 1;
    }
    FUN_0022b02c(obj, slot, next);
    return cur;
}
