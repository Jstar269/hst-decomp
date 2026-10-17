/* HSTMATCH module=EBOOT.BIN start=0x0022ac78 end=0x0022acf0 symbol=FUN_0022ac78 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: flag is an unsigned char passed to an int parameter (gives retail's andi s0 / andi a2), set through an inline bool getter compared `== true` (matching idiom: without `== true` the flag is if-converted); exact match verified; names and types await human review. */
struct Obj {
    char pad[0x138];
    int m138;
    bool IsM138Zero() { return m138 == 0; }
};

extern "C" Obj *FUN_0022cd60();
extern "C" void FUN_0022ad48(int, int, int);

extern "C" void FUN_0022ac78(int a, int b) {
    unsigned char flag = 0;
    if (FUN_0022cd60()) {
        if (FUN_0022cd60()->IsM138Zero() == true) flag = true;
    }
    FUN_0022ad48(a, b, flag);
}
