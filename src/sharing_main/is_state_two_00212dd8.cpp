/* HSTMATCH module=hstp_trans_main.prx start=0x00212dd8 end=0x00212e50 symbol=FUN_00212dd8 lang=c++ */
/* Clone of src/eboot/is_state_two_00204570.cpp (hstclone.py tag c025707): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: bounds-checked inline accessor returning int (an unsigned char result would add andi 0xff at the join), outer range guard kept as retail has both; exact match verified; names and types await human review. */
struct Mgr {
    char pad[0x1025];
    unsigned char state[15];
    int Get(int i) {
        if (i >= 0 && i < 15) return state[i];
        return 1;
    }
};
extern "C" Mgr *FUN_00177d4c();
extern "C" int FUN_00212dd8(int i) {
    if (i >= 0 && i < 15) {
        Mgr *m = FUN_00177d4c();
        if (m->Get(i) == 2) return 1;
    }
    return 0;
}
