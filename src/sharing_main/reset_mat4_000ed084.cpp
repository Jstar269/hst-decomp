/* HSTMATCH module=hstp_trans_main.prx start=0x000ed084 end=0x000ed168 symbol=FUN_000ed084 lang=c++ */
/* Clone of src/eboot/reset_mat4_000e7fb0.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
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
extern const M4 DAT_002cc260;
}

extern "C" void FUN_000ed084(Self *p)
{
    p->m = DAT_002cc260;
    p->s0 = 1.0f;
    p->s1 = 1.0f;
    p->s2 = 1.0f;
    p->f38c = 0;
    p->f314 = 0;
    p->f310 = 1.0f;
    p->f40 = 1.0f;
}
