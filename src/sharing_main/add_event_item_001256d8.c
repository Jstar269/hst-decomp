/* HSTMATCH module=hstp_trans_main.prx start=0x001256d8 end=0x00125750 symbol=FUN_001256d8 lang=c99 */
/* Clone of src/eboot/add_event_item_0011a504.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: fixed EABI signature with float 4th param and reconstructed switch(mode); exact match verified; names and types await human review. */

extern void FUN_00128024(void *, void *);
extern void FUN_00126d24(void *);

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

void FUN_001256d8(struct S *self, int mode, int arg, float val)
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
    FUN_00128024(&self->container, &item);
    FUN_00126d24(self);
    self->flags[mode] = 1;
}
