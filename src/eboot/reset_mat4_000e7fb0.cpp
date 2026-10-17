/* HSTMATCH module=EBOOT.BIN start=0x000e7fb0 end=0x000e8094 symbol=FUN_000e7fb0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: the 16 floats are a 64-byte matrix of four Vec4 members assigned whole from an extern const global (a user-declared V4() {} makes the implicit operator= memberwise, giving the row-batched lwc1 x4 / swc1 x4 copies); exact match verified; names and types await human review. */
struct V4 {
    float x, y, z, w;
    V4() {}
};
struct M4 { V4 r0, r1, r2, r3;  };
struct Self {
    char pad0[0x40];
    float f40;
    char pad1[0x310 - 0x44];
    float f310;
    int f314;
    char pad2[0x340 - 0x318];
    M4 m;
    float s0, s1, s2;
    int f38c;
};
extern "C" {
extern const M4 DAT_002bc410;
}

extern "C" void FUN_000e7fb0(Self *p)
{
    p->m = DAT_002bc410;
    p->s0 = 1.0f;
    p->s1 = 1.0f;
    p->s2 = 1.0f;
    p->f38c = 0;
    p->f314 = 0;
    p->f310 = 1.0f;
    p->f40 = 1.0f;
}
