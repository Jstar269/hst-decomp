/* HSTMATCH module=EBOOT.BIN start=0x0026f4e4 end=0x0026f7f4 symbol=FUN_0026f4e4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Four sequential scans (entry kinds 5, 1, 2, 3 of the registry at DAT_00338b08) that clear the result when an entry that qualifies (state >= 2, for kinds 1-3 also a nonzero 2-bit field at +0x65) has a slot value other than 4 or 5 in the matching range-checked table of the block (tables at +0x34c (2-byte cells), +0x84c, +0xacc, +0xd4c, 640 entries each; accessors in the 0x16b2b4 / 0x16b348 / 0x16b390 style, inlined here with the block as `this`). Matching idioms: `v - 4 > 1` on an unsigned (sltiu at; `>= 2` gives sltiu v0 and `v != 4 && v != 5` lays the branches out differently); the first scan reads the first byte of the 2-byte cell. */
#define CELL_COUNT 640 /* entries per table */

struct Block {
    char pad[0x34c];
    short slots[CELL_COUNT];
    unsigned char b[CELL_COUNT];
    unsigned char c[CELL_COUNT];
    unsigned char d[CELL_COUNT];
    short *Slot(int idx)
    {
        if (idx >= 0 && idx < CELL_COUNT)
            return &slots[idx];
        return 0;
    }
    unsigned char *B(int idx)
    {
        if (idx >= 0 && idx < CELL_COUNT)
            return &b[idx];
        return 0;
    }
    unsigned char *C(int idx)
    {
        if (idx >= 0 && idx < CELL_COUNT)
            return &c[idx];
        return 0;
    }
    unsigned char *D(int idx)
    {
        if (idx >= 0 && idx < CELL_COUNT)
            return &d[idx];
        return 0;
    }
};
struct Ent {
    char pad[96];
    signed char state;
    char pad61[4];
    signed char f65_0 : 2;
    signed char f65_2 : 2;
    signed char f65_4 : 4;
};
struct Reg;
extern "C" {
extern Reg *DAT_00338b08;
int FUN_000d8bfc(Reg *, int);
Ent *FUN_000d8c24(Reg *, int, int);
}
extern "C" int FUN_0026f4e4(Block *self)
{
    int ok = 1;
    int i;
    for (i = 0; i < FUN_000d8bfc(DAT_00338b08, 5); i++) {
        Ent *e = FUN_000d8c24(DAT_00338b08, 5, i);
        if (e != 0 && e->state >= 2) {
            unsigned v = *(unsigned char *)self->Slot(i);
            if (v - 4 > 1)
                ok = 0;
        }
    }
    for (i = 0; i < FUN_000d8bfc(DAT_00338b08, 1); i++) {
        Ent *e = FUN_000d8c24(DAT_00338b08, 1, i);
        if (e != 0 && (e->state >= 2 || e->f65_2 != 0)) {
            unsigned v = *self->B(i);
            if (v - 4 > 1)
                ok = 0;
        }
    }
    for (i = 0; i < FUN_000d8bfc(DAT_00338b08, 2); i++) {
        Ent *e = FUN_000d8c24(DAT_00338b08, 2, i);
        if (e != 0 && (e->state >= 2 || e->f65_2 != 0)) {
            unsigned v = *self->C(i);
            if (v - 4 > 1)
                ok = 0;
        }
    }
    for (i = 0; i < FUN_000d8bfc(DAT_00338b08, 3); i++) {
        Ent *e = FUN_000d8c24(DAT_00338b08, 3, i);
        if (e != 0 && (e->state >= 2 || e->f65_2 != 0)) {
            unsigned v = *self->D(i);
            if (v - 4 > 1)
                ok = 0;
        }
    }
    return ok;
}
