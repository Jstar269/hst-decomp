/* HSTMATCH module=EBOOT.BIN start=0x001beffc end=0x001bf1cc symbol=FUN_001beffc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2/v0) corrected by hand: raw offsets replaced by a typed object (byte tables at +0xfcc, +0xfe1, +0x1025, five-byte cells at +0x3444), the dropped extra arguments of FUN_001be968 and FUN_001bebb0 restored; exact match verified; names and types await human review. */
/* Matching idioms: the five-byte cell loop uses its own counter j (a shared i swaps s3/s4) and tests `enable` twice (kind, then the four flags), as retail does. */
extern int DAT_0034a7ec;
extern void FUN_000114c0(void *, int, int);
extern void FUN_001bc7e0(void *, int);
extern void FUN_001be728();
extern void FUN_001be968();
extern void FUN_001bebb0();
extern void FUN_001bec74();
extern void FUN_001bed48();
extern void FUN_001bee20();
extern void FUN_001bef18();

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
extern struct Slot *FUN_0027edbc(int, int);
extern struct Ent *FUN_00193474(int);

void FUN_001beffc(struct Obj *self, int enable)
{
    int i;
    FUN_001be728(self, enable);
    FUN_001be968(self, enable, enable, enable);
    FUN_001bebb0(self, enable, enable);
    FUN_001bec74(self, enable);
    FUN_001bed48(self, enable);
    FUN_001bee20(self, enable);
    for (i = 0; i < 21; i++) {
        struct Slot *e;
        self->a[i] = 0;
        e = FUN_0027edbc(DAT_0034a7ec, i);
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
    FUN_001bc7e0(self->sub, enable);
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
    FUN_001bef18(self, enable);
    for (i = 0; i < 15; i++)
        self->c[i] = FUN_00193474(i)->f7c;
}
