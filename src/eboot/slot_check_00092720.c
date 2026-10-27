/* HSTMATCH module=EBOOT.BIN start=0x00092720 end=0x00092790 symbol=FUN_00092720 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Slot i occupied: ask FUN_00095058; empty: true for slots 3/4 when flag is 0, or for any negative flag. One shared trailing `return 0;` (nested ifs, no early return 0) gives retail's single `move v0,zero` block that the call arm reaches through a likely slot. */
typedef struct Self Self;
struct Self {
    char pad[0x50];
    int slot[8];
};
extern int FUN_00095058(int);

int FUN_00092720(Self *self, int i, int flag)
{
    int v = self->slot[i];
    if (v != 0) {
        if (FUN_00095058(v) != 0) {
            return 1;
        }
    } else {
        if ((i == 3 || i == 4) && flag == 0) {
            return 1;
        }
        if (flag < 0) {
            return 1;
        }
    }
    return 0;
}
