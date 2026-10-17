/* HSTMATCH module=hstp_trans_main.prx start=0x0004c820 end=0x0004c898 symbol=__ct__10C_0004c820FRC10C_0004c820 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Out-of-line copy constructor of the collision triangle key (three Vec4 vertices, type, id; 64 bytes with
   padding), emitted by MWCC right after FUN_0004c078 which calls it; the Vec4 copies are inlined. Names provisional. */

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
} __attribute__((aligned(16)));

struct C_0004c820 {
    Vec4 v[3];
    int type;
    int id;
    C_0004c820(const C_0004c820 &k);
};

C_0004c820::C_0004c820(const C_0004c820 &k)
{
    v[0] = k.v[0];
    v[1] = k.v[1];
    v[2] = k.v[2];
    type = k.type;
    id = k.id;
}
