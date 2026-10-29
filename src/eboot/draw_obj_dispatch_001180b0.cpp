/* HSTMATCH module=EBOOT.BIN start=0x001180b0 end=0x00118144 symbol=FUN_001180b0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2/v0) corrected by hand: readability pass; the packed byte at +0x30 is a signed bitfield struct (1-bit flag, 3-bit selector at bits 3..5), +0x60/+0x61 are unsigned char, branches reordered (mode != 0 first), table pointer typed with the items array; exact match verified; names and types await human review. */
struct Obj_001180b0 {
    char pad0[0x30];
    signed char flag : 1;
    signed char mid : 2;
    signed char sel : 3;
    char pad31[0x2f];
    unsigned char kind;
    unsigned char mode;
};
struct Table_001180b0 {
    char pad[0x70];
    int *items[8];
};
struct Out_001180b0 {
    char pad[0x54];
    unsigned char v;
};
extern Table_001180b0 *DAT_003386b0;
extern "C" {
extern void FUN_000aba38(int *, void *, void *);
extern void FUN_000b0d40(int *, void *, int, int);
extern void FUN_000b12d8(int *, void *);
}
/* Dispatches a draw object to one of three handlers of the table entry its selector names, then copies its kind byte to the output. */
extern "C" void FUN_001180b0(Out_001180b0 *out, Obj_001180b0 *obj, int arg)
{
    int *handler = DAT_003386b0->items[obj->sel];
    if (obj->mode != 0) {
        FUN_000aba38(handler, obj, (char *)obj + 0x10);
    } else {
        if (obj->flag != 0) {
            FUN_000b12d8(handler, obj);
        } else {
            FUN_000b0d40(handler, obj, arg, 0);
        }
    }
    out->v = obj->kind;
}
