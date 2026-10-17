/* HSTMATCH module=hstp_trans_main.prx start=0x0023a4d4 end=0x0023a54c symbol=FUN_0023a4d4 lang=c++ */
/* Clone of src/eboot/call_with_flag_0022ac78.cpp (hstclone.py tag s10170158a1r2s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: flag is an unsigned char passed to an int parameter (gives retail's andi s0 / andi a2), set through an inline bool getter compared `== true` (matching idiom: without `== true` the flag is if-converted); exact match verified; names and types await human review. */
struct Obj {
    char pad[0x138];
    int m138;
    bool IsM138Zero() { return m138 == 0; }
};

extern "C" Obj *FUN_0023ce60();
extern "C" void FUN_0023a620(int, int, int);

extern "C" void FUN_0023a4d4(int a, int b) {
    unsigned char flag = 0;
    if (FUN_0023ce60()) {
        if (FUN_0023ce60()->IsM138Zero() == true) flag = true;
    }
    FUN_0023a620(a, b, flag);
}
