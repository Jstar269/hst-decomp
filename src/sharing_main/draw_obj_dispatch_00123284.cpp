/* HSTMATCH module=hstp_trans_main.prx start=0x00123284 end=0x00123318 symbol=FUN_00123284 lang=c++ */
/* Clone of src/eboot/draw_obj_dispatch_001180b0.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2/v0) corrected by hand: the packed byte at +0x30 is a signed bitfield struct (1-bit flag, 3-bit selector at bits 3..5), +0x60/+0x61 are unsigned char, branches reordered (mode != 0 first), table pointer typed with the items array; exact match verified; names and types await human review. */
struct Obj_00123284 {
    char pad0[0x30];
    signed char flag : 1;
    signed char mid : 2;
    signed char sel : 3;
    char pad31[0x2f];
    unsigned char kind;
    unsigned char mode;
};
struct Table_00123284 {
    char pad[0x70];
    int *items[8];
};
struct Out_00123284 {
    char pad[0x54];
    unsigned char v;
};
extern Table_00123284 *DAT_003e19f0;
extern "C" {
extern void FUN_000ae42c(int *, void *, void *);
extern void FUN_000b3d2c(int *, void *, int, int);
extern void FUN_000b42c4(int *, void *);
}
extern "C" void FUN_00123284(Out_00123284 *out, Obj_00123284 *o, int p3)
{
    int *t = DAT_003e19f0->items[o->sel];
    if (o->mode != 0) {
        FUN_000ae42c(t, o, (char *)o + 0x10);
    } else {
        if (o->flag != 0) {
            FUN_000b42c4(t, o);
        } else {
            FUN_000b3d2c(t, o, p3, 0);
        }
    }
    out->v = o->kind;
}
