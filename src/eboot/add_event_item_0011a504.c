/* HSTMATCH module=EBOOT.BIN start=0x0011a504 end=0x0011a57c symbol=FUN_0011a504 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: fixed EABI signature with float 4th param and reconstructed switch(mode); exact match verified; names and types await human review. */

extern void FUN_0011ce50(void *, void *);
extern void FUN_0011bb50(void *);

struct Item {
    int mode;
    int arg;
    float val;
};

struct S {
    char pad0[0x2f8];
    char container[0x18];
    char flags[16];
};

void FUN_0011a504(struct S *self, int mode, int arg, float val)
{
    switch (mode) {
    case 0:
        val = 0.0f;
        break;
    case 1:
        val = 64.0f;
        break;
    default:
        break;
    }
    struct Item item;
    item.mode = mode;
    item.arg = arg;
    item.val = val;
    FUN_0011ce50(&self->container, &item);
    FUN_0011bb50(self);
    self->flags[mode] = 1;
}
