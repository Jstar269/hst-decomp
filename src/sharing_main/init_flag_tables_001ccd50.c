/* HSTMATCH module=hstp_trans_main.prx start=0x001ccd50 end=0x001ccf20 symbol=FUN_001ccd50 lang=c99 */
/* Clone of src/eboot/init_flag_tables_001beffc.c (hstclone.py tag s10170158a1r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2/v0) corrected by hand: raw offsets replaced by a typed object (byte tables at +0xfcc, +0xfe1, +0x1025, five-byte cells at +0x3444), the dropped extra arguments of FUN_001cc6bc and FUN_001cc904 restored; exact match verified; names and types await human review. */
/* Matching idioms: the five-byte cell loop uses its own counter j (a shared i swaps s3/s4) and tests `enable` twice (kind, then the four flags), as retail does. */
extern int DAT_003f3b1c;
extern void FUN_000114c0(void *, int, int);
extern void FUN_001ca5c8(void *, int);
extern void FUN_001cc47c();
extern void FUN_001cc6bc();
extern void FUN_001cc904();
extern void FUN_001cc9c8();
extern void FUN_001cca9c();
extern void FUN_001ccb74();
extern void FUN_001ccc6c();

struct Cell {
    unsigned char kind;
    unsigned char flags[4];
};
struct Obj {
    char pad0[0xfcc];
    unsigned char a[21];
    unsigned char b[8];
    char pad1[0x1025 - 0xfe9];
    unsigned char c[15];
    char pad2[0x1378 - 0x1034];
    char sub[0x3444 - 0x1378];
    struct Cell cells[12];
};
struct Slot {
    char pad[4];
    short state;
};
struct Ent {
    char pad[0x7c];
    unsigned char f7c;
};
extern struct Slot *FUN_00290230(int, int);
extern struct Ent *FUN_0019fc84(int);

void FUN_001ccd50(struct Obj *self, int enable)
{
    int i;
    FUN_001cc47c(self, enable);
    FUN_001cc6bc(self, enable, enable, enable);
    FUN_001cc904(self, enable, enable);
    FUN_001cc9c8(self, enable);
    FUN_001cca9c(self, enable);
    FUN_001ccb74(self, enable);
    for (i = 0; i < 21; i++) {
        struct Slot *e;
        self->a[i] = 0;
        e = FUN_00290230(DAT_003f3b1c, i);
        if (e != 0 && e->state >= 0) {
            if (enable != 0)
                self->a[i] = 4;
            else if (e->state == 1)
                self->a[i] = 4;
        }
    }
    for (i = 0; i < 8; i++) {
        self->b[i] = 0;
        if (enable != 0)
            self->b[i] = 4;
        else if (i == 0)
            self->b[i] = 4;
    }
    FUN_001ca5c8(self->sub, enable);
    {
        int j;
        for (j = 0; j < 12; j++) {
            struct Cell *cell = &self->cells[j];
            cell->kind = 0;
            FUN_000114c0(cell->flags, 0, 4);
            if (enable != 0)
                cell->kind = 4;
            if (enable != 0) {
                cell->flags[0] = 1;
                cell->flags[1] = 1;
                cell->flags[2] = 1;
                cell->flags[3] = 1;
            }
        }
    }
    FUN_001ccc6c(self, enable);
    for (i = 0; i < 15; i++)
        self->c[i] = FUN_0019fc84(i)->f7c;
}
