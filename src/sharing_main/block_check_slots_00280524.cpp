/* HSTMATCH module=hstp_trans_main.prx start=0x00280524 end=0x00280834 symbol=FUN_00280524 lang=c++ */
/* Clone of src/eboot/block_check_slots_0026f4e4.cpp (hstclone.py tag s10170158a2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Four sequential scans (entry kinds 5, 1, 2, 3 of the registry at DAT_003e1e48) that clear the result when an entry that qualifies (state >= 2, for kinds 1-3 also a nonzero 2-bit field at +0x65) has a slot value other than 4 or 5 in the matching range-checked table of the block (tables at +0x34c (2-byte cells), +0x84c, +0xacc, +0xd4c, 640 entries each; accessors in the 0x16b2b4 / 0x16b348 / 0x16b390 style, inlined here with the block as `this`). Matching idioms: `v - 4 > 1` on an unsigned (sltiu at; `>= 2` gives sltiu v0 and `v != 4 && v != 5` lays the branches out differently); the first scan reads the first byte of the 2-byte cell. */
struct Block {
    char pad[0x34c];
    short slots[640];
    unsigned char b[640];
    unsigned char c[640];
    unsigned char d[640];
    short *Slot(int idx)
    {
        if (idx >= 0 && idx < 640)
            return &slots[idx];
        return 0;
    }
    unsigned char *B(int idx)
    {
        if (idx >= 0 && idx < 640)
            return &b[idx];
        return 0;
    }
    unsigned char *C(int idx)
    {
        if (idx >= 0 && idx < 640)
            return &c[idx];
        return 0;
    }
    unsigned char *D(int idx)
    {
        if (idx >= 0 && idx < 640)
            return &d[idx];
        return 0;
    }
};
struct Ent {
    char pad[96];
    signed char f60;
    char pad61[4];
    signed char f65_0 : 2;
    signed char f65_2 : 2;
    signed char f65_4 : 4;
};
struct Reg;
extern "C" {
extern Reg *DAT_003e1e48;
int FUN_000dca08(Reg *, int);
Ent *FUN_000dca74(Reg *, int, int);
}
extern "C" int FUN_00280524(Block *self)
{
    int ok = 1;
    int i;
    for (i = 0; i < FUN_000dca08(DAT_003e1e48, 5); i++) {
        Ent *e = FUN_000dca74(DAT_003e1e48, 5, i);
        if (e != 0 && e->f60 >= 2) {
            unsigned v = *(unsigned char *)self->Slot(i);
            if (v - 4 > 1)
                ok = 0;
        }
    }
    for (i = 0; i < FUN_000dca08(DAT_003e1e48, 1); i++) {
        Ent *e = FUN_000dca74(DAT_003e1e48, 1, i);
        if (e != 0 && (e->f60 >= 2 || e->f65_2 != 0)) {
            unsigned v = *self->B(i);
            if (v - 4 > 1)
                ok = 0;
        }
    }
    for (i = 0; i < FUN_000dca08(DAT_003e1e48, 2); i++) {
        Ent *e = FUN_000dca74(DAT_003e1e48, 2, i);
        if (e != 0 && (e->f60 >= 2 || e->f65_2 != 0)) {
            unsigned v = *self->C(i);
            if (v - 4 > 1)
                ok = 0;
        }
    }
    for (i = 0; i < FUN_000dca08(DAT_003e1e48, 3); i++) {
        Ent *e = FUN_000dca74(DAT_003e1e48, 3, i);
        if (e != 0 && (e->f60 >= 2 || e->f65_2 != 0)) {
            unsigned v = *self->D(i);
            if (v - 4 > 1)
                ok = 0;
        }
    }
    return ok;
}
