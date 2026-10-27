/* HSTMATCH module=hstp_trans_main.prx start=0x002c3b20 end=0x002c3b70 symbol=FUN_002c3b20 lang=c++ */
struct Rec {
    int w00;
    char a04[32];
    char a24[32];
    char c44, c45, c46;
    unsigned char b47, b48;
    char c49, c4a, c4b;
    int w4c, w50;
    char a54[16];
};
extern "C" Rec *FUN_002c3c54(Rec *, const Rec *);
extern "C" Rec *FUN_002c3b70(Rec *, const Rec *);
extern "C" void FUN_002c3b20(Rec *a, Rec *b)
{
    Rec tmp;
    FUN_002c3c54(&tmp, a);
    FUN_002c3b70(a, b);
    FUN_002c3b70(b, &tmp);
}
// First reconstruction from disassembly (wip-less queue item). 20/20 words, 6 differ: one global
// s0/s1 exchange (retail s0=param_1/s1=param_2; ours reversed). Declaration order, corrected swapped
// parameter order, pointer aliases, reference parameters and a 12-mutant permuter run all leave it.
// Bodies: tmp = *a via 0x2c3c54, then a = b, b = tmp via 0x2c3b70 (both EXACT in src/sharing_main).
// near miss from lane dsm1 (unreviewed)
