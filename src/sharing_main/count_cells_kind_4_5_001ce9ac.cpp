/* HSTMATCH module=hstp_trans_main.prx start=0x001ce9ac end=0x001cea04 symbol=FUN_001ce9ac lang=c++ */
/* Clone of src/eboot/count_cells_kind_4_5_001c0798.cpp (hstclone.py tag c025707): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: rewritten as a bounds-checked inline accessor over a typed 640-entry table (guard `i >= 0 && i < 640` gives retail's bltzl layout) and an unsigned `kind - 4 < 2` test; exact match verified; names and types await human review. */
struct Cell {
    unsigned char kind;
    unsigned char aux;
};

struct Obj {
    char pad[0x34c];
    Cell cells[640];

    Cell *At(int i) {
        if (i >= 0 && i < 640) return &cells[i];
        return 0;
    }
};

extern "C" int FUN_001ce9ac(Obj *o) {
    int n = 0;
    for (int i = 0; i < 640; i++) {
        if ((unsigned)(o->At(i)->kind - 4) < 2) n++;
    }
    return n;
}
