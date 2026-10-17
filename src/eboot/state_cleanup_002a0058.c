/* HSTMATCH module=EBOOT.BIN start=0x002a0058 end=0x002a00ac symbol=FUN_002a0058 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_002cbb24[];
extern int FUN_002b79a8(int);
extern void FUN_0029e3cc(const char *, int);
struct Obj { char pad[0x28]; int state; };
void FUN_002a0058(struct Obj *self)
{
    int state = self->state;
    if (state < 0)
        return;
    int result = FUN_002b79a8(state);
    if (result != 0)
        FUN_0029e3cc(DAT_002cbb24, result);
    self->state = -1;
}
