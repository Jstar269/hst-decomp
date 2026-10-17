/* HSTMATCH module=EBOOT.BIN start=0x00204570 end=0x002045e8 symbol=FUN_00204570 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: bounds-checked inline accessor returning int (an unsigned char result would add andi 0xff at the join), outer range guard kept as retail has both; exact match verified; names and types await human review. */
struct Mgr {
    char pad[0x1025];
    unsigned char state[15];
    int Get(int i) {
        if (i >= 0 && i < 15) return state[i];
        return 1;
    }
};
extern "C" Mgr *FUN_0016bb88();
extern "C" int FUN_00204570(int i) {
    if (i >= 0 && i < 15) {
        Mgr *m = FUN_0016bb88();
        if (m->Get(i) == 2) return 1;
    }
    return 0;
}
